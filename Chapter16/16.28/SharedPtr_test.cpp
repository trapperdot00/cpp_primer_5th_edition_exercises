#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <string>
#include "DebugDelete.h"
#include "SharedPtr.h"

template class SharedPtr<int>;

using namespace std;

// Tests operator*, get, use_count, unique, operator bool
template <typename T>
ostream &debugPrint(ostream &os, SharedPtr<T> &p, const string &name) {
	os << name << ' ';
	if (p) {
		const SharedPtr<T> &cp = p;
		os << "pointer value: " << *p << ", get: " << *p.get() << ", const get: " << *cp.get()
			<<  ", use_count: " << p.use_count() << ", " << (p.unique() ? "" : "not ") << "unique"
			<< ", bool value: " << bool(p);
	} else
		os << "nullpointer, use_count: " << p.use_count() << ", bool value: " << bool(p);
	return os;
}
template <typename T>
ostream &debugPrint(ostream &os, const SharedPtr<T> &p, const string &name) {
	os << name << ' ';
	if (p) {
		os << "pointer value: " << *p << ", const get: " << *p.get()
			<<  ", use_count: " << p.use_count() << ", " << (p.unique() ? "" : "not ") << "unique"
			<< ", bool value: " << bool(p);
	} else
		os << "nullpointer, use_count: " << p.use_count() << ", bool value: " << bool(p);
	return os;
}

int main() {
	{	// SharedPtr() Check
		SharedPtr<int> sp1;
		debugPrint(cout, sp1, "sp1") << "\n\n";
	}
	{	// SharedPtr(T *) Check
		SharedPtr<int> sp2(new int(2));
		debugPrint(cout, sp2, "sp2") << "\n\n";
	}
	{	// SharedPtr(T *, Deleter) and Copy Constructor Check
		SharedPtr<int> sp3(new int(3), DebugDelete());
		debugPrint(cout, sp3, "sp3") << endl;
		cout << "Copy constructing new SharedPtr\n";
		{
			SharedPtr<int> sp4(sp3);
			debugPrint(cout, sp3, "sp3") << endl;
			debugPrint(cout, sp4, "sp4") << endl;
		}
		debugPrint(cout, sp3, "sp3") << "\n\n";
	}
	{	// Move Constructor Check
		SharedPtr<int> sp5(new int(5), DebugDelete());
		debugPrint(cout, sp5, "sp5") << endl;
		cout << "Move constructing a new SharedPtr\n";
		// don't even try to access sp5 now!
		SharedPtr<int> sp6(std::move(sp5));
		debugPrint(cout, sp6, "sp6") << "\n\n";
	}
	{	// Copy Assignment Check
		SharedPtr<int> sp7(new int(7), DebugDelete());
		debugPrint(cout, sp7, "sp7") << endl;
		SharedPtr<int> sp8(new int(8), DebugDelete());
		debugPrint(cout, sp8, "sp8") << endl;
		cout << "Copy assigning sp7 to sp8\n";
		sp8 = sp7;
		debugPrint(cout, sp7, "sp7") << endl;
		debugPrint(cout, sp8, "sp8") << "\n\n";
	}
	{	// Move Assignment Check
		SharedPtr<int> sp9(new int(9), DebugDelete());
		debugPrint(cout, sp9, "sp9") << endl;
		SharedPtr<int> sp10(new int(10), DebugDelete());
		debugPrint(cout, sp10, "sp10") << endl;
		cout << "Move assigning sp9 to sp10\n";
		// don't even try to access sp9 now!
		sp10 = std::move(sp9);
		debugPrint(cout, sp10, "sp10") << "\n\n";
	}
	// Self Assignment Check
	{
		SharedPtr<int> sp11(new int(11), DebugDelete());
		debugPrint(cout, sp11, "sp11") << endl;
		cout << "Self copy-assigning sp11\n";
		sp11 = sp11;
		debugPrint(cout, sp11, "sp11") << "\n\n";
	}
	{	// Why would you do this?
		SharedPtr<int> sp12(new int(12), DebugDelete());
		debugPrint(cout, sp12, "sp12") << endl;
		cout << "Self move-assigning sp12\n";
		sp12 = std::move(sp12);
		debugPrint(cout, sp12, "sp12") << "\n\n";
	}

	{	// MakeShared and Arrow-Operator Check
		SharedPtr<vector<int>> sp13 = {MakeShared<vector<int>>(10, 13), DebugDelete()};
		cout << "sp13: ";
		for_each(sp13->cbegin(), sp13->cend(), [](int i){ cout << i << ' '; });
		cout << "\n\n";
	}
	{	// Reset Check
		SharedPtr<int> sp14 = {MakeShared<int>(14), DebugDelete()};
		debugPrint(cout, sp14, "sp14") << endl;
		sp14.reset();
		debugPrint(cout, sp14, "sp14") << endl;
		sp14.reset(new int(140));
		debugPrint(cout, sp14, "sp14") << endl;

		SharedPtr<int> sp15 = new int(15);
		debugPrint(cout, sp15, "sp15") << endl;
		sp15.reset(new int(150), DebugDelete());
		debugPrint(cout, sp15, "sp15") << "\n\n";
	}
	{	// Swap Check
		SharedPtr<int> sp16(new int(16), DebugDelete()),
				sp17(new int(17), DebugDelete());
		debugPrint(cout, sp16, "sp16") << endl;
		debugPrint(cout, sp17, "sp17") << endl;
		swap(sp16, sp17);
		debugPrint(cout, sp16, "sp16") << endl;
		debugPrint(cout, sp17, "sp17") << endl;
		sp16.swap(sp17);
		debugPrint(cout, sp16, "sp16") << endl;
		debugPrint(cout, sp17, "sp17") << "\n\n";
	}
	{	// Const SharedPtr Check
		const SharedPtr<int> csp1(new int(444), DebugDelete());
		debugPrint(cout, csp1, "csp1") << endl;
		const SharedPtr<int> csp2;
		debugPrint(cout, csp2, "csp2") << "\n\n";
	}
	{	// Equality Operator Check
		SharedPtr<int> sp18, sp19;
		cout << (sp18 == sp19) << " " << (sp18 != sp19) << "\n\n";
	}
	{	// Relational Operator Check	(based on memory address)
		SharedPtr<int> sp20(new int (12)), sp21(new int (1));
		cout << (sp20 < sp21) << " " << (sp20 > sp21) << " "
			<< (sp20 <= sp21) << " " << (sp20 >= sp21) << endl;
	}
	return 0;
}
