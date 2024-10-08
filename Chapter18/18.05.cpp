#include <stdexcept>
#include <iostream>
#include <cstdlib>

using std::exception;
using std::bad_cast;
using std::bad_alloc;
using std::runtime_error;
using std::overflow_error;
using std::underflow_error;
using std::range_error;
using std::logic_error;
using std::domain_error;
using std::invalid_argument;
using std::out_of_range;
using std::length_error;
using std::cerr;
using std::endl;
using std::abort;

int main() {
	try {
		/* ... */
	} catch (overflow_error e) {
		cerr << e.what() << endl;
		abort();
	} catch (underflow_error e) {
		cerr << e.what() << endl;
		abort();
	} catch (range_error e) {
		cerr << e.what() << endl;
		abort();
	} catch (domain_error e) {
		cerr << e.what() << endl;
		abort();
	} catch (invalid_argument e) {
		cerr << e.what() << endl;
		abort();		
	} catch (out_of_range e) {
		cerr << e.what() << endl;
		abort();
	} catch (length_error e) {
		cerr << e.what() << endl;
		abort();
	} catch (runtime_error e) {
		cerr << e.what() << endl;
		abort();
	} catch (logic_error e) {
		cerr << e.what() << endl;
		abort();
	} catch (bad_cast e) {
		cerr << e.what() << endl;
		abort();
	} catch (bad_alloc e) {
		cerr << e.what() << endl;
		abort();
	} catch (const exception &e) {
		cerr << e.what() << endl;
		abort();
	}
	return 0;
}
