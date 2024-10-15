#ifndef CHAPTER13_H
#define CHAPTER13_H

#include <string>
#include <iostream>
#include <cstddef>
#include <vector>
#include <memory>
#include <initializer_list>
#include <stdexcept>
#include <set>
#include <utility>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <iterator>

namespace cplusplus_primer {
	namespace chapter13 {
	namespace _05 {
		class HasPtr {
		public:
			HasPtr(const std::string &s = std::string()):
				ps(new std::string(s)), i(0) { }

			HasPtr(const HasPtr& orig) : ps(new std::string(*orig.ps)), i(orig.i) {}
			
			void nullStr() {
				delete ps;
				ps = nullptr;
			}
			const std::string& get() const {
				static std::string empty;
				return ps ? *ps : empty;
			}

		private:
			std::string *ps;
			int i;
		};
	}
	namespace _08 {
		class HasPtr {
		public:
			HasPtr(const std::string &s = std::string()):
				ps(new std::string(s)), i(0) { }

			// COPY CONSTRUCTOR
			HasPtr(const HasPtr& orig) : ps(new std::string(*orig.ps)), i(orig.i) {}
			
			// COPY-ASSIGNMENT OPERATOR
			HasPtr &operator=(const HasPtr &rhs) {
				delete ps;
				ps = new std::string(*rhs.ps);
				i = rhs.i;
				return *this;
			}

			void nullStr() {
				delete ps;
				ps = nullptr;
			}
			const std::string& get() const {
				static std::string empty;
				return ps ? *ps : empty;
			}

		private:
			std::string *ps;
			int i;
		};
	}
	namespace _11 {
		class HasPtr {
		public:
			HasPtr(const std::string &s = std::string()):
				ps(new std::string(s)), i(0) { }

			// COPY CONSTRUCTOR
			HasPtr(const HasPtr& orig) : ps(new std::string(*orig.ps)), i(orig.i) {}
			
			// COPY-ASSIGNMENT OPERATOR
			HasPtr &operator=(const HasPtr &rhs) {
				delete ps;
				ps = new std::string(*rhs.ps);
				i = rhs.i;
				return *this;
			}
			
			// DESTRUCTOR
			~HasPtr() {
				delete ps;
			}

			void nullStr() {
				delete ps;
				ps = nullptr;
			}
			const std::string& get() const {
				static std::string empty;
				return ps ? *ps : empty;
			}

		private:
			std::string *ps;
			int i;
		};
	}
	namespace _13 {
		struct X{
			// DEFAULT CONSTRUCTOR
			X() { std::cout << "X()" << std::endl; }
			
			// COPY CONSTRUCTOR
			X(const X&) { std::cout << "X(const X&)" << std::endl; }
			
			// COPY-ASSIGNMENT OPERATOR
			X& operator=(const X&) { std::cout << "X& operator=(const X&)" << std::endl; return *this; }

			// DESTRUCTOR
			~X() { std::cout << "~X()" << std::endl; }
		};
	}
	namespace _18 {
		class Employee {
			friend std::ostream &print(std::ostream &, const Employee &);
			static std::size_t currentID;
		public:
			Employee();
			Employee(const std::string &);
		private:
			std::string name;
			std::size_t id;
		};
	}
	namespace _19 {
		class Employee {
			friend std::ostream &print(std::ostream &, const Employee &);

			static std::size_t currentID;
		public:
			Employee();
			Employee(const std::string &);

			Employee(const Employee &);
			Employee &operator=(const Employee &);
		private:
			std::string name;
			std::size_t id;
		};
	}
	namespace _26 {
		class StrBlobPtr;
		class ConstStrBlobPtr;

		class StrBlob {
			friend class StrBlobPtr;
			friend class ConstStrBlobPtr;
		public:
			typedef std::vector<std::string>::size_type size_type;
			
			StrBlob();
			StrBlob(std::initializer_list<std::string>);

			StrBlob(const StrBlob &);
			StrBlob &operator=(const StrBlob &);
			
			size_type size() const { return data->size(); }
			bool empty() const { return data->empty(); }

			void push_back(const std::string &t) { data->push_back(t); }
			void pop_back();

			std::string &front();
			const std::string &front() const;
			std::string &back();
			const std::string &back() const;

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
			StrBlobPtr();
			StrBlobPtr(StrBlob &, std::size_t = 0);

			std::string &deref() const;
			StrBlobPtr &incr();

		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;

			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};

		class ConstStrBlobPtr {
		public:
			ConstStrBlobPtr();
			ConstStrBlobPtr(const StrBlob &, std::size_t = 0);

