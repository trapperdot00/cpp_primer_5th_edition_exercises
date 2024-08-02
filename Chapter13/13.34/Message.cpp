#include "Message.h"

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
	add_to_Folders(m);
}

Message &Message::operator=(const Message &rhs) {
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_folders(rhs);
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
	swap(lhs.folders, rhs.contents);
	for (Folder *f : lhs.folders)
		f->addMsg(&lhs);
	for (Folder *f : rhs.folders)
		f->addMsg(&rhs);
}
