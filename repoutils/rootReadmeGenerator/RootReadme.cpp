#include "RootReadme.h"

std::size_t RootReadme::existing() const {
	std::ifstream readmeFile(filename);
	std::size_t chapters = 0;
	if (readmeFile.is_open()) {
		for (std::string line; std::getline(readmeFile, line); ) {
			if (line.find("### [Chapter") != std::string::npos)
				++chapters;
		}
		std::cout << chapters << " chapters found" << std::endl;
	}
	return chapters;
}

std::string RootReadme::getChapterFilename(std::size_t chaNum) const {
	std::ostringstream builder;
	// Formatting: leading zero for chapters under 10
	builder << "Chapter" << (chaNum < 10 ? "0" : "") << chaNum;
	return builder.str();
}

std::string RootReadme::generate() const {
	std::string additionalLines;
	for (std::size_t curr = existing() + 1; curr <= chapterNum; ++curr) {
			// ifstream initialized by the current chapter's description's path
			std::ifstream chapterDesc(getChapterFilename(curr) + "/description.txt");
			if (!chapterDesc.is_open()) return "";
			// Extract text from description
			std::string desc;
			std::getline(chapterDesc, desc);
			std::ostringstream content;
			// Construct the line for the current chapter entry
			content << "### [" << getChapterFilename(curr) << "]("
					<< getChapterFilename(curr) << "/): " << desc << '\n';
			additionalLines += content.str();
	}
	return additionalLines;
}
