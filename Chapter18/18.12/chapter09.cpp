#include "chapter09.h"

namespace cplusplus_primer {
namespace chapter09 {
	Date::Date(const std::string &date) {
		assign(date);
	}
	void Date::assign(const std::string &date) {
		std::string temp = date;
		if (temp.find_first_of("/-|") != std::string::npos)	
		{
			formatDate(temp);
		}
		std::istringstream stream(temp);
		for (unsigned dateIndex = 0; dateIndex != 3 && stream >> temp; ++dateIndex) {
			//std::cout << dateIndex << ' ' << temp << '\n'; 
			switch (dateIndex) {
				case 0:	// Month
					processMonth(temp);
					break;
				case 1:	// Day
					processDay(temp);
					break;
				case 2:	// Year
					processYear(temp);
					break;
			}
		}
	}
	void Date::formatDate(std::string &unformatted) const {
		for (std::string::size_type index = 0; index != unformatted.size(); ++index) {
			switch (unformatted[index]) {
				case '/': case '-': case '|':
					unformatted.replace(index, 1, " ");
					break;
				default:
					break;
			}
		}
	}

	void Date::processMonth(const std::string &sMonth) {
		const std::string numeric = "+123456789";
		if (sMonth.find_first_of(numeric) != std::string::npos) {	// if contains numerics
			month = stoi(sMonth);
		} else {	// if month is in alphabetics
			std::vector<std::string> monthNames = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
			unsigned index = 0;
			while (sMonth.substr(0, 3) != monthNames[index] && index != 12) {
				++index;
			}
			month = index + 1;
		}
	}

	void Date::processDay(const std::string &sDay) {
		day = stoi(sDay);
	}

	void Date::processYear(const std::string &sYear) {
		year = stoi(sYear);
	}

	std::ostream &Date::print(std::ostream &os) const {
		os << month << '-' << day << '-' << year;
		return os;
	}
}
}
