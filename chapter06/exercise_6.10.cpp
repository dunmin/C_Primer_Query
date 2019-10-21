#include <iostream>
#include <algorithm>
using namespace std;

void pointer_swap(int *point1,int *point2)
{
    swap(*point1,*point2);
}

int main()
{
    int a,b;
    cin>>a>>b;
    pointer_swap(&a,&b);
    cout<<a<<" "<<b<<endl;
    return 0;
}
