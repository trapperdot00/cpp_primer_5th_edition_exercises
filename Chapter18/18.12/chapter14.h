#ifndef CHAPTER14_H
#define CHAPTER14_H

#include <string>
#include <iostream>
#include <memory>
#include <cstddef>
#include <utility>
#include <cstring>
#include <iterator>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <stdexcept>


namespace cplusplus_primer {
	namespace chapter14 {
	namespace _02 {
		class Sales_data;
			std::istream &read(std::istream&, Sales_data&);

		class Sales_data {
		public:
			friend std::istream &read(std::istream&, Sales_data&);
			friend std::ostream &print(std::ostream&, const Sales_data&);
			friend Sales_data add(const Sales_data&, const Sales_data&);

			Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {
				//std::cout << "mainConstructor" << std::endl;
			}
			Sales_data() : Sales_data("", 0, 0) {
				//std::cout << "empty" << std::endl;	
			}
			Sales_data(const std::string &s) : Sales_data(s, 0, 0) {
				//std::cout << "string" << std::endl;
			}
			Sales_data(std::istream &is) : Sales_data() {
				read(is, *this);
				//std::cout << "istream" << std::endl;
			}

			Sales_data &combine(const Sales_data&);
			std::string isbn() const { return bookNo; }
			
			Sales_data &operator+=(const Sales_data &);		// compound-assignment

		private:
			double avg_price() const;
			std::string bookNo;
			unsigned units_sold = 0;
			double revenue = 0.0;
		};

		std::istream &operator>>(std::istream &, Sales_data &);			// input operator
		std::ostream &operator<<(std::ostream &, const Sales_data &);	// output operator
		Sales_data operator+(Sales_data, Sales_data);					// addition operator

		Sales_data add(const Sales_data&, const Sales_data&);
		std::ostream &print(std::ostream&, const Sales_data&);


		// inline and constexpr functions should be defined in the class headers
		inline
		double Sales_data::avg_price() const {
			return units_sold ? revenue / units_sold : 0;
		}
	}
	namespace _05 {
		class Employee {
		public:
			Employee(const std::string &n) : name(n) {}
			Employee(const std::string &n, unsigned a) : name(n), age(a) {}

			Employee operator++();	// increment employee's age by one
			Employee operator--();	// decrement employee's age by one
			Employee &operator+=(unsigned);	// change employee's age
			Employee &operator-=(unsigned);	// change employee's age
		private:
			std::string name;
			unsigned age;
			std::string rank;
		};

		Employee operator+(Employee, unsigned);		// add to employee's age
		Employee operator-(Employee, unsigned);		// subtract from employee's age

		bool operator==(const Employee &, const Employee &);	// check for equality in each member ANDed
		bool operator!=(const Employee &, const Employee &);	// check for inequality in each member ANDed
	}
	namespace _06 {
		class Sales_data;
			std::istream &read(std::istream&, Sales_data&);

		class Sales_data {
		public:
			friend std::istream &read(std::istream&, Sales_data&);
			friend std::ostream &print(std::ostream&, const Sales_data&);
			friend Sales_data add(const Sales_data&, const Sales_data&);
			friend std::ostream &operator<<(std::ostream &, const Sales_data &);

			Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {
				//std::cout << "mainConstructor" << std::endl;
			}
			Sales_data() : Sales_data("", 0, 0) {
				//std::cout << "empty" << std::endl;	
			}
			Sales_data(const std::string &s) : Sales_data(s, 0, 0) {
				//std::cout << "string" << std::endl;
			}
			Sales_data(std::istream &is) : Sales_data() {
				read(is, *this);
				//std::cout << "istream" << std::endl;
			}

			Sales_data &combine(const Sales_data&);
			std::string isbn() const { return bookNo; }
			
			Sales_data &operator+=(const Sales_data &);		// compound-assignment

		private:
			double avg_price() const;
			std::string bookNo;
			unsigned units_sold = 0;
			double revenue = 0.0;
		};

		std::istream &operator>>(std::istream &, Sales_data &);			// input operator
		std::ostream &operator<<(std::ostream &, const Sales_data &);	// output operator
		Sales_data operator+(Sales_data, Sales_data);					// addition operator

		Sales_data add(const Sales_data&, const Sales_data&);
		std::ostream &print(std::ostream&, const Sales_data&);



		// inline and constexpr functions should be defined in the class headers
		inline
		double Sales_data::avg_price() const {
			return units_sold ? revenue / units_sold : 0;
		}
	}
	namespace _07 {
		class String {

			friend std::ostream &print(std::ostream &, const String &);	
			friend std::ostream &operator<<(std::ostream &, const String &);
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

		std::ostream &operator<<(std::ostream &, const String &);
	}
	namespace _08 {
		class Employee {
			friend std::ostream &operator<<(std::ostream &, const Employee &);
		public:
			Employee(const std::string &n) : name(n) {}
			Employee(const std::string &n, unsigned a) : name(n), age(a) {}

			Employee operator++();	// increment employee's age by one
			Employee operator--();	// decrement employee's age by one
			Employee &operator+=(unsigned);	// change employee's age
			Employee &operator-=(unsigned);	// change employee's age
		private:
			std::string name;
			unsigned age;
			std::string rank;
		};

		Employee operator+(Employee, unsigned);		// add to employee's age
		Employee operator-(Employee, unsigned);		// subtract from employee's age

		bool operator==(const Employee &, const Employee &);	// check for equality in each member ANDed
		bool operator!=(const Employee &, const Employee &);	// check for inequality in each member ANDed

		std::ostream &operator<<(std::ostream &, const Employee &);
	}
	namespace _09 {
		class Sales_data;
			std::istream &read(std::istream&, Sales_data&);

		class Sales_data {
		public:
			friend std::istream &read(std::istream&, Sales_data&);
			friend std::ostream &print(std::ostream&, const Sales_data&);
			friend Sales_data add(const Sales_data&, const Sales_data&);
			
			friend std::ostream &operator<<(std::ostream &, const Sales_data &);
			friend std::istream &operator>>(std::istream &, Sales_data &);

			Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {
				//std::cout << "mainConstructor" << std::endl;
			}
			Sales_data() : Sales_data("", 0, 0) {
				//std::cout << "empty" << std::endl;	
			}
			Sales_data(const std::string &s) : Sales_data(s, 0, 0) {
				//std::cout << "string" << std::endl;
			}
			Sales_data(std::istream &is) : Sales_data() {
				read(is, *this);
				//std::cout << "istream" << std::endl;
			}

			Sales_data &combine(const Sales_data&);
			std::string isbn() const { return bookNo; }
			
			Sales_data &operator+=(const Sales_data &);		// compound-assignment

		private:
			double avg_price() const;
			std::string bookNo;
			unsigned units_sold = 0;
			double revenue = 0.0;
		};

