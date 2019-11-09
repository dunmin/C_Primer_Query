#include "Sales_data.h"
#include <iostream>

Sales_data::~Sales_data()
{
    //dtor
}

Sales_data& Sales_data::combine(Sales_data &rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::istream& read(std::istream& is,Sales_data& rhs)
{
    double price  = 0;
    is>>rhs.bookNo>>rhs.units_sold>>price;
    rhs.revenue = price * rhs.units_sold;
    return is;
}

std::ostream &print(std::ostream& os, Sales_data& rhs)
{
    os<<rhs.isbn()<<" "<<rhs.units_sold<<" "<<rhs.revenue;
    return os;
}
