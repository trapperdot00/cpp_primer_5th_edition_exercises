#ifndef ROOTREADME_H
#define ROOTREADME_H

#include "../GeneratorBase.h"

#include <iostream>
#include <fstream>
#include <sstream>

class RootReadme : public GeneratorBase {
public:
	RootReadme(std::size_t i) : GeneratorBase(i) {}
	
	std::string generate() const override;
private:
	std::size_t existing() const override;
};

#endif
