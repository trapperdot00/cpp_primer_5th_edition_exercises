#include <iostream>

int main() {
	// std::cin >> int input_value;	
	int input_value;
	std::cin >> input_value;

	// int i = { 3.14 };	list initializer won't allow initializing with loss of precision
	int i = 3.14;

	// double salary = wage = 9999.99;	wage is not initialized yet
	double salary = 9999, wage = salary;
	std::cout << salary << "  -  " << wage << std::endl;


	int j = 3.14;

	return 0;
}
