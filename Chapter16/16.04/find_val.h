#ifndef FIND_VAL_H
#define FIND_VAL_H

template <typename It, typename T>
It find_val(It beg, It end, const T &val) {
	while (beg != end && *beg != val) {
		++beg;
	}
	return beg;
}

#endif
