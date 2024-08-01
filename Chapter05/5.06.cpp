#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main() {
	vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
	unsigned grade;
	if (!(cin >> grade) || grade > 100) return -1;
	string lettergrade = (grade < 60) ? scores[0] : scores[(grade - 50) / 10];
	lettergrade += (grade < 60 || grade == 100) ? "" : 
		   		   (grade % 10 > 7) ? "+" :
			   	   (grade % 10 < 3) ? "-" : "";	   
	cout << lettergrade << endl;
	return 0;
}

