#ifndef DEBUG_REP_H
#define DEBUG_REP_H

#include <string>
#include <sstream>
#include <iostream>

std::string debug_rep(const std::string &s) {
	return '"' + s + '"';
}

template <typename T> std::string debug_rep(const T &);
template <typename T> std::string debug_rep(T *);
template <> std::string debug_rep(char *);
template <> std::string debug_rep(const char *);

template <typename T>
std::string debug_rep(const T &t) {
	std::ostringstream ret;
	ret << t;
	return ret.str();
}

template <typename T>
std::string debug_rep(T *p) {
	std::ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p);
	else
		ret << " null pointer";
	return ret.str();
}

template <>
std::string debug_rep(char *c) {
	return debug_rep(std::string(c));
}

template <>
std::string debug_rep(const char *c) {
	return debug_rep(std::string(c));
}

#endif
