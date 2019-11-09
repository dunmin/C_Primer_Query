#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

class Sales_data
{
    friend std::istream &read(std::istream&, Sales_data&);
    friend std::ostream &print(std::ostream&, Sales_data&);
    public:
        Sales_data() = default;
        Sales_data(std::string bookNo,unsigned units_sold,double revenue):
            bookNo(bookNo),units_sold(units_sold),revenue(revenue){};
        Sales_data& combine(Sales_data &rhs);
        std::string isbn(){
            return bookNo;
        }
        virtual ~Sales_data();
    private:
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
};

std::istream &read(std::istream&, Sales_data&);
std::ostream &print(std::ostream&, Sales_data&);
#endif // SALES_DATA_H
