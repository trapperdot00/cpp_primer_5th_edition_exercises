#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <set>
#include <utility>	// std::swap

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

#endif
