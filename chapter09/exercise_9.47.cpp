#include <iostream>
#include <vector>
#include <string>
using namespace std;

string find_str(string &s, const string &str)
{
    string::size_type pos = 0;
    // 找数字
    while((pos=s.find_first_of(str, pos))!=string::npos){
        cout<<pos<<" ";
        ++pos;
    }
    cout<<endl;
    // 找字母
    pos = 0;
    while((pos=s.find_first_not_of(str, pos))!=string::npos){
        cout<<pos<<" ";
        ++pos;
    }
    cout<<endl;
    return s;
}

int main()
{
	string s = "sa2d4f1as2d3f", str="0123456789";
	find_str(s, str);
	return 0;
}
