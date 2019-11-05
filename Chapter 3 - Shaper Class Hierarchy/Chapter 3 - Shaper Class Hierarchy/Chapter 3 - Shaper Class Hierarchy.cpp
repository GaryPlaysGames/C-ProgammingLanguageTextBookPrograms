// Chapter 3 - Shaper Class Hierarchy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include "Triangle.h"
#include "Square.h"

template<typename C>
void get_Area(const C& container) {
	for (auto& a : container) {
		std::cout << a->area() << std::endl;
	}
}

int main()
{
	char cha;

	std::vector<std::unique_ptr<Shape>> shapes;
	std::string current_Shape;
	Square current_Square[2];

	for (int i = 0; i < 2; ++i) {
		std::cout << "Enter points in the form: [#, #, #] for triangle OR [#, #, #, #] for square" << std::endl;
		std::getline(std::cin, current_Shape);
		std::cout << current_Shape << std::endl;
		if (current_Shape.size() > 9) {
			std::cout << "Enter 4 points in the form: [#, #, #, #] for square again" << std::endl;
			std::cin >> current_Square[i];
			std::cout << current_Square[i] << std::endl;
			shapes.push_back(std::unique_ptr<Shape>(&current_Square[i]));
		}
	}

	get_Area(shapes);

	std::cin >> cha;

    return 0;
}

