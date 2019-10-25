#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <vector>
#include <string>
using namespace std;

string str_arr[4] = {"test1","test2","test3","test4"};

string (*func())[4]
{
    return &str_arr;
}

int main()
{
    string (*arr_pointer)[4] = func();
    cout<<**arr_pointer<<endl;
    return 0;
}
