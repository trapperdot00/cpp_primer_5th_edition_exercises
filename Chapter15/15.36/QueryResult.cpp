#include "QueryResult.h"

std::ostream &print(std::ostream &os, const QueryResult &q) {
	os << q.sought << " occurs " << q.line_nums->size() << " times\n";
	for (QueryResult::line_no num : *q.line_nums) {
		os << "\t(line " << num + 1 << ") " << *(q.file->begin() + num) << std::endl;
	}
	return os;
}
