#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
	vector<int> ivec;
	// size should be 0; capacity is implementation defined
	cout << "ivec: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;
	// give ivec 24 items
	for (vector<int>::size_type ix = 0; ix != 24; ++ix)
		ivec.push_back(ix);
	// size should be 24; capacity will be >= 24 and is implementation defined
	cout << "ivec: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;
	
	ivec.reserve(50);	// sets capacity to at least 50; might be more
	// size should be 24; capacity will be >= 50 and is implementation defined
	cout << "ivec: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;
	
	// add elements to use up the excess capacity
	while (ivec.size() != ivec.capacity())
		ivec.push_back(0);
	// capacity should be unchanged and size and capacity are now equal
	cout << "ivec: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;

	ivec.push_back(42); // add one more element
	// size should be 51; capacity will be >= 51 and is implementation defined
	cout << "ivec: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;
	
	ivec.shrink_to_fit();	// ask for the memory to be returned
	// size should be unchanged; capacity is implementation defined
	cout << "ivec: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;
	return 0;
}
