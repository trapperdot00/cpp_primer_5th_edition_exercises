#include "chapter13.h"

namespace cplusplus_primer {
	namespace chapter13 {
	namespace _18 {
		std::size_t Employee::currentID = 0;

		Employee::Employee() : id(currentID++) {}
		Employee::Employee(const std::string &n) : name(n), id(currentID++) {}

		std::ostream &print(std::ostream &os, const Employee &e) {
			os << e.name << ' ' << e.id;
			return os;
		}
	}
	namespace _19 {
		std::size_t Employee::currentID = 0;

		Employee::Employee() : id(currentID++) {}
		Employee::Employee(const std::string &n) : name(n), id(currentID++) {}

		Employee::Employee(const Employee &e) : name(e.name), id(currentID++) {}
		Employee &Employee::operator=(const Employee &e) {
			name = e.name;
			return *this;
		}

		std::ostream &print(std::ostream &os, const Employee &e) {
			os << e.name << ' ' << e.id;
			return os;
		}
	}
	namespace _26 {
		StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }
		StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) { }

		StrBlob::StrBlob(const StrBlob &obj) : data(std::make_shared<std::vector<std::string>>(*obj.data)) { }
		StrBlob &StrBlob::operator=(const StrBlob &rhs) {
			data = std::make_shared<std::vector<std::string>>(*rhs.data);
			return *this;
		}

		void StrBlob::check(size_type i, const std::string &msg) const {
			if (i >= data->size())
				throw std::out_of_range(msg);
		}

		std::string &StrBlob::front() {
			check(0, "front on empty StrBlob");
			return data->front();
		}

		const std::string &StrBlob::front() const {
			check(0, "front on empty const StrBlob");
			return data->front();
		}

		std::string &StrBlob::back() {
			check(0, "back on empty StrBlob");
			return data->back();
		}

		const std::string &StrBlob::back() const {
			check(0, "back on empty const StrBlob");
			return data->back();
		}

		void StrBlob::pop_back() {
			check(9, "pop_back on empty StrBlob");
			data->pop_back();
		}

		StrBlobPtr StrBlob::begin() {
			return StrBlobPtr(*this);
		}

		StrBlobPtr StrBlob::end() {
			return StrBlobPtr(*this, data->size());
		}

		ConstStrBlobPtr StrBlob::cbegin() const {
			return ConstStrBlobPtr(*this);
		}

		ConstStrBlobPtr StrBlob::cend() const {
			return ConstStrBlobPtr(*this, data->size());
		}

		// StrBlobPtr

		StrBlobPtr::StrBlobPtr() : curr(0) { }
		StrBlobPtr::StrBlobPtr(StrBlob &a, std::size_t i) : wptr(a.data), curr(i) { }

		std::string &StrBlobPtr::deref() const {
			std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}

		StrBlobPtr &StrBlobPtr::incr() {
			check(curr, "increment past end of StrBlobPtr");
			++curr;
			return *this;
		}

		std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const {
			std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
			if (!ret) {
				throw std::runtime_error("unbound StrBlobPtr");
			}
			if (i >= ret->size()) {
				throw std::out_of_range(msg);
			}
			return ret;
		}

		// ConstStrBlobPtr

