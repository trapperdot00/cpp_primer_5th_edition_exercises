#include "RootReadme.h"

std::size_t RootReadme::prevChapter() const {
	std::string filename = "README.md";
	std::ifstream in(filename);
	std::size_t existingCh = 0;
	for (std::string line; std::getline(in, line); ) {
		if (line.find("### [Chapter") != std::string::npos) ++existingCh;
	}
	return existingCh;
}

std::string RootReadme::generate() const {
	std::string additionalLines;
	std::size_t existing = prevChapter();
	std::cout << existing << " chapters found" << std::endl;
	for (std::size_t curr = existing; curr != chapterNum; ++curr) {
			std::cout << curr + 1 << std::endl;
			std::ostringstream descPath;
			descPath << "Chapter" << (curr + 1 < 10 ? "0" : "")
					<< curr + 1 << "/description.txt";
			std::ifstream chapterDesc(descPath.str());
			if (!chapterDesc.is_open()) return "";
			std::string desc;
			std::getline(chapterDesc, desc);
			std::cout << desc << std::endl;
			std::ostringstream content;
			content << "### [Chapter" << (curr + 1 < 10 ? "0" : "") << curr + 1 << "](Chapter" << (curr + 1 < 10 ? "0" : "") << curr + 1 << "/): " << desc << '\n';
			additionalLines += content.str();
	}
	return additionalLines;
}