		std::istream &operator>>(std::istream &, Sales_data &);			// input operator
		std::ostream &operator<<(std::ostream &, const Sales_data &);	// output operator
		Sales_data operator+(Sales_data, Sales_data);					// addition operator

		Sales_data add(const Sales_data&, const Sales_data&);
		std::ostream &print(std::ostream&, const Sales_data&);



		// inline and constexpr functions should be defined in the class headers
		inline
		double Sales_data::avg_price() const {
			return units_sold ? revenue / units_sold : 0;
		}
	}
	namespace _12 {
		class Employee {
			friend std::ostream &operator<<(std::ostream &, const Employee &);
			friend std::istream &operator>>(std::istream &, Employee &);
		public:
			Employee(const std::string &n = "") : name(n) {}
			Employee(const std::string &n, unsigned a) : name(n), age(a) {}

			Employee operator++();	// increment employee's age by one
			Employee operator--();	// decrement employee's age by one
			Employee &operator+=(unsigned);	// change employee's age
			Employee &operator-=(unsigned);	// change employee's age
		private:
			std::string name;
			unsigned age;
			std::string rank;
		};

		Employee operator+(Employee, unsigned);		// add to employee's age
		Employee operator-(Employee, unsigned);		// subtract from employee's age

		bool operator==(const Employee &, const Employee &);	// check for equality in each member ANDed
		bool operator!=(const Employee &, const Employee &);	// check for inequality in each member ANDed

		std::ostream &operator<<(std::ostream &, const Employee &);
		std::istream &operator>>(std::istream &, Employee &);
	}
	namespace _13 {
		class Sales_data;
			std::istream &read(std::istream&, Sales_data&);

		class Sales_data {
		public:
			friend std::istream &read(std::istream&, Sales_data&);
			friend std::ostream &print(std::ostream&, const Sales_data&);
			friend Sales_data add(const Sales_data&, const Sales_data&);
			
			friend std::ostream &operator<<(std::ostream &, const Sales_data &);
			friend std::istream &operator>>(std::istream &, Sales_data &);

			friend Sales_data operator+(const Sales_data &, const Sales_data &);
			friend Sales_data operator-(const Sales_data &, const Sales_data &);
			friend Sales_data operator*(const Sales_data &, const Sales_data &);
			friend Sales_data operator/(const Sales_data &, const Sales_data &);

			Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {
				//std::cout << "mainConstructor" << std::endl;
			}
			Sales_data() : Sales_data("", 0, 0) {
				//std::cout << "empty" << std::endl;	
			}
			Sales_data(const std::string &s) : Sales_data(s, 0, 0) {
				//std::cout << "string" << std::endl;
			}
			Sales_data(std::istream &is) : Sales_data() {
				read(is, *this);
				//std::cout << "istream" << std::endl;
			}

			Sales_data &combine(const Sales_data&);
			std::string isbn() const { return bookNo; }
			
			Sales_data &operator+=(const Sales_data &);		// compound-assignment

		private:
			double avg_price() const;
			std::string bookNo;
			unsigned units_sold = 0;
			double revenue = 0.0;
		};

		std::istream &operator>>(std::istream &, Sales_data &);			// input operator
		std::ostream &operator<<(std::ostream &, const Sales_data &);	// output operator
		Sales_data operator+(const Sales_data &, const Sales_data &);	// addition operator
		Sales_data operator-(const Sales_data &, const Sales_data &);	// subtraction operator
		Sales_data operator*(const Sales_data &, const Sales_data &);	// multiplication operator
		Sales_data operator/(const Sales_data &, const Sales_data &);	// division operator

		Sales_data add(const Sales_data&, const Sales_data&);
		std::ostream &print(std::ostream&, const Sales_data&);



		// inline and constexpr functions should be defined in the class headers
		inline
		double Sales_data::avg_price() const {
			return units_sold ? revenue / units_sold : 0;
		}
	}
	namespace _15 {
		class Employee {
			friend std::ostream &operator<<(std::ostream &, const Employee &);
			friend std::istream &operator>>(std::istream &, Employee &);

			friend Employee operator+(const Employee &, unsigned);
			friend Employee operator-(const Employee &, unsigned);
			
			friend Employee operator+(const Employee &, const Employee &);
			friend Employee operator-(const Employee &, const Employee &);
		public:
			Employee(const std::string &n = "") : name(n) {}
			Employee(const std::string &n, unsigned a) : name(n), age(a) {}

			Employee operator++();	// increment employee's age by one
			Employee operator--();	// decrement employee's age by one
			Employee &operator+=(unsigned);	// change employee's age
			Employee &operator-=(unsigned);	// change employee's age
		private:
			std::string name;
			unsigned age;
			std::string rank;
		};

		Employee operator+(const Employee &, unsigned);		// add to employee's age
		Employee operator-(const Employee &, unsigned);		// subtract from employee's age

		Employee operator+(const Employee &, const Employee &);
		Employee operator-(const Employee &, const Employee &);

		bool operator==(const Employee &, const Employee &);	// check for equality in each member ANDed
		bool operator!=(const Employee &, const Employee &);	// check for inequality in each member ANDed

		std::ostream &operator<<(std::ostream &, const Employee &);
		std::istream &operator>>(std::istream &, Employee &);
	}
	namespace _16 {
		class String {
			friend std::ostream &print(std::ostream &, const String &);	
			friend std::ostream &operator<<(std::ostream &, const String &);

			friend bool operator==(const String &, const String &);
			friend bool operator!=(const String &, const String &);
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

		std::ostream &operator<<(std::ostream &, const String &);

		bool operator==(const String &, const String &);
		bool operator!=(const String &, const String &);

		class StrVec {
			friend bool operator==(const StrVec &, const StrVec &);
			friend bool operator!=(const StrVec &, const StrVec &);
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

		bool operator==(const StrVec &, const StrVec &);
		bool operator!=(const StrVec &, const StrVec &);

		class StrBlobPtr;
		class ConstStrBlobPtr;

		class StrBlob {
			friend class StrBlobPtr;
			friend class ConstStrBlobPtr;

			friend bool operator==(const StrBlob &, const StrBlob &);
			friend bool operator!=(const StrBlob &, const StrBlob &);	// works without this, but just in case
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

		bool operator==(const StrBlob &, const StrBlob &);
		bool operator!=(const StrBlob &, const StrBlob &);

		class StrBlobPtr {
			friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
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

		bool operator==(const StrBlobPtr &, const StrBlobPtr &);
		bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

		class ConstStrBlobPtr {
			friend bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
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

		bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
	}
	namespace _17 {
		class Employee {
			friend std::ostream &operator<<(std::ostream &, const Employee &);
			friend std::istream &operator>>(std::istream &, Employee &);

			friend Employee operator+(const Employee &, unsigned);
			friend Employee operator-(const Employee &, unsigned);
			
