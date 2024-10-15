#include "chapter14.h"

namespace cplusplus_primer {
	namespace chapter14 {
	namespace _02 {
		Sales_data &Sales_data::combine(const Sales_data &rhs) {
			units_sold += rhs.units_sold;
			revenue += rhs.revenue;
			return *this;
		}

		// NONMEMBER FUNCTIONS

		Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data sum = lhs;
			sum.combine(rhs);
			return sum;
		}

		std::istream &read(std::istream &is, Sales_data &item) {
			double price = 0.0;
			is >> item.bookNo >> item.units_sold >> price;
			item.revenue = item.units_sold * price;
			return is;
		}

		std::ostream &print(std::ostream &os, const Sales_data &item) {
			os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
			return os;
		}
	}
	namespace _06 {
		Sales_data &Sales_data::combine(const Sales_data &rhs) {
			units_sold += rhs.units_sold;
			revenue += rhs.revenue;
			return *this;
		}

		// NONMEMBER FUNCTIONS

		Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data sum = lhs;
			sum.combine(rhs);
			return sum;
		}

		std::istream &read(std::istream &is, Sales_data &item) {
			double price = 0.0;
			is >> item.bookNo >> item.units_sold >> price;
			item.revenue = item.units_sold * price;
			return is;
		}

		std::ostream &print(std::ostream &os, const Sales_data &item) {
			os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
			return os;
		}

