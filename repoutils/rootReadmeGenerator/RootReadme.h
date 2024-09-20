#ifndef ROOTREADME_H
#define ROOTREADME_H

#include "../GeneratorBase.h"

#include <iostream>
#include <fstream>
#include <sstream>

// Class to use to generate readme files inside the root directory,
// containing each chapter's directory

class RootReadme : public GeneratorBase {
public:
	RootReadme(std::size_t i) : GeneratorBase(i) {}
	
	// Generates text to append to a readme file
	std::string generate() const override;
private:
	// Returns a count of existing chapters' entries
	std::size_t existing() const override;

	// Returns a filename to a chapter directory
	std::string getChapterFilename(std::size_t) const;
};

#endif
