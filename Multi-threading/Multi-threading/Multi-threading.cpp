// Multi-threading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <thread>
#include <mutex>
#include <functional>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>

int COUNT_NUM = 5;
std::mutex shared_object;

void part1OfRandomFormula(std::vector<int>& a, int* res) {
	std::unique_lock<std::mutex> m1{shared_object};
	int count = count_if(a.begin(), a.begin() + (a.size() / 2), [](const int& a) {return a < COUNT_NUM;});
	*res = count;
}

void part2OfRandomFormula(std::vector<int>& b, int* res) {
	std::unique_lock<std::mutex> m1{shared_object};
	int count = count_if(b.begin() + (b.size() / 2), b.end(), [](const int& a) {return a < COUNT_NUM;});
	*res = count;
}

void changeVector1(std::vector<int>& a) {
	std::unique_lock<std::mutex> m1{shared_object};
	a[0] = 55;
	for(int k = 0; k < a.size(); ++k)
		for (int i = 0; i < a.size(); ++i)
			std::cout << a[i];
	std::cout << std::endl;
}

void changeVector2(std::vector<int>& a) {
	std::unique_lock<std::mutex> m1{shared_object};
	a[0] = 44;
	for (int k = 0; k < a.size(); ++k)
		for (int i = 0; i < a.size(); ++i)
			std::cout << a[i];
	std::cout << std::endl;
}

int main()
{
	char tchar;

	std::vector<int> testVect{1, 10, 6, 2, 99, 54, 9, 11, 5, 4, 7};
	int res1, res2;

	std::thread t1{part1OfRandomFormula, std::ref(testVect), &res1};
	std::thread t2{part2OfRandomFormula, std::ref(testVect), &res2};

	t1.join();
	t2.join();

	std::cout << "RES 1: " << res1 << std::endl
		<< "RES 2: " << res2 << std::endl;

	std::thread t3{changeVector1, std::ref(testVect)};
	std::thread t4{changeVector2, std::ref(testVect)};

	t3.join();
	t4.join();

	std::cout << "RESULT: " << testVect[0] << std::endl;

	std::cin >> tchar;
    return 0;
}

