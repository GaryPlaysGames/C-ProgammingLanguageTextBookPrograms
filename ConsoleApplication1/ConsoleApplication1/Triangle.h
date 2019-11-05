#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "stdafx.h"
#include "Shape.h"

class Triangle : public Shape {
public:
	Triangle();

	double area() const;
	double parameter() const;
};

#endif // !TRIANGLE_H
