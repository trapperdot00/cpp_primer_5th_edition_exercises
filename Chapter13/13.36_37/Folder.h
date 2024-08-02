#ifndef FOLDER_H
#define FOLDER_H

#include "Message.h"
#include <set>
#include <string>
#include <utility>
#include <iostream>

class Message;

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

#endif
