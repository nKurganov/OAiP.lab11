#include <iostream>
#include "my_vector_11_5.h"
#include "time_class.h"

int main()
{
	std::cout << "Enter number of elements: ";
	int n;
	std::cin >> n;

	MyVector<Time> vec(n);
	vec.print("Initial vector: ");

	vec.add_max_to_begin();
	vec.print("After add max to begin: ");

	vec.erase_min();
	vec.print("After erase min: ");

	vec.inc_average();
	vec.print("After inc all element on average: ");

	std::cin.ignore();
	std::cin.get();
	return 0;
}