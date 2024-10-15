#include "chapter12.h"

namespace cplusplus_primer {
	namespace chapter12 {
	namespace _02 {
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
	}
	namespace _19 {
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
	}
	namespace _20 {
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
	}
	namespace _27 {
		TextQuery::TextQuery(std::ifstream &input) {
			std::size_t lineNo = 1;
			for (std::string line; std::getline(input, line); text.push_back(line)) {
				std::istringstream stream(line);
				std::string word;
				while (stream >> word) {
					std::set<std::size_t> &lineSet = word_lines[word];
					lineSet.insert(lineNo);
				}
				++lineNo;
			}
		}

		QueryResult::QueryResult(std::string s, std::set<std::size_t> n, std::vector<std::string> t) : toFind(s), lineNo(n), textLines(t) {}

		QueryResult TextQuery::query(const std::string &s) const {
			if (word_lines.find(s) == word_lines.end()) {
				return QueryResult(s, std::set<std::size_t>(), text);
			}
			return QueryResult(s, word_lines.find(s)->second, text);
		}

		std::ostream &print(std::ostream &os, const QueryResult &q) {
			std::size_t occurs = q.lineNo.size();
			os << q.toFind << " occurs " << occurs << " times\n";
			std::size_t currOcc = 0, currLine = 1;
			while (currOcc != occurs) {
				std::string line = q.textLines[currLine-1];
				if (line.find(q.toFind) != std::string::npos) {
					os << "   (line " << currLine << ") " << line << std::endl;
					++currOcc;
				}
				++currLine;
			}
			return os;
		}
	}
	namespace _30 {
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
			for (QueryResult::line_no num : *q.line_nums) {
				os << "\t(line " << num + 1 << ") " << *(q.file->begin() + num) << std::endl;
			}
			return os;
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
	}
	inline namespace _33 {
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
	}
	}
}
