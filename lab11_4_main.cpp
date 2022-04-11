#include <iostream>
#include <stack>
#include <algorithm>
#include <iterator>
#include <string>

#include "time_class.h"

typedef std::stack<Time> MyStack;

void print_stack(MyStack & vec, const std::string & message);
void fill_stack(MyStack & vec);
void add_max_to_begin(MyStack & vec);
void erase_min(MyStack & vec);
void inc_average(MyStack & vec);

int main()
{
	MyStack vec;

	fill_stack(vec);
	print_stack(vec, "Initial vector: ");

	add_max_to_begin(vec);
	print_stack(vec, "After add max to begin: ");

	erase_min(vec);
	print_stack(vec, "After erase min: ");

	inc_average(vec);
	print_stack(vec, "After inc all element on average: ");

	std::cin.ignore();
	std::cin.get();
	return 0;
}

void print_stack(MyStack & vec, const std::string & message)
{
	std::cout << message << "\n";
	
	MyStack temp;
	while (!vec.empty()) {
		temp.push(vec.top());
		vec.pop();
	}

	while (!temp.empty()) {
		std::cout << temp.top() << " ";
		vec.push(temp.top());
		temp.pop();
	}
	std::cout << "\n\n";
}

void fill_stack(MyStack & vec)
{
	std::cout << "Enter count elements: ";
	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		Time t;
		std::cin >> t;
		vec.push(t);
	}
}

void add_max_to_begin(MyStack & vec)
{
	Time max = vec.top();
	MyStack temp;
	while (!vec.empty()) {
		if (vec.top() > max)
			max = vec.top();
		temp.push(vec.top());
		vec.pop();
	}

	std::cout << "Max: " << max << "\n";

	vec.push(max);
	while (!temp.empty()) {
		vec.push(temp.top());
		temp.pop();
	}
}

void erase_min(MyStack & vec)
{
	Time min = vec.top();

	MyStack temp;
	while (!vec.empty()) {
		if (vec.top() < min)
			min = vec.top();
		temp.push(vec.top());
		vec.pop();
	}

	std::cout << "Min: " << min << "\n";

	while (!temp.empty()) {
		if (temp.top() != min)
			vec.push(temp.top());
		temp.pop();
	}
}

void inc_average(MyStack & vec)
{
	Time avg;
	MyStack temp;
	while (!vec.empty()) {
		avg = avg + vec.top();
		temp.push(vec.top());
		vec.pop();
	}

	avg = avg / temp.size();
	std::cout << "Average: " << avg << "\n";

	while (!temp.empty()) {
		vec.push(temp.top() + avg);
		temp.pop();
	}
}
