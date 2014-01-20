#include <iostream>

#include "lib/TemplateTest.h"

void sub1()
{
	std::cout << std::endl << "- sub1() -" << std::endl << std::endl;

	normalFunc();

	int a = min(1, 2);
	int b = max(1, 2);

	template_class<int> o_a(123);
	template_class<double> o_b(456);
	o_a.test();
	o_b.test();

	int (template_class<int>::*pFunc)(const int) const = nullptr;
	pFunc = &template_class<int>::test1;
	(o_a.*pFunc)(11);
//	(o_b.*pFunc)(12);
	pFunc = &template_class<int>::test2;
	(o_a.*pFunc)(21);
//	(o_b.*pFunc)(22);

	base1* o1a = new derived1a;
	base1* o1b = new derived1b;
	base2* o2a = new derived2a;
	base2* o2b = new derived2b;
	derived3a* o3a = new derived3a;
	derived3b* o3b = new derived3b;

	o1a->foo();
	o1b->foo();
	o2a->foo();
	o2b->foo();
	o3a->base_foo();
	o3b->base_foo();
}

// End of file
