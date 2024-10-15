#include "chapter16.h"

namespace cplusplus_primer {
	namespace chapter16 {
	namespace _03 {
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
	namespace _22 {
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

		QueryResult TextQuery::query(const std::string &s) const  {
			static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>, DebugDelete());
			std::map<std::string, std::shared_ptr<std::set<line_no>>>::const_iterator findIt = wm.find(s);
			if (findIt == wm.cend())
				return QueryResult(s, nodata, file);
			else
				return QueryResult(s, findIt->second, file);
		}

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

		std::ostream &operator<<(std::ostream &os, const Query &query) {
			return os << query.rep();
		}

		QueryResult NotQuery::eval(const TextQuery &text) const {
			QueryResult result = query.eval(text);
			std::shared_ptr<std::set<line_no>> ret_lines = std::make_shared<std::set<line_no>>();
			std::set<line_no>::iterator beg = result.begin(), end = result.end();
			std::size_t sz = result.get_file()->size();
			for (std::size_t n = 0; n != sz; ++n) {
				if (beg == end || *beg != n)
					ret_lines->insert(n);
				else if (beg != end)
					++beg;
			}
			return QueryResult(rep(), ret_lines, result.get_file());
		}

		QueryResult AndQuery::eval(const TextQuery &text) const {
			QueryResult left = lhs.eval(text), right = rhs.eval(text);
			std::shared_ptr<std::set<line_no>> ret_lines = std::make_shared<std::set<line_no>>();
			std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*ret_lines, ret_lines->begin()));
			return QueryResult(rep(), ret_lines, left.get_file());
		}

		QueryResult OrQuery::eval(const TextQuery &text) const {
			QueryResult left = lhs.eval(text), right = rhs.eval(text);
			std::shared_ptr<std::set<line_no>> ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
			ret_lines->insert(right.begin(), right.end());
			return QueryResult(rep(), ret_lines, left.get_file());
		}
	}
	namespace _48 {
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
	}
	namespace _56 {
		std::string debug_rep(const std::string &s) {
			return '"' + s + '"';
		}

		std::string debug_rep(char *c) {
			return debug_rep(std::string(c));
		}

		std::string debug_rep(const char *c) {
			return debug_rep(std::string(c));
		}
	}
	namespace _58 {
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
	namespace _62 {
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

		bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
			return lhs.bookNo == rhs.bookNo &&
				   lhs.units_sold == rhs.units_sold &&
				   lhs.revenue == rhs.revenue;
		}

		bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
			return !(lhs == rhs);
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
	namespace _64 {
		template <>
		std::size_t count_val(const std::vector<const char *> &vec, const char * const val) {
			std::size_t occurence = 0;
			for (const char * const &p : vec)
				if (std::strcmp(p, val) == 0) ++occurence;
			return occurence;
		}
	}
	namespace _65 {
		std::string debug_rep(const std::string &s) {
			return '"' + s + '"';
		}

		template <>
		std::string debug_rep(char *c) {
			return debug_rep(std::string(c));
		}

		template <>
		std::string debug_rep(const char *c) {
			return debug_rep(std::string(c));
		}
	}
	}
}
