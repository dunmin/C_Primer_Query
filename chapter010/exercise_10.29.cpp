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
    fstream in("test");
    istream_iterator<string> in_file(in);
    istream_iterator<string> eof;
    vector<string> str;
    while(in_file!=eof){
        str.push_back(*in_file++);
    }
    for(auto x:str){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
