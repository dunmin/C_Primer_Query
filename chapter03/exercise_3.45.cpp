#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int ia[3][4] =  {
        {1,2,3,4},
        {1,2,3,4},
        {1,2,3,4}
    };
    // important-·¶Î§for
    for(auto &p:ia){
        for(auto q:p){
            cout<<q<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    // ÏÂ±ê
    for(auto i=0;i<3;i++){
        for(auto j=0;j<4;j++){
            cout<<ia[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    // Ö¸Õë
    for(auto p=begin(ia);p!=end(ia);p++){
        for(auto *q=begin(*p);q!=end(*p);q++){
            cout<<*q<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}
