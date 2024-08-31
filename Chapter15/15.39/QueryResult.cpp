#include "QueryResult.h"

std::ostream &print(std::ostream &os, const QueryResult &q) {
	os << q.sought << " occurs " << q.line_nums->size() << " times\n";
	for (auto it = q.line_nums->cbegin(); it != q.line_nums->cend(); ++it) {
		auto num = *it;
		StrBlobPtr iter(*(q.file));
		for (QueryResult::line_no index = 0; index != num; ++index) {
			iter.incr();
		}
		os << "\t(line " << num + 1 << ") " << iter.deref() << std::endl;
	}	
	return os;
}
