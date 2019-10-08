#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int main()
{
    freopen("test","r",stdin);
    vector<int> num_group;
    int num;
    while(cin>>num){
        num_group.push_back(num);
    }
    cout<<"sum of adjacent:"<<endl;
    for(auto iter=num_group.begin();iter!=num_group.end()-1;iter++){
        cout<< *iter + *(iter+1)<<endl;
    }
    cout<<"sum of corresponding:"<<endl;
    for(auto it_start=num_group.begin(),it_end=num_group.end()-1;it_start!=it_end;it_start++,it_end--){
        cout<< *it_start + *it_end<<endl;
    }
    return 0;
}
