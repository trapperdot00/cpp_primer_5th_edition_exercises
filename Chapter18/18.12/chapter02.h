#ifndef CHAPTER02_H
#define CHAPTER02_H

#include <string>

namespace cplusplus_primer {
namespace chapter02 {
	struct Sales_data {
		std::string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;
	};
}
}

#endif
