#include <iostream>
#include <string>
#include <list>
#include <cstdio>
#include <algorithm>
#include <typeinfo>
using namespace std;

int main()
{
    vector<string> vec = {"1","333","666666","55555","7777777"};
    int sz = 6;
    cout<<count_if(vec.begin(), vec.end(), [sz](string x){return x.size()>=sz?true:false;})<<endl;
    return 0;
}
