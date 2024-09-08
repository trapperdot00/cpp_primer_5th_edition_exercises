#include "DebugDelete.h"
#include "UniquePtr.h"
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <string>

template class UniquePtr<int, DefaultDeleter>;

using namespace std;

// Tests operator*, get, const get, operator bool
template <typename T, typename D>
ostream &debugPrint(ostream &os, UniquePtr<T, D> &p, const string &name) {
	os << name << ' ';
	if (p) {
		const UniquePtr<T, D> &cp = p;
		os << "pointer value: " << *p << ", get: " << *p.get() << ", const get: "
			<< *cp.get() << ", bool value: " << bool(p);
	} else
		os << "nullpointer, bool value: " << bool(p);
	return os;
}
template <typename T, typename D>
ostream &debugPrint(ostream &os, const UniquePtr<T, D> &p, const string &name) {
	os << name << ' ';
	if (p) {
		os << "pointer value: " << *p << ", const get: " << *p.get() << ", bool value: " << bool(p);
	} else
		os << "nullpointer, bool value: " << bool(p);
	return os;
}

int main() {
	{	// UniquePtr() Check
		UniquePtr<int> up1;
		debugPrint(cout, up1, "up1") << "\n\n";
	}
	{	// UniquePtr(Deleter) Check
		UniquePtr<int, DebugDelete> up2{DebugDelete()};
		debugPrint(cout, up2, "up2") << "\n\n";
	}
	{	// UniquePtr(T *) Check
		UniquePtr<int> up3 = new int(3);
		debugPrint(cout, up3, "up3") << "\n\n";
	}
	{	// UniquePtr(T *, Deleter) Check
		UniquePtr<int, DebugDelete> up4 = {new int(4), DebugDelete()};
		debugPrint(cout, up4, "up4") << "\n\n";
	}
	{	// Move Constructor Check
		UniquePtr<int, DebugDelete> up5(new int(5), DebugDelete());
		debugPrint(cout, up5, "up5") << endl;
		UniquePtr<int, DebugDelete> up6(std::move(up5));
		debugPrint(cout, up6, "up6") << "\n\n";
	}
	{	// Move Assignment Operator Check
		UniquePtr<int, DebugDelete> up7(new int(7), DebugDelete()),
				up8(new int(8), DebugDelete());
		debugPrint(cout, up7, "up7") << endl;
		debugPrint(cout, up8, "up8") << endl;
		up8 = std::move(up7);
		debugPrint(cout, up8, "up8") << "\n\n";
	}
	{	// Self Move Assignment Check
		UniquePtr<int, DebugDelete> upA(new int(10), DebugDelete());
		debugPrint(cout, upA, "upA") << endl;
		upA = std::move(upA);	// You shouldn't access this after this
		debugPrint(cout, upA, "upA") << "\n\n";	// Broke the rules
	}
	{	// Swap Check
		UniquePtr<int, DebugDelete> up9(new int(9), DebugDelete()),
				up10(new int(10), DebugDelete());
		debugPrint(cout, up9, "up9") << endl;
		debugPrint(cout, up10, "up10") << endl;
		swap(up9, up10);
		debugPrint(cout, up9, "up9") << endl;
		debugPrint(cout, up10, "up10") << "\n\n";
	}
	{	// Release Check
		UniquePtr<int, DebugDelete> up11(new int(11), DebugDelete());
		debugPrint(cout, up11, "up11") << endl;
		UniquePtr<int, DebugDelete> up12(up11.release(), DebugDelete());
		debugPrint(cout, up11, "up11") << endl;
		debugPrint(cout, up12, "up12") << "\n\n";
	}
	{	// reset() Check
		UniquePtr<int, DebugDelete> up13(new int(13), DebugDelete());
		debugPrint(cout, up13, "up13") << endl;
		up13.reset();
		debugPrint(cout, up13, "up13") << "\n\n";
	}
	{	// reset(T *) Check
		UniquePtr<int, DebugDelete> up14(new int(14), DebugDelete());
		debugPrint(cout, up14, "up14") << endl;
		up14.reset(new int(1400));
		debugPrint(cout, up14, "up14") << "\n\n";
	}
	{	// reset(std::nullptr_t) Check
		UniquePtr<int, DebugDelete> up15(new int(15), DebugDelete());
		debugPrint(cout, up15, "up15") << endl;
		up15.reset(nullptr);
		debugPrint(cout, up15, "up15") << "\n\n";
	}
	{	// Arrow Operator Check
		UniquePtr<vector<int>, DebugDelete> up16(new vector<int>(10, 16), DebugDelete());
		for_each(up16->cbegin(), up16->cend(), [](int i){ cout << i << ' '; });
		cout << "\n\n";
	}
	{	// Const UniquePtr Check
		const UniquePtr<int, DebugDelete> cup(new int(100), DebugDelete());
		debugPrint(cout, cup, "cup") << endl;
		const UniquePtr<int, DebugDelete> cup2;
		debugPrint(cout, cup2, "cup2") << "\n\n";
	}
	{	// Equality Operator Check
		UniquePtr<int, DebugDelete> up17(new int(17), DebugDelete()),
				up18(new int(18), DebugDelete());
		cout << (up17 == up18) << " " << (up17 != up18) << "\n\n";
	}
	{	// Relational Operator Check	(based on memory address)
		UniquePtr<int, DebugDelete> up19(new int(19), DebugDelete()),
				up20(new int(20), DebugDelete());
		cout << (up19 < up20) << " " << (up19 > up20) << " "
			<< (up19 <= up20) << " " << (up19 >= up20) << endl;
	}

	return 0;
}
