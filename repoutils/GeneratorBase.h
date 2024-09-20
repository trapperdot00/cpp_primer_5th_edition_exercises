#ifndef GENERATORBASE_H
#define GENERATORBASE_H

#include <cstddef>
#include <string>

// Base class for RootReadme and ChapterReadme
// Contains data members and member functions common to those classes

class GeneratorBase {
public:
	GeneratorBase(std::size_t n) : chapterNum(n) {}
	virtual ~GeneratorBase() = default;

	// Generate string to append to readme
	virtual std::string generate() const = 0;

	// Readme file's filename with extension
	static const std::string filename;
protected:
	// Returns a count of existing entries
	virtual std::size_t existing() const = 0;

	std::size_t chapterNum;
};

#endif
