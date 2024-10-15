#include "chapter15.h"

namespace cplusplus_primer {
	namespace chapter15 {
	namespace _03 {
		double print_total(std::ostream &os, const Quote &item, std::size_t n) {
			double ret = item.net_price(n);
			os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
			return ret;
		}
	}
	namespace _05 {
		double print_total(std::ostream &os, const Quote &item, std::size_t n) {
			double ret = item.net_price(n);
			os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
			return ret;
		}

		Bulk_quote::Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
			Quote(book, p), min_qty(qty), discount(disc) {}

		double Bulk_quote::net_price(std::size_t cnt) const {
			if (cnt >= min_qty)
				return cnt * (1 - discount) * price;
			else
				return cnt * price;
		}
	}
	namespace _06 {
		double print_total(std::ostream &os, const Quote &item, std::size_t n) {
			double ret = item.net_price(n);
			os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
			return ret;
		}

		Bulk_quote::Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
			Quote(book, p), min_qty(qty), discount(disc) {}

		double Bulk_quote::net_price(std::size_t cnt) const {
			if (cnt >= min_qty)
				return cnt * (1 - discount) * price;
			else
				return cnt * price;
		}
	}
	namespace _07 {
		double print_total(std::ostream &os, const Quote &item, std::size_t n) {
			double ret = item.net_price(n);
			os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
			return ret;
		}

		Retail_quote::Retail_quote(const std::string &book, double p, std::size_t n, double disc) : 
			Quote(book, p), max_qty(n), discount(disc) {}

		double Retail_quote::net_price(std::size_t cnt) const {
			if (cnt <= max_qty)
				return cnt * (1 - discount) * price;
			else
				return cnt * price;
		}
	}
	namespace _11 {
		double print_total(std::ostream &os, const Quote &item, std::size_t n) {
			double ret = item.net_price(n);
			os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
			return ret;
		}

		std::ostream &Quote::debug(std::ostream &os) const {
			os << bookNo << ' ' << price;
			return os;
		}

		Bulk_quote::Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
			Quote(book, p), min_qty(qty), discount(disc) {}

		double Bulk_quote::net_price(std::size_t cnt) const {
			if (cnt >= min_qty)
				return cnt * (1 - discount) * price;
			else
				return cnt * price;
		}

		std::ostream &Bulk_quote::debug(std::ostream &os) const {
			Quote::debug(os) << ' ';
			os << min_qty << ' ' << discount;
			return os;
		}

		Retail_quote::Retail_quote(const std::string &book, double p, std::size_t n, double disc) : 
			Quote(book, p), max_qty(n), discount(disc) {}

		double Retail_quote::net_price(std::size_t cnt) const {
			if (cnt <= max_qty)
				return cnt * (1 - discount) * price;
			else
				return cnt * price;
		}

		std::ostream &Retail_quote::debug(std::ostream &os) const {
			Quote::debug(os) << ' ';
			os << max_qty << ' ' << discount;
			return os;
		}
	}
	namespace _15 {
		double print_total(std::ostream &os, const Quote &item, std::size_t n) {
			double ret = item.net_price(n);
			os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
			return ret;
		}

		std::ostream &Quote::debug(std::ostream &os) const {
			os << bookNo << ' ' << price;
			return os;
		}

		double Bulk_quote::net_price(std::size_t cnt) const {
			if (cnt >= quantity)
				return cnt * (1 - discount) * price;
			else
				return cnt * price;
		}
	}
	namespace _16 {
		double print_total(std::ostream &os, const Quote &item, std::size_t n) {
			double ret = item.net_price(n);
			os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
			return ret;
		}

		std::ostream &Quote::debug(std::ostream &os) const {
			os << bookNo << ' ' << price;
			return os;
		}

		double Retail_quote::net_price(std::size_t cnt) const {
			if (cnt <= quantity)
				return cnt * (1 - discount) * price;
			else
				return cnt * price;
		}
	}
	namespace _17 {
		double print_total(std::ostream &os, const Quote &item, std::size_t n) {
			double ret = item.net_price(n);
			os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
			return ret;
		}

		std::ostream &Quote::debug(std::ostream &os) const {
			os << bookNo << ' ' << price;
			return os;
		}
	}
	namespace _21 {
		std::ostream &printCenter(std::ostream &os, const Polygon &p) {
			os << p.centerPoint.first << ' ' << p.centerPoint.second;
			return os;
		}
	}
	namespace _26 {
		double print_total(std::ostream &os, const Quote &item, std::size_t n) {
			double ret = item.net_price(n);
			os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
			return ret;
		}

