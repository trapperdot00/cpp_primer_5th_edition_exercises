#include "RootReadme.h"

// Returns the last chapter's number in the readme file
std::size_t RootReadme::prevChapter() const {
	std::string filename = "README.md";
	std::ifstream in(filename);
	std::size_t existingCh = 0;
	for (std::string line; std::getline(in, line); ) {
		if (line.find("### [Chapter") != std::string::npos) ++existingCh;
	}
	return existingCh;
}

// Generates a string to append at the end of the readme file
// Fetches descriptions from each chapter's root directory
std::string RootReadme::generate() const {
	std::string additionalLines;
	std::size_t existing = prevChapter();
	std::cout << existing << " chapters found" << std::endl;
	for (std::size_t curr = existing; curr != chapterNum; ++curr) {
			std::ostringstream descPath;
			descPath << "Chapter" << (curr + 1 < 10 ? "0" : "")
					 << curr + 1 << "/description.txt";
			std::ifstream chapterDesc(descPath.str());
			if (!chapterDesc.is_open()) return "";
			std::string desc;
			std::getline(chapterDesc, desc);
			std::ostringstream content;
			content << "### [Chapter" << (curr + 1 < 10 ? "0" : "")
					<< curr + 1 << "](Chapter" << (curr + 1 < 10 ? "0" : "")
					<< curr + 1 << "/): " << desc << '\n';
			additionalLines += content.str();
	}
	return additionalLines;
}
