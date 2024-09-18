#ifndef ROOTREADME_H
#define ROOTREADME_H

#include <cstddef>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class RootReadme {
public:
	RootReadme(std::size_t i) : chapterNum(i) {}

	std::string generate() const;
private:
	std::size_t prevChapter() const;

	std::size_t chapterNum;
};

#endif
