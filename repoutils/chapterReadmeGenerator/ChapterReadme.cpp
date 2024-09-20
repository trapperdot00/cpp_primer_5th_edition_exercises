#include "ChapterReadme.h"

// # Chapter01: Getting Started
// ## [Exercise 1.1](1.01.cpp)
// ...exercise text

// Checks for an existing README.md, returns the count of found exercises
// that have an entry in the readme file
std::size_t ChapterReadme::existing() const {
 	std::ifstream readmeFile(filename);
	std::size_t exercises = 0;
	if (readmeFile.is_open()) {
		for (std::string line; std::getline(readmeFile, line); ) {
			if (line.find("## [Exercise ") != std::string::npos)
				++exercises;
		}
		std::cout << exercises << " exercises found" << std::endl;
	}
	return exercises;
}

std::string ChapterReadme::getExerciseFilename(std::size_t excNum) const {
	std::ostringstream builder;
	builder << chapterNum << '.' << (excNum < 10 ? "0" : "") << excNum;
	return builder.str();
}

std::string ChapterReadme::getFullFilename(std::size_t excNum) const {
	std::string fname = getExerciseFilename(excNum);
	return fname + (std::ifstream(fname + ".cpp").is_open() ? ".cpp" :
			std::ifstream(fname + ".txt").is_open() ? ".txt" : "");
}

std::string ChapterReadme::generate() const {
	std::ostringstream content;
	for (std::size_t eCnt = existing() + 1; eCnt <= exerciseCount; ++eCnt) {
		std::string fullFilename = getFullFilename(eCnt);
		content << "## [Exercise " << chapterNum << '.' << eCnt << "]("
				<< fullFilename << ")\n\n";
	}
	return content.str();
}
