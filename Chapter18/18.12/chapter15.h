#ifndef CHAPTER15_H
#define CHAPTER15_H

#include <string>
#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include <set>
#include <initializer_list>
#include <stdexcept>
#include <map>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <iterator>

namespace cplusplus_primer {
	namespace chapter15 {
	namespace _03 {
		class Quote {
		public:
			Quote() = default;
			Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
			std::string isbn() const { return bookNo; }
			virtual double net_price(std::size_t n) const { return n * price; }
			virtual ~Quote() = default;
		private:
			std::string bookNo;
		protected:
			double price = 0.0;
		};

		double print_total(std::ostream &, const Quote &, std::size_t);
	}
	namespace _05 {
		class Quote {
		public:
			Quote() = default;
			Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
			std::string isbn() const { return bookNo; }
			virtual double net_price(std::size_t n) const { return n * price; }
			virtual ~Quote() = default;
		private:
			std::string bookNo;
		protected:
			double price = 0.0;
		};

		double print_total(std::ostream &, const Quote &, std::size_t);

		class Bulk_quote : public Quote {
		public:
			Bulk_quote() = default;
			Bulk_quote(const std::string &, double, std::size_t, double);
			double net_price(std::size_t) const override;
		private:
			std::size_t min_qty = 0;
			double discount = 0.0;
		};
	}
	namespace _06 {
		class Quote {
		public:
			Quote() = default;
			Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
			std::string isbn() const { return bookNo; }
			virtual double net_price(std::size_t n) const { return n * price; }
			virtual ~Quote() = default;
		private:
			std::string bookNo;
		protected:
			double price = 0.0;
		};

		double print_total(std::ostream &, const Quote &, std::size_t);

		class Bulk_quote : public Quote {
		public:
			Bulk_quote() = default;
			Bulk_quote(const std::string &, double, std::size_t, double);
			double net_price(std::size_t) const override;
		private:
			std::size_t min_qty = 0;
			double discount = 0.0;
		};
	}
	namespace _07 {
		class Quote {
		public:
			Quote() = default;
			Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
			std::string isbn() const { return bookNo; }
			virtual double net_price(std::size_t n) const { return n * price; }
			virtual ~Quote() = default;
		private:
			std::string bookNo;
		protected:
			double price = 0.0;
		};

		double print_total(std::ostream &, const Quote &, std::size_t);

		class Retail_quote : public Quote {
		public:
			Retail_quote() = default;
			Retail_quote(const std::string &, double, std::size_t, double);
			double net_price(std::size_t) const override;
		private:
			std::size_t max_qty = 0;
			double discount = 0.0;
		};
	}
	namespace _11 {
		class Quote {
		public:
			Quote() = default;
			Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
			std::string isbn() const { return bookNo; }
			virtual double net_price(std::size_t n) const { return n * price; }
			virtual ~Quote() = default;

			virtual std::ostream &debug(std::ostream &) const;
		private:
			std::string bookNo;
		protected:
			double price = 0.0;
		};

		double print_total(std::ostream &, const Quote &, std::size_t);

		class Bulk_quote : public Quote {
		public:
			Bulk_quote() = default;
			Bulk_quote(const std::string &, double, std::size_t, double);
			double net_price(std::size_t) const override;

			std::ostream &debug(std::ostream &) const override;
		private:
			std::size_t min_qty = 0;
			double discount = 0.0;
		};

		class Retail_quote : public Quote {
		public:
			Retail_quote() = default;
			Retail_quote(const std::string &, double, std::size_t, double);
			double net_price(std::size_t) const override;

			std::ostream &debug(std::ostream &) const override;
		private:
			std::size_t max_qty = 0;
			double discount = 0.0;
		};
	}
	namespace _15 {
		class Quote {
		public:
			Quote() = default;
			Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
			std::string isbn() const { return bookNo; }
			virtual double net_price(std::size_t n) const { return n * price; }
			virtual ~Quote() = default;

			virtual std::ostream &debug(std::ostream &) const;
		private:
			std::string bookNo;
		protected:
			double price = 0.0;
		};

		double print_total(std::ostream &, const Quote &, std::size_t);

		class Disc_quote : public Quote {
		public:
			Disc_quote() = default;
			Disc_quote(const std::string &book, double price, std::size_t qty, double disc)
				: Quote(book, price), quantity(qty), discount(disc) {}
			double net_price(std::size_t) const = 0;
		protected:
			std::size_t quantity = 0;
			double discount = 0.0;
		};

		class Bulk_quote : public Disc_quote {
		public:
			Bulk_quote() = default;
			Bulk_quote(const std::string &book, double price, std::size_t qty, double disc)
				: Disc_quote(book, price, qty, disc) {}

			double net_price(std::size_t) const override;
		};
	}
	namespace _16 {
		class Quote {
		public:
			Quote() = default;
			Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
			std::string isbn() const { return bookNo; }
			virtual double net_price(std::size_t n) const { return n * price; }
			virtual ~Quote() = default;

			virtual std::ostream &debug(std::ostream &) const;
		private:
			std::string bookNo;
		protected:
			double price = 0.0;
		};

		double print_total(std::ostream &, const Quote &, std::size_t);

