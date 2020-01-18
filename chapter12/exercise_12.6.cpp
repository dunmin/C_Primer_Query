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
using namespace std;

void print_vec(vector<int> *ptr)
{
    for(auto x:*ptr)
        cout<<x<<endl;
}

void func(vector<int> *ptr)
{
    int x,y;
    cin>>x>>y;
    (*ptr).push_back(x);
    (*ptr).push_back(y);
    print_vec(ptr);
}

int main()
{
    vector<int> *vec_ptr = new vector<int>;
    func(vec_ptr);
    delete vec_ptr;
    return 0;
}