			friend Employee operator+(const Employee &, const Employee &);
			friend Employee operator-(const Employee &, const Employee &);

			friend bool operator==(const Employee &, const Employee &);
			friend bool operator!=(const Employee &, const Employee &);
		public:
			Employee(const std::string &n = "") : name(n) {}
			Employee(const std::string &n, unsigned a) : name(n), age(a) {}

			Employee operator++();	// increment employee's age by one
			Employee operator--();	// decrement employee's age by one
			Employee &operator+=(unsigned);	// change employee's age
			Employee &operator-=(unsigned);	// change employee's age
		private:
			std::string name;
			unsigned age;
			std::string rank;
		};

		Employee operator+(const Employee &, unsigned);		// add to employee's age
		Employee operator-(const Employee &, unsigned);		// subtract from employee's age

		Employee operator+(const Employee &, const Employee &);
		Employee operator-(const Employee &, const Employee &);

		bool operator==(const Employee &, const Employee &);	// check for equality in each member ANDed
		bool operator!=(const Employee &, const Employee &);	// check for inequality in each member ANDed

		std::ostream &operator<<(std::ostream &, const Employee &);
		std::istream &operator>>(std::istream &, Employee &);

		bool operator==(const Employee &, const Employee &);
		bool operator!=(const Employee &, const Employee &);
	}
	namespace _18 {
		class String {
			friend std::ostream &print(std::ostream &, const String &);	
			friend std::ostream &operator<<(std::ostream &, const String &);

			friend bool operator==(const String &, const String &);
			friend bool operator!=(const String &, const String &);

			friend bool operator<(const String &, const String &);
			friend bool operator>(const String &, const String &);
			friend bool operator<=(const String &, const String &);
			friend bool operator>=(const String &, const String &);
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

		std::ostream &operator<<(std::ostream &, const String &);

		bool operator==(const String &, const String &);
		bool operator!=(const String &, const String &);

		bool operator<(const String &, const String &);
		bool operator>(const String &, const String &);
		bool operator<=(const String &, const String &);
		bool operator>=(const String &, const String &);

		class StrVec {
			friend bool operator==(const StrVec &, const StrVec &);
			friend bool operator!=(const StrVec &, const StrVec &);

			friend bool operator<(const StrVec &, const StrVec &);
			friend bool operator>(const StrVec &, const StrVec &);
			friend bool operator<=(const StrVec &, const StrVec &);
			friend bool operator>=(const StrVec &, const StrVec &);
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

		bool operator==(const StrVec &, const StrVec &);
		bool operator!=(const StrVec &, const StrVec &);

		bool operator<(const StrVec &, const StrVec &);
		bool operator>(const StrVec &, const StrVec &);
		bool operator<=(const StrVec &, const StrVec &);
		bool operator>=(const StrVec &, const StrVec &);

		class StrBlobPtr;
		class ConstStrBlobPtr;

		class StrBlob {
			friend class StrBlobPtr;
			friend class ConstStrBlobPtr;

			friend bool operator==(const StrBlob &, const StrBlob &);
			friend bool operator!=(const StrBlob &, const StrBlob &);	// works without this, but just in case
			
			friend bool operator<(const StrBlob &, const StrBlob &);
			friend bool operator>(const StrBlob &, const StrBlob &);
			friend bool operator<=(const StrBlob &, const StrBlob &);
			friend bool operator>=(const StrBlob &, const StrBlob &);
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

		bool operator==(const StrBlob &, const StrBlob &);
		bool operator!=(const StrBlob &, const StrBlob &);

		bool operator<(const StrBlob &, const StrBlob &);
		bool operator>(const StrBlob &, const StrBlob &);
		bool operator<=(const StrBlob &, const StrBlob &);
		bool operator>=(const StrBlob &, const StrBlob &);

		class StrBlobPtr {
			friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

			friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);
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

		bool operator==(const StrBlobPtr &, const StrBlobPtr &);
		bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

		bool operator<(const StrBlobPtr &, const StrBlobPtr &);
		bool operator>(const StrBlobPtr &, const StrBlobPtr &);
		bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
		bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

		class ConstStrBlobPtr {
			friend bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

			friend bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
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

		bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

		bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
	}
	namespace _20 {
		class Sales_data;
			std::istream &read(std::istream&, Sales_data&);

		class Sales_data {
		public:
			friend std::istream &read(std::istream&, Sales_data&);
			friend std::ostream &print(std::ostream&, const Sales_data&);
			friend Sales_data add(const Sales_data&, const Sales_data&);
			
			friend std::ostream &operator<<(std::ostream &, const Sales_data &);
			friend std::istream &operator>>(std::istream &, Sales_data &);

			friend Sales_data operator+(const Sales_data &, const Sales_data &);
			friend Sales_data operator-(const Sales_data &, const Sales_data &);
			friend Sales_data operator*(const Sales_data &, const Sales_data &);
			friend Sales_data operator/(const Sales_data &, const Sales_data &);

			Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {
				//std::cout << "mainConstructor" << std::endl;
			}
			Sales_data() : Sales_data("", 0, 0) {
				//std::cout << "empty" << std::endl;	
			}
			Sales_data(const std::string &s) : Sales_data(s, 0, 0) {
				//std::cout << "string" << std::endl;
			}
			Sales_data(std::istream &is) : Sales_data() {
				read(is, *this);
				//std::cout << "istream" << std::endl;
			}

			Sales_data &combine(const Sales_data&);
			std::string isbn() const { return bookNo; }
			
			Sales_data &operator+=(const Sales_data &);		// compound-assignment

		private:
			double avg_price() const;
			std::string bookNo;
			unsigned units_sold = 0;
			double revenue = 0.0;
		};

		std::istream &operator>>(std::istream &, Sales_data &);			// input operator
		std::ostream &operator<<(std::ostream &, const Sales_data &);	// output operator
		Sales_data operator+(const Sales_data &, const Sales_data &);	// addition operator
		Sales_data operator-(const Sales_data &, const Sales_data &);	// subtraction operator
		Sales_data operator*(const Sales_data &, const Sales_data &);	// multiplication operator
		Sales_data operator/(const Sales_data &, const Sales_data &);	// division operator

		Sales_data add(const Sales_data&, const Sales_data&);
		std::ostream &print(std::ostream&, const Sales_data&);



		// inline and constexpr functions should be defined in the class headers
		inline
		double Sales_data::avg_price() const {
			return units_sold ? revenue / units_sold : 0;
		}
	}
	namespace _21 {
		class Sales_data;
			std::istream &read(std::istream&, Sales_data&);

		class Sales_data {
		public:
			friend std::istream &read(std::istream&, Sales_data&);
			friend std::ostream &print(std::ostream&, const Sales_data&);
			friend Sales_data add(const Sales_data&, const Sales_data&);
			
			friend std::ostream &operator<<(std::ostream &, const Sales_data &);
			friend std::istream &operator>>(std::istream &, Sales_data &);

