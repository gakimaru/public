#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
#include <algorithm>

#include "lib/TemplateTest.h"

#define countof(x) (sizeof(x) / sizeof(x[0]))

void sub1();
void sub2();

int main(const int argc, const char* argv[])
{
	std::cout << "- main():START -" << std::endl;

	sub1();
	sub2();

	//おまけ：STLのアルゴリズムをテスト
	{
		std::cout << "- Sort normal array -" << std::endl;
		int arr[] = { 1, 2, 3, 4, 5 };
		std::random_shuffle(&arr[0], &arr[countof(arr)]);		     std::cout << "init:   "; std::copy(&arr[0], &arr[countof(arr)], std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
		std::sort(&arr[0], &arr[countof(arr)]);		                 std::cout << "sorted1:"; std::copy(&arr[0], &arr[countof(arr)], std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
		std::sort(&arr[0], &arr[countof(arr)], std::greater<int>()); std::cout << "sorted2:"; std::copy(&arr[0], &arr[countof(arr)], std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
		std::sort(&arr[0], &arr[countof(arr)], std::less<int>());    std::cout << "sorted3:"; std::copy(&arr[0], &arr[countof(arr)], std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
	}
	{
		std::cout << "- Sort std::vector -" << std::endl;
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		std::random_shuffle(vec.begin(), vec.end());		    std::cout << "init:   "; std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
		std::sort(vec.begin(), vec.end());		                std::cout << "sorted1:"; std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
		std::sort(vec.begin(), vec.end(), std::greater<int>());	std::cout << "sorted2:"; std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
		std::sort(vec.begin(), vec.end(), std::less<int>());	std::cout << "sorted3:"; std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
	}
	{
		//高階関数
		struct is_even
		{
			typedef bool result_type;
			bool operator()(int x) const { return x % 2 == 0; }
		};
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(3);
		vec.push_back(5);
		vec.push_back(6);
		vec.push_back(7);
		vec.push_back(9);
		std::cout << "vec: "; std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
		std::vector<int>::iterator found = std::find_if(vec.begin(), vec.end(), is_even());
		if (found != vec.end())
		{
			std::cout << "  is_found(even)=" << *found << " [Indeex=" << std::distance(vec.begin(), found) << "]" << std::endl;
		}
		else
		{
			std::cout << "  is_found(even)=not found." << std::endl;

		}
	}

	std::cout << "- main():END -" << std::endl;
	
	return EXIT_SUCCESS;
}

// End of file