		std::ostream &operator<<(std::ostream &os, const Sales_data &item) {
			os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
			return os;
		}
	}
	namespace _07 {
		std::allocator<char> String::alloc;

		std::pair<char *, char *> String::exact_alloc_copy(const char *b, const char *e) const {
			char *data = alloc.allocate(e - b);
			return std::make_pair(data, std::uninitialized_copy(b, e, data));
		}

		void String::free() const {
			for (const char *p = first_free; p != elements; )
				alloc.destroy(--p);
			alloc.deallocate(elements, cap - elements);
		}

		void String::reallocate() {
			std::size_t newcapacity = size() ? 2 * size() : 1;
			char *newdata = alloc.allocate(newcapacity);
			char *dest = std::uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), newdata);
			free();
			elements = newdata;
			first_free = dest;
			cap = elements + newcapacity;
		}

		String::String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
		String::String(const char *cp) {
			std::size_t strsize = std::strlen(cp);
			std::pair<char *, char *> data = exact_alloc_copy(cp, cp + strsize);
			elements = data.first;
			first_free = cap = data.second;
		}
		String::String(const String &s) {
			std::cout << "copy constructor" << std::endl;
			std::pair<char *, char *> data = exact_alloc_copy(s.cbegin(), s.cend());
			elements = data.first;
			first_free = cap = data.second;
		}
		String::String(String &&s) noexcept
			: elements(s.elements), first_free(s.first_free), cap(s.cap)
		{
			std::cout << "move constructor" << std::endl;
			s.elements = s.first_free = s.cap = nullptr;
		}
		String &String::operator=(const String &rhs) {
			std::cout << "copy-assignment operator" << std::endl;
			std::pair<char *, char *> newdata = exact_alloc_copy(rhs.cbegin(), rhs.cend());
			free();
			elements = newdata.first;
			first_free = cap = newdata.second;
			return *this;
		}
		String &String::operator=(String &&rhs) noexcept
		{
			std::cout << "move-assignment operator" << std::endl;
			if (this != &rhs) {
				free();
				elements = rhs.elements;
				first_free = rhs.first_free;
				cap = rhs.cap;
				rhs.elements = rhs.first_free = rhs.cap = nullptr;
			}
			return *this;
		}

		String::~String() { free(); }

		void String::push_back(char c) {
			check_full_realloc();
			alloc.construct(first_free++, c);
		}

		std::ostream &print(std::ostream &os, const String &s) {
			for (const char *cp = s.cbegin(); cp != s.cend(); ++cp)
				os << *cp;
			return os;
		}

		std::ostream &operator<<(std::ostream &os, const String &s) {
			for (const char *cp = s.cbegin(); cp != s.cend(); ++cp)
				os << *cp;
			return os;
		}
	}
	namespace _08 {
		std::ostream &operator<<(std::ostream &os, const Employee &e) {
			os << e.name << " " << e.age << " " << e.rank;
			return os;
		}
	}
	namespace _09 {
		Sales_data &Sales_data::combine(const Sales_data &rhs) {
			units_sold += rhs.units_sold;
			revenue += rhs.revenue;
			return *this;
		}

		// NONMEMBER FUNCTIONS

		Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data sum = lhs;
			sum.combine(rhs);
			return sum;
		}

		std::istream &read(std::istream &is, Sales_data &item) {
			double price = 0.0;
			is >> item.bookNo >> item.units_sold >> price;
			item.revenue = item.units_sold * price;
			return is;
		}

		std::ostream &print(std::ostream &os, const Sales_data &item) {
			os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
			return os;
		}

		std::ostream &operator<<(std::ostream &os, const Sales_data &item) {
			os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
			return os;
		}

		std::istream &operator>>(std::istream &is, Sales_data &item) {
			double price;
			is >> item.bookNo >> item.units_sold >> price;
			if (is)
				item.revenue = item.units_sold * price;
			else
				item = Sales_data();
			return is;
		}
	}
	namespace _12 {
		std::ostream &operator<<(std::ostream &os, const Employee &e) {
			os << e.name << " " << e.age << " " << e.rank;
			return os;
		}

		std::istream &operator>>(std::istream &is, Employee &e) {
			is >> e.name >> e.age >> e.rank;
			if (!is)
				e = Employee();
			return is;
		}
	}
	namespace _13 {
		Sales_data &Sales_data::combine(const Sales_data &rhs) {
			units_sold += rhs.units_sold;
			revenue += rhs.revenue;
			return *this;
		}

		// NONMEMBER FUNCTIONS

		Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data sum = lhs;
			sum.combine(rhs);
			return sum;
		}

		std::istream &read(std::istream &is, Sales_data &item) {
			double price = 0.0;
			is >> item.bookNo >> item.units_sold >> price;
			item.revenue = item.units_sold * price;
			return is;
		}

		std::ostream &print(std::ostream &os, const Sales_data &item) {
			os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
			return os;
		}

		std::ostream &operator<<(std::ostream &os, const Sales_data &item) {
			os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
			return os;
		}

		std::istream &operator>>(std::istream &is, Sales_data &item) {
			double price;
			is >> item.bookNo >> item.units_sold >> price;
			if (is)
				item.revenue = item.units_sold * price;
			else
				item = Sales_data();
			return is;
		}

		Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold += rhs.units_sold;
			ret.revenue += rhs.revenue;
			return ret;
		}
		Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold -= rhs.units_sold;
			ret.revenue -= rhs.revenue;
			return ret;
		}
		Sales_data operator*(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold *= rhs.units_sold;
			ret.revenue *= rhs.revenue;
			return ret;
		}
		Sales_data operator/(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold /= rhs.units_sold;
			ret.revenue /= rhs.revenue;
			return ret;
		}
	}
	namespace _15 {
		std::ostream &operator<<(std::ostream &os, const Employee &e) {
			os << e.name << " " << e.age << " " << e.rank;
			return os;
		}

		std::istream &operator>>(std::istream &is, Employee &e) {
			is >> e.name >> e.age >> e.rank;
			if (!is)
				e = Employee();
			return is;
		}

		Employee operator+(const Employee &lhs, unsigned rhs) {
			Employee ret = lhs;
			ret.age += rhs;
			return ret;
		}

		Employee operator+(const Employee &lhs, const Employee &rhs) {
			Employee ret = lhs;
			ret.age += rhs.age;
			return ret;
		}

		Employee operator-(const Employee &lhs, unsigned rhs) {
			Employee ret = lhs;
			ret.age -= rhs;
			return ret;
		}

		Employee operator-(const Employee &lhs, const Employee &rhs) {
			Employee ret = lhs;
			ret.age -= rhs.age;
			return ret;
		}
	}
	namespace _16 {
		std::allocator<char> String::alloc;

		std::pair<char *, char *> String::exact_alloc_copy(const char *b, const char *e) const {
			char *data = alloc.allocate(e - b);
			return std::make_pair(data, std::uninitialized_copy(b, e, data));
		}

		void String::free() const {
			for (const char *p = first_free; p != elements; )
				alloc.destroy(--p);
			alloc.deallocate(elements, cap - elements);
		}

		void String::reallocate() {
			std::size_t newcapacity = size() ? 2 * size() : 1;
			char *newdata = alloc.allocate(newcapacity);
			char *dest = std::uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), newdata);
			free();
			elements = newdata;
			first_free = dest;
			cap = elements + newcapacity;
		}

		String::String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
		String::String(const char *cp) {
			std::size_t strsize = std::strlen(cp);
			std::pair<char *, char *> data = exact_alloc_copy(cp, cp + strsize);
			elements = data.first;
			first_free = cap = data.second;
		}
		String::String(const String &s) {
			std::cout << "copy constructor" << std::endl;
			std::pair<char *, char *> data = exact_alloc_copy(s.cbegin(), s.cend());
			elements = data.first;
			first_free = cap = data.second;
		}
		String::String(String &&s) noexcept
			: elements(s.elements), first_free(s.first_free), cap(s.cap)
		{
			std::cout << "move constructor" << std::endl;
			s.elements = s.first_free = s.cap = nullptr;
		}
		String &String::operator=(const String &rhs) {
			std::cout << "copy-assignment operator" << std::endl;
			std::pair<char *, char *> newdata = exact_alloc_copy(rhs.cbegin(), rhs.cend());
			free();
			elements = newdata.first;
			first_free = cap = newdata.second;
			return *this;
		}
		String &String::operator=(String &&rhs) noexcept
		{
			std::cout << "move-assignment operator" << std::endl;
			if (this != &rhs) {
				free();
				elements = rhs.elements;
				first_free = rhs.first_free;
				cap = rhs.cap;
				rhs.elements = rhs.first_free = rhs.cap = nullptr;
			}
			return *this;
		}

		String::~String() { free(); }

		void String::push_back(char c) {
			check_full_realloc();
			alloc.construct(first_free++, c);
		}

		std::ostream &print(std::ostream &os, const String &s) {
			for (const char *cp = s.cbegin(); cp != s.cend(); ++cp)
				os << *cp;
			return os;
		}

		std::ostream &operator<<(std::ostream &os, const String &s) {
			for (const char *cp = s.cbegin(); cp != s.cend(); ++cp)
				os << *cp;
			return os;
		}

		bool operator==(const String &lhs, const String &rhs) {
			return lhs.elements == rhs.elements &&
					lhs.first_free == rhs.first_free &&
					lhs.cap == rhs.cap;
		}

		bool operator!=(const String &lhs, const String &rhs) {
			return !(lhs == rhs);
		}

		void StrVec::push_back(const std::string &s) {
			chk_n_alloc();	// ensure that there is room for another element
			// construct a copy of s in the element to which first_free points
			alloc.construct(first_free++, s);
		}

		std::pair<std::string *, std::string *>
		StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
			// allocate space to hold as many elements as in the range
			// data denotes the first allocated from the range
			// allocate function takes a size
			std::string *data = alloc.allocate(e - b);
			// initialize and return a pair constructed from data and
			// the value returned by uninitialized_copy
			return {data, std::uninitialized_copy(b, e, data)};
		}

		void StrVec::free() {
				// may not pass deallocate a 0 pointer; if elements is 0, there's no work to do
			if (elements) {
				// destroy the old elements in reverse order
				for (std::string *p = first_free; p != elements; /*empty*/ )
					alloc.destroy(--p);
				std::for_each(elements, first_free, [this](std::string &s){ alloc.destroy(&s);});

				alloc.deallocate(elements, cap - elements);
			}
		}

		StrVec::StrVec(const std::initializer_list<std::string> &il) {
			std::pair<std::string *, std::string *> data = alloc_n_copy(il.begin(), il.end());
			elements = data.first;
			first_free = cap = data.second;
		}

		StrVec::StrVec(const StrVec &s) {
			// call alloc_n_copy to allocate exactly as many elements as in s
			std::pair<std::string *, std::string *> newdata = alloc_n_copy(s.begin(), s.end());
			elements = newdata.first;
			first_free = cap = newdata.second;
		}

		// MOVE CONSTRUCTOR
		StrVec::StrVec(StrVec &&s) noexcept
			: elements(s.elements), first_free(s.first_free), cap(s.cap) 
		{
			s.elements = s.first_free = s.cap = nullptr;
		}
		// MOVE-ASSIGNMENT OPERATOR
		StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
			if (this != &rhs) {
				free();
				elements = rhs.elements;
				first_free = rhs.first_free;
				cap = rhs.cap;
				rhs.elements = rhs.first_free = rhs.cap = nullptr;
			}
			return *this;
		}

		StrVec::~StrVec() { free(); }

		StrVec &StrVec::operator=(const StrVec &rhs) {
			// calls alloc_n_copy to allocate exactly as many elements as in rhs
			std::pair<std::string *, std::string *> newdata = alloc_n_copy(rhs.begin(), rhs.end());
			free();
			elements = newdata.first;
			first_free = cap = newdata.second;
			return *this;
		}

		void StrVec::reallocate() {
			// we'll allocate space for twice as many elements as the current size
			std::size_t newcapacity = size() ? 2 * size() : 1;
			// allocate new memory
			std::string *newdata = alloc.allocate(newcapacity);
			// move the data from the old memory to the new
			std::string *dest = newdata;	// points to the next free position in the new array
			std::string *elem = elements;	// points to the next element in the old array
			for (std::size_t i = 0; i != size(); ++i)
				alloc.construct(dest++, std::move(*elem++));
			free();	// free the old space once we've moved the elements
			// update our data structure to point to the new elements
			elements = newdata;
			first_free = dest;
			cap = elements + newcapacity;
		}

		void StrVec::reserve(std::size_t n) {
			if (n > capacity()) {
				std::size_t oldsize = size();
				std::string *newdata = alloc.allocate(n);
				std::uninitialized_copy(elements, first_free, newdata);
				free();
				elements = newdata;
				first_free = elements + oldsize;
				cap = elements + n;
			}
		}

		void StrVec::resize(std::size_t n) { resize(n, ""); }

		void StrVec::resize(std::size_t n, const std::string &s) {
			if (n < size()) {
				while (first_free != elements + n)
					alloc.destroy(--first_free);
			} else if (n > size()) {
				reserve(n);
				while (first_free != elements + n)
					alloc.construct(first_free++, s);
			}
		}

		bool operator==(const StrVec &lhs, const StrVec &rhs) {
			return lhs.elements == rhs.elements &&
					lhs.first_free == rhs.first_free &&
					lhs.cap == rhs.cap;
		}

		bool operator!=(const StrVec &lhs, const StrVec &rhs) {
			return !(lhs == rhs);
		}

		StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
		StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

		void StrBlob::check(size_type i, const std::string &msg) const {
			if (i >= data->size())
				throw std::out_of_range(msg);
		}

		std::string &StrBlob::front() {
			check(0, "front on empty StrBlob");
			return data->front();
		}

		std::string &StrBlob::back() {
			check(0, "back on empty StrBlob");
			return data->back();
		}

		void StrBlob::pop_back() {
			check(0, "pop_back on empty StrBlob");
			data->pop_back();
		}

		StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
		StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

		ConstStrBlobPtr StrBlob::cbegin() const { return ConstStrBlobPtr(*this); }
		ConstStrBlobPtr StrBlob::cend() const { return ConstStrBlobPtr(*this, data->size()); }

		bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
			return *lhs.data == *rhs.data;
		}

		bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
			return !(lhs == rhs);
		}

		std::shared_ptr<std::vector<std::string>>
		StrBlobPtr::check(std::size_t i, const std::string &msg) const {
			std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
			if (!ret)
				throw std::runtime_error("unbound StrBlobPtr");
			if (i >= ret->size())
				throw std::out_of_range(msg);
			return ret;
		}

		std::string &StrBlobPtr::deref() const {
			std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}

		StrBlobPtr &StrBlobPtr::incr() {
			check(curr, "increment past end of StrBlobPtr");
			++curr;
			return *this;
		}

		bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return lhs.wptr.lock() == rhs.wptr.lock() &&
					lhs.curr == rhs.curr;
		}

		bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return !(lhs == rhs);
		}

		std::shared_ptr<std::vector<std::string>>
		ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const {
			std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
			if (!ret)
				throw std::runtime_error("unbound StrBlobPtr");
			if (i >= ret->size())
				throw std::out_of_range(msg);
			return ret;
		}

		const std::string &ConstStrBlobPtr::deref() const {
			std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}

		ConstStrBlobPtr &ConstStrBlobPtr::incr() {
			check(curr, "increment past end of StrBlobPtr");
			++curr;
			return *this;
		}

		bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return lhs.wptr.lock() == rhs.wptr.lock() &&
					lhs.curr == rhs.curr;
		}

		bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return !(lhs == rhs);
		}
	}
	namespace _17 {
		std::ostream &operator<<(std::ostream &os, const Employee &e) {
			os << e.name << " " << e.age << " " << e.rank;
			return os;
		}

		std::istream &operator>>(std::istream &is, Employee &e) {
			is >> e.name >> e.age >> e.rank;
			if (!is)
				e = Employee();
			return is;
		}

		Employee operator+(const Employee &lhs, unsigned rhs) {
			Employee ret = lhs;
			ret.age += rhs;
			return ret;
		}

		Employee operator+(const Employee &lhs, const Employee &rhs) {
			Employee ret = lhs;
			ret.age += rhs.age;
			return ret;
		}

		Employee operator-(const Employee &lhs, unsigned rhs) {
			Employee ret = lhs;
			ret.age -= rhs;
			return ret;
		}

		Employee operator-(const Employee &lhs, const Employee &rhs) {
			Employee ret = lhs;
			ret.age -= rhs.age;
			return ret;
		}

		bool operator==(const Employee &lhs, const Employee &rhs) {
			return lhs.name == rhs.name &&
					lhs.age == rhs.age &&
					lhs.rank == rhs.rank;
		}

		bool operator!=(const Employee &lhs, const Employee &rhs) {
			return !(lhs == rhs);
		}
	}
	namespace _18 {
		std::allocator<char> String::alloc;

		std::pair<char *, char *> String::exact_alloc_copy(const char *b, const char *e) const {
			char *data = alloc.allocate(e - b);
			return std::make_pair(data, std::uninitialized_copy(b, e, data));
		}

		void String::free() const {
			for (const char *p = first_free; p != elements; )
				alloc.destroy(--p);
			alloc.deallocate(elements, cap - elements);
		}

		void String::reallocate() {
			std::size_t newcapacity = size() ? 2 * size() : 1;
			char *newdata = alloc.allocate(newcapacity);
			char *dest = std::uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), newdata);
			free();
			elements = newdata;
			first_free = dest;
			cap = elements + newcapacity;
		}

		String::String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
		String::String(const char *cp) {
			std::size_t strsize = std::strlen(cp);
			std::pair<char *, char *> data = exact_alloc_copy(cp, cp + strsize);
			elements = data.first;
			first_free = cap = data.second;
		}
		String::String(const String &s) {
			std::cout << "copy constructor" << std::endl;
			std::pair<char *, char *> data = exact_alloc_copy(s.cbegin(), s.cend());
			elements = data.first;
			first_free = cap = data.second;
		}
		String::String(String &&s) noexcept
			: elements(s.elements), first_free(s.first_free), cap(s.cap)
		{
			std::cout << "move constructor" << std::endl;
			s.elements = s.first_free = s.cap = nullptr;
		}
		String &String::operator=(const String &rhs) {
			std::cout << "copy-assignment operator" << std::endl;
			std::pair<char *, char *> newdata = exact_alloc_copy(rhs.cbegin(), rhs.cend());
			free();
			elements = newdata.first;
			first_free = cap = newdata.second;
			return *this;
		}
		String &String::operator=(String &&rhs) noexcept
		{
			std::cout << "move-assignment operator" << std::endl;
			if (this != &rhs) {
				free();
				elements = rhs.elements;
				first_free = rhs.first_free;
				cap = rhs.cap;
				rhs.elements = rhs.first_free = rhs.cap = nullptr;
			}
			return *this;
		}

		String::~String() { free(); }

		void String::push_back(char c) {
			check_full_realloc();
			alloc.construct(first_free++, c);
		}

		std::ostream &print(std::ostream &os, const String &s) {
			for (const char *cp = s.cbegin(); cp != s.cend(); ++cp)
				os << *cp;
			return os;
		}

		std::ostream &operator<<(std::ostream &os, const String &s) {
			for (const char *cp = s.cbegin(); cp != s.cend(); ++cp)
				os << *cp;
			return os;
		}

		bool operator==(const String &lhs, const String &rhs) {
			if (lhs.size() != rhs.size())
				return false;
			// both sizes match
			const char *p1 = lhs.cbegin(), *p2 = rhs.cbegin();
			const char *e = lhs.cend();
			while (p1 != e) {
				if (*p1 != *p2)
					return false;
				++p1;
				++p2;
			}
			// sizes match and elements are equal between the two Strings
			return true;
		}

		bool operator!=(const String &lhs, const String &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const String &lhs, const String &rhs) {
			const char *p1 = lhs.cbegin(), *p2 = rhs.cbegin();
			while (p1 != lhs.cend() && p2 != rhs.cend()) {
				if (*p1 < *p2)
					return true;
				else if (*p1 > *p2)
					return false;
				++p1;
				++p2;
			}
			return lhs.size() < rhs.size();
		}

		bool operator>(const String &lhs, const String &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const String &lhs, const String &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const String &lhs, const String &rhs) {
			return !(lhs < rhs);
		}

		void StrVec::push_back(const std::string &s) {
			chk_n_alloc();	// ensure that there is room for another element
			// construct a copy of s in the element to which first_free points
			alloc.construct(first_free++, s);
		}

		std::pair<std::string *, std::string *>
		StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
			// allocate space to hold as many elements as in the range
			// data denotes the first allocated from the range
			// allocate function takes a size
			std::string *data = alloc.allocate(e - b);
			// initialize and return a pair constructed from data and
			// the value returned by uninitialized_copy
			return {data, std::uninitialized_copy(b, e, data)};
		}

		void StrVec::free() {
				// may not pass deallocate a 0 pointer; if elements is 0, there's no work to do
			if (elements) {
				// destroy the old elements in reverse order
				for (std::string *p = first_free; p != elements; /*empty*/ )
					alloc.destroy(--p);
				std::for_each(elements, first_free, [this](std::string &s){ alloc.destroy(&s);});

				alloc.deallocate(elements, cap - elements);
			}
		}

		StrVec::StrVec(const std::initializer_list<std::string> &il) {
			std::pair<std::string *, std::string *> data = alloc_n_copy(il.begin(), il.end());
			elements = data.first;
			first_free = cap = data.second;
		}

		StrVec::StrVec(const StrVec &s) {
			// call alloc_n_copy to allocate exactly as many elements as in s
			std::pair<std::string *, std::string *> newdata = alloc_n_copy(s.begin(), s.end());
			elements = newdata.first;
			first_free = cap = newdata.second;
		}

		// MOVE CONSTRUCTOR
		StrVec::StrVec(StrVec &&s) noexcept
			: elements(s.elements), first_free(s.first_free), cap(s.cap) 
		{
			s.elements = s.first_free = s.cap = nullptr;
		}
		// MOVE-ASSIGNMENT OPERATOR
		StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
			if (this != &rhs) {
				free();
				elements = rhs.elements;
				first_free = rhs.first_free;
				cap = rhs.cap;
				rhs.elements = rhs.first_free = rhs.cap = nullptr;
			}
			return *this;
		}

		StrVec::~StrVec() { free(); }

		StrVec &StrVec::operator=(const StrVec &rhs) {
			// calls alloc_n_copy to allocate exactly as many elements as in rhs
			std::pair<std::string *, std::string *> newdata = alloc_n_copy(rhs.begin(), rhs.end());
			free();
			elements = newdata.first;
			first_free = cap = newdata.second;
			return *this;
		}

		void StrVec::reallocate() {
			// we'll allocate space for twice as many elements as the current size
			std::size_t newcapacity = size() ? 2 * size() : 1;
			// allocate new memory
			std::string *newdata = alloc.allocate(newcapacity);
			// move the data from the old memory to the new
			std::string *dest = newdata;	// points to the next free position in the new array
			std::string *elem = elements;	// points to the next element in the old array
			for (std::size_t i = 0; i != size(); ++i)
				alloc.construct(dest++, std::move(*elem++));
			free();	// free the old space once we've moved the elements
			// update our data structure to point to the new elements
			elements = newdata;
			first_free = dest;
			cap = elements + newcapacity;
		}

		void StrVec::reserve(std::size_t n) {
			if (n > capacity()) {
				std::size_t oldsize = size();
				std::string *newdata = alloc.allocate(n);
				std::uninitialized_copy(elements, first_free, newdata);
				free();
				elements = newdata;
				first_free = elements + oldsize;
				cap = elements + n;
			}
		}

		void StrVec::resize(std::size_t n) { resize(n, ""); }

		void StrVec::resize(std::size_t n, const std::string &s) {
			if (n < size()) {
				while (first_free != elements + n)
					alloc.destroy(--first_free);
			} else if (n > size()) {
				reserve(n);
				while (first_free != elements + n)
					alloc.construct(first_free++, s);
			}
		}

		bool operator==(const StrVec &lhs, const StrVec &rhs) {
			if (lhs.size() != rhs.size())
				return false;
			// if sizes are the same, check for equality between each element
			const std::string *p1 = lhs.begin(), *p2 = rhs.begin();
			const std::string *e = lhs.end();
			while (p1 != e) {
				if (*p1 != *p2)
					return false;
				++p1;
				++p2;
			}
			// if sizes match and elements are equal
			return true;
		}

		bool operator!=(const StrVec &lhs, const StrVec &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const StrVec &lhs, const StrVec &rhs) {
			const std::string *p1 = lhs.begin(), *p2 = rhs.begin();
			// check elements up to the shortest size
			while (p1 != lhs.end() && p2 != rhs.end()) {
				if (*p1 < *p2)
					return true;
				else if (*p1 > *p2)
					return false;
				++p1;
				++p2;
			}
			// if all elements are equal
			return lhs.size() < rhs.size();
		}

		bool operator>(const StrVec &lhs, const StrVec &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const StrVec &lhs, const StrVec &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const StrVec &lhs, const StrVec &rhs) {
			return !(lhs < rhs);
		}

		StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
		StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

		void StrBlob::check(size_type i, const std::string &msg) const {
			if (i >= data->size())
				throw std::out_of_range(msg);
		}

		std::string &StrBlob::front() {
			check(0, "front on empty StrBlob");
			return data->front();
		}

		std::string &StrBlob::back() {
			check(0, "back on empty StrBlob");
			return data->back();
		}

		void StrBlob::pop_back() {
			check(0, "pop_back on empty StrBlob");
			data->pop_back();
		}

		StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
		StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

		ConstStrBlobPtr StrBlob::cbegin() const { return ConstStrBlobPtr(*this); }
		ConstStrBlobPtr StrBlob::cend() const { return ConstStrBlobPtr(*this, data->size()); }

		bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
			return *lhs.data == *rhs.data;
		}

		bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
			return *lhs.data < *rhs.data;
		}

		bool operator>(const StrBlob &lhs, const StrBlob &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const StrBlob &lhs, const StrBlob &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const StrBlob &lhs, const StrBlob &rhs) {
			return !(lhs < rhs);
		}

		std::shared_ptr<std::vector<std::string>>
		StrBlobPtr::check(std::size_t i, const std::string &msg) const {
			std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
			if (!ret)
				throw std::runtime_error("unbound StrBlobPtr");
			if (i >= ret->size())
				throw std::out_of_range(msg);
			return ret;
		}

		std::string &StrBlobPtr::deref() const {
			std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}

		StrBlobPtr &StrBlobPtr::incr() {
			check(curr, "increment past end of StrBlobPtr");
			++curr;
			return *this;
		}

		bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return lhs.wptr.lock() == rhs.wptr.lock() &&
					lhs.curr == rhs.curr;
		}

		bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("comparing two StrBlobPtrs that don't point to the same object");
			return lhs.curr < rhs.curr;
		}

		bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return !(lhs < rhs);

		}

		std::shared_ptr<std::vector<std::string>>
		ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const {
			std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
			if (!ret)
				throw std::runtime_error("unbound StrBlobPtr");
			if (i >= ret->size())
				throw std::out_of_range(msg);
			return ret;
		}

		const std::string &ConstStrBlobPtr::deref() const {
			std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}

		ConstStrBlobPtr &ConstStrBlobPtr::incr() {
			check(curr, "increment past end of StrBlobPtr");
			++curr;
			return *this;
		}

		bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return lhs.wptr.lock() == rhs.wptr.lock() &&
					lhs.curr == rhs.curr;
		}

		bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("comparing two ConstStrBlobPtrs that don't point to the same object");
			return lhs.curr < rhs.curr;
		}

		bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return !(lhs < rhs);
		}
	}
	namespace _20 {
		Sales_data &Sales_data::combine(const Sales_data &rhs) {
			units_sold += rhs.units_sold;
			revenue += rhs.revenue;
			return *this;
		}

		// NONMEMBER FUNCTIONS

		Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data sum = lhs;
			sum.combine(rhs);
			return sum;
		}

		std::istream &read(std::istream &is, Sales_data &item) {
			double price = 0.0;
			is >> item.bookNo >> item.units_sold >> price;
			item.revenue = item.units_sold * price;
			return is;
		}

		std::ostream &print(std::ostream &os, const Sales_data &item) {
			os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
			return os;
		}

		std::ostream &operator<<(std::ostream &os, const Sales_data &item) {
			os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
			return os;
		}

		std::istream &operator>>(std::istream &is, Sales_data &item) {
			double price;
			is >> item.bookNo >> item.units_sold >> price;
			if (is)
				item.revenue = item.units_sold * price;
			else
				item = Sales_data();
			return is;
		}

		Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret += rhs;
			return ret;
		}
		Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold -= rhs.units_sold;
			ret.revenue -= rhs.revenue;
			return ret;
		}
		Sales_data operator*(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold *= rhs.units_sold;
			ret.revenue *= rhs.revenue;
			return ret;
		}
		Sales_data operator/(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold /= rhs.units_sold;
			ret.revenue /= rhs.revenue;
			return ret;
		}

		Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
			units_sold += rhs.units_sold;
			revenue += rhs.revenue;
			return *this;
		}
	}
	namespace _21 {
		Sales_data &Sales_data::combine(const Sales_data &rhs) {
			units_sold += rhs.units_sold;
			revenue += rhs.revenue;
			return *this;
		}

		// NONMEMBER FUNCTIONS

		Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data sum = lhs;
			sum.combine(rhs);
			return sum;
		}

		std::istream &read(std::istream &is, Sales_data &item) {
			double price = 0.0;
			is >> item.bookNo >> item.units_sold >> price;
			item.revenue = item.units_sold * price;
			return is;
		}

		std::ostream &print(std::ostream &os, const Sales_data &item) {
			os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
			return os;
		}

		std::ostream &operator<<(std::ostream &os, const Sales_data &item) {
			os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
			return os;
		}

		std::istream &operator>>(std::istream &is, Sales_data &item) {
			double price;
			is >> item.bookNo >> item.units_sold >> price;
			if (is)
				item.revenue = item.units_sold * price;
			else
				item = Sales_data();
			return is;
		}
		// bad practice
		Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold += rhs.units_sold;
			ret.revenue += rhs.revenue;
			return ret;
		}
		Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold -= rhs.units_sold;
			ret.revenue -= rhs.revenue;
			return ret;
		}
		Sales_data operator*(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold *= rhs.units_sold;
			ret.revenue *= rhs.revenue;
			return ret;
		}
		Sales_data operator/(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold /= rhs.units_sold;
			ret.revenue /= rhs.revenue;
			return ret;
		}

		Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
			*this = *this + rhs;
			return *this;
		}
	}
	namespace _22 {
		Sales_data &Sales_data::combine(const Sales_data &rhs) {
			units_sold += rhs.units_sold;
			revenue += rhs.revenue;
			return *this;
		}

		// NONMEMBER FUNCTIONS

		Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data sum = lhs;
			sum.combine(rhs);
			return sum;
		}

		std::istream &read(std::istream &is, Sales_data &item) {
			double price = 0.0;
			is >> item.bookNo >> item.units_sold >> price;
			item.revenue = item.units_sold * price;
			return is;
		}

		std::ostream &print(std::ostream &os, const Sales_data &item) {
			os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
			return os;
		}

		std::ostream &operator<<(std::ostream &os, const Sales_data &item) {
			os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
			return os;
		}

		std::istream &operator>>(std::istream &is, Sales_data &item) {
			double price;
			is >> item.bookNo >> item.units_sold >> price;
			if (is)
				item.revenue = item.units_sold * price;
			else
				item = Sales_data();
			return is;
		}

		Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret += rhs;
			return ret;
		}
		Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold -= rhs.units_sold;
			ret.revenue -= rhs.revenue;
			return ret;
		}
		Sales_data operator*(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold *= rhs.units_sold;
			ret.revenue *= rhs.revenue;
			return ret;
		}
		Sales_data operator/(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold /= rhs.units_sold;
			ret.revenue /= rhs.revenue;
			return ret;
		}

		Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
			units_sold += rhs.units_sold;
			revenue += rhs.revenue;
			return *this;
		}

		Sales_data &Sales_data::operator=(const std::string &s) {
			bookNo = s;
			units_sold = 0;
			revenue = 0.0;
			return *this;
		}
	}
	namespace _23 {
		void StrVec::push_back(const std::string &s) {
			chk_n_alloc();	// ensure that there is room for another element
			// construct a copy of s in the element to which first_free points
			alloc.construct(first_free++, s);
		}

		std::pair<std::string *, std::string *>
		StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
			// allocate space to hold as many elements as in the range
			// data denotes the first allocated from the range
			// allocate function takes a size
			std::string *data = alloc.allocate(e - b);
			// initialize and return a pair constructed from data and
			// the value returned by uninitialized_copy
			return {data, std::uninitialized_copy(b, e, data)};
		}

		void StrVec::free() {
				// may not pass deallocate a 0 pointer; if elements is 0, there's no work to do
			if (elements) {
				// destroy the old elements in reverse order
				for (std::string *p = first_free; p != elements; /*empty*/ )
					alloc.destroy(--p);
				std::for_each(elements, first_free, [this](std::string &s){ alloc.destroy(&s);});

				alloc.deallocate(elements, cap - elements);
			}
		}

		StrVec::StrVec(const std::initializer_list<std::string> &il) {
			std::pair<std::string *, std::string *> data = alloc_n_copy(il.begin(), il.end());
			elements = data.first;
			first_free = cap = data.second;
		}

		StrVec::StrVec(const StrVec &s) {
			// call alloc_n_copy to allocate exactly as many elements as in s
			std::pair<std::string *, std::string *> newdata = alloc_n_copy(s.begin(), s.end());
			elements = newdata.first;
			first_free = cap = newdata.second;
		}

		// MOVE CONSTRUCTOR
		StrVec::StrVec(StrVec &&s) noexcept
			: elements(s.elements), first_free(s.first_free), cap(s.cap) 
		{
			s.elements = s.first_free = s.cap = nullptr;
		}
		// MOVE-ASSIGNMENT OPERATOR
		StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
			if (this != &rhs) {
				free();
				elements = rhs.elements;
				first_free = rhs.first_free;
				cap = rhs.cap;
				rhs.elements = rhs.first_free = rhs.cap = nullptr;
			}
			return *this;
		}

		StrVec::~StrVec() { free(); }

		StrVec &StrVec::operator=(const StrVec &rhs) {
			// calls alloc_n_copy to allocate exactly as many elements as in rhs
			std::pair<std::string *, std::string *> newdata = alloc_n_copy(rhs.begin(), rhs.end());
			free();
			elements = newdata.first;
			first_free = cap = newdata.second;
			return *this;
		}

		void StrVec::reallocate() {
			// we'll allocate space for twice as many elements as the current size
			std::size_t newcapacity = size() ? 2 * size() : 1;
			// allocate new memory
			std::string *newdata = alloc.allocate(newcapacity);
			// move the data from the old memory to the new
			std::string *dest = newdata;	// points to the next free position in the new array
			std::string *elem = elements;	// points to the next element in the old array
			for (std::size_t i = 0; i != size(); ++i)
				alloc.construct(dest++, std::move(*elem++));
			free();	// free the old space once we've moved the elements
			// update our data structure to point to the new elements
			elements = newdata;
			first_free = dest;
			cap = elements + newcapacity;
		}

		void StrVec::reserve(std::size_t n) {
			if (n > capacity()) {
				std::size_t oldsize = size();
				std::string *newdata = alloc.allocate(n);
				std::uninitialized_copy(elements, first_free, newdata);
				free();
				elements = newdata;
				first_free = elements + oldsize;
				cap = elements + n;
			}
		}

		void StrVec::resize(std::size_t n) { resize(n, ""); }

		void StrVec::resize(std::size_t n, const std::string &s) {
			if (n < size()) {
				while (first_free != elements + n)
					alloc.destroy(--first_free);
			} else if (n > size()) {
				reserve(n);
				while (first_free != elements + n)
					alloc.construct(first_free++, s);
			}
		}

		bool operator==(const StrVec &lhs, const StrVec &rhs) {
			if (lhs.size() != rhs.size())
				return false;
			// if sizes are the same, check for equality between each element
			const std::string *p1 = lhs.begin(), *p2 = rhs.begin();
			const std::string *e = lhs.end();
			while (p1 != e) {
				if (*p1 != *p2)
					return false;
				++p1;
				++p2;
			}
			// if sizes match and elements are equal
			return true;
		}

		bool operator!=(const StrVec &lhs, const StrVec &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const StrVec &lhs, const StrVec &rhs) {
			const std::string *p1 = lhs.begin(), *p2 = rhs.begin();
			// check elements up to the shortest size
			while (p1 != lhs.end() && p2 != rhs.end()) {
				if (*p1 < *p2)
					return true;
				else if (*p1 > *p2)
					return false;
				++p1;
				++p2;
			}
			// if all elements are equal
			return lhs.size() < rhs.size();
		}

		bool operator>(const StrVec &lhs, const StrVec &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const StrVec &lhs, const StrVec &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const StrVec &lhs, const StrVec &rhs) {
			return !(lhs < rhs);
		}

		StrVec &StrVec::operator=(const std::initializer_list<std::string> &il) {
			std::pair<std::string *, std::string *> newdata = alloc_n_copy(il.begin(), il.end());
			free();
			elements = newdata.first;
			first_free = cap = newdata.second;
			return *this;
		}
	}
	namespace _24 {
		std::ostream &operator<<(std::ostream &os, const Employee &e) {
			os << e.name << " " << e.age << " " << e.rank;
			return os;
		}

		std::istream &operator>>(std::istream &is, Employee &e) {
			is >> e.name >> e.age >> e.rank;
			if (!is)
				e = Employee();
			return is;
		}

		Employee operator+(const Employee &lhs, unsigned rhs) {
			Employee ret = lhs;
			ret.age += rhs;
			return ret;
		}

		Employee operator+(const Employee &lhs, const Employee &rhs) {
			Employee ret = lhs;
			ret.age += rhs.age;
			return ret;
		}

		Employee operator-(const Employee &lhs, unsigned rhs) {
			Employee ret = lhs;
			ret.age -= rhs;
			return ret;
		}

		Employee operator-(const Employee &lhs, const Employee &rhs) {
			Employee ret = lhs;
			ret.age -= rhs.age;
			return ret;
		}

		bool operator==(const Employee &lhs, const Employee &rhs) {
			return lhs.name == rhs.name &&
					lhs.age == rhs.age &&
					lhs.rank == rhs.rank;
		}

		bool operator!=(const Employee &lhs, const Employee &rhs) {
			return !(lhs == rhs);
		}

		Employee &Employee::operator=(const Employee &e) {
			name = e.name;
			age = e.age;
			rank = e.rank;
			return *this;
		}

		Employee &Employee::operator=(Employee &&e) noexcept {
			name = std::move(e.name);
			age = std::move(e.age);
			rank = std::move(e.rank);
			return *this;
		}
	}
	namespace _25 {
		std::ostream &operator<<(std::ostream &os, const Employee &e) {
			os << e.name << " " << e.age << " " << e.rank;
			return os;
		}

		std::istream &operator>>(std::istream &is, Employee &e) {
			is >> e.name >> e.age >> e.rank;
			if (!is)
				e = Employee();
			return is;
		}

		Employee operator+(const Employee &lhs, unsigned rhs) {
			Employee ret = lhs;
			ret.age += rhs;
			return ret;
		}

		Employee operator+(const Employee &lhs, const Employee &rhs) {
			Employee ret = lhs;
			ret.age += rhs.age;
			return ret;
		}

		Employee operator-(const Employee &lhs, unsigned rhs) {
			Employee ret = lhs;
			ret.age -= rhs;
			return ret;
		}

		Employee operator-(const Employee &lhs, const Employee &rhs) {
			Employee ret = lhs;
			ret.age -= rhs.age;
			return ret;
		}

		bool operator==(const Employee &lhs, const Employee &rhs) {
			return lhs.name == rhs.name &&
					lhs.age == rhs.age &&
					lhs.rank == rhs.rank;
		}

		bool operator!=(const Employee &lhs, const Employee &rhs) {
			return !(lhs == rhs);
		}

		Employee &Employee::operator=(const Employee &e) {
			name = e.name;
			age = e.age;
			rank = e.rank;
			return *this;
		}

		Employee &Employee::operator=(Employee &&e) noexcept {
			name = std::move(e.name);
			age = std::move(e.age);
			rank = std::move(e.rank);
			return *this;
		}

		Employee &Employee::operator=(const std::initializer_list<std::string> &il) {
			if (il.size() != 3)
				throw std::runtime_error("invalid size of initializer_list");
			std::initializer_list<std::string>::const_iterator it = il.begin();
			name = *it++;
			age = std::stoul(*it++);
			rank = *it;
			return *this;
		}
	}
	namespace _26 {
		std::allocator<char> String::alloc;

		std::pair<char *, char *> String::exact_alloc_copy(const char *b, const char *e) const {
			char *data = alloc.allocate(e - b);
			return std::make_pair(data, std::uninitialized_copy(b, e, data));
		}

		void String::free() const {
			for (const char *p = first_free; p != elements; )
				alloc.destroy(--p);
			alloc.deallocate(elements, cap - elements);
		}

		void String::reallocate() {
			std::size_t newcapacity = size() ? 2 * size() : 1;
			char *newdata = alloc.allocate(newcapacity);
			char *dest = std::uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), newdata);
			free();
			elements = newdata;
			first_free = dest;
			cap = elements + newcapacity;
		}

		String::String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
		String::String(const char *cp) {
			std::size_t strsize = std::strlen(cp);
			std::pair<char *, char *> data = exact_alloc_copy(cp, cp + strsize);
			elements = data.first;
			first_free = cap = data.second;
		}
		String::String(const String &s) {
			std::cout << "copy constructor" << std::endl;
			std::pair<char *, char *> data = exact_alloc_copy(s.cbegin(), s.cend());
			elements = data.first;
			first_free = cap = data.second;
		}
		String::String(String &&s) noexcept
			: elements(s.elements), first_free(s.first_free), cap(s.cap)
		{
			std::cout << "move constructor" << std::endl;
			s.elements = s.first_free = s.cap = nullptr;
		}
		String &String::operator=(const String &rhs) {
			std::cout << "copy-assignment operator" << std::endl;
			std::pair<char *, char *> newdata = exact_alloc_copy(rhs.cbegin(), rhs.cend());
			free();
			elements = newdata.first;
			first_free = cap = newdata.second;
			return *this;
		}
		String &String::operator=(String &&rhs) noexcept
		{
			std::cout << "move-assignment operator" << std::endl;
			if (this != &rhs) {
				free();
				elements = rhs.elements;
				first_free = rhs.first_free;
				cap = rhs.cap;
				rhs.elements = rhs.first_free = rhs.cap = nullptr;
			}
			return *this;
		}

		String::~String() { free(); }

		void String::push_back(char c) {
			check_full_realloc();
			alloc.construct(first_free++, c);
		}

		std::ostream &print(std::ostream &os, const String &s) {
			for (const char *cp = s.cbegin(); cp != s.cend(); ++cp)
				os << *cp;
			return os;
		}

		std::ostream &operator<<(std::ostream &os, const String &s) {
			for (const char *cp = s.cbegin(); cp != s.cend(); ++cp)
				os << *cp;
			return os;
		}

		bool operator==(const String &lhs, const String &rhs) {
			if (lhs.size() != rhs.size())
				return false;
			// both sizes match
			const char *p1 = lhs.cbegin(), *p2 = rhs.cbegin();
			const char *e = lhs.cend();
			while (p1 != e) {
				if (*p1 != *p2)
					return false;
				++p1;
				++p2;
			}
			// sizes match and elements are equal between the two Strings
			return true;
		}

		bool operator!=(const String &lhs, const String &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const String &lhs, const String &rhs) {
			const char *p1 = lhs.cbegin(), *p2 = rhs.cbegin();
			while (p1 != lhs.cend() && p2 != rhs.cend()) {
				if (*p1 < *p2)
					return true;
				else if (*p1 > *p2)
					return false;
				++p1;
				++p2;
			}
			return lhs.size() < rhs.size();
		}

		bool operator>(const String &lhs, const String &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const String &lhs, const String &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const String &lhs, const String &rhs) {
			return !(lhs < rhs);
		}

		void StrVec::push_back(const std::string &s) {
			chk_n_alloc();	// ensure that there is room for another element
			// construct a copy of s in the element to which first_free points
			alloc.construct(first_free++, s);
		}

		std::pair<std::string *, std::string *>
		StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
			// allocate space to hold as many elements as in the range
			// data denotes the first allocated from the range
			// allocate function takes a size
			std::string *data = alloc.allocate(e - b);
			// initialize and return a pair constructed from data and
			// the value returned by uninitialized_copy
			return {data, std::uninitialized_copy(b, e, data)};
		}

		void StrVec::free() {
				// may not pass deallocate a 0 pointer; if elements is 0, there's no work to do
			if (elements) {
				// destroy the old elements in reverse order
				for (std::string *p = first_free; p != elements; /*empty*/ )
					alloc.destroy(--p);
				std::for_each(elements, first_free, [this](std::string &s){ alloc.destroy(&s);});

				alloc.deallocate(elements, cap - elements);
			}
		}

		StrVec::StrVec(const std::initializer_list<std::string> &il) {
			std::pair<std::string *, std::string *> data = alloc_n_copy(il.begin(), il.end());
			elements = data.first;
			first_free = cap = data.second;
		}

		StrVec::StrVec(const StrVec &s) {
			// call alloc_n_copy to allocate exactly as many elements as in s
			std::pair<std::string *, std::string *> newdata = alloc_n_copy(s.begin(), s.end());
			elements = newdata.first;
			first_free = cap = newdata.second;
		}

		// MOVE CONSTRUCTOR
		StrVec::StrVec(StrVec &&s) noexcept
			: elements(s.elements), first_free(s.first_free), cap(s.cap) 
		{
			s.elements = s.first_free = s.cap = nullptr;
		}
		// MOVE-ASSIGNMENT OPERATOR
		StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
			if (this != &rhs) {
				free();
				elements = rhs.elements;
				first_free = rhs.first_free;
				cap = rhs.cap;
				rhs.elements = rhs.first_free = rhs.cap = nullptr;
			}
			return *this;
		}

		StrVec::~StrVec() { free(); }

		StrVec &StrVec::operator=(const StrVec &rhs) {
			// calls alloc_n_copy to allocate exactly as many elements as in rhs
			std::pair<std::string *, std::string *> newdata = alloc_n_copy(rhs.begin(), rhs.end());
			free();
			elements = newdata.first;
			first_free = cap = newdata.second;
			return *this;
		}

		void StrVec::reallocate() {
			// we'll allocate space for twice as many elements as the current size
			std::size_t newcapacity = size() ? 2 * size() : 1;
			// allocate new memory
			std::string *newdata = alloc.allocate(newcapacity);
			// move the data from the old memory to the new
			std::string *dest = newdata;	// points to the next free position in the new array
			std::string *elem = elements;	// points to the next element in the old array
			for (std::size_t i = 0; i != size(); ++i)
				alloc.construct(dest++, std::move(*elem++));
			free();	// free the old space once we've moved the elements
			// update our data structure to point to the new elements
			elements = newdata;
			first_free = dest;
			cap = elements + newcapacity;
		}

		void StrVec::reserve(std::size_t n) {
			if (n > capacity()) {
				std::size_t oldsize = size();
				std::string *newdata = alloc.allocate(n);
				std::uninitialized_copy(elements, first_free, newdata);
				free();
				elements = newdata;
				first_free = elements + oldsize;
				cap = elements + n;
			}
		}

		void StrVec::resize(std::size_t n) { resize(n, ""); }

		void StrVec::resize(std::size_t n, const std::string &s) {
			if (n < size()) {
				while (first_free != elements + n)
					alloc.destroy(--first_free);
			} else if (n > size()) {
				reserve(n);
				while (first_free != elements + n)
					alloc.construct(first_free++, s);
			}
		}

		bool operator==(const StrVec &lhs, const StrVec &rhs) {
			if (lhs.size() != rhs.size())
				return false;
			// if sizes are the same, check for equality between each element
			const std::string *p1 = lhs.begin(), *p2 = rhs.begin();
			const std::string *e = lhs.end();
			while (p1 != e) {
				if (*p1 != *p2)
					return false;
				++p1;
				++p2;
			}
			// if sizes match and elements are equal
			return true;
		}

		bool operator!=(const StrVec &lhs, const StrVec &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const StrVec &lhs, const StrVec &rhs) {
			const std::string *p1 = lhs.begin(), *p2 = rhs.begin();
			// check elements up to the shortest size
			while (p1 != lhs.end() && p2 != rhs.end()) {
				if (*p1 < *p2)
					return true;
				else if (*p1 > *p2)
					return false;
				++p1;
				++p2;
			}
			// if all elements are equal
			return lhs.size() < rhs.size();
		}

		bool operator>(const StrVec &lhs, const StrVec &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const StrVec &lhs, const StrVec &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const StrVec &lhs, const StrVec &rhs) {
			return !(lhs < rhs);
		}

		StrVec &StrVec::operator=(const std::initializer_list<std::string> &il) {
			std::pair<std::string *, std::string *> newdata = alloc_n_copy(il.begin(), il.end());
			free();
			elements = newdata.first;
			first_free = cap = newdata.second;
			return *this;
		}

		StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
		StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

		void StrBlob::check(size_type i, const std::string &msg) const {
			if (i >= data->size())
				throw std::out_of_range(msg);
		}

		std::string &StrBlob::front() {
			check(0, "front on empty StrBlob");
			return data->front();
		}

		std::string &StrBlob::back() {
			check(0, "back on empty StrBlob");
			return data->back();
		}

		void StrBlob::pop_back() {
			check(0, "pop_back on empty StrBlob");
			data->pop_back();
		}

		StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
		StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

		ConstStrBlobPtr StrBlob::cbegin() const { return ConstStrBlobPtr(*this); }
		ConstStrBlobPtr StrBlob::cend() const { return ConstStrBlobPtr(*this, data->size()); }

		bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
			return *lhs.data == *rhs.data;
		}

		bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
			return *lhs.data < *rhs.data;
		}

		bool operator>(const StrBlob &lhs, const StrBlob &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const StrBlob &lhs, const StrBlob &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const StrBlob &lhs, const StrBlob &rhs) {
			return !(lhs < rhs);
		}

		std::shared_ptr<std::vector<std::string>>
		StrBlobPtr::check(std::size_t i, const std::string &msg) const {
			std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
			if (!ret)
				throw std::runtime_error("unbound StrBlobPtr");
			if (i >= ret->size())
				throw std::out_of_range(msg);
			return ret;
		}

		std::string &StrBlobPtr::deref() const {
			std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}

		StrBlobPtr &StrBlobPtr::incr() {
			check(curr, "increment past end of StrBlobPtr");
			++curr;
			return *this;
		}

		bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return lhs.wptr.lock() == rhs.wptr.lock() &&
					lhs.curr == rhs.curr;
		}

		bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("comparing two StrBlobPtrs that don't point to the same object");
			return lhs.curr < rhs.curr;
		}

		bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return !(lhs < rhs);

		}

		std::string &StrBlobPtr::operator[](std::size_t n) {
			std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
			return (*p)[n];
		}

		const std::string &StrBlobPtr::operator[](std::size_t n) const {
			std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
			return (*p)[n];
		}

		std::shared_ptr<std::vector<std::string>>
		ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const {
			std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
			if (!ret)
				throw std::runtime_error("unbound StrBlobPtr");
			if (i >= ret->size())
				throw std::out_of_range(msg);
			return ret;
		}

		const std::string &ConstStrBlobPtr::deref() const {
			std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}

		ConstStrBlobPtr &ConstStrBlobPtr::incr() {
			check(curr, "increment past end of StrBlobPtr");
			++curr;
			return *this;
		}

		bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return lhs.wptr.lock() == rhs.wptr.lock() &&
					lhs.curr == rhs.curr;
		}

		bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("comparing two ConstStrBlobPtrs that don't point to the same object");
			return lhs.curr < rhs.curr;
		}

		bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return !(lhs < rhs);
		}

		std::string &ConstStrBlobPtr::operator[](std::size_t n) {
			std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
			return (*p)[n];
		}

		const std::string &ConstStrBlobPtr::operator[](std::size_t n) const {
			std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
			return (*p)[n];
		}
	}
	namespace _27 {
		StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
		StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

		void StrBlob::check(size_type i, const std::string &msg) const {
			if (i >= data->size())
				throw std::out_of_range(msg);
		}

		std::string &StrBlob::front() {
			check(0, "front on empty StrBlob");
			return data->front();
		}

		std::string &StrBlob::back() {
			check(0, "back on empty StrBlob");
			return data->back();
		}

		void StrBlob::pop_back() {
			check(0, "pop_back on empty StrBlob");
			data->pop_back();
		}

		StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
		StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

		ConstStrBlobPtr StrBlob::cbegin() const { return ConstStrBlobPtr(*this); }
		ConstStrBlobPtr StrBlob::cend() const { return ConstStrBlobPtr(*this, data->size()); }

		bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
			return *lhs.data == *rhs.data;
		}

		bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
			return *lhs.data < *rhs.data;
		}

		bool operator>(const StrBlob &lhs, const StrBlob &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const StrBlob &lhs, const StrBlob &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const StrBlob &lhs, const StrBlob &rhs) {
			return !(lhs < rhs);
		}

		std::shared_ptr<std::vector<std::string>>
		StrBlobPtr::check(std::size_t i, const std::string &msg) const {
			std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
			if (!ret)
				throw std::runtime_error("unbound StrBlobPtr");
			if (i >= ret->size())
				throw std::out_of_range(msg);
			return ret;
		}

		std::string &StrBlobPtr::deref() const {
			std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}

		StrBlobPtr &StrBlobPtr::incr() {
			check(curr, "increment past end of StrBlobPtr");
			++curr;
			return *this;
		}

		bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return lhs.wptr.lock() == rhs.wptr.lock() &&
					lhs.curr == rhs.curr;
		}

		bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("comparing two StrBlobPtrs that don't point to the same object");
			return lhs.curr < rhs.curr;
		}

		bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return !(lhs < rhs);

		}

		std::string &StrBlobPtr::operator[](std::size_t n) {
			std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
			return (*p)[n];
		}

		const std::string &StrBlobPtr::operator[](std::size_t n) const {
			std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
			return (*p)[n];
		}

		// prefix operators
		StrBlobPtr &StrBlobPtr::operator++() {
			check(curr++, "increment past end of StrBlobPtr");
			return *this;
		}
		StrBlobPtr &StrBlobPtr::operator--() {
			check(--curr, "decrement past begin of StrBlobPtr");
			return *this;
		}

		// postfix operator
		StrBlobPtr StrBlobPtr::operator++(int) {
			StrBlobPtr ret = *this;
			++*this;
			return ret;
		}
		StrBlobPtr StrBlobPtr::operator--(int) {
			StrBlobPtr ret = *this;
			--*this;
			return ret;
		}

		std::shared_ptr<std::vector<std::string>>
		ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const {
			std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
			if (!ret)
				throw std::runtime_error("unbound StrBlobPtr");
			if (i >= ret->size())
				throw std::out_of_range(msg);
			return ret;
		}

		const std::string &ConstStrBlobPtr::deref() const {
			std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}

		ConstStrBlobPtr &ConstStrBlobPtr::incr() {
			check(curr, "increment past end of StrBlobPtr");
			++curr;
			return *this;
		}

		bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return lhs.wptr.lock() == rhs.wptr.lock() &&
					lhs.curr == rhs.curr;
		}

		bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("comparing two ConstStrBlobPtrs that don't point to the same object");
			return lhs.curr < rhs.curr;
		}

		bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return !(lhs < rhs);
		}

		std::string &ConstStrBlobPtr::operator[](std::size_t n) {
			std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
			return (*p)[n];
		}

		const std::string &ConstStrBlobPtr::operator[](std::size_t n) const {
			std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
			return (*p)[n];
		}

		// prefix operators
		ConstStrBlobPtr &ConstStrBlobPtr::operator++() {
			check(curr++, "increment past end of ConstStrBlobPtr");
			return *this;
		}
		ConstStrBlobPtr &ConstStrBlobPtr::operator--() {
			check(--curr, "decrement past begin of ConstStrBlobPtr");
			return *this;
		}

		// postfix operators
		ConstStrBlobPtr ConstStrBlobPtr::operator++(int) {
			ConstStrBlobPtr ret = *this;
			++*this;
			return ret;
		}
		ConstStrBlobPtr ConstStrBlobPtr::operator--(int) {
			ConstStrBlobPtr ret = *this;
			--*this;
			return ret;
		}
	}
	namespace _28 {
		StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
		StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

		void StrBlob::check(size_type i, const std::string &msg) const {
			if (i >= data->size())
				throw std::out_of_range(msg);
		}

		std::string &StrBlob::front() {
			check(0, "front on empty StrBlob");
			return data->front();
		}

		std::string &StrBlob::back() {
			check(0, "back on empty StrBlob");
			return data->back();
		}

		void StrBlob::pop_back() {
			check(0, "pop_back on empty StrBlob");
			data->pop_back();
		}

		StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
		StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

		ConstStrBlobPtr StrBlob::cbegin() const { return ConstStrBlobPtr(*this); }
		ConstStrBlobPtr StrBlob::cend() const { return ConstStrBlobPtr(*this, data->size()); }

		bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
			return *lhs.data == *rhs.data;
		}

		bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
			return *lhs.data < *rhs.data;
		}

		bool operator>(const StrBlob &lhs, const StrBlob &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const StrBlob &lhs, const StrBlob &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const StrBlob &lhs, const StrBlob &rhs) {
			return !(lhs < rhs);
		}

		std::shared_ptr<std::vector<std::string>>
		StrBlobPtr::check(std::size_t i, const std::string &msg) const {
			std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
			if (!ret)
				throw std::runtime_error("unbound StrBlobPtr");
			if (i >= ret->size())
				throw std::out_of_range(msg);
			return ret;
		}

		std::string &StrBlobPtr::deref() const {
			std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}

		StrBlobPtr &StrBlobPtr::incr() {
			check(curr, "increment past end of StrBlobPtr");
			++curr;
			return *this;
		}

		bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return lhs.wptr.lock() == rhs.wptr.lock() &&
					lhs.curr == rhs.curr;
		}

		bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("comparing two StrBlobPtrs that don't point to the same object");
			return lhs.curr < rhs.curr;
		}

		bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return !(lhs < rhs);

		}

		std::string &StrBlobPtr::operator[](std::size_t n) {
			std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
			return (*p)[n];
		}

		const std::string &StrBlobPtr::operator[](std::size_t n) const {
			std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
			return (*p)[n];
		}

		// prefix operators
		StrBlobPtr &StrBlobPtr::operator++() {
			check(curr++, "increment past end of StrBlobPtr");
			return *this;
		}
		StrBlobPtr &StrBlobPtr::operator--() {
			check(--curr, "decrement past begin of StrBlobPtr");
			return *this;
		}

		// postfix operator
		StrBlobPtr StrBlobPtr::operator++(int) {
			StrBlobPtr ret = *this;
			++*this;
			return ret;
		}
		StrBlobPtr StrBlobPtr::operator--(int) {
			StrBlobPtr ret = *this;
			--*this;
			return ret;
		}

		StrBlobPtr operator+(const StrBlobPtr &p, std::size_t n) {
			StrBlobPtr ret = p;
			ret.curr += n;
			ret.check(ret.curr - 1, "incrementing past end of StrBlobPtr");
			return ret;
		}
		StrBlobPtr operator-(const StrBlobPtr &p, std::size_t n) {
			StrBlobPtr ret = p;
			ret.curr -= n;
			ret.check(ret.curr, "decrement past begin of StrBlobPtr");
			return ret;
		}
		std::ptrdiff_t operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("StrBlobPtrs don't refer to the same object");
			std::ptrdiff_t ret = lhs.curr;
			ret -= rhs.curr;
			return ret;
		}

		std::shared_ptr<std::vector<std::string>>
		ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const {
			std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
			if (!ret)
				throw std::runtime_error("unbound StrBlobPtr");
			if (i >= ret->size())
				throw std::out_of_range(msg);
			return ret;
		}

		const std::string &ConstStrBlobPtr::deref() const {
			std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}

		ConstStrBlobPtr &ConstStrBlobPtr::incr() {
			check(curr, "increment past end of StrBlobPtr");
			++curr;
			return *this;
		}

		bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return lhs.wptr.lock() == rhs.wptr.lock() &&
					lhs.curr == rhs.curr;
		}

		bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("comparing two ConstStrBlobPtrs that don't point to the same object");
			return lhs.curr < rhs.curr;
		}

		bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return !(lhs < rhs);
		}

		std::string &ConstStrBlobPtr::operator[](std::size_t n) {
			std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
			return (*p)[n];
		}

		const std::string &ConstStrBlobPtr::operator[](std::size_t n) const {
			std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
			return (*p)[n];
		}

		// prefix operators
		ConstStrBlobPtr &ConstStrBlobPtr::operator++() {
			check(curr++, "increment past end of ConstStrBlobPtr");
			return *this;
		}
		ConstStrBlobPtr &ConstStrBlobPtr::operator--() {
			check(--curr, "decrement past begin of ConstStrBlobPtr");
			return *this;
		}

		// postfix operators
		ConstStrBlobPtr ConstStrBlobPtr::operator++(int) {
			ConstStrBlobPtr ret = *this;
			++*this;
			return ret;
		}
		ConstStrBlobPtr ConstStrBlobPtr::operator--(int) {
			ConstStrBlobPtr ret = *this;
			--*this;
			return ret;
		}

		ConstStrBlobPtr operator+(const ConstStrBlobPtr &p, std::size_t n) {
			ConstStrBlobPtr ret = p;
			ret.curr += n;
			ret.check(ret.curr - 1, "incrementing past end of ConstStrBlobPtr");
			return ret;
		}
		ConstStrBlobPtr operator-(const ConstStrBlobPtr &p, std::size_t n) {
			ConstStrBlobPtr ret = p;
			ret.curr -= n;
			ret.check(ret.curr, "decrement past begin of ConstStrBlobPtr");
			return ret;
		}
		std::ptrdiff_t operator-(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("ConstStrBlobPtrs don't refer to the same object");
			std::ptrdiff_t ret = lhs.curr;
			ret -= rhs.curr;
			return ret;
		}
	}
	namespace _30 {
		StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
		StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

		void StrBlob::check(size_type i, const std::string &msg) const {
			if (i >= data->size())
				throw std::out_of_range(msg);
		}

		std::string &StrBlob::front() {
			check(0, "front on empty StrBlob");
			return data->front();
		}

		std::string &StrBlob::back() {
			check(0, "back on empty StrBlob");
			return data->back();
		}

		void StrBlob::pop_back() {
			check(0, "pop_back on empty StrBlob");
			data->pop_back();
		}

		StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
		StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

		ConstStrBlobPtr StrBlob::cbegin() const { return ConstStrBlobPtr(*this); }
		ConstStrBlobPtr StrBlob::cend() const { return ConstStrBlobPtr(*this, data->size()); }

		bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
			return *lhs.data == *rhs.data;
		}

		bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
			return *lhs.data < *rhs.data;
		}

		bool operator>(const StrBlob &lhs, const StrBlob &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const StrBlob &lhs, const StrBlob &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const StrBlob &lhs, const StrBlob &rhs) {
			return !(lhs < rhs);
		}

		std::shared_ptr<std::vector<std::string>>
		StrBlobPtr::check(std::size_t i, const std::string &msg) const {
			std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
			if (!ret)
				throw std::runtime_error("unbound StrBlobPtr");
			if (i >= ret->size())
				throw std::out_of_range(msg);
			return ret;
		}

		std::string &StrBlobPtr::deref() const {
			std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}

		StrBlobPtr &StrBlobPtr::incr() {
			check(curr, "increment past end of StrBlobPtr");
			++curr;
			return *this;
		}

		bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return lhs.wptr.lock() == rhs.wptr.lock() &&
					lhs.curr == rhs.curr;
		}

		bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("comparing two StrBlobPtrs that don't point to the same object");
			return lhs.curr < rhs.curr;
		}

		bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return !(lhs < rhs);

		}

		std::string &StrBlobPtr::operator[](std::size_t n) {
			std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
			return (*p)[n];
		}

		const std::string &StrBlobPtr::operator[](std::size_t n) const {
			std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
			return (*p)[n];
		}

		// prefix operators
		StrBlobPtr &StrBlobPtr::operator++() {
			check(curr++, "increment past end of StrBlobPtr");
			return *this;
		}
		StrBlobPtr &StrBlobPtr::operator--() {
			check(--curr, "decrement past begin of StrBlobPtr");
			return *this;
		}

		// postfix operator
		StrBlobPtr StrBlobPtr::operator++(int) {
			StrBlobPtr ret = *this;
			++*this;
			return ret;
		}
		StrBlobPtr StrBlobPtr::operator--(int) {
			StrBlobPtr ret = *this;
			--*this;
			return ret;
		}

		StrBlobPtr operator+(const StrBlobPtr &p, std::size_t n) {
			StrBlobPtr ret = p;
			ret.curr += n;
			ret.check(ret.curr - 1, "incrementing past end of StrBlobPtr");
			return ret;
		}
		StrBlobPtr operator-(const StrBlobPtr &p, std::size_t n) {
			StrBlobPtr ret = p;
			ret.curr -= n;
			ret.check(ret.curr, "decrement past begin of StrBlobPtr");
			return ret;
		}
		std::ptrdiff_t operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("StrBlobPtrs don't refer to the same object");
			std::ptrdiff_t ret = lhs.curr;
			ret -= rhs.curr;
			return ret;
		}

		std::string &StrBlobPtr::operator*() const {
			std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}
		std::string *StrBlobPtr::operator->() const {
			return &this->operator*();
		}

		std::shared_ptr<std::vector<std::string>>
		ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const {
			std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
			if (!ret)
				throw std::runtime_error("unbound StrBlobPtr");
			if (i >= ret->size())
				throw std::out_of_range(msg);
			return ret;
		}

		const std::string &ConstStrBlobPtr::deref() const {
			std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}

		ConstStrBlobPtr &ConstStrBlobPtr::incr() {
			check(curr, "increment past end of StrBlobPtr");
			++curr;
			return *this;
		}

		bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return lhs.wptr.lock() == rhs.wptr.lock() &&
					lhs.curr == rhs.curr;
		}

		bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("comparing two ConstStrBlobPtrs that don't point to the same object");
			return lhs.curr < rhs.curr;
		}

		bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return !(lhs < rhs);
		}

		std::string &ConstStrBlobPtr::operator[](std::size_t n) {
			std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
			return (*p)[n];
		}

		const std::string &ConstStrBlobPtr::operator[](std::size_t n) const {
			std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
			return (*p)[n];
		}

		// prefix operators
		ConstStrBlobPtr &ConstStrBlobPtr::operator++() {
			check(curr++, "increment past end of ConstStrBlobPtr");
			return *this;
		}
		ConstStrBlobPtr &ConstStrBlobPtr::operator--() {
			check(--curr, "decrement past begin of ConstStrBlobPtr");
			return *this;
		}

		// postfix operators
		ConstStrBlobPtr ConstStrBlobPtr::operator++(int) {
			ConstStrBlobPtr ret = *this;
			++*this;
			return ret;
		}
		ConstStrBlobPtr ConstStrBlobPtr::operator--(int) {
			ConstStrBlobPtr ret = *this;
			--*this;
			return ret;
		}

		ConstStrBlobPtr operator+(const ConstStrBlobPtr &p, std::size_t n) {
			ConstStrBlobPtr ret = p;
			ret.curr += n;
			ret.check(ret.curr - 1, "incrementing past end of ConstStrBlobPtr");
			return ret;
		}
		ConstStrBlobPtr operator-(const ConstStrBlobPtr &p, std::size_t n) {
			ConstStrBlobPtr ret = p;
			ret.curr -= n;
			ret.check(ret.curr, "decrement past begin of ConstStrBlobPtr");
			return ret;
		}
		std::ptrdiff_t operator-(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("ConstStrBlobPtrs don't refer to the same object");
			std::ptrdiff_t ret = lhs.curr;
			ret -= rhs.curr;
			return ret;
		}

		const std::string &ConstStrBlobPtr::operator*() const {
			std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}
		const std::string *ConstStrBlobPtr::operator->() const {
			return &this->operator*();
		}
	}
	namespace _32 {
		StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
		StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

		void StrBlob::check(size_type i, const std::string &msg) const {
			if (i >= data->size())
				throw std::out_of_range(msg);
		}

		std::string &StrBlob::front() {
			check(0, "front on empty StrBlob");
			return data->front();
		}

		std::string &StrBlob::back() {
			check(0, "back on empty StrBlob");
			return data->back();
		}

		void StrBlob::pop_back() {
			check(0, "pop_back on empty StrBlob");
			data->pop_back();
		}

		StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
		StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

		ConstStrBlobPtr StrBlob::cbegin() const { return ConstStrBlobPtr(*this); }
		ConstStrBlobPtr StrBlob::cend() const { return ConstStrBlobPtr(*this, data->size()); }

		bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
			return *lhs.data == *rhs.data;
		}

		bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
			return *lhs.data < *rhs.data;
		}

		bool operator>(const StrBlob &lhs, const StrBlob &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const StrBlob &lhs, const StrBlob &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const StrBlob &lhs, const StrBlob &rhs) {
			return !(lhs < rhs);
		}

		std::shared_ptr<std::vector<std::string>>
		StrBlobPtr::check(std::size_t i, const std::string &msg) const {
			std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
			if (!ret)
				throw std::runtime_error("unbound StrBlobPtr");
			if (i >= ret->size())
				throw std::out_of_range(msg);
			return ret;
		}

		std::string &StrBlobPtr::deref() const {
			std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}

		StrBlobPtr &StrBlobPtr::incr() {
			check(curr, "increment past end of StrBlobPtr");
			++curr;
			return *this;
		}

		bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return lhs.wptr.lock() == rhs.wptr.lock() &&
					lhs.curr == rhs.curr;
		}

		bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("comparing two StrBlobPtrs that don't point to the same object");
			return lhs.curr < rhs.curr;
		}

		bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			return !(lhs < rhs);

		}

		std::string &StrBlobPtr::operator[](std::size_t n) {
			std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
			return (*p)[n];
		}

		const std::string &StrBlobPtr::operator[](std::size_t n) const {
			std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
			return (*p)[n];
		}

		// prefix operators
		StrBlobPtr &StrBlobPtr::operator++() {
			check(curr++, "increment past end of StrBlobPtr");
			return *this;
		}
		StrBlobPtr &StrBlobPtr::operator--() {
			check(--curr, "decrement past begin of StrBlobPtr");
			return *this;
		}

		// postfix operator
		StrBlobPtr StrBlobPtr::operator++(int) {
			StrBlobPtr ret = *this;
			++*this;
			return ret;
		}
		StrBlobPtr StrBlobPtr::operator--(int) {
			StrBlobPtr ret = *this;
			--*this;
			return ret;
		}

		StrBlobPtr operator+(const StrBlobPtr &p, std::size_t n) {
			StrBlobPtr ret = p;
			ret.curr += n;
			ret.check(ret.curr - 1, "incrementing past end of StrBlobPtr");
			return ret;
		}
		StrBlobPtr operator-(const StrBlobPtr &p, std::size_t n) {
			StrBlobPtr ret = p;
			ret.curr -= n;
			ret.check(ret.curr, "decrement past begin of StrBlobPtr");
			return ret;
		}
		std::ptrdiff_t operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("StrBlobPtrs don't refer to the same object");
			std::ptrdiff_t ret = lhs.curr;
			ret -= rhs.curr;
			return ret;
		}

		std::string &StrBlobPtr::operator*() const {
			std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}
		std::string *StrBlobPtr::operator->() const {
			return &this->operator*();
		}

		std::shared_ptr<std::vector<std::string>>
		ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const {
			std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
			if (!ret)
				throw std::runtime_error("unbound StrBlobPtr");
			if (i >= ret->size())
				throw std::out_of_range(msg);
			return ret;
		}

		const std::string &ConstStrBlobPtr::deref() const {
			std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}

		ConstStrBlobPtr &ConstStrBlobPtr::incr() {
			check(curr, "increment past end of StrBlobPtr");
			++curr;
			return *this;
		}

		bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return lhs.wptr.lock() == rhs.wptr.lock() &&
					lhs.curr == rhs.curr;
		}

		bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return !(lhs == rhs);
		}

		bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("comparing two ConstStrBlobPtrs that don't point to the same object");
			return lhs.curr < rhs.curr;
		}

		bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return rhs < lhs;
		}

		bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return !(lhs > rhs);
		}

		bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			return !(lhs < rhs);
		}

		std::string &ConstStrBlobPtr::operator[](std::size_t n) {
			std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
			return (*p)[n];
		}

		const std::string &ConstStrBlobPtr::operator[](std::size_t n) const {
			std::shared_ptr<std::vector<std::string>> p = check(n, "index out of range");
			return (*p)[n];
		}

		// prefix operators
		ConstStrBlobPtr &ConstStrBlobPtr::operator++() {
			check(curr++, "increment past end of ConstStrBlobPtr");
			return *this;
		}
		ConstStrBlobPtr &ConstStrBlobPtr::operator--() {
			check(--curr, "decrement past begin of ConstStrBlobPtr");
			return *this;
		}

		// postfix operators
		ConstStrBlobPtr ConstStrBlobPtr::operator++(int) {
			ConstStrBlobPtr ret = *this;
			++*this;
			return ret;
		}
		ConstStrBlobPtr ConstStrBlobPtr::operator--(int) {
			ConstStrBlobPtr ret = *this;
			--*this;
			return ret;
		}

		ConstStrBlobPtr operator+(const ConstStrBlobPtr &p, std::size_t n) {
			ConstStrBlobPtr ret = p;
			ret.curr += n;
			ret.check(ret.curr - 1, "incrementing past end of ConstStrBlobPtr");
			return ret;
		}
		ConstStrBlobPtr operator-(const ConstStrBlobPtr &p, std::size_t n) {
			ConstStrBlobPtr ret = p;
			ret.curr -= n;
			ret.check(ret.curr, "decrement past begin of ConstStrBlobPtr");
			return ret;
		}
		std::ptrdiff_t operator-(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
			if (lhs.wptr.lock() != rhs.wptr.lock())
				throw std::runtime_error("ConstStrBlobPtrs don't refer to the same object");
			std::ptrdiff_t ret = lhs.curr;
			ret -= rhs.curr;
			return ret;
		}

		const std::string &ConstStrBlobPtr::operator*() const {
			std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}
		const std::string *ConstStrBlobPtr::operator->() const {
			return &this->operator*();
		}

		StrBlobPtr &PtrToStrBlobPtr::operator*() const {
			return *p;
		}

		StrBlobPtr *PtrToStrBlobPtr::operator->() const {
			return &this->operator*();
		}
	}
	namespace _34 {
		int IfThenElse::operator()(bool b, int i, int j) const {
			return b ? i : j;
		}
	}
	namespace _35 {
		std::string ReadString::operator()() const {
			std::string line;
			std::getline(is, line);
			if (!is)
				return std::string();
			return line;
		}
	}
	namespace _36 {
		std::string ReadString::operator()() const {
			std::string line;
			std::getline(is, line);
			if (!is)
				return std::string();
			return line;
		}
	}
	namespace _37 {
		bool Equal::operator()(int i) const {
			return i == val;
		}
	}
	namespace _38 {
		bool Bound::operator()(const std::string &s) const {
			return s.size() <= max_length;
		}
	}
	namespace _39 {
		bool Bound::operator()(const std::string &s) const {
			return s.size() <= max_length;
		}
	}
	namespace _45 {
		Sales_data &Sales_data::combine(const Sales_data &rhs) {
			units_sold += rhs.units_sold;
			revenue += rhs.revenue;
			return *this;
		}

		// NONMEMBER FUNCTIONS

		Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data sum = lhs;
			sum.combine(rhs);
			return sum;
		}

		std::istream &read(std::istream &is, Sales_data &item) {
			double price = 0.0;
			is >> item.bookNo >> item.units_sold >> price;
			item.revenue = item.units_sold * price;
			return is;
		}

		std::ostream &print(std::ostream &os, const Sales_data &item) {
			os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
			return os;
		}

		std::ostream &operator<<(std::ostream &os, const Sales_data &item) {
			os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
			return os;
		}

		std::istream &operator>>(std::istream &is, Sales_data &item) {
			double price;
			is >> item.bookNo >> item.units_sold >> price;
			if (is)
				item.revenue = item.units_sold * price;
			else
				item = Sales_data();
			return is;
		}

		Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret += rhs;
			return ret;
		}
		Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold -= rhs.units_sold;
			ret.revenue -= rhs.revenue;
			return ret;
		}
		Sales_data operator*(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold *= rhs.units_sold;
			ret.revenue *= rhs.revenue;
			return ret;
		}
		Sales_data operator/(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold /= rhs.units_sold;
			ret.revenue /= rhs.revenue;
			return ret;
		}

		Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
			units_sold += rhs.units_sold;
			revenue += rhs.revenue;
			return *this;
		}

		Sales_data &Sales_data::operator=(const std::string &s) {
			bookNo = s;
			units_sold = 0;
			revenue = 0.0;
			return *this;
		}
	}
	namespace _49 {
		std::ostream &operator<<(std::ostream &os, const Employee &e) {
			os << e.name << " " << e.age << " " << e.rank;
			return os;
		}

		std::istream &operator>>(std::istream &is, Employee &e) {
			is >> e.name >> e.age >> e.rank;
			if (!is)
				e = Employee();
			return is;
		}

		Employee operator+(const Employee &lhs, unsigned rhs) {
			Employee ret = lhs;
			ret.age += rhs;
			return ret;
		}

		Employee operator+(const Employee &lhs, const Employee &rhs) {
			Employee ret = lhs;
			ret.age += rhs.age;
			return ret;
		}

		Employee operator-(const Employee &lhs, unsigned rhs) {
			Employee ret = lhs;
			ret.age -= rhs;
			return ret;
		}

		Employee operator-(const Employee &lhs, const Employee &rhs) {
			Employee ret = lhs;
			ret.age -= rhs.age;
			return ret;
		}

		bool operator==(const Employee &lhs, const Employee &rhs) {
			return lhs.name == rhs.name &&
					lhs.age == rhs.age &&
					lhs.rank == rhs.rank;
		}

		bool operator!=(const Employee &lhs, const Employee &rhs) {
			return !(lhs == rhs);
		}

		Employee &Employee::operator=(const Employee &e) {
			name = e.name;
			age = e.age;
			rank = e.rank;
			return *this;
		}

		Employee &Employee::operator=(Employee &&e) noexcept {
			name = std::move(e.name);
			age = std::move(e.age);
			rank = std::move(e.rank);
			return *this;
		}

		Employee &Employee::operator=(const std::initializer_list<std::string> &il) {
			if (il.size() != 3)
				throw std::runtime_error("invalid size of initializer_list");
			std::initializer_list<std::string>::const_iterator it = il.begin();
			name = *it++;
			age = std::stoul(*it++);
			rank = *it;
			return *this;
		}
	}
	}
}
