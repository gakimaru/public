/* git credential-wincred に登録されているユーザーとパスワードを全削除 */

/*#define _CRT_SECURE_NO_WARNINGS*/

#include <windows.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>

/* Cred系APIのインターフェースを定義 */

typedef struct _CREDENTIAL_ATTRIBUTEW
{
	LPWSTR	Keyword;
	DWORD	Flags;
	DWORD	ValueSize;
	LPBYTE	Value;
} CREDENTIAL_ATTRIBUTEW, *PCREDENTIAL_ATTRIBUTEW;

typedef struct _CREDENTIALW
{
	DWORD					Flags;
	DWORD					Type;
	LPWSTR					TargetName;
	LPWSTR					Comment;
	FILETIME				LastWritten;
	DWORD					CredentialBlobSize;
	LPBYTE					CredentialBlob;
	DWORD					Persist;
	DWORD					AttributeCount;
	PCREDENTIAL_ATTRIBUTEW	Attributes;
	LPWSTR					TargetAlias;
	LPWSTR					UserName;
} CREDENTIALW, *PCREDENTIALW;

/*typedef BOOL (WINAPI *CredWriteWT)(PCREDENTIALW, DWORD);*/
typedef BOOL (WINAPI *CredEnumerateWT)(LPCWSTR, DWORD, DWORD *,PCREDENTIALW **);
typedef VOID (WINAPI *CredFreeT)(PVOID);
typedef BOOL (WINAPI *CredDeleteWT)(LPCWSTR, DWORD, DWORD);

static HMODULE advapi_module;
/*static CredWriteWT CredWriteW;*/
static CredEnumerateWT CredEnumerateW;
static CredFreeT CredFree;
static CredDeleteWT CredDeleteW;

#define CRED_TYPE_GENERIC			(1)
#define CRED_PERSIST_LOCAL_MACHINE	(2)
#define CRED_MAX_ATTRIBUTES			(64)

static void load_cred_funcs(void)
{
	advapi_module = LoadLibrary("advapi32.dll");
	if(!advapi_module)
	{
		printf("Failed to load advapi32.dll.\r\n");
		exit(EXIT_FAILURE);
	}
/*	CredWriteW = (CredWriteWT)GetProcAddress(advapi_module, "CredWriteW");*/
	CredEnumerateW = (CredEnumerateWT)GetProcAddress(advapi_module, "CredEnumerateW");
	CredFree = (CredFreeT)GetProcAddress(advapi_module, "CredFree");
	CredDeleteW = (CredDeleteWT)GetProcAddress(advapi_module, "CredDeleteW");
/*	if(!CredWriteW || !CredEnumerateW || !CredFree || !CredDeleteW)*/
	if(!CredEnumerateW || !CredFree || !CredDeleteW)
	{
		printf("Failed to load functions.\r\n");
		exit(EXIT_FAILURE);
	}
}

static void print_param(const char* name, LPCWSTR param, size_t param_len)
{
	char buf[8192];
	int len = WideCharToMultiByte(CP_UTF8, 0, param, (int)param_len, NULL, 0, NULL, FALSE);
	if(!WideCharToMultiByte(CP_UTF8, 0, param, (int)param_len, buf, len, NULL, FALSE))
	{
		printf("WideCharToMultiByte() failed.\r\n");
		exit(EXIT_FAILURE);
	}
	printf("%s=", name);
	fwrite(buf, 1, len, stdout);
	putchar('\n');
}

int main(int argc, char *argv[])
{
	CREDENTIALW **creds;
	DWORD num_creds;
	DWORD i;
	
	load_cred_funcs();
	if(!CredEnumerateW(L"git:*", 0, &num_creds, &creds))
	{
		printf("git-wincred entry is nothing.\r\n");
		return EXIT_SUCCESS;
	}
	for (i = 0; i < num_creds; ++i)
	{
        printf("\r\n");
		printf("Erase:\r\n");
		print_param("  Target", creds[i]->TargetName, wcslen(creds[i]->TargetName));
		print_param("  UserName", creds[i]->UserName, wcslen(creds[i]->UserName));
		print_param("  Password", L"****************************************************************", creds[i]->CredentialBlobSize / sizeof(WCHAR));
		CredDeleteW(creds[i]->TargetName, creds[i]->Type, 0);
    }
	CredFree(creds);
	return EXIT_SUCCESS;
}
