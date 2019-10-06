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
    vector<string> word_group;
    string word;
    while(cin>>word){
        if(word=="null") break;
        else {
            word_group.push_back(word);
        }
    }
    for(auto &X : word_group){
        for(auto &Y : X){
            Y = toupper(Y);
        }
    }
    for(auto X : word_group){
        cout<<X<<endl;
    }
    return 0;
}
