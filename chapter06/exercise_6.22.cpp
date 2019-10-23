#include <iostream>
#include <algorithm>
using namespace std;

void swap_pointer(int *&var1,int *&var2)
{
    swap(var1,var2);
}

int main()
{
    int a,b;
    cin>>a>>b;
    int *p1 = &a,*p2 = &b;
    cout<<*p1<<" "<<*p2<<endl;
    swap_pointer(p1,p2);
    cout<<*p1<<" "<<*p2<<endl;
    return 0;
}