			const std::string &deref() const;
			ConstStrBlobPtr &incr();

		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;

			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};
	}
	namespace _27 {
		class HasPtr {
		public:
			HasPtr(const std::string & = std::string());
			HasPtr(const HasPtr &);
			HasPtr &operator=(const HasPtr &);
			~HasPtr();

			std::size_t use_count() const { return *use; }

		private:
			std::string *ps;
			int i;
			std::size_t *use;
		};
	}
	namespace _28 {
		class TreeNode {
		public:
			TreeNode();
			TreeNode(const TreeNode &);
			TreeNode &operator=(const TreeNode &);
			~TreeNode();

			int use_count() const { return *count; }
		private:
			std::string value;
			int *count;
			TreeNode *left;
			TreeNode *right;
		};

		class BinStrTree {
		public:
			BinStrTree();
			BinStrTree(const BinStrTree &);
			BinStrTree &operator=(const BinStrTree &);
			~BinStrTree();

		private:
			TreeNode *root;
		};
	}
	namespace _30 {
		class HasPtr {
			friend void swap(HasPtr &, HasPtr &);
		public:
			HasPtr(const std::string & = std::string());
			HasPtr(const HasPtr &);
			HasPtr &operator=(HasPtr);
			~HasPtr();
		private:
			std::string *ps;
			int i;
		};

		inline void swap(HasPtr &lhs, HasPtr &rhs) {
			std::cout << "swap(HasPtr &, HasPtr &);" << std::endl;
			using std::swap;
			swap(lhs.ps, rhs.ps);
			swap(lhs.i, rhs.i);
		}
	}
	namespace _31 {
		class HasPtr {
			friend void swap(HasPtr &, HasPtr &);
			friend std::ostream &print(std::ostream &, const HasPtr &);
		public:
			HasPtr(const std::string & = std::string());
			HasPtr(const HasPtr &);
			HasPtr &operator=(HasPtr);
			~HasPtr();

			bool operator<(const HasPtr &rhs) const { return *ps < *rhs.ps; }
		private:
			std::string *ps;
			int i;
		};

		inline void swap(HasPtr &lhs, HasPtr &rhs) {
			std::cout << "swapping " << *lhs.ps << " and " << *rhs.ps << std::endl;
			using std::swap;
			swap(lhs.ps, rhs.ps);
			swap(lhs.i, rhs.i);
		}
	}
	namespace _37 {
		class Folder;

		class Message {
			friend class Folder;
			friend void swap(Message &, Message &);
			friend std::ostream &print(std::ostream &, const Folder &);
		public:
			explicit Message(const std::string &str = "") : contents(str) {}
			Message(const Message &);
			Message &operator=(const Message &);
			~Message();

			void save(Folder &);
			void remove(Folder &);
			
			void addFld(Folder *);
			void remFld(Folder *);
		private:
			std::string contents;
			std::set<Folder *> folders;

			void add_to_Folders(const Message &);
			void remove_from_Folders();


		};

		class Folder {
			friend class Message;
			friend void swap(Folder &, Folder &);
			friend std::ostream &print(std::ostream &, const Folder &);
		public:
			explicit Folder(const std::string &str = "") : name(str) {}
			Folder(const Folder &);
			Folder &operator=(const Folder &);
			~Folder();

			void addMsg(Message *);
			void remMsg(Message *);

		private:
			std::string name;
			std::set<Message *> messages;

			void add_to_Messages(const Folder &);
			void remove_from_Messages();
		};
	}
	namespace _39 {
		class StrVec {
		public:
			StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
			StrVec(const StrVec &);
			StrVec &operator=(const StrVec &);
			~StrVec();

			void push_back(const std::string &);

			std::string *begin() const { return elements; }
			std::string *end() const { return first_free; }

			std::size_t size() const { return first_free - elements; }
			std::size_t capacity() const { return cap - elements; }

			// allocate space for at least n elements
			void reserve(std::size_t);
			// resize so that it has n elements. if n < size(), the excess elements are discarded
			// if new elements must be added, they are value initialized
			void resize(std::size_t);
			// resize to have n elements. any elements added have value s
			void resize(std::size_t, const std::string &);

		private:

			std::allocator<std::string> alloc;
			void chk_n_alloc()
				{ if (size() == capacity()) reallocate(); }
			std::pair<std::string *, std::string *> alloc_n_copy
					(const std::string *, const std::string *);
			void free();
			void reallocate();

			std::string *elements;
			std::string *first_free;
			std::string *cap;
		};
	}
	namespace _40 {
		class StrVec {
		public:
			StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
			StrVec(const std::initializer_list<std::string> &);
			StrVec(const StrVec &);
			StrVec &operator=(const StrVec &);
			~StrVec();

