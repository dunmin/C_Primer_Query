#include <iostream>
#include <algorithm>
using namespace std;

void reset(int &a)
{
    a = 0;
}

int main()
{
    int a=2;
    reset(a);
    cout<<a<<endl;
    return 0;
}