			friend Sales_data operator+(const Sales_data &, const Sales_data &);
			friend Sales_data operator-(const Sales_data &, const Sales_data &);
			friend Sales_data operator*(const Sales_data &, const Sales_data &);
			friend Sales_data operator/(const Sales_data &, const Sales_data &);

			Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {
				//std::cout << "mainConstructor" << std::endl;
			}
			Sales_data() : Sales_data("", 0, 0) {
				//std::cout << "empty" << std::endl;	
			}
			Sales_data(const std::string &s) : Sales_data(s, 0, 0) {
				//std::cout << "string" << std::endl;
			}
			Sales_data(std::istream &is) : Sales_data() {
				read(is, *this);
				//std::cout << "istream" << std::endl;
			}

			Sales_data &combine(const Sales_data&);
			std::string isbn() const { return bookNo; }
			
			Sales_data &operator+=(const Sales_data &);		// compound-assignment

		private:
			double avg_price() const;
			std::string bookNo;
			unsigned units_sold = 0;
			double revenue = 0.0;
		};

		std::istream &operator>>(std::istream &, Sales_data &);			// input operator
		std::ostream &operator<<(std::ostream &, const Sales_data &);	// output operator
		Sales_data operator+(const Sales_data &, const Sales_data &);	// addition operator
		Sales_data operator-(const Sales_data &, const Sales_data &);	// subtraction operator
		Sales_data operator*(const Sales_data &, const Sales_data &);	// multiplication operator
		Sales_data operator/(const Sales_data &, const Sales_data &);	// division operator

		Sales_data add(const Sales_data&, const Sales_data&);
		std::ostream &print(std::ostream&, const Sales_data&);



		// inline and constexpr functions should be defined in the class headers
		inline
		double Sales_data::avg_price() const {
			return units_sold ? revenue / units_sold : 0;
		}
	}
	namespace _22 {
		class Sales_data;
			std::istream &read(std::istream&, Sales_data&);

		class Sales_data {
			friend std::istream &read(std::istream&, Sales_data&);
			friend std::ostream &print(std::ostream&, const Sales_data&);
			friend Sales_data add(const Sales_data&, const Sales_data&);
			
			friend std::ostream &operator<<(std::ostream &, const Sales_data &);
			friend std::istream &operator>>(std::istream &, Sales_data &);

			friend Sales_data operator+(const Sales_data &, const Sales_data &);
			friend Sales_data operator-(const Sales_data &, const Sales_data &);
			friend Sales_data operator*(const Sales_data &, const Sales_data &);
			friend Sales_data operator/(const Sales_data &, const Sales_data &);

		public:
			Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {
				//std::cout << "mainConstructor" << std::endl;
			}
			Sales_data() : Sales_data("", 0, 0) {
				//std::cout << "empty" << std::endl;	
			}
			Sales_data(const std::string &s) : Sales_data(s, 0, 0) {
				//std::cout << "string" << std::endl;
			}
			Sales_data(std::istream &is) : Sales_data() {
				read(is, *this);
				//std::cout << "istream" << std::endl;
			}

			Sales_data &combine(const Sales_data&);
			std::string isbn() const { return bookNo; }
			
			Sales_data &operator+=(const Sales_data &);		// compound-assignment

			Sales_data &operator=(const std::string &);
		private:
			double avg_price() const;
			std::string bookNo;
			unsigned units_sold = 0;
			double revenue = 0.0;
		};

		std::istream &operator>>(std::istream &, Sales_data &);			// input operator
		std::ostream &operator<<(std::ostream &, const Sales_data &);	// output operator
		Sales_data operator+(const Sales_data &, const Sales_data &);	// addition operator
		Sales_data operator-(const Sales_data &, const Sales_data &);	// subtraction operator
		Sales_data operator*(const Sales_data &, const Sales_data &);	// multiplication operator
		Sales_data operator/(const Sales_data &, const Sales_data &);	// division operator

		Sales_data add(const Sales_data&, const Sales_data&);
		std::ostream &print(std::ostream&, const Sales_data&);



		// inline and constexpr functions should be defined in the class headers
		inline
		double Sales_data::avg_price() const {
			return units_sold ? revenue / units_sold : 0;
		}
	}
	namespace _23 {
		class StrVec {
			friend bool operator==(const StrVec &, const StrVec &);
			friend bool operator!=(const StrVec &, const StrVec &);

			friend bool operator<(const StrVec &, const StrVec &);
			friend bool operator>(const StrVec &, const StrVec &);
			friend bool operator<=(const StrVec &, const StrVec &);
			friend bool operator>=(const StrVec &, const StrVec &);
		public:
			StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
			StrVec(const std::initializer_list<std::string> &);
			StrVec(const StrVec &);
			StrVec(StrVec &&) noexcept;					// move constructor
			StrVec &operator=(const StrVec &);
			StrVec &operator=(StrVec &&) noexcept;		// move-assignment operator
			StrVec &operator=(const std::initializer_list<std::string> &);
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

		bool operator==(const StrVec &, const StrVec &);
		bool operator!=(const StrVec &, const StrVec &);

		bool operator<(const StrVec &, const StrVec &);
		bool operator>(const StrVec &, const StrVec &);
		bool operator<=(const StrVec &, const StrVec &);
		bool operator>=(const StrVec &, const StrVec &);
	}
	namespace _24 {
		class Employee {
			friend std::ostream &operator<<(std::ostream &, const Employee &);
			friend std::istream &operator>>(std::istream &, Employee &);

			friend Employee operator+(const Employee &, unsigned);
			friend Employee operator-(const Employee &, unsigned);
			
			friend Employee operator+(const Employee &, const Employee &);
			friend Employee operator-(const Employee &, const Employee &);

			friend bool operator==(const Employee &, const Employee &);
			friend bool operator!=(const Employee &, const Employee &);
		public:
			Employee(const std::string &n = "") : name(n) {}
			Employee(const std::string &n, unsigned a) : name(n), age(a) {}
			Employee(const Employee &e) : name(e.name), age(e.age), rank(e.rank) {}
			Employee(Employee &&e) noexcept : name(std::move(e.name)), age(std::move(e.age)), rank(std::move(e.rank)) {}

			Employee &operator=(const Employee &);
			Employee &operator=(Employee &&) noexcept;

			Employee operator++();	// increment employee's age by one
			Employee operator--();	// decrement employee's age by one
			Employee &operator+=(unsigned);	// change employee's age
			Employee &operator-=(unsigned);	// change employee's age
		private:
			std::string name;
			unsigned age;
			std::string rank;
		};

		Employee operator+(const Employee &, unsigned);		// add to employee's age
		Employee operator-(const Employee &, unsigned);		// subtract from employee's age

		Employee operator+(const Employee &, const Employee &);
		Employee operator-(const Employee &, const Employee &);

