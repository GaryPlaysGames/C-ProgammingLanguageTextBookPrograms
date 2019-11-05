#ifndef SQUARE_H
#define SQUARE_H

#include "stdafx.h"
#include "Shape.h"

class Square : public Shape {
public:
	Square();

	double area() const;
	double parameter() const;
};

#endif // !SQUARE_H
