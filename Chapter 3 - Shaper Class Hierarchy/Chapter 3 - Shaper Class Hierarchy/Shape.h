#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
	Shape();

	virtual double area() const = 0;
	virtual double parameter() const = 0;

	Shape(const Shape&) = delete;
	Shape& operator=(const Shape&) = delete;

	Shape(Shape&&) = delete;
	Shape& operator=(Shape&&) = delete;

	virtual ~Shape();
};

#endif // !SHAPE_H
