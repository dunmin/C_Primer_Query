#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

istream& readfunc(istream& in)
{
    string in_string;
    while(in>>in_string){
        cout<<in_string<<endl;
    }
    // eof 时,eofbit和failbit都会置1
    cout<<in.fail()<<endl;                  // 1
    cout<<in.eof()<<endl;                   // 1
    in.clear(in.rdstate() & ~in.eofbit & ~in.failbit);// 110 & 101 & 011
    cout<<in.rdstate()<<endl;               // 0
    return in;
}

int main()
{
    freopen("test","r",stdin);
    readfunc(cin);
}
