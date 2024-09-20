#ifndef GENERATORBASE_H
#define GENERATORBASE_H

#include <cstddef>
#include <string>

class GeneratorBase {
public:
	GeneratorBase(std::size_t n) : chapterNum(n) {}
	virtual ~GeneratorBase() = default;

	virtual std::string generate() const = 0;

	static const std::string filename;
protected:
	virtual std::size_t existing() const = 0;

	std::size_t chapterNum;
};

#endif
