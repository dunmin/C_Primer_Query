#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;


int main()
{
    vector<string> a;
    list<char *> b = {"124", "123", "999"};
    a.assign(b.begin(), b.end());
    for(auto x:a){
        cout<<x<<endl;
    }
	return 0;
}
