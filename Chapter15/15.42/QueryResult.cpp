#include "QueryResult.h"

// prints lines from beg_line inclusive to end_line exclusive
std::ostream &print(std::ostream &os, const QueryResult &q, std::size_t beg_line, std::size_t end_line) {
	if (beg_line >= end_line) {
		throw std::runtime_error("Invalid range");		
	}

	std::size_t occurance = 0;
	std::ostringstream stream;
	for (auto it = q.line_nums->cbegin(); it != q.line_nums->cend() && *it < end_line - 1; ++it) {
		if (*it >= beg_line - 1) {
			auto num = *it;
			StrBlobPtr iter(*(q.file));
			for (QueryResult::line_no index = 0; index != num; ++index) {
				iter.incr();
			}
			++occurance;
			stream << "\t(line " << num + 1 << ") " << iter.deref() << std::endl;
		}
	}
	os << q.sought << " occurs " << occurance << " times from line "
	   << beg_line << " inclusive to line " << end_line << " exclusive\n";
	os << stream.str();
	return os;
}
