#ifndef SQUARE_H
#define SQUARE_H

#include "Polygon.h"

class Square : public Polygon {
public:
	Square() = default;
	Square(double length) : Polygon(4, 4), sideLength(length) {}

	double length() const { return sideLength; }

	double perimeter() const override { return sideLength * sides(); }
	double area() const override { return sideLength * sideLength; }

	void moveDelta(int dx, int dy) {
		centerPoint.first += dx;
		centerPoint.second += dy;
	}

	~Square() = default;
private:
	double sideLength = 0;
};

#endif
