#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <stack>
#include <string>
#include <iostream>

template <typename T>
class MyVector
{
public:
	MyVector() {}
	MyVector(int n);

	void print(const std::string & message);
	void add_max_to_begin();
	void erase_min();
	void inc_average();

private:
	std::stack<T> vec;
};

template <typename T>
MyVector<T>::MyVector(int n)
{
	for (int i = 0; i < n; ++i) {
		T t;
		std::cin >> t;
		vec.push(t);
	}
}

template <typename T>
void MyVector<T>::print(const std::string & message)
{
	std::cout << message << "\n";

	std::stack<T> temp;
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

template <typename T>
void MyVector<T>::add_max_to_begin()
{
	T max = vec.top();
	std::stack<T> temp;
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

template <typename T>
void MyVector<T>::erase_min()
{
	T min = vec.top();

	std::stack<T> temp;
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

template <typename T>
void MyVector<T>::inc_average()
{
	T avg;
	std::stack<T> temp;
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

#endif