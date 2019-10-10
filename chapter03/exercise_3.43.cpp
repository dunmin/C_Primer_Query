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
    // important-·range for
    for(int (&p)[4]:ia){
        for(int q:p){
            cout<<q<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    // index
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<ia[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    // pointer
    for(int (*p)[4]=begin(ia);p!=end(ia);p++){
        for(int *q=begin(*p);q!=end(*p);q++){
            cout<<*q<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}
