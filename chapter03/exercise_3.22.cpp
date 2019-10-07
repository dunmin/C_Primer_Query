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
    //freopen("test","r",stdin);
    vector<string> word_group;
    string word;
    while(cin>>word){
        word_group.push_back(word);
    }
    for(auto it = word_group.begin();it!=word_group.end()&&!it->empty();it++){
        for(auto &X : (*it)){
            X = toupper(X);
        }
    }
    for(auto X : word_group){
        cout<<X<<endl;
    }
    return 0;
}
