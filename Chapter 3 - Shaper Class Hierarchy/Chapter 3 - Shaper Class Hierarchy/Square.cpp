#include "stdafx.h"
#include <iostream>
#include <initializer_list>
#include <ios>
#include <cmath>
#include "Shape.h"
#include "Square.h"

Square::Square() 
: Shape() {
	try {
		points = new double[4];
		points[0] = 0.0;
		points[1] = 0.0;
		points[2] = 0.0;
		points[3] = 0.0;
	}
	catch (std::exception& e) {
		std::cout << "ERROR: " << e.what() << std::endl;
		delete points;
		throw;
	}
	catch (...) {
		std::cout << "UNKNOWN ERROR" << std::endl;
		delete points;
		throw;
	}
}

Square::Square(double a, double b, double c, double d) 
: Shape() {
	try {
		points = new double[4];
		points[0] = a;
		points[0] = b;
		points[0] = c;
		points[0] = d;
	}
	catch (std::exception& e) {
		std::cout << "ERROR: " << e.what() << std::endl;
		delete points;
		throw;
	}
	catch (...) {
		std::cout << "UNKNOWN ERROR" << std::endl;
		delete points;
		throw;
	}
}

Square::Square(std::initializer_list<double>& il) 
: Shape() {
	try {
		points = new double[4];
		int counter = 0;
		for (auto p = il.begin(); p != il.end(); ++p)
			points[counter++] = *p;
	}
	catch (std::exception& e) {
		std::cout << "ERROR: " << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "UNKNOWN ERROR" << std::endl;
	}
}

Square::Square(const Square& a) 
: Shape() {
	for (int i = 0; i < 4; ++i)
		points[i] = a.points[i];
	std::cout << "POINT: " << a.points[0] << std::endl;
}

Square& Square::operator=(const Square& a) {
	if (&a != this) {
		for (int i = 0; i < 4; ++i)
			points[i] = a.points[i];
		std::cout << "POINT: " << a.points[0] << std::endl;
	}
	return *this;
}

Square::Square(Square&& a) 
	: Shape(), points{a.points} {
	a.points = nullptr;
}

Square& Square::operator=(Square&& a) {
	if (&a != this) {
		points = a.points;
		a.points = nullptr;
	}
	return *this;
}

bool Square::operator==(const Square& a) const {
	if (&a != this) {
		for (int i = 0; i < 4; ++i)
			if (points[i] != a.points[i])
				return false;
		return true;
	}
	return true;
}

bool Square::operator!=(const Square& a) const {
	return !(a == *this);
}

Square& Square::operator*() {
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Square& a) {
	return os << "[" << a.points[0] << ", " << a.points[1] << ", " << a.points[2] << ", " << a.points[3] << "]";
}

std::istream& operator>>(std::istream& is, const Square& a) {
	char c;
	if (is >> c && c == '[')
		for (int i = 0; i < 3; ++i) {
			is >> a.points[i];
			if (is >> c && c != ',')
				throw;
		}
	if(is >> a.points[3] && is >> c && c == ']') {
		return is;
	}
	is.setstate(std::ios_base::failbit);
	return is;
}

bool Square::operator()(const Square& a) const {
	return *this == a;
}

double* Square::begin() const {
	return &points[0];
}

double* Square::end() const {
	return &points[4];
}

double Square::area() const {
	return 2 * (std::abs(points[0] + points[1]));
}

double Square::parameter() const {
	return points[0] + points[1] + points[2] + points[3];
}

Square::~Square() {
	delete[] points;
}