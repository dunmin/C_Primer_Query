#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;

istream& readfunc(istream& in)
{
    string in_string;
    while(in>>in_string){
        cout<<in_string<<endl;
    }
    cout<<in.fail()<<endl;
    cout<<in.eof()<<endl;
    in.clear(in.rdstate() & ~in.eofbit & ~in.failbit);
    cout<<in.rdstate()<<endl;
    return in;
}

int main()
{
    istringstream in("test");
    readfunc(in);
}
