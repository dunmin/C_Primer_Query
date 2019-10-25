#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <vector>
#include <string>
using namespace std;

string str_arr[4] = {"test1","test2","test3","test4"};

//使用正常方法
/*string (*func())[4]
{
    return &str_arr;
}*/

// 使用重命名
/*typedef string str_array[4];
str_array *func()
{
    return &str_arr;
}*/

// 使用decltype
/*decltype(str_arr) *func()
{
    return &str_arr;
}*/

// 使用尾置返回类型
auto func()->string(*)[4]
{
    return &str_arr;
}

int main()
{
    string (*arr_pointer)[4] = func();
    cout<<**arr_pointer<<endl;
    return 0;
}
