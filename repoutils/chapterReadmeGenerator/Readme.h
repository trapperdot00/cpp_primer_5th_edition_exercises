#ifndef README_H
#define README_H

#include <string>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>

class Readme {
public:
	Readme(std::size_t c, std::size_t e) : chapterNum(c), exerciseCount(e) {}
	std::string generate() const;
private:
	std::size_t check_existing(std::ostringstream &) const;

	std::size_t chapterNum;
	std::size_t exerciseCount;
};

#endif
