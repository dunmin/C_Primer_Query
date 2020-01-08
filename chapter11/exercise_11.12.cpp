#include <iostream>
#include <string>
#include <list>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <fstream>
using namespace std;

int main()
{
    vector<pair<string, int>> pair_vec;
    fstream in("test");
    string name;
    int score;
    while(in>>name>>score){
        pair_vec.push_back(make_pair(name, score));
    }
    for(auto x:pair_vec){
        cout<<x.first<<" "<<x.second<<endl;
    }
    return 0;
}
