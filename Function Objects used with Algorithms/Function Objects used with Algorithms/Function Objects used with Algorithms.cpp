// Function Objects used with Algorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
#include "Vec.h"

template<typename C>
void print_container(C& container) {
	std::cout << container[0] << std::endl;
}

template<typename C, typename V>
bool find_val(C& container, V value) {
	return std::find(container.begin(), container.end(), value) != container.end();
}

template<typename T>
using Iterator = typename T::iterator;

template<typename C, typename V>
std::vector<Iterator<C>> find_all(C& container, V value) {
	std::vector<Iterator<C>> res;
	for (auto p = container.begin(); p != container.end(); ++p) {
		if ((*p) == value) {
			res.push_back(p);
		}
	}
	return res;
}

int main()
{
	char c;
	Vec<int> a = { 1, 2, 3 };
	const Vec<int> b = { 1, 2, 3 };
	std::cout << a[0] << std::endl;
	std::cout << b[0] << std::endl;

	std::map<std::string, int> my_map {std::pair<std::string, int>("hi1", 1), std::pair<std::string, int>("hi2", 2)};
	std::unordered_map<std::string, int> my_hashmap {std::pair<std::string, int>("hi1", 1), std::pair<std::string, int>("hi2", 2)};
	std::list<int> my_list{ 1, 2, 3 };
	std::list<int> my_list2;
	std::vector<int> vec1 = { 1, 2, 3 };

	std::unique_copy(vec1.begin(), vec1.end(), std::back_inserter(my_list2));
	for (auto p = my_list2.begin(); p != my_list2.end(); ++p)
		std::cout << *p << std::endl;

	int count = std::count_if(my_list.begin(), my_list.end(), [&](const int& i) {return i < a[2];});
	std::cout << "count = " << count << std::endl;

	print_container(vec1);
	std:: cout << find_val(vec1, 1);

	std::vector<Iterator<std::vector<int>>> res = find_all(vec1, 1);


	std::cin >> c;
    return 0;
}

