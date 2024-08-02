#include "Message.h"
#include "Folder.h"

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
