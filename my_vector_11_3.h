#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>

template <typename T>
class MyVector
{
public:
	MyVector() {}
	MyVector(int n);

	void print(const std::string & message) const;
	void add_max_to_begin();
	void erase_min();
	void inc_average();

private:
	std::vector<T> vec;
};

template <typename T>
MyVector<T>::MyVector(int n)
{
	for (int i = 0; i < n; ++i) {
		std::cout << "Element #" << i + 1 << ":\n";
		T el;
		std::cin >> el;
		vec.push_back(el);
	}
}

template <typename T>
void MyVector<T>::print(const std::string & message) const
{
	std::cout << message << "\n";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << "\n\n";
}

template <typename T>
void MyVector<T>::add_max_to_begin()
{
	T max = *std::max_element(vec.begin(), vec.end());
	std::cout << "Max: " << max << "\n";
	vec.insert(vec.begin(), max);
}

template <typename T>
void MyVector<T>::erase_min()
{
	std::vector<T>::const_iterator min = std::min_element(vec.begin(), vec.end());
	std::cout << "Min: " << *min << "\n";
	vec.erase(min);
}

template <typename T>
void MyVector<T>::inc_average()
{
	T avg = T();
	for (size_t i = 0; i < vec.size(); ++i)
		avg += vec[i];
	avg = avg / vec.size();

	std::cout << "Average: " << avg << "\n";
	for (size_t i = 0; i < vec.size(); ++i)
		vec[i] += avg;
}

#endif