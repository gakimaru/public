#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "lib/TemplateTest.h"

void sub1();
void sub2();

int main(const int argc, const char* argv[])
{
	std::cout << "main() : START" << std::endl;

	sub1();
	sub2();

	std::cout << "main() : END" << std::endl;
	
	return EXIT_SUCCESS;
}

// End of file