		class Disc_quote : public Quote {
		public:
			Disc_quote() = default;
			Disc_quote(const std::string &book, double price, std::size_t qty, double disc)
				: Quote(book, price), quantity(qty), discount(disc) {}
			double net_price(std::size_t) const = 0;
		protected:
			std::size_t quantity = 0;
			double discount = 0.0;
		};

		class Retail_quote : public Disc_quote {
		public:
			Retail_quote() = default;
			Retail_quote(const std::string &book, double price, std::size_t qty, double disc)
				: Disc_quote(book, price, qty, disc) {}

			double net_price(std::size_t) const override;
		};
	}
	namespace _17 {
		class Quote {
		public:
			Quote() = default;
			Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
			std::string isbn() const { return bookNo; }
			virtual double net_price(std::size_t n) const { return n * price; }
			virtual ~Quote() = default;

			virtual std::ostream &debug(std::ostream &) const;
		private:
			std::string bookNo;
		protected:
			double price = 0.0;
		};

		double print_total(std::ostream &, const Quote &, std::size_t);

		class Disc_quote : public Quote {
		public:
			Disc_quote() = default;
			Disc_quote(const std::string &book, double price, std::size_t qty, double disc)
				: Quote(book, price), quantity(qty), discount(disc) {}
			double net_price(std::size_t) const = 0;
		protected:
			std::size_t quantity = 0;
			double discount = 0.0;
		};
	}
	namespace _20 {
		class Base {
		public:
			void pub_mem();

			void memfcn(Base &b) { b = *this; }
		protected:
			int prot_mem;
		private:
			char priv_mem;
		};

		struct Pub_Derv : public Base {
			int f() { return prot_mem; }

			void memfcn(Base &b) { b = *this; }
		};

		struct Prot_Derv : protected Base {
			int func() const { return prot_mem; }

			void memfcn(Base &b) { b = *this; }
		};

		struct Priv_Derv : private Base {
			int f1() const { return prot_mem; }

			void memfcn(Base &b) { b = *this; }
		};

		struct Derived_from_Public : public Pub_Derv {
			int use_base() { return prot_mem; }

			void memfcn(Base &b) { b = *this; }
		};

		struct Derived_from_Protected : public Prot_Derv {
			int use_base() { return prot_mem; }

			void memfcn(Base &b) { b = *this; }
		};

		struct Derived_from_Private : public Priv_Derv {
			int i = 13;

//			void memfcn(Base &b) { b = *this; }
		};
	}
	namespace _21 {
		class Polygon {
			friend std::ostream &printCenter(std::ostream &, const Polygon &);
		public:
			Polygon() = default;
			Polygon(std::size_t sd, std::size_t crnr) : sideCount(sd), cornerCount(crnr) {}
			
			std::size_t sides() const { return sideCount; }
			std::size_t corners() const { return cornerCount; }

			virtual double perimeter() const = 0;
			virtual double area() const = 0;

			void center() { centerPoint = std::make_pair(0, 0); }

			virtual ~Polygon() = default;
		private:
			std::size_t sideCount = 0;
			std::size_t cornerCount = 0;
		protected:
			std::pair<int, int> centerPoint = std::make_pair(0, 0);
		};

		class Square : public Polygon {
		public:
			Square() = default;
			Square(double length) : Polygon(4, 4), sideLength(length) {}

			double length() const { return sideLength; }

			double perimeter() const override { return sideLength * sides(); }
			double area() const override { return sideLength * sideLength; }

			void moveDelta(int dx, int dy) {
				centerPoint.first += dx;
				centerPoint.second += dy;
			}

			~Square() = default;
		private:
			double sideLength = 0;
		};
	}
	namespace _26 {
		class Quote {
		public:
			Quote() : bookNo(""), price(0.0) {
				std::cout << "Quote default constructor" << std::endl;
			}
			Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {
				std::cout << "Quote constructor" << std::endl;
			}
			std::string isbn() const { return bookNo; }
			virtual double net_price(std::size_t n) const { return n * price; }
			virtual ~Quote() {
				std::cout << "Quote destructor" << std::endl;
			}
			
			Quote(const Quote &q) : bookNo(q.bookNo), price(q.price) {
				std::cout << "Quote copy constructor" << std::endl;
			}
			Quote(Quote &&q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price)) {
				std::cout << "Quote move constructor" << std::endl;
			}
			Quote &operator=(const Quote &rhs) {
				std::cout << "Quote copy assignment operator" << std::endl;
				bookNo = rhs.bookNo;
				price = rhs.price;
				return *this;
			}
			Quote &operator=(Quote &&rhs) noexcept {
				std::cout << "Quote move assignment operator" << std::endl;
				bookNo = std::move(rhs.bookNo);
				price = std::move(rhs.price);
				return *this;
			}

			virtual std::ostream &debug(std::ostream &) const;
		private:
			std::string bookNo;
		protected:
			double price = 0.0;
		};

		double print_total(std::ostream &, const Quote &, std::size_t);

		class Disc_quote : public Quote {
		public:
			Disc_quote() = default;
			Disc_quote(const std::string &book, double price, std::size_t qty, double disc)
				: Quote(book, price), quantity(qty), discount(disc) {}
			double net_price(std::size_t) const = 0;
		protected:
			std::size_t quantity = 0;
			double discount = 0.0;
		};

