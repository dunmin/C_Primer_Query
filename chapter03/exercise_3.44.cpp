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

    // pointer
    using array_type = int[4];
    for(array_type *p=begin(ia);p!=end(ia);p++){
        for(int *q=begin(*p);q!=end(*p);q++){
            cout<<*q<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}