		bool operator==(const Employee &, const Employee &);	// check for equality in each member ANDed
		bool operator!=(const Employee &, const Employee &);	// check for inequality in each member ANDed

		std::ostream &operator<<(std::ostream &, const Employee &);
		std::istream &operator>>(std::istream &, Employee &);

		bool operator==(const Employee &, const Employee &);
		bool operator!=(const Employee &, const Employee &);
	}
	namespace _25 {
		class Employee {
			friend std::ostream &operator<<(std::ostream &, const Employee &);
			friend std::istream &operator>>(std::istream &, Employee &);

			friend Employee operator+(const Employee &, unsigned);
			friend Employee operator-(const Employee &, unsigned);
			
			friend Employee operator+(const Employee &, const Employee &);
			friend Employee operator-(const Employee &, const Employee &);

			friend bool operator==(const Employee &, const Employee &);
			friend bool operator!=(const Employee &, const Employee &);
		public:
			Employee(const std::string &n = "") : name(n) {}
			Employee(const std::string &n, unsigned a) : name(n), age(a) {}
			Employee(const Employee &e) : name(e.name), age(e.age), rank(e.rank) {}
			Employee(Employee &&e) noexcept : name(std::move(e.name)), age(std::move(e.age)), rank(std::move(e.rank)) {}

			Employee &operator=(const Employee &);
			Employee &operator=(Employee &&) noexcept;
			Employee &operator=(const std::initializer_list<std::string> &);

			Employee operator++();	// increment employee's age by one
			Employee operator--();	// decrement employee's age by one
			Employee &operator+=(unsigned);	// change employee's age
			Employee &operator-=(unsigned);	// change employee's age
		private:
			std::string name;
			unsigned age = 18;
			std::string rank;
		};

		Employee operator+(const Employee &, unsigned);		// add to employee's age
		Employee operator-(const Employee &, unsigned);		// subtract from employee's age

		Employee operator+(const Employee &, const Employee &);
		Employee operator-(const Employee &, const Employee &);

		bool operator==(const Employee &, const Employee &);	// check for equality in each member ANDed
		bool operator!=(const Employee &, const Employee &);	// check for inequality in each member ANDed

		std::ostream &operator<<(std::ostream &, const Employee &);
		std::istream &operator>>(std::istream &, Employee &);

		bool operator==(const Employee &, const Employee &);
		bool operator!=(const Employee &, const Employee &);
	}
	namespace _26 {
		class String {
			friend std::ostream &print(std::ostream &, const String &);	
			friend std::ostream &operator<<(std::ostream &, const String &);

			friend bool operator==(const String &, const String &);
			friend bool operator!=(const String &, const String &);

			friend bool operator<(const String &, const String &);
			friend bool operator>(const String &, const String &);
			friend bool operator<=(const String &, const String &);
			friend bool operator>=(const String &, const String &);
		public:
			String();
			String(const char *);
			String(const String &);
			String(String &&) noexcept;					// move constructor
			String &operator=(const String &);
			String &operator=(String &&) noexcept;		// move-assignment operator
			~String();

			char &operator[](std::size_t n) { return elements[n]; }
			const char &operator[](std::size_t n) const { return elements[n]; }

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

		std::ostream &operator<<(std::ostream &, const String &);

		bool operator==(const String &, const String &);
		bool operator!=(const String &, const String &);

		bool operator<(const String &, const String &);
		bool operator>(const String &, const String &);
		bool operator<=(const String &, const String &);
		bool operator>=(const String &, const String &);

		class StrVec {
			friend bool operator==(const StrVec &, const StrVec &);
			friend bool operator!=(const StrVec &, const StrVec &);

			friend bool operator<(const StrVec &, const StrVec &);
			friend bool operator>(const StrVec &, const StrVec &);
			friend bool operator<=(const StrVec &, const StrVec &);
			friend bool operator>=(const StrVec &, const StrVec &);
		public:
			StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
			StrVec(const std::initializer_list<std::string> &);
			StrVec(const StrVec &);
			StrVec(StrVec &&) noexcept;					// move constructor
			StrVec &operator=(const StrVec &);
			StrVec &operator=(StrVec &&) noexcept;		// move-assignment operator
			StrVec &operator=(const std::initializer_list<std::string> &);
			~StrVec();

			std::string &operator[](std::size_t n) { return elements[n]; }
			const std::string &operator[](std::size_t n) const { return elements[n]; }

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

		bool operator==(const StrVec &, const StrVec &);
		bool operator!=(const StrVec &, const StrVec &);

		bool operator<(const StrVec &, const StrVec &);
		bool operator>(const StrVec &, const StrVec &);
		bool operator<=(const StrVec &, const StrVec &);
		bool operator>=(const StrVec &, const StrVec &);

		class StrBlobPtr;
		class ConstStrBlobPtr;

		class StrBlob {
			friend class StrBlobPtr;
			friend class ConstStrBlobPtr;

			friend bool operator==(const StrBlob &, const StrBlob &);
			friend bool operator!=(const StrBlob &, const StrBlob &);	// works without this, but just in case
			
			friend bool operator<(const StrBlob &, const StrBlob &);
			friend bool operator>(const StrBlob &, const StrBlob &);
			friend bool operator<=(const StrBlob &, const StrBlob &);
			friend bool operator>=(const StrBlob &, const StrBlob &);
		public:
			typedef std::vector<std::string>::size_type size_type;
			
			StrBlob();
			StrBlob(std::initializer_list<std::string>);

			size_type size() const { return data->size(); }
			bool empty() const { return data->empty(); }
			
			std::string &operator[](std::size_t n) { return (*data)[n]; }
			const std::string &operator[](std::size_t n) const { return (*data)[n]; }

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

		bool operator==(const StrBlob &, const StrBlob &);
		bool operator!=(const StrBlob &, const StrBlob &);

		bool operator<(const StrBlob &, const StrBlob &);
		bool operator>(const StrBlob &, const StrBlob &);
		bool operator<=(const StrBlob &, const StrBlob &);
		bool operator>=(const StrBlob &, const StrBlob &);

		class StrBlobPtr {
			friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

			friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);
		public:
			StrBlobPtr() : curr(0) {}
			StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}

			std::string &operator[](std::size_t);
			const std::string &operator[](std::size_t) const;

			std::string &deref() const;
			StrBlobPtr &incr();
		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};

		bool operator==(const StrBlobPtr &, const StrBlobPtr &);
		bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

		bool operator<(const StrBlobPtr &, const StrBlobPtr &);
		bool operator>(const StrBlobPtr &, const StrBlobPtr &);
		bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
		bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

		class ConstStrBlobPtr {
			friend bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

			friend bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		public:
			ConstStrBlobPtr() : curr(0) {}
			ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}

			std::string &operator[](std::size_t);
			const std::string &operator[](std::size_t) const;

