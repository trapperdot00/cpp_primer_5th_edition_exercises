#ifndef CHAPTER03_H
#define CHAPTER03_H

#include <string>

namespace cplusplus_primer {
namespace chapter03 {
	struct Sales_data {
		std::string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;
	};
}
}

#endif
