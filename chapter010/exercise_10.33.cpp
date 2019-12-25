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
    istream_iterator<int> in_file(in);
    istream_iterator<int> eof;
    fstream file1("out1");
    fstream file2("out2");
    ostream_iterator<int> out1(file1);
    ostream_iterator<int> out2(file2);
    while(in_file!=eof){
        int val = *in_file++;
        if(val%2==0){
            out1 = val;
        }
        else {
            out2 = val;
        }
    }
    return 0;
}
