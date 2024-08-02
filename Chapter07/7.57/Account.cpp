#include "Account.h"

double Account::initRate() {
	return 0.25;
}

void Account::rate(double newRate) {
	interestRate = newRate;
}

double Account::interestRate = initRate();

constexpr int Account::period;
