#include <iostream>
#include <string>
#include <list>
#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(const string &x)
{
    return x.size() >= 5;
}

int main()
{
    vector<string> sstr = {"55555", "4444", "333","666666"};
    auto pos = partition(sstr.begin(), sstr.end(), cmp);
    for(auto iter = sstr.begin();iter!=pos;iter++){
        cout<<*iter<<endl;
    }
    return 0;
}
