#include <iostream>
#include <vector>
using namespace std;

int func(int a, int b){
    return 1;
}

int func(int,int);

int add(int a,int b){
    return a+b;
}
int minu(int a,int b){
    return a-b;
}
int multiply(int a,int b){
    return a*b;
}
int division(int a,int b){
    return a/b;
}


int main()
{
    vector<decltype(func)*> q;
    q.push_back(add);
    q.push_back(minu);
    q.push_back(multiply);
    q.push_back(division);
    for(vector<decltype(func)*>::iterator iter = q.begin();iter!=q.end();iter++){
        cout<<(*iter)(1,2)<<endl;
        // cout<<(**iter)(1,2)<<endl;               // 与上面的方式等价
    }
    return 0;
}
