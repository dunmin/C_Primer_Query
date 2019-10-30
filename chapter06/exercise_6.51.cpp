#include <iostream>
using namespace std;

void f(int a,int b)
{
    cout<<a<<" "<<b<<endl;
}

void f(double a,double b = 3.14)
{
    cout<<a<<" "<<b<<endl;
}

void f()
{
    cout<<"empty"<<endl;
}

void f(int a)
{
    cout<<a<<endl;
}

int main()
{
    //f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
}