		class Bulk_quote : public Disc_quote {
		public:
			Bulk_quote() : Disc_quote() {
				std::cout << "Bulk_quote default constructor" << std::endl;
			}
			Bulk_quote(const std::string &book, double price, std::size_t qty, double disc)
				: Disc_quote(book, price, qty, disc) {
				std::cout << "Bulk_quote constructor" << std::endl;
			}

			double net_price(std::size_t) const override;

			Bulk_quote(const Bulk_quote &b) : Disc_quote(b) {
				std::cout << "Bulk_quote copy constructor" << std::endl;
			}
			Bulk_quote(Bulk_quote &&b) noexcept : Disc_quote(std::move(b)) {
				std::cout << "Bulk_quote move constructor" << std::endl;
			}
			Bulk_quote &operator=(const Bulk_quote &rhs) {
				Disc_quote::operator=(rhs);
				std::cout << "Bulk_quote copy assignment operator" << std::endl;
				return *this;
			}
			Bulk_quote &operator=(Bulk_quote &&rhs) noexcept {
				Disc_quote::operator=(std::move(rhs));
				std::cout << "Bulk_quote move assignment operator" << std::endl;
				return *this;
			}
			~Bulk_quote() {
				std::cout << "Bulk_quote destructor" << std::endl;
			}
		};
	}
	namespace _27 {
		class Quote {
		public:
			Quote() = default;
			Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
			std::string isbn() const { return bookNo; }
			virtual double net_price(std::size_t n) const { return n * price; }
			virtual ~Quote() = default;

			virtual std::ostream &debug(std::ostream &) const;
		private:
			std::string bookNo;
		protected:
			double price = 0.0;
		};

		double print_total(std::ostream &, const Quote &, std::size_t);

		class Disc_quote : public Quote {
		public:
			Disc_quote() = default;
			Disc_quote(const std::string &book, double price, std::size_t qty, double disc)
				: Quote(book, price), quantity(qty), discount(disc) {}
			double net_price(std::size_t) const = 0;
		protected:
			std::size_t quantity = 0;
			double discount = 0.0;
		};

		class Bulk_quote : public Disc_quote {
		public:
			using Disc_quote::Disc_quote;

			double net_price(std::size_t) const override;
		};
	}
	namespace _28 {
		class Quote {
		public:
			Quote() = default;
			Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
			std::string isbn() const { return bookNo; }
			virtual double net_price(std::size_t n) const { return n * price; }
			virtual ~Quote() = default;

			virtual std::ostream &debug(std::ostream &) const;
		private:
			std::string bookNo;
		protected:
			double price = 0.0;
		};

		double print_total(std::ostream &, const Quote &, std::size_t);

		class Disc_quote : public Quote {
		public:
			Disc_quote() = default;
			Disc_quote(const std::string &book, double price, std::size_t qty, double disc)
				: Quote(book, price), quantity(qty), discount(disc) {}
			double net_price(std::size_t) const = 0;
		protected:
			std::size_t quantity = 0;
			double discount = 0.0;
		};

		class Bulk_quote : public Disc_quote {
		public:
			using Disc_quote::Disc_quote;

			double net_price(std::size_t) const override;
		};
	}
	namespace _29 {
		class Quote {
		public:
			Quote() = default;
			Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
			std::string isbn() const { return bookNo; }
			virtual double net_price(std::size_t n) const { return n * price; }
			virtual ~Quote() = default;

			virtual std::ostream &debug(std::ostream &) const;
		private:
			std::string bookNo;
		protected:
			double price = 0.0;
		};

		double print_total(std::ostream &, const Quote &, std::size_t);

		class Disc_quote : public Quote {
		public:
			Disc_quote() = default;
			Disc_quote(const std::string &book, double price, std::size_t qty, double disc)
				: Quote(book, price), quantity(qty), discount(disc) {}
			double net_price(std::size_t) const = 0;
		protected:
			std::size_t quantity = 0;
			double discount = 0.0;
		};

		class Bulk_quote : public Disc_quote {
		public:
			using Disc_quote::Disc_quote;

			double net_price(std::size_t) const override;
		};
	}
	namespace _30 {
		class Quote {
		public:
			Quote() = default;
			Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
			std::string isbn() const { return bookNo; }
			virtual double net_price(std::size_t n) const { return n * price; }
			virtual ~Quote() = default;

			virtual Quote *clone() const & 	{ return new Quote(*this);				}
			virtual Quote *clone() &&		{ return new Quote(std::move(*this)); 	}
			virtual std::ostream &debug(std::ostream &) const;
		private:
			std::string bookNo;
		protected:
			double price = 0.0;
		};

		double print_total(std::ostream &, const Quote &, std::size_t);

		class Disc_quote : public Quote {
		public:
			Disc_quote() = default;
			Disc_quote(const std::string &book, double price, std::size_t qty, double disc)
				: Quote(book, price), quantity(qty), discount(disc) {}
			double net_price(std::size_t) const = 0;
		protected:
			std::size_t quantity = 0;
			double discount = 0.0;
		};

