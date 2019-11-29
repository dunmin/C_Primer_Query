#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <fstream>
using namespace std;


int main()
{
    fstream fs("test2.txt");
    deque<string> que;
    string str;
    while(fs>>str){
        que.push_back(str);
    }
    for(auto x:que){
        cout<<x<<endl;
    }
    return 0;
}