		std::ostream &Quote::debug(std::ostream &os) const {
			os << bookNo << ' ' << price;
			return os;
		}

		double Bulk_quote::net_price(std::size_t cnt) const {
			if (cnt >= quantity)
				return cnt * (1 - discount) * price;
			else
				return cnt * price;
		}
	}
	namespace _27 {
		double print_total(std::ostream &os, const Quote &item, std::size_t n) {
			double ret = item.net_price(n);
			os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
			return ret;
		}

		std::ostream &Quote::debug(std::ostream &os) const {
			os << bookNo << ' ' << price;
			return os;
		}

		double Bulk_quote::net_price(std::size_t cnt) const {
			if (cnt >= quantity)
				return cnt * (1 - discount) * price;
			else
				return cnt * price;
		}
	}
	namespace _28 {
		double print_total(std::ostream &os, const Quote &item, std::size_t n) {
			double ret = item.net_price(n);
			os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
			return ret;
		}

		std::ostream &Quote::debug(std::ostream &os) const {
			os << bookNo << ' ' << price;
			return os;
		}

		double Bulk_quote::net_price(std::size_t cnt) const {
			if (cnt >= quantity)
				return cnt * (1 - discount) * price;
			else
				return cnt * price;
		}
	}
	namespace _29 {
		double print_total(std::ostream &os, const Quote &item, std::size_t n) {
			double ret = item.net_price(n);
			os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
			return ret;
		}

		std::ostream &Quote::debug(std::ostream &os) const {
			os << bookNo << ' ' << price;
			return os;
		}

		double Bulk_quote::net_price(std::size_t cnt) const {
			if (cnt >= quantity)
				return cnt * (1 - discount) * price;
			else
				return cnt * price;
		}
	}
	namespace _30 {
		double print_total(std::ostream &os, const Quote &item, std::size_t n) {
			double ret = item.net_price(n);
			os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
			return ret;
		}

		std::ostream &Quote::debug(std::ostream &os) const {
			os << bookNo << ' ' << price;
			return os;
		}

		double Bulk_quote::net_price(std::size_t cnt) const {
			if (cnt >= quantity)
				return cnt * (1 - discount) * price;
			else
				return cnt * price;
		}

		double Basket::total_receipt(std::ostream &os) const {
			double sum = 0.0;
			for (std::multiset<std::shared_ptr<Quote>, decltype(compare)*>::const_iterator iter = items.cbegin(); 
					iter != items.cend();
					iter = items.upper_bound(*iter)) {
				sum += print_total(os, **iter, items.count(*iter));
			}
			os << "Total Sale: " << sum << std::endl;
			return sum;
		}
	}
	namespace _35 {
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
			static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
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
	}
	namespace _36 {
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
			static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
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
	}
	namespace _39 {
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
			static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
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
	namespace _41 {
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
			static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
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
	namespace _42 {
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
			static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
			std::map<std::string, std::shared_ptr<std::set<line_no>>>::const_iterator findIt = wm.find(s);
			if (findIt == wm.cend())
				return QueryResult(s, nodata, file);
			else
				return QueryResult(s, findIt->second, file);
		}

		// prints lines from beg_line inclusive to end_line exclusive
		std::ostream &print(std::ostream &os, const QueryResult &q, std::size_t beg_line, std::size_t end_line) {
			if (beg_line >= end_line) {
				throw std::runtime_error("Invalid range");		
			}

			std::size_t occurance = 0;
			std::ostringstream stream;
			for (auto it = q.line_nums->cbegin(); it != q.line_nums->cend() && *it < end_line - 1; ++it) {
				if (*it >= beg_line - 1) {
					auto num = *it;
					StrBlobPtr iter(*(q.file));
					for (QueryResult::line_no index = 0; index != num; ++index) {
						iter.incr();
					}
					++occurance;
					stream << "\t(line " << num + 1 << ") " << iter.deref() << std::endl;
				}
			}
			os << q.sought << " occurs " << occurance << " times from line "
			   << beg_line << " inclusive to line " << end_line << " exclusive\n";
			os << stream.str();
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
	}
}