			void push_back(const std::string &);

			std::string *begin() const { return elements; }
			std::string *end() const { return first_free; }

			std::size_t size() const { return first_free - elements; }
			std::size_t capacity() const { return cap - elements; }

			// allocate space for at least n elements
			void reserve(std::size_t);
			// resize so that it has n elements. if n < size(), the excess elements are discarded
			// if new elements must be added, they are value initialized
			void resize(std::size_t);
			// resize to have n elements. any elements added have value s
			void resize(std::size_t, const std::string &);

		private:

			std::allocator<std::string> alloc;
			void chk_n_alloc()
				{ if (size() == capacity()) reallocate(); }
			std::pair<std::string *, std::string *> alloc_n_copy
					(const std::string *, const std::string *);
			void free();
			void reallocate();

			std::string *elements;
			std::string *first_free;
			std::string *cap;
		};
	}
	namespace _42 {
		class StrVec {
		public:
			StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
			StrVec(const std::initializer_list<std::string> &);
			StrVec(const StrVec &);
			StrVec &operator=(const StrVec &);
			~StrVec();

			void push_back(const std::string &);

			std::string *begin() const { return elements; }
			std::string *end() const { return first_free; }

			std::size_t size() const { return first_free - elements; }
			std::size_t capacity() const { return cap - elements; }

			// allocate space for at least n elements
			void reserve(std::size_t);
			// resize so that it has n elements. if n < size(), the excess elements are discarded
			// if new elements must be added, they are value initialized
			void resize(std::size_t);
			// resize to have n elements. any elements added have value s
			void resize(std::size_t, const std::string &);

		private:

			std::allocator<std::string> alloc;
			void chk_n_alloc()
				{ if (size() == capacity()) reallocate(); }
			std::pair<std::string *, std::string *> alloc_n_copy
					(const std::string *, const std::string *);
			void free();
			void reallocate();

			std::string *elements;
			std::string *first_free;
			std::string *cap;
		};

		class QueryResult;

		class TextQuery {
		public:
			TextQuery(std::ifstream &);
			
			QueryResult query(const std::string &) const;

		private:
			std::shared_ptr<StrVec> text;
			std::map<std::string, std::shared_ptr<std::set<std::size_t>>> wordLines;
		};

		class QueryResult {
			friend std::ostream &print(std::ostream &, const QueryResult &);
		public:
			QueryResult(const std::string &, const std::shared_ptr<StrVec> &, const std::shared_ptr<std::set<std::size_t>> &);
		private:
			std::string sought;
			std::shared_ptr<StrVec> text;
			std::shared_ptr<std::set<std::size_t>> lineNums;
		};
	}
	namespace _43 {
		class StrVec {
		public:
			StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
			StrVec(const std::initializer_list<std::string> &);
			StrVec(const StrVec &);
			StrVec &operator=(const StrVec &);
			~StrVec();

			void push_back(const std::string &);

			std::string *begin() const { return elements; }
			std::string *end() const { return first_free; }

			std::size_t size() const { return first_free - elements; }
			std::size_t capacity() const { return cap - elements; }

			// allocate space for at least n elements
			void reserve(std::size_t);
			// resize so that it has n elements. if n < size(), the excess elements are discarded
			// if new elements must be added, they are value initialized
			void resize(std::size_t);
			// resize to have n elements. any elements added have value s
			void resize(std::size_t, const std::string &);

		private:

			std::allocator<std::string> alloc;
			void chk_n_alloc()
				{ if (size() == capacity()) reallocate(); }
			std::pair<std::string *, std::string *> alloc_n_copy
					(const std::string *, const std::string *);
			void free();
			void reallocate();

			std::string *elements;
			std::string *first_free;
			std::string *cap;
		};
	}
	namespace _44 {
		class String {

			friend std::ostream &print(std::ostream &, const String &);	
		public:
			String();
			String(const char *);
			String(const String &);
			String &operator=(const String &);
			~String();

			void push_back(char);

			std::size_t size() const { return first_free - elements; }
			std::size_t capacity() const { return cap - elements; }
			char *begin() { return elements; }
			const char *cbegin() const { return elements; }
			char *end() { return first_free; }
			const char *cend() const { return first_free; }
		private:
			static std::allocator<char> alloc;
			
			void reallocate();
			std::pair<char *, char *> exact_alloc_copy(const char *, const char *) const;
			void check_full_realloc() { if (size() == capacity()) reallocate(); }
			void free() const;


