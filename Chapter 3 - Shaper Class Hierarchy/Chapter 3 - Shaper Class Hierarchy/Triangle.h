#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <initializer_list>
#include "Shape.h"

class Triangle : public Shape {
public:
	Triangle();
	Triangle(const double& x, const double& y, const double& z);
	Triangle(std::initializer_list<double>& il);

	Triangle(const Triangle& a);
	Triangle& operator=(const Triangle& a);
	Triangle(Triangle&& a);
	Triangle& operator=(Triangle&&a);

	Triangle operator+(const Triangle& other) const;
	Triangle operator-(const Triangle& other) const;
	Triangle operator*(const Triangle& other) const;
	Triangle operator/(const Triangle& other) const;

	friend std::ostream& operator<<(std::ostream& os, const Triangle& a);
	friend std::istream& operator>>(std::istream& is, Triangle& a);

	bool operator()(const Triangle& a);

	double area() const;
	double parameter() const;

	~Triangle();

private:
	double* points;
};

#endif