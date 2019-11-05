// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <memory>
#include "Square.h"
#include "Triangle.h"

template<typename C>
void get_Area(const C& container) {
	for (const auto& a : container)
		std::cout << a->area() << std::endl;
}

int main()
{
	char ab;

	std::vector<std::unique_ptr<Shape>> a;

	if (true) {
		Square my_Square;
		a.push_back(std::unique_ptr<Shape>(&my_Square));
	}

	a.push_back(std::unique_ptr<Shape>(new Triangle()));

	get_Area(a);

	std::cin >> ab;

    return 0;
}

