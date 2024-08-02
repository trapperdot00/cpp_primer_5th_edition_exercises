#include <memory>
#include <iostream>

using std::shared_ptr;
using std::cout;
using std::endl;

struct destination{
	int address;
};

struct connection{
	bool active() const { return connected; }
	
	int address;
	bool connected = false;

};

connection connect(destination* d) {
	connection c;
	c.connected = true;
	c.address = d->address;
	return c;
}

void disconnect(connection *c) {
	c->connected = false;
}

void end_connection(connection *c) {
	disconnect(c);
}

void f(destination &d) {
	connection c = connect(&d);
	shared_ptr<connection> p(&c, [](connection *conn){ end_connection(conn); });
	cout << (c.active() ? "connected to " : "not connected to ");
	cout << c.address << endl;
	p.reset();
	cout << (c.active() ? "connected to " : "not connected to ");
	cout << c.address << endl;
}

int main() {
	destination d;
	d.address = 420;
	f(d);

	return 0;
}
