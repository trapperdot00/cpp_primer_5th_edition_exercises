#ifndef CHAPTER12_H
#define CHAPTER12_H

#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <memory>
#include <initializer_list>
#include <stdexcept>
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>

namespace cplusplus_primer {
	namespace chapter12 {
	namespace _02 {
		class StrBlob {
		public:
			typedef std::vector<std::string>::size_type size_type;
			
			StrBlob();
			StrBlob(std::initializer_list<std::string>);

			size_type size() const { return data->size(); }
			bool empty() const { return data->empty(); }
			
			void push_back(const std::string &s) { data->push_back(s); }
			void pop_back();
			
			std::string &front();
			std::string &back();
		private:
			std::shared_ptr<std::vector<std::string>> data;
			void check(size_type, const std::string &) const;
		};
	}

	namespace _19 {
		class StrBlobPtr;

		class StrBlob {
			friend class StrBlobPtr;
		public:
			typedef std::vector<std::string>::size_type size_type;
			
			StrBlob();
			StrBlob(std::initializer_list<std::string>);

			size_type size() const { return data->size(); }
			bool empty() const { return data->empty(); }
			
			void push_back(const std::string &s) { data->push_back(s); }
			void pop_back();
			
			std::string &front();
			std::string &back();

			StrBlobPtr begin();
			StrBlobPtr end();
		private:
			std::shared_ptr<std::vector<std::string>> data;
			void check(size_type, const std::string &) const;
		};

		class StrBlobPtr {
		public:
			StrBlobPtr() : curr(0) {}
			StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
			std::string &deref() const;
			StrBlobPtr &incr();
		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};
	}

	namespace _20 {
		class StrBlobPtr;

		class StrBlob {
			friend class StrBlobPtr;
		public:
			typedef std::vector<std::string>::size_type size_type;
			
			StrBlob();
			StrBlob(std::initializer_list<std::string>);

			size_type size() const { return data->size(); }
			bool empty() const { return data->empty(); }
			
			void push_back(const std::string &s) { data->push_back(s); }
			void pop_back();
			
			std::string &front();
			std::string &back();

			StrBlobPtr begin();
			StrBlobPtr end();
		private:
			std::shared_ptr<std::vector<std::string>> data;
			void check(size_type, const std::string &) const;
		};

		class StrBlobPtr {
		public:
			StrBlobPtr() : curr(0) {}
			StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
			std::string &deref() const;
			StrBlobPtr &incr();
		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};
	}

	namespace _22 {	
		class StrBlobPtr;
		class ConstStrBlobPtr;

		class StrBlob {
			friend class StrBlobPtr;
			friend class ConstStrBlobPtr;
		public:
			typedef std::vector<std::string>::size_type size_type;
			
			StrBlob();
			StrBlob(std::initializer_list<std::string>);

			size_type size() const { return data->size(); }
			bool empty() const { return data->empty(); }
			
			void push_back(const std::string &s) { data->push_back(s); }
			void pop_back();
			
			std::string &front();
			std::string &back();

			StrBlobPtr begin();
			StrBlobPtr end();

			ConstStrBlobPtr cbegin() const;
			ConstStrBlobPtr cend() const;
		private:
			std::shared_ptr<std::vector<std::string>> data;
			void check(size_type, const std::string &) const;
		};

		class StrBlobPtr {
		public:
			StrBlobPtr() : curr(0) {}
			StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
			std::string &deref() const;
			StrBlobPtr &incr();
		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};

		class ConstStrBlobPtr {
		public:
			ConstStrBlobPtr() : curr(0) {}
			ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
			const std::string &deref() const;
			ConstStrBlobPtr &incr();
		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};
	}
	namespace _27 {
		class QueryResult;
		class TextQuery {
		public:
			TextQuery(std::ifstream &);
			QueryResult query(const std::string &) const;
		private:
			std::vector<std::string> text;
			std::map<std::string, std::set<std::size_t>> word_lines;
		};

		class QueryResult {
			friend std::ostream &print(std::ostream &, const QueryResult &);
		public:
			QueryResult(std::string, std::set<std::size_t>, std::vector<std::string>);
		private:
			std::string toFind;
			std::set<std::size_t> lineNo;
			std::vector<std::string> textLines;
		};

		std::ostream &print(std::ostream &, const QueryResult &); 
	}

	namespace _30 {
		class QueryResult;

		class TextQuery {
		public:
			typedef std::vector<std::string>::size_type line_no;
			TextQuery(std::ifstream &in) : file(std::make_shared<std::vector<std::string>>()) {
				line_no line_num = 0;
				for (std::string line; std::getline(in, line); file->push_back(line), ++line_num) {
					std::string word;
					std::istringstream stream(line);
					while (stream >> word) {
						std::shared_ptr<std::set<line_no>> &lines = wm[word];
						if (!lines)
							lines.reset(new std::set<line_no>);
						lines->insert(line_num);
					}
				}
			}
			QueryResult query(const std::string &) const;
		private:
			std::shared_ptr<std::vector<std::string>> file;
			std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
		};