			char *elements;
			char *first_free;
			char *cap;
		};
	}
	namespace _47 {
		class String {

			friend std::ostream &print(std::ostream &, const String &);	
		public:
			String();
			String(const char *);
			String(const String &);
			String &operator=(const String &);
			~String();

			void push_back(char);

			std::size_t size() const { return first_free - elements; }
			std::size_t capacity() const { return cap - elements; }
			char *begin() { return elements; }
			const char *cbegin() const { return elements; }
			char *end() { return first_free; }
			const char *cend() const { return first_free; }
		private:
			static std::allocator<char> alloc;
			
			void reallocate();
			std::pair<char *, char *> exact_alloc_copy(const char *, const char *) const;
			void check_full_realloc() { if (size() == capacity()) reallocate(); }
			void free() const;


			char *elements;
			char *first_free;
			char *cap;
		};
	}
	namespace _48 {
		class String {

			friend std::ostream &print(std::ostream &, const String &);	
		public:
			String();
			String(const char *);
			String(const String &);
			String &operator=(const String &);
			~String();

			void push_back(char);

			std::size_t size() const { return first_free - elements; }
			std::size_t capacity() const { return cap - elements; }
			char *begin() { return elements; }
			const char *cbegin() const { return elements; }
			char *end() { return first_free; }
			const char *cend() const { return first_free; }
		private:
			static std::allocator<char> alloc;
			
			void reallocate();
			std::pair<char *, char *> exact_alloc_copy(const char *, const char *) const;
			void check_full_realloc() { if (size() == capacity()) reallocate(); }
			void free() const;


			char *elements;
			char *first_free;
			char *cap;
		};
	}
	namespace _49 {
		class String {
			friend std::ostream &print(std::ostream &, const String &);	
		public:
			String();
			String(const char *);
			String(const String &);
			String(String &&) noexcept;					// move constructor
			String &operator=(const String &);
			String &operator=(String &&) noexcept;		// move-assignment operator
			~String();

			void push_back(char);

			std::size_t size() const { return first_free - elements; }
			std::size_t capacity() const { return cap - elements; }
			char *begin() { return elements; }
			const char *cbegin() const { return elements; }
			char *end() { return first_free; }
			const char *cend() const { return first_free; }
		private:
			static std::allocator<char> alloc;
			
			void reallocate();
			std::pair<char *, char *> exact_alloc_copy(const char *, const char *) const;
			void check_full_realloc() { if (size() == capacity()) reallocate(); }
			void free() const;


			char *elements;
			char *first_free;
			char *cap;
		};

		class StrVec {
		public:
			StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
			StrVec(const std::initializer_list<std::string> &);
			StrVec(const StrVec &);
			StrVec(StrVec &&) noexcept;					// move constructor
			StrVec &operator=(const StrVec &);
			StrVec &operator=(StrVec &&) noexcept;		// move-assignment operator
			~StrVec();

			void push_back(const std::string &);

			std::string *begin() const { return elements; }
			std::string *end() const { return first_free; }

			std::size_t size() const { return first_free - elements; }
			std::size_t capacity() const { return cap - elements; }

			// allocate space for at least n elements
			void reserve(std::size_t);
			// resize so that it has n elements. if n < size(), the excess elements are discarded
			// if new elements must be added, they are value initialized
			void resize(std::size_t);
			// resize to have n elements. any elements added have value s
			void resize(std::size_t, const std::string &);

		private:
			std::allocator<std::string> alloc;
			void chk_n_alloc()
				{ if (size() == capacity()) reallocate(); }
			std::pair<std::string *, std::string *> alloc_n_copy
					(const std::string *, const std::string *);
			void free();
			void reallocate();

			std::string *elements;
			std::string *first_free;
			std::string *cap;
		};

		class Folder;

		class Message {
			friend class Folder;
			friend void swap(Message &, Message &);
			friend std::ostream &print(std::ostream &, const Folder &);
		public:
			explicit Message(const std::string &str = "") : contents(str) {}
			Message(const Message &);
			Message(Message &&);					// move constructor
			Message &operator=(const Message &);
			Message &operator=(Message &&);			// move-assignment operator
			~Message();

			void save(Folder &);
			void remove(Folder &);
			
			void addFld(Folder *);
			void remFld(Folder *);
		private:
			std::string contents;
			std::set<Folder *> folders;

			void add_to_Folders(const Message &);
			void remove_from_Folders();
			void move_Folders(Message *);

		};

