#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <iostream>

using count_type = std::vector<std::string>::size_type;

count_type with_function(const std::vector<std::string> &vec) {
	std::function<bool (const std::string &)> fcn = &std::string::empty;
	count_type ret = std::count_if(vec.cbegin(), vec.cend(), fcn);
	return ret;
}
count_type with_mem_fn(const std::vector<std::string> &vec) {
	auto fcn = std::mem_fn(&std::string::empty);
	count_type ret = std::count_if(vec.cbegin(), vec.cend(), fcn);
	return ret;
}
count_type with_bind(const std::vector<std::string> &vec) {
	auto fcn = std::bind(&std::string::empty, std::placeholders::_1);
	count_type ret = std::count_if(vec.cbegin(), vec.cend(), fcn);
	return ret;
}

int main() {
	std::vector<std::string> svec;

	std::istream &in = std::cin;
	for (std::string line; std::getline(in, line); svec.push_back(line)) ;
	
	std::cout << with_function(svec) << '\n' <<
				 with_mem_fn(svec) << '\n' << 
				 with_bind(svec) << std::endl;
	return 0;
}
