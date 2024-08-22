#ifndef POLYGON_H
#define POLYGON_H

#include <cstddef>
#include <utility>
#include <vector>
#include <iostream>

class Polygon {
	friend std::ostream &printCenter(std::ostream &, const Polygon &);
public:
	Polygon() = default;
	Polygon(std::size_t sd, std::size_t crnr) : sideCount(sd), cornerCount(crnr) {}
	
	std::size_t sides() const { return sideCount; }
	std::size_t corners() const { return cornerCount; }

	virtual double perimeter() const = 0;
	virtual double area() const = 0;

	void center() { centerPoint = std::make_pair(0, 0); }

	virtual ~Polygon() = default;
private:
	std::size_t sideCount = 0;
	std::size_t cornerCount = 0;
protected:
	std::pair<int, int> centerPoint = std::make_pair(0, 0);
};

std::ostream &printCenter(std::ostream &os, const Polygon &p) {
	os << p.centerPoint.first << ' ' << p.centerPoint.second;
	return os;
}

#endif
