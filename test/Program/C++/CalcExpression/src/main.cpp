#include <stdio.h>
#include <stdlib.h>

int sub()
{
	printf("    -> Called!\n");
	return 1;
}

#define TEST(expr) { printf("expr=\"%s\"\n", #expr); const int ret = (expr); printf("  result=%d\n", ret); }

int main(const int argc, const char* argv[])
{
	TEST(1);
	TEST(1 + 1);
	
	TEST(true && sub());
	TEST(false && sub());
	TEST(true || sub());
	TEST(false || sub());
	TEST(sub() && true);
	TEST(sub() && false);
	TEST(sub() || true);
	TEST(sub() || false);
	TEST(true ? sub() : 999);
	TEST(false ? sub() : 999);
	TEST(true ? 999 : sub());
	TEST(false ? 999 : sub());
	TEST(0xffffffff & sub());
	TEST(0x00000000 & sub());
	TEST(0xffffffff | sub());
	TEST(0x00000000 | sub());
	TEST(sub() & 0xffffffff);
	TEST(sub() & 0x00000000);
	TEST(sub() | 0xffffffff);
	TEST(sub() | 0x00000000);
	TEST(1 * sub());
	TEST(0 * sub());
	TEST(1 / sub());
	TEST(0 / sub());
	TEST(sub() * 1);
	TEST(sub() * 0);
	TEST(sub() / 1);
//	TEST(sub() / 0);
	
//yŒ‹‰Êz
//	expr = "1"
//	  result = 1
//	expr = "1 + 1"
//	  result = 2
//	expr = "true && sub()"
//	    ->Called!
//	  result = 1
//	expr = "false && sub()"
//	  result = 0
//	expr = "true || sub()"
//	  result = 1
//	expr = "false || sub()"
//	    ->Called!
//	  result = 1
//	expr = "sub() && true"
//	    ->Called!
//	  result = 1
//	expr = "sub() && false"
//	    ->Called!
//	  result = 0
//	expr = "sub() || true"
//	    ->Called!
//	  result = 1
//	expr = "sub() || false"
//	    ->Called!
//	  result = 1
//	expr = "true ? sub() : 999"
//	    ->Called!
//	  result = 1
//	expr = "false ? sub() : 999"
//	  result = 999
//	expr = "true ? 999 : sub()"
//	  result = 999
//	expr = "false ? 999 : sub()"
//	    ->Called!
//	  result = 1
//	expr = "0xffffffff & sub()"
//	    ->Called!
//	  result = 1
//	expr = "0x00000000 & sub()"
//	    ->Called!
//	  result = 0
//	expr = "0xffffffff | sub()"
//	    ->Called!
//	  result = -1
//	expr = "0x00000000 | sub()"
//	    ->Called!
//	  result = 1
//	expr = "sub() & 0xffffffff"
//	    ->Called!
//	  result = 1
//	expr = "sub() & 0x00000000"
//	    ->Called!
//	  result = 0
//	expr = "sub() | 0xffffffff"
//	    ->Called!
//	  result = -1
//	expr = "sub() | 0x00000000"
//	    ->Called!
//	  result = 1
//	expr = "1 * sub()"
//	    ->Called!
//	  result = 1
//	expr = "0 * sub()"
//	    ->Called!
//	  result = 0
//	expr = "1 / sub()"
//	    ->Called!
//	  result = 1
//	expr = "0 / sub()"
//	    ->Called!
//	  result = 0
//	expr = "sub() * 1"
//	    ->Called!
//	  result = 1
//	expr = "sub() * 0"
//	    ->Called!
//	  result = 0
//	expr = "sub() / 1"
//	    ->Called!
//	  result = 1
	
	return EXIT_SUCCESS;
}

// End of file

