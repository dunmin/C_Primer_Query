#include <iostream>
#include <string>
#include <list>
#include <cstdio>
#include <algorithm>
#include <typeinfo>
#include <functional>
#include <iterator>
#include <forward_list>
using namespace std;

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7,7,7,8};
    list<int> lis;
    unique_copy(vec.begin(), vec.end(), back_inserter(lis));
    for(auto x:lis){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
