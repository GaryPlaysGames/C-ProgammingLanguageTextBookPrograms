#include "stdafx.h"
#include <iostream> 
#include <initializer_list>
#include <exception> 
#include <cmath>
#include <ios>
#include "Triangle.h"

Triangle::Triangle()
	: Shape() {
	try {
		points = new double[2];
		points[0] = 0.0f;
		points[1] = 0.0f;
		points[2] = 0.0f;
	}
	catch (std::exception& e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
}

Triangle::Triangle(const double& x, const double& y, const double& z)
	: Shape() {
	try {
		points = new double[2];
		points[0] = x;
		points[1] = y;
		points[2] = z;
	}
	catch (std::out_of_range& e) {
		std::cerr << "ERROR out of range: " << e.what() << std::endl;
		throw;
	}
	catch (...) {
		std::cerr << "ERROR unknown" << std::endl;
		throw;
	}
}


Triangle::Triangle(std::initializer_list<double>& il)
	: Shape() {
	try {
		points = new double[2];
		int counter = 0;
		for (auto k = il.begin(); k != il.end(); ++counter && ++k) {
			points[counter] = (*k);
		}
	}
	catch (std::exception& e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		delete points;
		throw;
	}
}

Triangle::Triangle(const Triangle& a)
	: Shape() {
	points = new double[3];
	for (int i = 0; i < 3; ++i) {
		points[i] = a.points[i];
	}
}

Triangle& Triangle::operator=(const Triangle& a) {
	if (&a != this) {
		for (int i = 0; i < 3; ++i) {
			points[i] = a.points[i];
		}
	}
	return *this;
}

Triangle::Triangle(Triangle&& a)
	: Shape(), points(a.points) {
	a.points = nullptr;
}

Triangle& Triangle::operator=(Triangle&&a) {
	if (&a != this) {
		points = a.points;
		a.points = nullptr;
	}
	return *this;
}

Triangle Triangle::operator+(const Triangle& other) const {
	Triangle result;
	for (int i = 0; i < 3; ++i) {
		result.points[i] = points[i] + other.points[i];
	}
	return result;
}

Triangle Triangle::operator-(const Triangle& other) const {
	Triangle result;
	for (int i = 0; i < 3; ++i) {
		result.points[i] = points[i] - other.points[i];
	}
	return result;
}

Triangle Triangle::operator*(const Triangle& other) const {
	Triangle result;
	for (int i = 0; i < 3; ++i) {
		result.points[i] = points[i] * other.points[i];
	}
	return result;
}

Triangle Triangle::operator/(const Triangle& other) const {
	Triangle result;
	for (int i = 0; i < 3; ++i) {
		result.points[i] = points[i] / other.points[i];
	}
	return result;
}

std::ostream& operator<<(std::ostream& os, const Triangle& a) {
	return os << "[ " << a.points[0] << ", " << a.points[1] << ", " << a.points[2] << " ]";
}

std::istream& operator>>(std::istream& is, Triangle& a) {
	char c;
	if (is >> c && c == '[')
		for (int i = 0; i < 2; ++i)
			is >> a.points[i] >> c;
	if (c == ',' && is >> a.points[2] >> c && c == ']')
		return is;
	is.setstate(std::ios_base::failbit);
	return is;
}

bool Triangle::operator()(const Triangle& a) {
	if (&a == this)
		return true;
	for (int i = 0; i < 3; ++i) {
		if (points[i] != a.points[i])
			return false;
		return true;
	}
}

double Triangle::area() const {
	double s = (points[0] + points[1] + points[2]) / 2;
	return std::sqrt( s * (s - points[0]) * (s - points[1]) * (s - points[2]) );
}

double Triangle::parameter() const {
	return points[0] + points[1] + points[2];
 }

Triangle::~Triangle() {
	delete[] points;
}