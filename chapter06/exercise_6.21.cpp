#include <iostream>
#include <algorithm>
using namespace std;

int func(int var1,const int *var2)
{
    if(var1>(*var2)) return var1;
    else return (*var2);
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<func(a,&b)<<endl;
    return 0;
}