			const std::string &deref() const;
			ConstStrBlobPtr &incr();
		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};

		bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

		bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
	}
	namespace _27 {
		class StrBlobPtr;
		class ConstStrBlobPtr;

		class StrBlob {
			friend class StrBlobPtr;
			friend class ConstStrBlobPtr;

			friend bool operator==(const StrBlob &, const StrBlob &);
			friend bool operator!=(const StrBlob &, const StrBlob &);	// works without this, but just in case
			
			friend bool operator<(const StrBlob &, const StrBlob &);
			friend bool operator>(const StrBlob &, const StrBlob &);
			friend bool operator<=(const StrBlob &, const StrBlob &);
			friend bool operator>=(const StrBlob &, const StrBlob &);
		public:
			typedef std::vector<std::string>::size_type size_type;
			
			StrBlob();
			StrBlob(std::initializer_list<std::string>);

			size_type size() const { return data->size(); }
			bool empty() const { return data->empty(); }
			
			std::string &operator[](std::size_t n) { return (*data)[n]; }
			const std::string &operator[](std::size_t n) const { return (*data)[n]; }

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

		bool operator==(const StrBlob &, const StrBlob &);
		bool operator!=(const StrBlob &, const StrBlob &);

		bool operator<(const StrBlob &, const StrBlob &);
		bool operator>(const StrBlob &, const StrBlob &);
		bool operator<=(const StrBlob &, const StrBlob &);
		bool operator>=(const StrBlob &, const StrBlob &);

		class StrBlobPtr {
			friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

			friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);
		public:
			StrBlobPtr() : curr(0) {}
			StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}

			std::string &operator[](std::size_t);
			const std::string &operator[](std::size_t) const;

			StrBlobPtr &operator++();	// prefix
			StrBlobPtr &operator--();
			StrBlobPtr operator++(int);	// postfix
			StrBlobPtr operator--(int);

			std::string &deref() const;
			StrBlobPtr &incr();
		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};

		bool operator==(const StrBlobPtr &, const StrBlobPtr &);
		bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

		bool operator<(const StrBlobPtr &, const StrBlobPtr &);
		bool operator>(const StrBlobPtr &, const StrBlobPtr &);
		bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
		bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

		class ConstStrBlobPtr {
			friend bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

			friend bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		public:
			ConstStrBlobPtr() : curr(0) {}
			ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}

			ConstStrBlobPtr &operator++();	// prefix
			ConstStrBlobPtr &operator--();
			ConstStrBlobPtr operator++(int);	// postfix
			ConstStrBlobPtr operator--(int);

			std::string &operator[](std::size_t);
			const std::string &operator[](std::size_t) const;

			const std::string &deref() const;
			ConstStrBlobPtr &incr();
		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};

		bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

		bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
	}
	namespace _28 {
		class StrBlobPtr;
		class ConstStrBlobPtr;

		class StrBlob {
			friend class StrBlobPtr;
			friend class ConstStrBlobPtr;

			friend bool operator==(const StrBlob &, const StrBlob &);
			friend bool operator!=(const StrBlob &, const StrBlob &);	// works without this, but just in case
			
			friend bool operator<(const StrBlob &, const StrBlob &);
			friend bool operator>(const StrBlob &, const StrBlob &);
			friend bool operator<=(const StrBlob &, const StrBlob &);
			friend bool operator>=(const StrBlob &, const StrBlob &);
		public:
			typedef std::vector<std::string>::size_type size_type;
			
			StrBlob();
			StrBlob(std::initializer_list<std::string>);

			size_type size() const { return data->size(); }
			bool empty() const { return data->empty(); }
			
			std::string &operator[](std::size_t n) { return (*data)[n]; }
			const std::string &operator[](std::size_t n) const { return (*data)[n]; }

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

		bool operator==(const StrBlob &, const StrBlob &);
		bool operator!=(const StrBlob &, const StrBlob &);

		bool operator<(const StrBlob &, const StrBlob &);
		bool operator>(const StrBlob &, const StrBlob &);
		bool operator<=(const StrBlob &, const StrBlob &);
		bool operator>=(const StrBlob &, const StrBlob &);

		class StrBlobPtr {
			friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

			friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

			friend StrBlobPtr operator+(const StrBlobPtr &, std::size_t);
			friend StrBlobPtr operator-(const StrBlobPtr &, std::size_t);
			friend std::ptrdiff_t operator-(const StrBlobPtr &, const StrBlobPtr &);
		public:
			StrBlobPtr() : curr(0) {}
			StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}

			std::string &operator[](std::size_t);
			const std::string &operator[](std::size_t) const;

			StrBlobPtr &operator++();	// prefix
			StrBlobPtr &operator--();
			StrBlobPtr operator++(int);	// postfix
			StrBlobPtr operator--(int);

			std::string &deref() const;
			StrBlobPtr &incr();
		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};

		bool operator==(const StrBlobPtr &, const StrBlobPtr &);
		bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

		bool operator<(const StrBlobPtr &, const StrBlobPtr &);
		bool operator>(const StrBlobPtr &, const StrBlobPtr &);
		bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
		bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

		StrBlobPtr operator+(const StrBlobPtr &, std::size_t);
		StrBlobPtr operator-(const StrBlobPtr &, std::size_t);
		std::ptrdiff_t operator-(const StrBlobPtr &, const StrBlobPtr &);

		class ConstStrBlobPtr {
			friend bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

			friend bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

			friend ConstStrBlobPtr operator+(const ConstStrBlobPtr &, std::size_t);
			friend ConstStrBlobPtr operator-(const ConstStrBlobPtr &, std::size_t);
			friend std::ptrdiff_t operator-(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		public:
			ConstStrBlobPtr() : curr(0) {}
			ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}

			ConstStrBlobPtr &operator++();	// prefix
			ConstStrBlobPtr &operator--();
			ConstStrBlobPtr operator++(int);	// postfix
			ConstStrBlobPtr operator--(int);

			std::string &operator[](std::size_t);
			const std::string &operator[](std::size_t) const;

			const std::string &deref() const;
			ConstStrBlobPtr &incr();
		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};

		bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

		bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

		ConstStrBlobPtr operator+(const ConstStrBlobPtr &, std::size_t);
		ConstStrBlobPtr operator-(const ConstStrBlobPtr &, std::size_t);
		std::ptrdiff_t operator-(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
	}
	namespace _30 {
		class StrBlobPtr;
		class ConstStrBlobPtr;

		class StrBlob {
			friend class StrBlobPtr;
			friend class ConstStrBlobPtr;

			friend bool operator==(const StrBlob &, const StrBlob &);
			friend bool operator!=(const StrBlob &, const StrBlob &);	// works without this, but just in case
			