		class Folder {
			friend class Message;
			friend void swap(Folder &, Folder &);
			friend std::ostream &print(std::ostream &, const Folder &);
		public:
			explicit Folder(const std::string &str = "") : name(str) {}
			Folder(const Folder &);
			Folder &operator=(const Folder &);
			~Folder();

			void addMsg(Message *);
			void remMsg(Message *);

		private:
			std::string name;
			std::set<Message *> messages;

			void add_to_Messages(const Folder &);
			void remove_from_Messages();
		};
	}
	namespace _50 {
		class String {
			friend std::ostream &print(std::ostream &, const String &);	
		public:
			String();
			String(const char *);
			String(const String &);
			String(String &&) noexcept;					// move constructor
			String &operator=(const String &);
			String &operator=(String &&) noexcept;		// move-assignment operator
			~String();

			void push_back(char);

			std::size_t size() const { return first_free - elements; }
			std::size_t capacity() const { return cap - elements; }
			char *begin() { return elements; }
			const char *cbegin() const { return elements; }
			char *end() { return first_free; }
			const char *cend() const { return first_free; }
		private:
			static std::allocator<char> alloc;
			
			void reallocate();
			std::pair<char *, char *> exact_alloc_copy(const char *, const char *) const;
			void check_full_realloc() { if (size() == capacity()) reallocate(); }
			void free() const;


			char *elements;
			char *first_free;
			char *cap;
		};
	}
	namespace _53 {
		class HasPtr {
			friend void swap(HasPtr &, HasPtr &);
			friend std::ostream &print(std::ostream &, const HasPtr &);
		public:
			HasPtr(const std::string & = std::string());
			HasPtr(const HasPtr &);
			HasPtr(HasPtr &&) noexcept;
			HasPtr &operator=(const HasPtr &);
			HasPtr &operator=(HasPtr &&) noexcept;
			~HasPtr();

			bool operator<(const HasPtr &rhs) const { return *ps < *rhs.ps; }
		private:
			std::string *ps;
			int i;
		};

		inline void swap(HasPtr &lhs, HasPtr &rhs) {
			std::cout << "swapping " << *lhs.ps << " and " << *rhs.ps << std::endl;
			using std::swap;
			swap(lhs.ps, rhs.ps);
			swap(lhs.i, rhs.i);
		}
	}
	namespace _54 {
		class HasPtr {
			friend void swap(HasPtr &, HasPtr &);
			friend std::ostream &print(std::ostream &, const HasPtr &);
		public:
			HasPtr(const std::string & = std::string());
			HasPtr(const HasPtr &);
			HasPtr(HasPtr &&) noexcept;
			HasPtr &operator=(HasPtr);
			HasPtr &operator=(HasPtr &&) noexcept;
			~HasPtr();

			bool operator<(const HasPtr &rhs) const { return *ps < *rhs.ps; }
		private:
			std::string *ps;
			int i;
		};

		inline void swap(HasPtr &lhs, HasPtr &rhs) {
			std::cout << "swapping " << *lhs.ps << " and " << *rhs.ps << std::endl;
			using std::swap;
			swap(lhs.ps, rhs.ps);
			swap(lhs.i, rhs.i);
		}
	}
	namespace _55 {
		class StrBlobPtr;
		class ConstStrBlobPtr;

		class StrBlob {
			friend class StrBlobPtr;
			friend class ConstStrBlobPtr;
		public:
			typedef std::vector<std::string>::size_type size_type;
			
			StrBlob();
			StrBlob(std::initializer_list<std::string>);

			StrBlob(const StrBlob &);
			StrBlob &operator=(const StrBlob &);
			
			size_type size() const { return data->size(); }
			bool empty() const { return data->empty(); }

			void push_back(const std::string &t)
				{ data->push_back(t); }
			void push_back(std::string &&t)
				{ data->push_back(std::move(t)); }
			void pop_back();

			std::string &front();
			const std::string &front() const;
			std::string &back();
			const std::string &back() const;

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
			StrBlobPtr();
			StrBlobPtr(StrBlob &, std::size_t = 0);

			std::string &deref() const;
			StrBlobPtr &incr();

		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;

			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};

		class ConstStrBlobPtr {
		public:
			ConstStrBlobPtr();
			ConstStrBlobPtr(const StrBlob &, std::size_t = 0);

			const std::string &deref() const;
			ConstStrBlobPtr &incr();

		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;

			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};
	}
	namespace _58 {
		class Foo {
		public:
			Foo(const Foo &);
			Foo &operator=(const Foo &) &;
			Foo &operator=(Foo &&) &;

			Foo sorted() &&;
			Foo sorted() const &;

		private:
			std::vector<int> data;
		};
	}
	}
}

#endif
