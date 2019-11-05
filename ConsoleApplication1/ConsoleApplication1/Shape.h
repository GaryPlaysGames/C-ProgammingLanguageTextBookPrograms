#ifndef SHAPE_H
#define SHAPE_H

#include "stdafx.h"

class Shape {
public:
	Shape();

	virtual double area() const = 0;
	virtual double parameter() const = 0;
};

#endif // !SHAPE_H
