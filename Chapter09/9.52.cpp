#include <stack>
#include <string>
#include <iostream>

using std::string;
using std::stack;
using std::cout;
using std::endl;
using std::cin;

int main() {
	string expr;
	stack<char> charStack;
	if (!getline(cin, expr)) { return -1; }
	for (const char &c : expr) {
		if (c == ')') {
			while (!charStack.empty() && charStack.top() != '(') {
				charStack.pop();
			}
			if (!charStack.empty()) {
				charStack.pop();
			}
			charStack.push('#');
		}
		else {
			charStack.push(c);
		}
	}
	string output;
	while (!charStack.empty()) {
		output.insert(output.begin(), charStack.top());
		charStack.pop();
	}
	cout << output << endl;
	return 0;
}