		class Bulk_quote : public Disc_quote {
		public:
			using Disc_quote::Disc_quote;

			double net_price(std::size_t) const override;
			Bulk_quote *clone() const & override	{ return new Bulk_quote(*this); }
			Bulk_quote *clone() && override 		{ return new Bulk_quote(std::move(*this)); }
		};


		class Basket {
		public:
			// "old" method that takes a shared_ptr
			void add_item(const std::shared_ptr<Quote> &sale) {
				items.insert(sale);
			}
			// methods that manage memory allocation instead of the user
			void add_item(const Quote &sale) {
				items.insert(std::shared_ptr<Quote>(sale.clone()));
			}
			void add_item(Quote &&sale)	{
				items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
			}
			
			double total_receipt(std::ostream &) const;
		private:
			static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) {
				return lhs->isbn() < rhs->isbn();
			}
			std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
		};
	}
	namespace _35 {
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
						
						// erase not alphanumeric characters from the current word
						word.erase(std::remove_if(word.begin(), word.end(), [](char c){ return !std::isalnum(c); }), word.end());
						
						// transform current word's all characters to lowercase
						std::transform(word.begin(), word.end(), word.begin(), [](char c){ return std::tolower(c); });
						
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

		class Query_base {
			friend class Query;
		protected:
			using line_no = TextQuery::line_no;
			virtual ~Query_base() = default;
		private:
			virtual std::string rep() const = 0;
		};

		class WordQuery : public Query_base {
			friend class Query;

			WordQuery(const std::string &s) : query_word(s) {}
			
			std::string rep() const override { return query_word; }
			std::string query_word;
		};

		class Query {
			friend Query operator~(const Query &);
			friend Query operator|(const Query &, const Query &);
			friend Query operator&(const Query &, const Query &);
		public:
			Query(const std::string &s) : q(new WordQuery(s)) {}

			std::string rep() const { return q->rep(); }
		private:
			Query(std::shared_ptr<Query_base> query) : q(query) {}

			std::shared_ptr<Query_base> q;
		};

		std::ostream &operator<<(std::ostream &, const Query &);

		class NotQuery : public Query_base {
			friend Query operator~(const Query &);
			NotQuery(const Query &q) : query(q) {}

			std::string rep() const override { return "~(" + query.rep() + ")"; }
			Query query;
		};

		inline Query operator~(const Query &operand) {
			return std::shared_ptr<Query_base>(new NotQuery(operand));
		}

		class BinaryQuery : public Query_base {
		protected:
			BinaryQuery(const Query &l, const Query &r, std::string s)
				: lhs(l), rhs(r), opSym(s) {}
			std::string rep() const override {
					return "(" + lhs.rep() + " "
							   + opSym + " "
							   + rhs.rep() + ")";
			}
			Query lhs, rhs;
			std::string opSym;
		};

		class AndQuery : public BinaryQuery {
			friend Query operator&(const Query &, const Query &);
			AndQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "&") {}
		};

		inline Query operator&(const Query &lhs, const Query &rhs) {
			return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
		}

		class OrQuery : public BinaryQuery {
			friend Query operator|(const Query &, const Query &);
			OrQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "|") {}
		};

		inline Query operator|(const Query &lhs, const Query &rhs) {
			return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
		}
	}
	namespace _36 {
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
						
						// erase not alphanumeric characters from the current word
						word.erase(std::remove_if(word.begin(), word.end(), [](char c){ return !std::isalnum(c); }), word.end());
						
						// transform current word's all characters to lowercase
						std::transform(word.begin(), word.end(), word.begin(), [](char c){ return std::tolower(c); });
						
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

		class Query_base {
			friend class Query;
		protected:
			using line_no = TextQuery::line_no;
			virtual ~Query_base() = default;
		private:
			virtual std::string rep() const = 0;
		};

		class WordQuery : public Query_base {
			friend class Query;

			WordQuery(const std::string &s) : query_word(s) {
				std::cout << "WordQuery::WordQuery" << std::endl;
			}
			
			std::string rep() const override {
				std::cout << "WordQuery::rep" << std::endl;
				return query_word;
			}
			std::string query_word;
		};

		class Query {
			friend Query operator~(const Query &);
			friend Query operator|(const Query &, const Query &);
			friend Query operator&(const Query &, const Query &);
		public:
			Query(const std::string &s) : q(new WordQuery(s)) {
				std::cout << "Query::Query (string)" << std::endl;
			}

			std::string rep() const {
				std::cout << "Query::rep" << std::endl;
				return q->rep();
			}
		private:
			Query(std::shared_ptr<Query_base> query) : q(query) {
				std::cout << "Query::Query (shared_ptr)" << std::endl;
			}

			std::shared_ptr<Query_base> q;
		};

		std::ostream &operator<<(std::ostream &, const Query &);

		class NotQuery : public Query_base {
			friend Query operator~(const Query &);
			NotQuery(const Query &q) : query(q) {
				std::cout << "NotQuery::NotQuery" << std::endl;
			}

			std::string rep() const override {
				std::cout << "NotQuery::rep" << std::endl;
				return "~(" + query.rep() + ")";
			}
			Query query;
		};

		inline Query operator~(const Query &operand) {
			return std::shared_ptr<Query_base>(new NotQuery(operand));
		}

		class BinaryQuery : public Query_base {
		protected:
			BinaryQuery(const Query &l, const Query &r, std::string s)
				: lhs(l), rhs(r), opSym(s) {
				std::cout << "BinaryQuery::BinaryQuery" << std::endl;	
			}
			std::string rep() const override {
					std::cout << "BinaryQuery::rep" << std::endl;
					return "(" + lhs.rep() + " "
							   + opSym + " "
							   + rhs.rep() + ")";
			}
			Query lhs, rhs;
			std::string opSym;
		};

		class AndQuery : public BinaryQuery {
			friend Query operator&(const Query &, const Query &);
			AndQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "&") {
				std::cout << "AndQuery::AndQuery" << std::endl;
			}
		};

		inline Query operator&(const Query &lhs, const Query &rhs) {
			return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
		}

		class OrQuery : public BinaryQuery {
			friend Query operator|(const Query &, const Query &);
			OrQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "|") {
				std::cout << "OrQuery::OrQuery" << std::endl;
			}
		};

		inline Query operator|(const Query &lhs, const Query &rhs) {
			return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
		}
	}
	namespace _39 {
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
						
						// erase not alphanumeric characters from the current word
						word.erase(std::remove_if(word.begin(), word.end(), [](char c){ return !std::isalnum(c); }), word.end());
						
						// transform current word's all characters to lowercase
						std::transform(word.begin(), word.end(), word.begin(), [](char c){ return std::tolower(c); });
						
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

		class Query_base {
			friend class Query;
		protected:
			using line_no = TextQuery::line_no;
			virtual ~Query_base() = default;
		private:
			virtual std::string rep() const = 0;
			virtual QueryResult eval(const TextQuery &) const = 0;
		};

		class WordQuery : public Query_base {
			friend class Query;

			WordQuery(const std::string &s) : query_word(s) {}
			
			std::string rep() const override {
				return query_word;
			}
			QueryResult eval(const TextQuery &t) const override {
				return t.query(query_word);
			}

			std::string query_word;
		};

		class Query {
			friend Query operator~(const Query &);
			friend Query operator|(const Query &, const Query &);
			friend Query operator&(const Query &, const Query &);
		public:
			Query(const std::string &s) : q(new WordQuery(s)) {}

			std::string rep() const {
				return q->rep();
			}
			QueryResult eval(const TextQuery &t) const {
				return q->eval(t);
			}
		private:
			Query(std::shared_ptr<Query_base> query) : q(query) {}

			std::shared_ptr<Query_base> q;
		};

		std::ostream &operator<<(std::ostream &, const Query &);

		class NotQuery : public Query_base {
			friend Query operator~(const Query &);
			NotQuery(const Query &q) : query(q) {
				std::cout << "NotQuery::NotQuery" << std::endl;
			}

			std::string rep() const override {
				std::cout << "NotQuery::rep" << std::endl;
				return "~(" + query.rep() + ")";
			}
			QueryResult eval(const TextQuery &) const override;

			Query query;
		};

		inline Query operator~(const Query &operand) {
			return std::shared_ptr<Query_base>(new NotQuery(operand));
		}

		class BinaryQuery : public Query_base {
		protected:
			BinaryQuery(const Query &l, const Query &r, std::string s)
				: lhs(l), rhs(r), opSym(s) {}
			std::string rep() const {
					return "(" + lhs.rep() + " "
							   + opSym + " "
							   + rhs.rep() + ")";
			}
			Query lhs, rhs;
			std::string opSym;
		};

		class AndQuery : public BinaryQuery {
			friend Query operator&(const Query &, const Query &);
			AndQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "&") {}
			QueryResult eval(const TextQuery &) const override;
		};

		inline Query operator&(const Query &lhs, const Query &rhs) {
			return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
		}

		class OrQuery : public BinaryQuery {
			friend Query operator|(const Query &, const Query &);
			OrQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "|") {}
			QueryResult eval(const TextQuery &) const override;
		};

		inline Query operator|(const Query &lhs, const Query &rhs) {
			return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
		}
	}
	namespace _41 {
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
						
						// erase not alphanumeric characters from the current word
						word.erase(std::remove_if(word.begin(), word.end(), [](char c){ return !std::isalnum(c); }), word.end());
						
						// transform current word's all characters to lowercase
						std::transform(word.begin(), word.end(), word.begin(), [](char c){ return std::tolower(c); });
						
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

		class Query_base {
			friend class Query;
		protected:
			using line_no = TextQuery::line_no;

			Query_base() = default;
			Query_base(const Query_base &) = default;
			Query_base(Query_base &&) = default;
			Query_base &operator=(const Query_base &) = default;
			Query_base &operator=(Query_base &&) = default;
			virtual ~Query_base() = default;
		private:
			virtual std::string rep() const = 0;
			virtual QueryResult eval(const TextQuery &) const = 0;

			virtual Query_base *clone() const = 0;
		};

		class WordQuery : public Query_base {
			friend class Query;

			WordQuery(const std::string &s) : query_word(s) {}
			
			std::string rep() const override {
				return query_word;
			}
			QueryResult eval(const TextQuery &t) const override {
				return t.query(query_word);
			}
			WordQuery *clone() const override {
				return new WordQuery(query_word);
			}

			// Copy constructor
			WordQuery(const WordQuery &wq) : Query_base(wq), query_word(wq.query_word) {}
			// Move constructor
			WordQuery(WordQuery &&wq) noexcept : Query_base(std::move(wq)), query_word(std::move(wq.query_word)) {}
			// Copy-assignment operator
			WordQuery &operator=(const WordQuery &rhs) {
				Query_base::operator=(rhs);
				query_word = rhs.query_word;
				return *this;
			}
			// Move assignment operator
			WordQuery &operator=(WordQuery &&rhs) noexcept {
				if (this != &rhs) {
					Query_base::operator=(std::move(rhs));
					query_word = std::move(rhs.query_word);
				}
				return *this;
			}
			// Destructor
			~WordQuery() = default;

			std::string query_word;
		};

		class Query {
			friend Query operator~(const Query &);
			friend Query operator|(const Query &, const Query &);
			friend Query operator&(const Query &, const Query &);
		public:
			Query(const std::string &s) : q(new WordQuery(s)) {}

			std::string rep() const {
				return q->rep();
			}
			QueryResult eval(const TextQuery &t) const {
				return q->eval(t);
			}
			// Copy constructor
			Query(const Query &query) : q(query.clone()) {}
			// Move constructor
			Query(Query &&query) : q(query.q) {
				query.q = nullptr;
			}
			// Copy-assignment operator
			Query &operator=(const Query &rhs) {
				Query_base *temp = rhs.clone();
				delete q;
				q = temp;
				return *this;
			}
			// Move-assignment operator
			Query &operator=(Query &&rhs) {
				if (this != &rhs) {
					delete q;
					q = rhs.q;
					rhs.q = nullptr;
				}
				return *this;
			}
			// Destructor
			~Query() {
				delete q;
			}
		private:
			Query(Query_base *query) : q(query) {}
			Query_base *clone() const {
				return q->clone();
			}

			Query_base *q = nullptr;
		};

		std::ostream &operator<<(std::ostream &, const Query &);

		class NotQuery : public Query_base {
			friend Query operator~(const Query &);
			NotQuery(const Query &q) : query(q) {
				std::cout << "NotQuery::NotQuery" << std::endl;
			}

			std::string rep() const override {
				std::cout << "NotQuery::rep" << std::endl;
				return "~(" + query.rep() + ")";
			}
			QueryResult eval(const TextQuery &) const override;
			NotQuery *clone() const override {
				return new NotQuery(query);
			}

			// Copy constructor
			NotQuery(const NotQuery &nq) : Query_base(nq), query(nq.query) {}
			// Move constructor
			NotQuery(NotQuery &&nq) noexcept : Query_base(std::move(nq)), query(std::move(nq.query)) {}
			// Copy-assignment operator
			NotQuery &operator=(const NotQuery &rhs) {
				Query_base::operator=(rhs);
				query = rhs.query;
				return *this;
			}
			// Move-assignment operator
			NotQuery &operator=(NotQuery &&rhs) noexcept {
				if (this != &rhs) {
					Query_base::operator=(std::move(rhs));
					query = std::move(rhs.query);
				}
				return *this;
			}
			// Destructor
			~NotQuery() = default;

			Query query;
		};

		inline Query operator~(const Query &operand) {
			return new NotQuery(operand);
		}

		class BinaryQuery : public Query_base {
		protected:
			BinaryQuery(const Query &l, const Query &r, std::string s)
				: lhs(l), rhs(r), opSym(s) {}
			std::string rep() const {
					return "(" + lhs.rep() + " "
							   + opSym + " "
							   + rhs.rep() + ")";
			}

			// Copy constructor
			BinaryQuery(const BinaryQuery &bq)
					: Query_base(bq), lhs(bq.lhs), rhs(bq.rhs), opSym(bq.opSym) {}
			// Move constructor
			BinaryQuery(BinaryQuery &&bq) noexcept
					: Query_base(std::move(bq)), lhs(std::move(bq.lhs)),
					rhs(std::move(bq.rhs)), opSym(std::move(bq.opSym)) {}
			// Copy-assignment operator
			BinaryQuery &operator=(const BinaryQuery &rhs_bq) {
				Query_base::operator=(rhs_bq);
				lhs = rhs_bq.lhs;
				rhs = rhs_bq.rhs;
				opSym = rhs_bq.opSym;
				return *this;
			}
			// Move-assignment operator
			BinaryQuery &operator=(BinaryQuery &&rhs_bq) noexcept {
				if (this != &rhs_bq) {
					Query_base::operator=(std::move(rhs_bq));
					lhs = std::move(rhs_bq.lhs);
					rhs = std::move(rhs_bq.rhs);
					opSym = std::move(rhs_bq.opSym);
				}
				return *this;
			}
			// Destructor
			~BinaryQuery() = default;

			Query lhs, rhs;
			std::string opSym;
		};

		class AndQuery : public BinaryQuery {
			friend Query operator&(const Query &, const Query &);
			AndQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "&") {}
			QueryResult eval(const TextQuery &) const override;

			AndQuery *clone() const override {
				return new AndQuery(lhs, rhs);
			}

			// Copy constructor
			AndQuery(const AndQuery &aq) : BinaryQuery(aq) {}
			// Move constructor
			AndQuery(AndQuery &&aq) noexcept : BinaryQuery(std::move(aq)) {}
			// Copy-assignment operator
			AndQuery &operator=(const AndQuery &rhs) {
				BinaryQuery::operator=(rhs);
				return *this;
			}
			// Move-assignment operator
			AndQuery &operator=(AndQuery &&rhs) noexcept {
				if (this != &rhs) {
					BinaryQuery::operator=(std::move(rhs));
				}
				return *this;
			}
			// Destructor
			~AndQuery() = default;
		};

		inline Query operator&(const Query &lhs, const Query &rhs) {
			return new AndQuery(lhs, rhs);
		}

		class OrQuery : public BinaryQuery {
			friend Query operator|(const Query &, const Query &);
			OrQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "|") {}
			QueryResult eval(const TextQuery &) const override;

			OrQuery *clone() const override {
				return new OrQuery(lhs, rhs);
			}

			// Copy constructor
			OrQuery(const OrQuery &oq) : BinaryQuery(oq) {}
			// Move constructor
			OrQuery(OrQuery &&oq) noexcept : BinaryQuery(std::move(oq)) {}
			// Copy-assignment operator
			OrQuery &operator=(const OrQuery &rhs) {
				BinaryQuery::operator=(rhs);
				return *this;
			}
			// Move-assignment operator
			OrQuery &operator=(OrQuery &&rhs) noexcept {
				if (this != &rhs) {
					BinaryQuery::operator=(std::move(rhs));
				}
				return *this;
			}
			// Destructor
			~OrQuery() = default;
		};

		inline Query operator|(const Query &lhs, const Query &rhs) {
			return new OrQuery(lhs, rhs);
		}
	}
	namespace _42 {
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
						
						// erase not alphanumeric characters from the current word
						word.erase(std::remove_if(word.begin(), word.end(), [](char c){ return !std::isalnum(c); }), word.end());
						
						// transform current word's all characters to lowercase
						std::transform(word.begin(), word.end(), word.begin(), [](char c){ return std::tolower(c); });
						
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
		friend std::ostream &print(std::ostream &, const QueryResult &, std::size_t, std::size_t);
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

		class Query_base {
			friend class Query;
		protected:
			using line_no = TextQuery::line_no;

			Query_base() = default;
			Query_base(const Query_base &) = default;
			Query_base(Query_base &&) = default;
			Query_base &operator=(const Query_base &) = default;
			Query_base &operator=(Query_base &&) = default;
			virtual ~Query_base() = default;
		private:
			virtual std::string rep() const = 0;
			virtual QueryResult eval(const TextQuery &) const = 0;

			virtual Query_base *clone() const = 0;
		};

		class WordQuery : public Query_base {
			friend class Query;

			WordQuery(const std::string &s) : query_word(s) {}
			
			std::string rep() const override {
				return query_word;
			}
			QueryResult eval(const TextQuery &t) const override {
				return t.query(query_word);
			}
			WordQuery *clone() const override {
				return new WordQuery(query_word);
			}

			// Copy constructor
			WordQuery(const WordQuery &wq) : Query_base(wq), query_word(wq.query_word) {}
			// Move constructor
			WordQuery(WordQuery &&wq) noexcept : Query_base(std::move(wq)), query_word(std::move(wq.query_word)) {}
			// Copy-assignment operator
			WordQuery &operator=(const WordQuery &rhs) {
				Query_base::operator=(rhs);
				query_word = rhs.query_word;
				return *this;
			}
			// Move assignment operator
			WordQuery &operator=(WordQuery &&rhs) noexcept {
				if (this != &rhs) {
					Query_base::operator=(std::move(rhs));
					query_word = std::move(rhs.query_word);
				}
				return *this;
			}
			// Destructor
			~WordQuery() = default;

			std::string query_word;
		};

		class Query {
			friend Query operator~(const Query &);
			friend Query operator|(const Query &, const Query &);
			friend Query operator&(const Query &, const Query &);
		public:
			Query(const std::string &s) : q(new WordQuery(s)) {}

			std::string rep() const {
				return q->rep();
			}
			QueryResult eval(const TextQuery &t) const {
				return q->eval(t);
			}
			// Copy constructor
			Query(const Query &query) : q(query.clone()) {}
			// Move constructor
			Query(Query &&query) : q(query.q) {
				query.q = nullptr;
			}
			// Copy-assignment operator
			Query &operator=(const Query &rhs) {
				Query_base *temp = rhs.clone();
				delete q;
				q = temp;
				return *this;
			}
			// Move-assignment operator
			Query &operator=(Query &&rhs) {
				if (this != &rhs) {
					delete q;
					q = rhs.q;
					rhs.q = nullptr;
				}
				return *this;
			}
			// Destructor
			~Query() {
				delete q;
			}
		private:
			Query(Query_base *query) : q(query) {}
			Query_base *clone() const {
				return q->clone();
			}

			Query_base *q = nullptr;
		};

		std::ostream &operator<<(std::ostream &, const Query &);

		class NotQuery : public Query_base {
			friend Query operator~(const Query &);
			NotQuery(const Query &q) : query(q) {
				std::cout << "NotQuery::NotQuery" << std::endl;
			}

			std::string rep() const override {
				std::cout << "NotQuery::rep" << std::endl;
				return "~(" + query.rep() + ")";
			}
			QueryResult eval(const TextQuery &) const override;
			NotQuery *clone() const override {
				return new NotQuery(query);
			}

			// Copy constructor
			NotQuery(const NotQuery &nq) : Query_base(nq), query(nq.query) {}
			// Move constructor
			NotQuery(NotQuery &&nq) noexcept : Query_base(std::move(nq)), query(std::move(nq.query)) {}
			// Copy-assignment operator
			NotQuery &operator=(const NotQuery &rhs) {
				Query_base::operator=(rhs);
				query = rhs.query;
				return *this;
			}
			// Move-assignment operator
			NotQuery &operator=(NotQuery &&rhs) noexcept {
				if (this != &rhs) {
					Query_base::operator=(std::move(rhs));
					query = std::move(rhs.query);
				}
				return *this;
			}
			// Destructor
			~NotQuery() = default;

			Query query;
		};

		inline Query operator~(const Query &operand) {
			return new NotQuery(operand);
		}

		class BinaryQuery : public Query_base {
		protected:
			BinaryQuery(const Query &l, const Query &r, std::string s)
				: lhs(l), rhs(r), opSym(s) {}
			std::string rep() const {
					return "(" + lhs.rep() + " "
							   + opSym + " "
							   + rhs.rep() + ")";
			}

			// Copy constructor
			BinaryQuery(const BinaryQuery &bq)
					: Query_base(bq), lhs(bq.lhs), rhs(bq.rhs), opSym(bq.opSym) {}
			// Move constructor
			BinaryQuery(BinaryQuery &&bq) noexcept
					: Query_base(std::move(bq)), lhs(std::move(bq.lhs)),
					rhs(std::move(bq.rhs)), opSym(std::move(bq.opSym)) {}
			// Copy-assignment operator
			BinaryQuery &operator=(const BinaryQuery &rhs_bq) {
				Query_base::operator=(rhs_bq);
				lhs = rhs_bq.lhs;
				rhs = rhs_bq.rhs;
				opSym = rhs_bq.opSym;
				return *this;
			}
			// Move-assignment operator
			BinaryQuery &operator=(BinaryQuery &&rhs_bq) noexcept {
				if (this != &rhs_bq) {
					Query_base::operator=(std::move(rhs_bq));
					lhs = std::move(rhs_bq.lhs);
					rhs = std::move(rhs_bq.rhs);
					opSym = std::move(rhs_bq.opSym);
				}
				return *this;
			}
			// Destructor
			~BinaryQuery() = default;

			Query lhs, rhs;
			std::string opSym;
		};

		class AndQuery : public BinaryQuery {
			friend Query operator&(const Query &, const Query &);
			AndQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "&") {}
			QueryResult eval(const TextQuery &) const override;

			AndQuery *clone() const override {
				return new AndQuery(lhs, rhs);
			}

			// Copy constructor
			AndQuery(const AndQuery &aq) : BinaryQuery(aq) {}
			// Move constructor
			AndQuery(AndQuery &&aq) noexcept : BinaryQuery(std::move(aq)) {}
			// Copy-assignment operator
			AndQuery &operator=(const AndQuery &rhs) {
				BinaryQuery::operator=(rhs);
				return *this;
			}
			// Move-assignment operator
			AndQuery &operator=(AndQuery &&rhs) noexcept {
				if (this != &rhs) {
					BinaryQuery::operator=(std::move(rhs));
				}
				return *this;
			}
			// Destructor
			~AndQuery() = default;
		};

		inline Query operator&(const Query &lhs, const Query &rhs) {
			return new AndQuery(lhs, rhs);
		}

		class OrQuery : public BinaryQuery {
			friend Query operator|(const Query &, const Query &);
			OrQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "|") {}
			QueryResult eval(const TextQuery &) const override;

			OrQuery *clone() const override {
				return new OrQuery(lhs, rhs);
			}

			// Copy constructor
			OrQuery(const OrQuery &oq) : BinaryQuery(oq) {}
			// Move constructor
			OrQuery(OrQuery &&oq) noexcept : BinaryQuery(std::move(oq)) {}
			// Copy-assignment operator
			OrQuery &operator=(const OrQuery &rhs) {
				BinaryQuery::operator=(rhs);
				return *this;
			}
			// Move-assignment operator
			OrQuery &operator=(OrQuery &&rhs) noexcept {
				if (this != &rhs) {
					BinaryQuery::operator=(std::move(rhs));
				}
				return *this;
			}
			// Destructor
			~OrQuery() = default;
		};

		inline Query operator|(const Query &lhs, const Query &rhs) {
			return new OrQuery(lhs, rhs);
		}
	}
	}
}

#endif
