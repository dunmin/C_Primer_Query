#include <iostream>
#include <string>
#include <list>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <set>
#include <fstream>
#include <memory>
using namespace std;

void print_vec(shared_ptr<vector<int>> ptr)
{
    for(auto x:*ptr)
        cout<<x<<endl;
}

void func(shared_ptr<vector<int>> ptr)
{
    int x,y;
    cin>>x>>y;
    (*ptr).push_back(x);
    (*ptr).push_back(y);
    print_vec(ptr);
}

int main()
{
    shared_ptr<vector<int>> vec_ptr = make_shared<vector<int>>();
    func(vec_ptr);
    return 0;
}
