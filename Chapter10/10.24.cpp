#include <functional>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

std::ostream &print(std::ostream &os, int val, char sep) {
	os << val << sep;
	return os;
}

bool check_size(const std::string &s, std::string::size_type sz) {
	return s.size() < sz;
}

int main() {
	std::vector<int> ivec;
	for (int temp; std::cin >> temp; ivec.push_back(temp)) ;
	std::cout << '\n';
	std::for_each(ivec.cbegin(), ivec.cend(), std::bind(print, std::ref(std::cout), std::placeholders::_1, ' '));
	std::string s{"1234567890"};
	std::vector<int>::const_iterator iter = std::find_if(ivec.cbegin(), ivec.cend(), std::bind(check_size, s, std::placeholders::_1));
	if (iter != ivec.end())
		std::cout << "\nFirst element that has a value bigger than " << s << "'s size: " << *iter << std::endl;
	else
		std::cout << "\nThere are no elements in the vector that has a larger value than " << s << "'s size." << std::endl;
	return 0;
}

