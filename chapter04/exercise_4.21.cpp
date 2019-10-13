#include <iostream>
#include <cstring>
#include <string>
#include <string>
#include <cctype>
#include <vector>
using namespace std;
vector<int> number = {1,2,3,4,5,6,7};

int main()
{
    for(auto &X:number){
        X = ((X%2==0)?X:X*2);
    }
    for(auto X:number){
        cout<<X<<endl;
    }
    return 0;
}
