#include <iostream>
#include <string>
#include <list>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <fstream>
using namespace std;

int main()
{
    fstream file("test");
    map<string, int> dict;
    string word;
    while(file>>word){
        ++dict[word];
    }
    for(auto x:dict){
        cout<<x.first<<" "<<x.second<<endl;
    }
    return 0;
}
