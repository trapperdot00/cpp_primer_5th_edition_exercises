#ifndef CHAPTER06_H
#define CHAPTER06_H

#include <string>

namespace cplusplus_primer {
namespace chapter06 {
	inline bool isShorter(const std::string &s1, const std::string &s2) {
		return s1.size() < s2.size();
	}
}
}

#endif
