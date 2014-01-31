#include <stdio.h>

int global_without_value;
int global_with_value = 1;
const int global_const_value = 2;

void func2()
{
	printf("func2()\n");
	int local_var2 = 0;
	printf("&local_var2 =%p\n", &local_var2);
}

void func1()
{
	printf("func1()\n");
//int local_var[16 * 1024 * 1024] = {};
	int local_var1a = 0;
	int local_var1b = 0;
	int local_var1c = 0;
	printf("&local_var1a=%p\n", &local_var1a);
	printf("&local_var1b=%p\n", &local_var1b);
	printf("&local_var1c=%p\n", &local_var1c);
	func2();
}

int main(const int argc, const char* argv[])
{
	int local_var0 = 0;
	printf("&local_var0 =%p\n", &local_var0);
	func1();
	func2();

	printf("main():begin\n");
	static int static_without_value;
	static int static_with_value = 3;
	static const int static_const_value = 4;
	int auto_without_value;
	int auto_with_value = 5;
	const int auto_const_value = 6;
	const char* auto_str = "STRING";
	
	global_without_value = 101;
	global_with_value = 102;
	static_without_value = 103;
	static_with_value = 104;
	auto_without_value = 105;
	auto_with_value = 106;
	printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,\"%s\"\n",
		global_without_value,
		global_with_value,
		global_const_value,
		static_without_value,
		static_with_value,
		static_const_value,
		auto_without_value,
		auto_with_value,
		auto_const_value,
		auto_str
	);
	printf("main():end\n");
	
	return 0;
}

class auto_run_test_class
{
public:
	auto_run_test_class()
	{
		printf("auto_run_test_class::constructor()\n");
	}
	~auto_run_test_class()
	{
		printf("auto_run_test_class::destructor()\n");
	}

};
auto_run_test_class auto_run_test_obj;

__attribute__((constructor))
void auto_run_test_func_constructor_1()
{
	printf("auto_run_test_fun_constructor_1()\n");
}

__attribute__((constructor))
void auto_run_test_func_constructor_2()
{
	printf("auto_run_test_fun_constructor_2()\n");
}

__attribute__((destructor))
void auto_run_test_func_destructor_1()
{
	printf("auto_run_test_fun_destructor_1()\n");
}

__attribute__((destructor))
void auto_run_test_func_destructor_2()
{
	printf("auto_run_test_fun_destructor_2()\n");
}

