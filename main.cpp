/*
    C++ Primer 5th Edition
    Exercise 7.21:  Update your Sales_data class to hide its implementation. The
    programs you've written to use Sales_data operations should still continue to
    work. Recompile those programs with your new class definition to verify that
    they still work.
*/

#include <iostream>
#include <string>

class Sales_data
{
    friend std::istream& read(std::istream&, Sales_data&);
    friend std::ostream& print(std::ostream&, const Sales_data&);
public:
    Sales_data() = default;
    Sales_data(const std::string& b) : bookNo(b) { }
    Sales_data(const std::string& b, const unsigned& n, const double& p) :
               bookNo(b), units_sold(n), revenue(p*n) { }
    Sales_data(std::istream&);

    const std::string& isbn() const { return bookNo; }
    const unsigned getUnits_sold() const { return units_sold; }
    const double getRevenue() const { return revenue; }

    Sales_data& combine(const Sales_data& rhs)
    {
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this;
    }
    double avg_price() const
    {
        if (units_sold)
            return revenue/units_sold;
        else
            return 0;
    }

private:

    std::string bookNo;
    unsigned units_sold;
    double revenue;
};

Sales_data::Sales_data(std::istream& is)
{
    read(is, *this);
}

std::istream& read(std::istream& is, Sales_data& item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream& print(std::ostream& os, const Sales_data& item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

int main()
{
    Sales_data total(std::cin);
    if (std::cin) {
        Sales_data trans(std::cin);
        while (std::cin) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(std::cout, total) << std::endl;
                total = trans;
            }
            read(std::cin, trans);
        }
        print(std::cout, total) << std::endl;
    } else {
        std::cerr << "No data!" << std::endl;
        return -1;
    }
    return 0;
}
