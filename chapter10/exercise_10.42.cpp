#include <iostream>
#include <string>
#include <list>
#include <cstdio>
#include <algorithm>
#include <typeinfo>
#include <functional>
#include <iterator>
#include <fstream>
#include <forward_list>
using namespace std;

int main()
{
    list<int> vec = {1,2,3,4,0,1,0,7};
    vec.sort();
    vec.unique();
    for(auto x:vec){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
