#include "Folder.h"
#include "Message.h"

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
