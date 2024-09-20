#ifndef CHAPTERREADME_H
#define CHAPTERREADME_H

#include "../GeneratorBase.h"

#include <fstream>
#include <iostream>
#include <sstream>

// Class to use to generate readme files inside chapters' directories

class ChapterReadme : public GeneratorBase {
public:
	ChapterReadme(std::size_t n, std::size_t e) : GeneratorBase(n), exerciseCount(e) {}

	// Generates text to append to a readme file
	std::string generate() const override;
private:
	// Returns a count of existing exercises' entries
	std::size_t existing() const override;

	// Returns a filename to an exercise directory or file with no extension
	std::string getExerciseFilename(std::size_t) const;
	
	// Returns a filename to an exercise directory or file with an extension
	std::string getFullFilename(std::size_t) const;

	// Generation will cycle through exercises 1 to this number inclusive
	std::size_t exerciseCount;
};

#endif
