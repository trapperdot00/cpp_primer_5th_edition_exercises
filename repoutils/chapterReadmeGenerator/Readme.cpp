#include "Readme.h"

// # Chapter01: Getting Started
// ## [Exercise 1.1](1.01.cpp)
// ...exercise text

// Checks for an existing README.md, returns the count of found exercises
std::size_t Readme::check_existing(std::ostringstream &oss) const {
	std::ostringstream filename;
	filename << "README.md";
 	std::ifstream readmeFile(filename.str());
	std::size_t exercises = 1;
	if (readmeFile.is_open()) {
		for (std::string line; std::getline(readmeFile, line); oss << line << '\n') ;
		std::string content = oss.str();
		for (std::string::const_iterator it = content.cbegin(), it2 = content.cbegin() + 9; it != content.cend() && it2 != content.cend(); ++it, ++it2) {
			if (std::string(it, it2) == "[Exercise")
				++exercises;
		}
		std::cout << exercises - 1 << " exercises found" << std::endl;
		return exercises;
	} else {
		return 1;
	}
}

// Generates a readme template while retaining previous text,
// returns a string containing the whole file
std::string Readme::generate() const {
	std::ostringstream content;
	std::size_t eCnt = check_existing(content);
	if (eCnt == 1)
		// Title of the Chapter
		content << "# Chapter" << (chapterNum < 10 ? "0" : "") << chapterNum << ": \n";
	// Exercises
	for ( ; eCnt < exerciseCount + 1; ++eCnt) {
		content << "## [Exercise " << chapterNum << "." << eCnt << "](" 
				<< chapterNum << "." << (eCnt < 10 ? "0" : "") << eCnt;
		std::ostringstream filename;
		filename << chapterNum << "." << (eCnt < 10 ? "0" : "") << eCnt;
		// insert file extension if not a directory
		std::string basefilename = filename.str();
		// Basically bruteforce through the two used extensions,
		// .cpp and .txt, and if neither is present,
		// then the exercise must be in a directory, no extension
		std::ifstream cpp_sourcefile(basefilename + ".cpp");
		std::ifstream txt_sourcefile(basefilename + ".txt");
		content << (cpp_sourcefile.is_open() ? ".cpp" : txt_sourcefile.is_open() ? ".txt" : "") << ")\n\n";
	}
	return content.str();
}
