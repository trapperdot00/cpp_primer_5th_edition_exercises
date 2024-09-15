#ifndef DEBUG_REP_H
#define DEBUG_REP_H

#include <string>
#include <sstream>
#include <iostream>

template <typename T> std::string debug_rep(const T &);
template <typename T> std::string debug_rep(T *);
std::string debug_rep(const std::string &);
std::string debug_rep(char *);
std::string debug_rep(const char *);

template <typename T>
std::string debug_rep(const T &t) {
	std::cout << "debug_rep<T>(const T &)" << std::endl;

	std::ostringstream ret;
	ret << t;
	return ret.str();
}

template <typename T>
std::string debug_rep(T *p) {
	std::cout << "debug_rep<T>(T *)" << std::endl;

	std::ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p);
	else
		ret << " null pointer";
	return ret.str();
}

std::string debug_rep(const std::string &s) {
	std::cout << "debug_rep(const std::string &)" << std::endl;

	return '"' + s + '"';
}

std::string debug_rep(char *c) {
	std::cout << "debug_rep(char *)" << std::endl;

	return debug_rep(std::string(c));
}

std::string debug_rep(const char *c) {
	std::cout << "debug_rep(const char *)" << std::endl;

	return debug_rep(std::string(c));
}

#endif