		ConstStrBlobPtr::ConstStrBlobPtr() : curr(0) { }
		ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob &a, std::size_t i) : wptr(a.data), curr(i) { }

		const std::string &ConstStrBlobPtr::deref() const {
			std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
			return (*p)[curr];
		}

		ConstStrBlobPtr &ConstStrBlobPtr::incr() {
			check(curr, "increment past end of StrBlobPtr");
			++curr;
			return *this;
		}

		std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const {
			std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
			if (!ret) {
				throw std::runtime_error("unbound ConstStrBlobPtr");
			}
			if (i >= ret->size()) {
				throw std::out_of_range(msg);
			}
			return ret;
		}
	}
	namespace _27 {
		HasPtr::HasPtr(const std::string &s) : ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
		HasPtr::HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }

		HasPtr &HasPtr::operator=(const HasPtr &rhs) {
			++*rhs.use;
			if (--*use == 0) {
				delete ps;
				delete use;
			}
			ps = rhs.ps;
			i = rhs.i;
			use = rhs.use;
			return *this;
		}

		HasPtr::~HasPtr() {
			if (--*use == 0) {
				delete ps;
				delete use;
			}
		}
	}
	namespace _28 {
		TreeNode::TreeNode() : value(""), count(new int(1)), left(nullptr), right(nullptr) { }
		TreeNode::TreeNode(const TreeNode &t) : value(t.value), count(t.count), left(t.left), right(t.right) { ++*count; }
		TreeNode &TreeNode::operator=(const TreeNode &rhs) {
			++*rhs.count;
			if (--*count == 0) {
				delete count;
				delete left;
				delete right;
			}
			value = rhs.value;
			count = rhs.count;
			left = rhs.left;
			right = rhs.right;
			return *this;
		}
		TreeNode::~TreeNode() {
			if (--*count == 0) {
				delete count;
				delete left;
				delete right;
			}
		}

		BinStrTree::BinStrTree() : root(new TreeNode()) { }
		BinStrTree::BinStrTree(const BinStrTree &b) : root(new TreeNode(*b.root)) { }
		BinStrTree &BinStrTree::operator=(const BinStrTree &rhs) {
			TreeNode *newRoot = new TreeNode(*rhs.root);
			delete root;
			root = newRoot;
			return *this;
		}
		BinStrTree::~BinStrTree() {
			delete root;
		}
	}
	namespace _30 {
		// VALUELIKE

		HasPtr::HasPtr(const std::string &s) : ps(new std::string(s)), i(0) { }
		HasPtr::HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i) { }
		HasPtr &HasPtr::operator=(HasPtr rhs) {
			swap(*this, rhs);
			return *this;
		}
		HasPtr::~HasPtr() {
			delete ps;
		}
	}
	namespace _31 {
		// VALUELIKE

		HasPtr::HasPtr(const std::string &s) : ps(new std::string(s)), i(0) { }
		HasPtr::HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i) { }
		HasPtr &HasPtr::operator=(HasPtr rhs) {
			swap(*this, rhs);
			return *this;
		}
		HasPtr::~HasPtr() {
			delete ps;
		}

		std::ostream &print(std::ostream &os, const HasPtr &p) {
			os << *p.ps;
			return os;
		}
	}	
	namespace _37 {
		Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
			add_to_Folders(m);
		}

		Message &Message::operator=(const Message &rhs) {
			remove_from_Folders();
			contents = rhs.contents;
			folders = rhs.folders;
			add_to_Folders(rhs);
			return *this;
		}

		Message::~Message() {
			remove_from_Folders();
		}

		void Message::save(Folder &f) {
			folders.insert(&f);
			f.addMsg(this);
		}

		void Message::remove(Folder &f) {
			folders.erase(&f);
			f.remMsg(this);
		}

		void Message::addFld(Folder *f) {
			folders.insert(f);
		}
		void Message::remFld(Folder *f) {
			folders.erase(f);
		}

		void Message::add_to_Folders(const Message &m) {
			for (Folder *f : m.folders)
				f->addMsg(this);
		}
		void Message::remove_from_Folders() {
			for (Folder *f : folders)
				f->remMsg(this);
		}

		void swap(Message &lhs, Message &rhs) {
			using std::swap;
			for (Folder *f : lhs.folders)
				f->remMsg(&lhs);
			for (Folder *f : rhs.folders)
				f->remMsg(&rhs);
			swap(lhs.contents, rhs.contents);
			swap(lhs.folders, rhs.folders);
			for (Folder *f : lhs.folders)
				f->addMsg(&lhs);
			for (Folder *f : rhs.folders)
				f->addMsg(&rhs);
		}


		Folder::Folder(const Folder &f) : name(f.name), messages(f.messages) {
			add_to_Messages(f);
		}

		Folder &Folder::operator=(const Folder &rhs) {
			remove_from_Messages();
			name = rhs.name;
			messages = rhs.messages;
			add_to_Messages(rhs);
			return *this;
		}

		Folder::~Folder() {
			remove_from_Messages();
		}

		void Folder::addMsg(Message *m) {
			messages.insert(m);
		}

		void Folder::remMsg(Message *m) {
			messages.erase(m);
		}

		void Folder::add_to_Messages(const Folder &f) {
			for (Message *m : f.messages)
				m->addFld(this);
		}
		void Folder::remove_from_Messages() {
			for (Message *m : messages)
				m->remFld(this);
		}

		void swap(Folder &lhs, Folder &rhs) {
			using std::swap;
			for (Message *m : lhs.messages)
				m->remFld(&lhs);
			for (Message *m : rhs.messages)
				m->remFld(&rhs);
			swap(lhs.name, rhs.name);
			swap(lhs.messages, rhs.messages);
			for (Message *m : lhs.messages)
				m->addFld(&lhs);
			for (Message *m : rhs.messages)
				m->addFld(&rhs);
		}

		std::ostream &print(std::ostream &os, const Folder &f) {
			os << "Folder : " << f.name << std::endl;
			for (Message *m : f.messages)
				os << m->contents << std::endl;
			return os;
		}
	}
	namespace _39 {
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
				alloc.deallocate(elements, cap - elements);
			}
		}

		StrVec::StrVec(const StrVec &s) {
			// call alloc_n_copy to allocate exactly as many elements as in s
			std::pair<std::string *, std::string *> newdata = alloc_n_copy(s.begin(), s.end());
			elements = newdata.first;
			first_free = cap = newdata.second;
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
	}
	namespace _40 {
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
	}
	namespace _42 {
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

		TextQuery::TextQuery(std::ifstream &in) : text(std::make_shared<StrVec>()) {
			std::size_t currLine = 0;
			for (std::string line; std::getline(in, line); text->push_back(line)) {
				std::istringstream stream(line);
				std::string word;
				while (stream >> word) {
					std::shared_ptr<std::set<std::size_t>> &lines = wordLines[word];
					if (!lines)
						lines.reset(new std::set<std::size_t>);
					lines->insert(currLine);
				}
				++currLine;
			}
		}

		QueryResult TextQuery::query(const std::string &s) const {
			static std::shared_ptr<std::set<std::size_t>> nodata = std::make_shared<std::set<std::size_t>>();
			if (wordLines.find(s) == wordLines.end())
				return QueryResult(s, text, nodata);
			return QueryResult(s, text, (*wordLines.find(s)).second);
		}

		QueryResult::QueryResult(const std::string &s, const std::shared_ptr<StrVec> &t, const std::shared_ptr<std::set<std::size_t>> &p) : sought(s), text(t), lineNums(p) {}

		std::ostream &print(std::ostream &os, const QueryResult &q) {
			os << "Selected word: " << q.sought << '\n';
			if (q.lineNums->empty())
				os << "\tNot found" << '\n';
			for (std::set<std::size_t>::const_iterator it = q.lineNums->cbegin(); it != q.lineNums->cend(); ++it) {
				os << "\t(line " << (*it) + 1 << ") " << *(q.text->begin() + *it) << '\n';
			}
			return os;
		}
	}
	namespace _43 {
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
	}
	namespace _44 {
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
			char *dest = newdata;
			char *elem = elements;
			for (std::size_t i = 0; i != size(); ++i)
				alloc.construct(dest++, *elem++);
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
			std::pair<char *, char *> data = exact_alloc_copy(s.cbegin(), s.cend());
			elements = data.first;
			first_free = cap = data.second;
		}
		String &String::operator=(const String &rhs) {
			std::pair<char *, char *> newdata = exact_alloc_copy(rhs.cbegin(), rhs.cend());
			free();
			elements = newdata.first;
			first_free = cap = newdata.second;
			return *this;
		}
		String::~String() { free(); }

		void String::push_back(char c) {
			check_full_realloc();
			alloc.construct(first_free++, c);
		}

		std::ostream &print(std::ostream &os, const String &s) {
			std::size_t length = s.size();
			char *cp = new char[length + 1];
			const char *elem = s.elements;
			char *dest = cp;
			for (std::size_t i = 0; i != length; ++i) {
				*dest++ = *elem++;
			}
			cp[length] = '\0';
			os << cp;
			delete[] cp;
			return os;
		}
	}
	namespace _47 {
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
			char *dest = newdata;
			char *elem = elements;
			for (std::size_t i = 0; i != size(); ++i)
				alloc.construct(dest++, *elem++);
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
		String &String::operator=(const String &rhs) {
			std::cout << "copy-assignment operator" << std::endl;
			std::pair<char *, char *> newdata = exact_alloc_copy(rhs.cbegin(), rhs.cend());
			free();
			elements = newdata.first;
			first_free = cap = newdata.second;
			return *this;
		}
		String::~String() { free(); }

		void String::push_back(char c) {
			check_full_realloc();
			alloc.construct(first_free++, c);
		}

		std::ostream &print(std::ostream &os, const String &s) {
			std::size_t length = s.size();
			char *cp = new char[length + 1];
			const char *elem = s.elements;
			char *dest = cp;
			for (std::size_t i = 0; i != length; ++i) {
				*dest++ = *elem++;
			}
			cp[length] = '\0';
			os << cp;
			delete[] cp;
			return os;
		}
	}
	namespace _48 {
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
			char *dest = newdata;
			char *elem = elements;
			for (std::size_t i = 0; i != size(); ++i)
				alloc.construct(dest++, *elem++);
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
		String &String::operator=(const String &rhs) {
			std::cout << "copy-assignment operator" << std::endl;
			std::pair<char *, char *> newdata = exact_alloc_copy(rhs.cbegin(), rhs.cend());
			free();
			elements = newdata.first;
			first_free = cap = newdata.second;
			return *this;
		}
		String::~String() { free(); }

		void String::push_back(char c) {
			check_full_realloc();
			alloc.construct(first_free++, c);
		}

		std::ostream &print(std::ostream &os, const String &s) {
			std::size_t length = s.size();
			char *cp = new char[length + 1];
			const char *elem = s.elements;
			char *dest = cp;
			for (std::size_t i = 0; i != length; ++i) {
				*dest++ = *elem++;
			}
			cp[length] = '\0';
			os << cp;
			delete[] cp;
			return os;
		}
	}
	namespace _49 {
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
			char *dest = newdata;
			char *elem = elements;
			for (std::size_t i = 0; i != size(); ++i)
				alloc.construct(dest++, *elem++);
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
			std::size_t length = s.size();
			char *cp = new char[length + 1];
			const char *elem = s.elements;
			char *dest = cp;
			for (std::size_t i = 0; i != length; ++i) {
				*dest++ = *elem++;
			}
			cp[length] = '\0';
			os << cp;
			delete[] cp;
			return os;
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


		Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
			add_to_Folders(m);
		}
		void Message::move_Folders(Message *m) {
			folders = std::move(m->folders);
			for (Folder *f : folders) {
				f->remMsg(m);
				f->addMsg(this);
			}
			m->folders.clear();
		}

		Message::Message(Message &&m) : contents(std::move(m.contents)) {
			move_Folders(&m);
		}
		Message &Message::operator=(const Message &rhs) {
			remove_from_Folders();
			contents = rhs.contents;
			folders = rhs.folders;
			add_to_Folders(rhs);
			return *this;
		}
		Message &Message::operator=(Message &&rhs) {
			if (this != &rhs) {
				remove_from_Folders();
				contents = std::move(rhs.contents);
				move_Folders(&rhs);
			}
			return *this;
		}

		Message::~Message() {
			remove_from_Folders();
		}

		void Message::save(Folder &f) {
			folders.insert(&f);
			f.addMsg(this);
		}

		void Message::remove(Folder &f) {
			folders.erase(&f);
			f.remMsg(this);
		}

		void Message::addFld(Folder *f) {
			folders.insert(f);
		}
		void Message::remFld(Folder *f) {
			folders.erase(f);
		}

		void Message::add_to_Folders(const Message &m) {
			for (Folder *f : m.folders)
				f->addMsg(this);
		}
		void Message::remove_from_Folders() {
			for (Folder *f : folders)
				f->remMsg(this);
		}

		void swap(Message &lhs, Message &rhs) {
			using std::swap;
			for (Folder *f : lhs.folders)
				f->remMsg(&lhs);
			for (Folder *f : rhs.folders)
				f->remMsg(&rhs);
			swap(lhs.contents, rhs.contents);
			swap(lhs.folders, rhs.folders);
			for (Folder *f : lhs.folders)
				f->addMsg(&lhs);
			for (Folder *f : rhs.folders)
				f->addMsg(&rhs);
		}


		Folder::Folder(const Folder &f) : name(f.name), messages(f.messages) {
			add_to_Messages(f);
		}

		Folder &Folder::operator=(const Folder &rhs) {
			remove_from_Messages();
			name = rhs.name;
			messages = rhs.messages;
			add_to_Messages(rhs);
			return *this;
		}

		Folder::~Folder() {
			remove_from_Messages();
		}

		void Folder::addMsg(Message *m) {
			messages.insert(m);
		}

		void Folder::remMsg(Message *m) {
			messages.erase(m);
		}

		void Folder::add_to_Messages(const Folder &f) {
			for (Message *m : f.messages)
				m->addFld(this);
		}
		void Folder::remove_from_Messages() {
			for (Message *m : messages)
				m->remFld(this);
		}

		void swap(Folder &lhs, Folder &rhs) {
			using std::swap;
			for (Message *m : lhs.messages)
				m->remFld(&lhs);
			for (Message *m : rhs.messages)
				m->remFld(&rhs);
			swap(lhs.name, rhs.name);
			swap(lhs.messages, rhs.messages);
			for (Message *m : lhs.messages)
				m->addFld(&lhs);
			for (Message *m : rhs.messages)
				m->addFld(&rhs);
		}

		std::ostream &print(std::ostream &os, const Folder &f) {
			os << "Folder : " << f.name << std::endl;
			for (Message *m : f.messages)
				os << m->contents << std::endl;
			return os;
		}
	}
	namespace _50 {
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
			std::size_t length = s.size();
			char *cp = new char[length + 1];
			const char *elem = s.elements;
			char *dest = cp;
			for (std::size_t i = 0; i != length; ++i) {
				*dest++ = *elem++;
			}
			cp[length] = '\0';
			os << cp;
			delete[] cp;
			return os;
		}
	}
	}
}