		class QueryResult {
		friend std::ostream &print(std::ostream &, const QueryResult &);
		public:
			typedef std::vector<std::string>::size_type line_no;
			QueryResult(const std::string &s, std::shared_ptr<std::set<line_no>> l, std::shared_ptr<std::vector<std::string>> f)
				: sought(s), line_nums(l), file(f) {}
		private:
			std::string sought;
			std::shared_ptr<std::set<line_no>> line_nums;
			std::shared_ptr<std::vector<std::string>> file;
		};
	}

	namespace _32 {
		class StrBlobPtr;
		class ConstStrBlobPtr;

		class StrBlob {
			friend class StrBlobPtr;
			friend class ConstStrBlobPtr;
		public:
			typedef std::vector<std::string>::size_type size_type;
			
			StrBlob();
			StrBlob(std::initializer_list<std::string>);

			size_type size() const { return data->size(); }
			bool empty() const { return data->empty(); }
			
			void push_back(const std::string &s) { data->push_back(s); }
			void pop_back();
			
			std::string &front();
			std::string &back();

			StrBlobPtr begin();
			StrBlobPtr end();

			ConstStrBlobPtr cbegin() const;
			ConstStrBlobPtr cend() const;
		private:
			std::shared_ptr<std::vector<std::string>> data;
			void check(size_type, const std::string &) const;
		};

		class StrBlobPtr {
		public:
			StrBlobPtr() : curr(0) {}
			StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
			std::string &deref() const;
			StrBlobPtr &incr();
		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};

		class ConstStrBlobPtr {
		public:
			ConstStrBlobPtr() : curr(0) {}
			ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
			const std::string &deref() const;
			ConstStrBlobPtr &incr();
		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};

		class QueryResult;

		class TextQuery {
		public:
			typedef StrBlob::size_type line_no;
			TextQuery(std::ifstream &in) : file(std::make_shared<StrBlob>()) {
				line_no line_num = 0;
				for (std::string line; std::getline(in, line); file->push_back(line), ++line_num) {
					std::string word;
					std::istringstream stream(line);
					while (stream >> word) {
						std::shared_ptr<std::set<line_no>> &lines = wm[word];
						if (!lines)
							lines.reset(new std::set<line_no>);
						lines->insert(line_num);
					}
				}
			}
			QueryResult query(const std::string &) const;
		private:
			std::shared_ptr<StrBlob> file;
			std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
		};

		class QueryResult {
		friend std::ostream &print(std::ostream &, const QueryResult &);
		public:
			typedef StrBlob::size_type line_no;
			QueryResult(const std::string &s, std::shared_ptr<std::set<line_no>> l, std::shared_ptr<StrBlob> f) : sought(s), line_nums(l), file(f) {}
		private:
			std::string sought;
			std::shared_ptr<std::set<line_no>> line_nums;
			std::shared_ptr<StrBlob> file;
		};
	}
	inline namespace _33 {
		class StrBlobPtr;
		class ConstStrBlobPtr;

		class StrBlob {
			friend class StrBlobPtr;
			friend class ConstStrBlobPtr;
		public:
			typedef std::vector<std::string>::size_type size_type;
			
			StrBlob();
			StrBlob(std::initializer_list<std::string>);

			size_type size() const { return data->size(); }
			bool empty() const { return data->empty(); }
			
			void push_back(const std::string &s) { data->push_back(s); }
			void pop_back();
			
			std::string &front();
			std::string &back();

			StrBlobPtr begin();
			StrBlobPtr end();

			ConstStrBlobPtr cbegin() const;
			ConstStrBlobPtr cend() const;
		private:
			std::shared_ptr<std::vector<std::string>> data;
			void check(size_type, const std::string &) const;
		};

		class StrBlobPtr {
		public:
			StrBlobPtr() : curr(0) {}
			StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
			std::string &deref() const;
			StrBlobPtr &incr();
		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};

		class ConstStrBlobPtr {
		public:
			ConstStrBlobPtr() : curr(0) {}
			ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
			const std::string &deref() const;
			ConstStrBlobPtr &incr();
		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};

		class QueryResult;

		class TextQuery {
		public:
			typedef StrBlob::size_type line_no;
			TextQuery(std::ifstream &in) : file(std::make_shared<StrBlob>()) {
				line_no line_num = 0;
				for (std::string line; std::getline(in, line); file->push_back(line), ++line_num) {
					std::string word;
					std::istringstream stream(line);
					while (stream >> word) {
						std::shared_ptr<std::set<line_no>> &lines = wm[word];
						if (!lines)
							lines.reset(new std::set<line_no>);
						lines->insert(line_num);
					}
				}
			}
			QueryResult query(const std::string &) const;
		private:
			std::shared_ptr<StrBlob> file;
			std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
		};

		class QueryResult {
		friend std::ostream &print(std::ostream &, const QueryResult &);
		public:
			typedef StrBlob::size_type line_no;
			QueryResult(const std::string &s, std::shared_ptr<std::set<line_no>> l, std::shared_ptr<StrBlob> f) : sought(s), line_nums(l), file(f) {}
			
			std::set<line_no>::iterator begin() { return line_nums->begin(); }
			std::set<line_no>::iterator end() { return line_nums->end(); }
			std::shared_ptr<StrBlob> get_file() const { return file; }
		private:
			std::string sought;
			std::shared_ptr<std::set<line_no>> line_nums;
			std::shared_ptr<StrBlob> file;
		};
	}
	}
}

#endif
