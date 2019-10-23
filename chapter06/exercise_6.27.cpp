#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <vector>
using namespace std;

int func(initializer_list<int> x)
{
    int sum = 0;
    for(auto num:x){
        sum += num;
    }
    return sum;
}

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<func({a,b,c,d})<<endl;
    return 0;
}
