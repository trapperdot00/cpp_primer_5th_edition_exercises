#include <string>
#include <sstream>
#include <iostream>
#include <vector>
class Date {
	// MM-DD-YYYY
public:
	Date(const std::string &);
	Date() : month(0), day(0), year(0) {}

	void assign(const std::string &);
	std::ostream &print(std::ostream &) const;
private:
	void formatDate(std::string &) const;
	void processMonth(const std::string &);
	void processDay(const std::string &);
	void processYear(const std::string &);
	unsigned month;
	unsigned day;
	unsigned year;
};
