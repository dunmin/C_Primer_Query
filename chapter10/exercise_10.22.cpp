#include <iostream>
#include <string>
#include <list>
#include <cstdio>
#include <algorithm>
#include <typeinfo>
#include <functional>
using namespace std;
using std::placeholders::_1;


bool check_size(const string &s, int sz){
    return s.size() < sz;
}


int main()
{
    vector<string> words = {"1","22","4444","333","666666"};
    int sz = 6;
    auto wc = count_if(words.begin(), words.end(), bind(check_size, _1, sz));
    cout<<wc<<endl;
    return 0;
}
