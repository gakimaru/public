//common.hは強制インクルードに設定

#include "other.h"

int main(const int argc, const char* argv[])
{
	printf("COMMON_CONST = %d\n", COMMON_CONST);
	
	other_func();
	
	return EXIT_SUCCESS;
}

// End of file