			friend bool operator<(const StrBlob &, const StrBlob &);
			friend bool operator>(const StrBlob &, const StrBlob &);
			friend bool operator<=(const StrBlob &, const StrBlob &);
			friend bool operator>=(const StrBlob &, const StrBlob &);
		public:
			typedef std::vector<std::string>::size_type size_type;
			
			StrBlob();
			StrBlob(std::initializer_list<std::string>);

			size_type size() const { return data->size(); }
			bool empty() const { return data->empty(); }
			
			std::string &operator[](std::size_t n) { return (*data)[n]; }
			const std::string &operator[](std::size_t n) const { return (*data)[n]; }

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

		bool operator==(const StrBlob &, const StrBlob &);
		bool operator!=(const StrBlob &, const StrBlob &);

		bool operator<(const StrBlob &, const StrBlob &);
		bool operator>(const StrBlob &, const StrBlob &);
		bool operator<=(const StrBlob &, const StrBlob &);
		bool operator>=(const StrBlob &, const StrBlob &);

		class StrBlobPtr {
			friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

			friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

			friend StrBlobPtr operator+(const StrBlobPtr &, std::size_t);
			friend StrBlobPtr operator-(const StrBlobPtr &, std::size_t);
			friend std::ptrdiff_t operator-(const StrBlobPtr &, const StrBlobPtr &);
		public:
			StrBlobPtr() : curr(0) {}
			StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}

			std::string &operator[](std::size_t);
			const std::string &operator[](std::size_t) const;

			std::string &operator*() const;
			std::string *operator->() const;

			StrBlobPtr &operator++();	// prefix
			StrBlobPtr &operator--();
			StrBlobPtr operator++(int);	// postfix
			StrBlobPtr operator--(int);

			std::string &deref() const;
			StrBlobPtr &incr();
		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};

		bool operator==(const StrBlobPtr &, const StrBlobPtr &);
		bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

		bool operator<(const StrBlobPtr &, const StrBlobPtr &);
		bool operator>(const StrBlobPtr &, const StrBlobPtr &);
		bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
		bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

		StrBlobPtr operator+(const StrBlobPtr &, std::size_t);
		StrBlobPtr operator-(const StrBlobPtr &, std::size_t);
		std::ptrdiff_t operator-(const StrBlobPtr &, const StrBlobPtr &);

		class ConstStrBlobPtr {
			friend bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

			friend bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

			friend ConstStrBlobPtr operator+(const ConstStrBlobPtr &, std::size_t);
			friend ConstStrBlobPtr operator-(const ConstStrBlobPtr &, std::size_t);
			friend std::ptrdiff_t operator-(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		public:
			ConstStrBlobPtr() : curr(0) {}
			ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}

			ConstStrBlobPtr &operator++();	// prefix
			ConstStrBlobPtr &operator--();
			ConstStrBlobPtr operator++(int);	// postfix
			ConstStrBlobPtr operator--(int);

			const std::string &operator*() const;
			const std::string *operator->() const;

			std::string &operator[](std::size_t);
			const std::string &operator[](std::size_t) const;

			const std::string &deref() const;
			ConstStrBlobPtr &incr();
		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};

		bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

		bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

		ConstStrBlobPtr operator+(const ConstStrBlobPtr &, std::size_t);
		ConstStrBlobPtr operator-(const ConstStrBlobPtr &, std::size_t);
		std::ptrdiff_t operator-(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
	}
	namespace _32 {
		class StrBlobPtr;
		class ConstStrBlobPtr;

		class StrBlob {
			friend class StrBlobPtr;
			friend class ConstStrBlobPtr;

			friend bool operator==(const StrBlob &, const StrBlob &);
			friend bool operator!=(const StrBlob &, const StrBlob &);	// works without this, but just in case
			
			friend bool operator<(const StrBlob &, const StrBlob &);
			friend bool operator>(const StrBlob &, const StrBlob &);
			friend bool operator<=(const StrBlob &, const StrBlob &);
			friend bool operator>=(const StrBlob &, const StrBlob &);
		public:
			typedef std::vector<std::string>::size_type size_type;
			
			StrBlob();
			StrBlob(std::initializer_list<std::string>);

			size_type size() const { return data->size(); }
			bool empty() const { return data->empty(); }
			
			std::string &operator[](std::size_t n) { return (*data)[n]; }
			const std::string &operator[](std::size_t n) const { return (*data)[n]; }

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

		bool operator==(const StrBlob &, const StrBlob &);
		bool operator!=(const StrBlob &, const StrBlob &);

		bool operator<(const StrBlob &, const StrBlob &);
		bool operator>(const StrBlob &, const StrBlob &);
		bool operator<=(const StrBlob &, const StrBlob &);
		bool operator>=(const StrBlob &, const StrBlob &);

		class StrBlobPtr {
			friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

			friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
			friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

			friend StrBlobPtr operator+(const StrBlobPtr &, std::size_t);
			friend StrBlobPtr operator-(const StrBlobPtr &, std::size_t);
			friend std::ptrdiff_t operator-(const StrBlobPtr &, const StrBlobPtr &);
		public:
			StrBlobPtr() : curr(0) {}
			StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}

			std::string &operator[](std::size_t);
			const std::string &operator[](std::size_t) const;

			std::string &operator*() const;
			std::string *operator->() const;

			StrBlobPtr &operator++();	// prefix
			StrBlobPtr &operator--();
			StrBlobPtr operator++(int);	// postfix
			StrBlobPtr operator--(int);

			std::string &deref() const;
			StrBlobPtr &incr();
		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};

		bool operator==(const StrBlobPtr &, const StrBlobPtr &);
		bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

		bool operator<(const StrBlobPtr &, const StrBlobPtr &);
		bool operator>(const StrBlobPtr &, const StrBlobPtr &);
		bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
		bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

		StrBlobPtr operator+(const StrBlobPtr &, std::size_t);
		StrBlobPtr operator-(const StrBlobPtr &, std::size_t);
		std::ptrdiff_t operator-(const StrBlobPtr &, const StrBlobPtr &);

		class ConstStrBlobPtr {
			friend bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

			friend bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
			friend bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

			friend ConstStrBlobPtr operator+(const ConstStrBlobPtr &, std::size_t);
			friend ConstStrBlobPtr operator-(const ConstStrBlobPtr &, std::size_t);
			friend std::ptrdiff_t operator-(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		public:
			ConstStrBlobPtr() : curr(0) {}
			ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}

			ConstStrBlobPtr &operator++();	// prefix
			ConstStrBlobPtr &operator--();
			ConstStrBlobPtr operator++(int);	// postfix
			ConstStrBlobPtr operator--(int);

			const std::string &operator*() const;
			const std::string *operator->() const;

			std::string &operator[](std::size_t);
			const std::string &operator[](std::size_t) const;

			const std::string &deref() const;
			ConstStrBlobPtr &incr();
		private:
			std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
			std::weak_ptr<std::vector<std::string>> wptr;
			std::size_t curr;
		};

		bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

		bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
		bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

		ConstStrBlobPtr operator+(const ConstStrBlobPtr &, std::size_t);
		ConstStrBlobPtr operator-(const ConstStrBlobPtr &, std::size_t);
		std::ptrdiff_t operator-(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

		class PtrToStrBlobPtr {
		public:
			PtrToStrBlobPtr(StrBlobPtr &sp) : p(&sp) {}
			StrBlobPtr &operator*() const;
			StrBlobPtr *operator->() const;
		private:
			StrBlobPtr *p = nullptr;
		};
	}
	namespace _34 {
		struct IfThenElse {
			int operator()(bool, int, int) const;
		};
	}
	namespace _35 {
		class ReadString {
		public:
			ReadString(std::istream &i = std::cin) : is(i) {}
			std::string operator()() const;
		private:
			std::istream &is;
		};
	}
	namespace _36 {
		class ReadString {
		public:
			ReadString(std::istream &i = std::cin) : is(i) {}
			std::string operator()() const;
		private:
			std::istream &is;
		};
	}
	namespace _37 {
		class Equal {
		public:
			Equal(int i) : val(i) {}
			bool operator()(int) const;
		private:
			int val;
		};
	}
	namespace _38 {
		class Bound {
		public:
			Bound(std::string::size_type n) : max_length(n) {}
			bool operator()(const std::string &) const;
		private:
			std::string::size_type max_length;
		};
	}
	namespace _39 {
		class Bound {
		public:
			Bound(std::string::size_type n) : max_length(n) {}
			bool operator()(const std::string &) const;
		private:
			std::string::size_type max_length;
		};
	}
	namespace _40 {
		class PrintString {
		public:
			PrintString(std::ostream &o, char c) : os(o), sep(c) {}
			void operator()(const std::string &s) const
				{ os << s << sep; }
		private:
			std::ostream &os;
			char sep;
		};
	
		struct ShorterString {
			bool operator()(const std::string &a, const std::string &b) const
				{ return a.size() < b.size(); }
		};
	
		class SizeComp {
		public:
			SizeComp(std::vector<std::string>::size_type n) : sz(n) {}
			bool operator()(const std::string &a) const
				{ return a.size() >= sz; }
		private:
			std::vector<std::string>::size_type sz;
		};
	}
	namespace _45 {
		class Sales_data;
			std::istream &read(std::istream&, Sales_data&);

		class Sales_data {
			friend std::istream &read(std::istream&, Sales_data&);
			friend std::ostream &print(std::ostream&, const Sales_data&);
			friend Sales_data add(const Sales_data&, const Sales_data&);
			
			friend std::ostream &operator<<(std::ostream &, const Sales_data &);
			friend std::istream &operator>>(std::istream &, Sales_data &);

			friend Sales_data operator+(const Sales_data &, const Sales_data &);
			friend Sales_data operator-(const Sales_data &, const Sales_data &);
			friend Sales_data operator*(const Sales_data &, const Sales_data &);
			friend Sales_data operator/(const Sales_data &, const Sales_data &);

		public:
			Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {
				//std::cout << "mainConstructor" << std::endl;
			}
			Sales_data() : Sales_data("", 0, 0) {
				//std::cout << "empty" << std::endl;	
			}
			Sales_data(const std::string &s) : Sales_data(s, 0, 0) {
				//std::cout << "string" << std::endl;
			}
			Sales_data(std::istream &is) : Sales_data() {
				read(is, *this);
				//std::cout << "istream" << std::endl;
			}

			Sales_data &combine(const Sales_data&);
			std::string isbn() const { return bookNo; }
			
			Sales_data &operator+=(const Sales_data &);		// compound-assignment
			Sales_data &operator=(const std::string &);		// copy-assignment operator
			
			explicit operator std::string() const { return bookNo; }
			explicit operator double() const { return revenue; }
		private:
			double avg_price() const;
			std::string bookNo;
			unsigned units_sold = 0;
			double revenue = 0.0;
		};

		std::istream &operator>>(std::istream &, Sales_data &);			// input operator
		std::ostream &operator<<(std::ostream &, const Sales_data &);	// output operator
		Sales_data operator+(const Sales_data &, const Sales_data &);	// addition operator
		Sales_data operator-(const Sales_data &, const Sales_data &);	// subtraction operator
		Sales_data operator*(const Sales_data &, const Sales_data &);	// multiplication operator
		Sales_data operator/(const Sales_data &, const Sales_data &);	// division operator

		Sales_data add(const Sales_data&, const Sales_data&);
		std::ostream &print(std::ostream&, const Sales_data&);

		// inline and constexpr functions should be defined in the class headers
		inline
		double Sales_data::avg_price() const {
			return units_sold ? revenue / units_sold : 0;
		}
	}
	namespace _49 {
		class Employee {
			friend std::ostream &operator<<(std::ostream &, const Employee &);
			friend std::istream &operator>>(std::istream &, Employee &);

			friend Employee operator+(const Employee &, unsigned);
			friend Employee operator-(const Employee &, unsigned);
			
			friend Employee operator+(const Employee &, const Employee &);
			friend Employee operator-(const Employee &, const Employee &);

			friend bool operator==(const Employee &, const Employee &);
			friend bool operator!=(const Employee &, const Employee &);
		public:
			Employee(const std::string &n = "") : name(n) {}
			Employee(const std::string &n, unsigned a) : name(n), age(a) {}
			Employee(const Employee &e) : name(e.name), age(e.age), rank(e.rank) {}
			Employee(Employee &&e) noexcept : name(std::move(e.name)), age(std::move(e.age)), rank(std::move(e.rank)) {}

			Employee &operator=(const Employee &);
			Employee &operator=(Employee &&) noexcept;
			Employee &operator=(const std::initializer_list<std::string> &);

			Employee operator++();	// increment employee's age by one
			Employee operator--();	// decrement employee's age by one
			Employee &operator+=(unsigned);	// change employee's age
			Employee &operator-=(unsigned);	// change employee's age
			
			operator bool() const { return !(name.empty() && age == 18 && rank.empty()); }
		private:
			std::string name;
			unsigned age = 18;
			std::string rank;
		};

		Employee operator+(const Employee &, unsigned);		// add to employee's age
		Employee operator-(const Employee &, unsigned);		// subtract from employee's age

		Employee operator+(const Employee &, const Employee &);
		Employee operator-(const Employee &, const Employee &);

		bool operator==(const Employee &, const Employee &);	// check for equality in each member ANDed
		bool operator!=(const Employee &, const Employee &);	// check for inequality in each member ANDed

		std::ostream &operator<<(std::ostream &, const Employee &);
		std::istream &operator>>(std::istream &, Employee &);

		bool operator==(const Employee &, const Employee &);
		bool operator!=(const Employee &, const Employee &);
	}
	}
}

#endif
