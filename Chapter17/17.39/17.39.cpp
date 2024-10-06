#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>

using std::fstream;
using std::string;
using std::getline;
using std::cerr;
using std::endl;
using std::size_t;

int main() {
	// Open file "copyOut" to read and write, with the marker positioned
	// To the end of the file
	fstream InOut("copyOut", fstream::in | fstream::out | fstream::ate);
	// If the file is not open print an error message to stderr,
	// And return from main with a nonzero value
	if (!InOut) {
		cerr << "File doesn't exist" << endl;
		return EXIT_FAILURE;
	}
	// Save the current (which is positioned to the end, because of the ate flag),
	// Marker position, tellg/tellp returns a pos_type, which is unsigned,
	// Holds an absolute position
	fstream::pos_type end_mark = InOut.tellg();
	// Set the marker to the beginning of the file, with an offset of zero,
	// Offset has type of off_type,
	// Which is a signed value that holds a relative position
	InOut.seekg(0, fstream::beg);
	// cnt will hold our character/byte count
	size_t cnt = 0;
	// line holds each read line of input
	string line;
	// While InOut is in a valid state,
	// We haven't reached the end_mark we had saved,
	// And we can get another line from InOut
	while (InOut && InOut.tellg() != end_mark && getline(InOut, line)) {
		// Increase cnt by the current line's size, plus one for the newline char
		cnt += line.size() + 1;
		// Save current position in curr_pos, because we will reposition the marker
		fstream::pos_type curr_pos = InOut.tellg();
		// Reposition the marker to the end of the file, offset by 0
		InOut.seekp(0, fstream::end);
		// Write the current value that cnt holds to the end of the whole file
		InOut << cnt;
		// If this isn't the last line, print a space as a separator
		if (curr_pos != end_mark)
			InOut << ' ';
		// Position the marker to the previous, saved position
		InOut.seekg(curr_pos);
	}
	// Position the marker to the end of the file
	InOut.seekp(0, fstream::end);
	// Append a newline
	InOut << '\n';
	return 0;
}
