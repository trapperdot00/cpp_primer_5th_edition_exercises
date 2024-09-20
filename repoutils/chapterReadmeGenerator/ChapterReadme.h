#ifndef CHAPTERREADME_H
#define CHAPTERREADME_H

#include "../GeneratorBase.h"

#include <fstream>
#include <iostream>
#include <sstream>

class ChapterReadme : public GeneratorBase {
public:
	ChapterReadme(std::size_t n, std::size_t e) : GeneratorBase(n), exerciseCount(e) {}
	std::string generate() const override;
private:
	std::size_t existing() const override;

	std::string getExerciseFilename(std::size_t) const;
	std::string getFullFilename(std::size_t) const;

	std::size_t exerciseCount;
};

#endif
