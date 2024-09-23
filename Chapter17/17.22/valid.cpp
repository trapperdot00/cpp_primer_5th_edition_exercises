#include "valid.h"

bool valid(const std::smatch &m) {
	// If there is a starting parenthesis in the phone number
	if (m[1].matched) {
		// There must be a closing parenthesis after the area code
		// and there must only be a space delimiter, or none
		return m[3].matched && (m[4].matched == false || m[4].str() == " ");
	} else {
		// If there is no parenthesis before the area code,
		// the delimiters must match
		return !m[3].matched && (m[4].str() == m[6].str());
	}
}
