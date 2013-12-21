//非テンプレートクラス実装

#include <iostream>

#include "TemplateTest.h"

void normalFunc()
{
	std::cout << "normalFunc" << std::endl;
}

void base1::foo() const
{
	std::cout << "base1::foo()" << std::endl;
}

void base2::foo() const
{
	std::cout << "base2::foo()" << std::endl;
}

void derived1a::foo() const
{
	std::cout << "derive1a::foo()" << std::endl;
}

void derived1b::foo() const
{
	std::cout << "derive1b::foo()" << std::endl;
}

void derived2a::foo() const
{
	std::cout << "derive2a::foo()" << std::endl;
}

void derived2b::foo() const
{
	std::cout << "derive2b::foo()" << std::endl;
}

void derived3a::foo() const
{
	std::cout << "derive3a::foo()" << std::endl;
}

void derived3b::foo() const
{
	std::cout << "derive3b::foo()" << std::endl;
}

// End of file
