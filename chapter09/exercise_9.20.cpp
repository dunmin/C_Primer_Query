#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <deque>
using namespace std;


int main()
{
    list<int> lis = {1,2,3,4,5,6};
    deque<int> odd;
    deque<int> even;
    for(auto x:lis){
        if(x%2==0) even.push_back(x);
        else odd.push_back(x);
    }
    for(auto x:odd){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
