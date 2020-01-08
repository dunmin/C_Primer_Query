#include <iostream>
#include <string>
#include <list>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec = {1,2,3,4,5,6,2,3,4,5,1,7};
    sort(vec.begin(), vec.end());
    for(auto x:vec){
        cout<<x<<" ";
    }
    cout<<endl;
    auto delpos = unique(vec.begin(),vec.end());
    for(auto x:vec){
        cout<<x<<" ";
    }
    cout<<endl;
    vec.erase(delpos,vec.end());
    for(auto x:vec){
        cout<<x<<" ";
    }
    return 0;
}
