#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <initializer_list>
#include "Shape.h"

class Square : public Shape {
public:
	Square();
	Square(double a, double b, double c, double d);
	Square(std::initializer_list<double>& il);

	Square(const Square& a);
	Square& operator=(const Square& a);
	Square(Square&& a);
	Square& operator=(Square&& a);

	bool operator==(const Square& a) const;
	bool operator!=(const Square& a) const;
	Square& operator*();

	friend std::ostream& operator<<(std::ostream& os, const Square& a);
	friend std::istream& operator>>(std::istream& is, const Square& a);

	bool operator()(const Square& a) const;

	double* begin() const;
	double* end() const;

	double area() const override;
	double parameter() const override;

	~Square();

private:
	double* points;
};

#endif