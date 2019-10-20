#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    int a,b;
    while(cin>>a>>b){
        try{
            if(b==0){
                throw runtime_error("divisor is 0");
            }
            cout<<a/b<<endl;
            break;
        }catch(runtime_error err){
            cout<<err.what()<<endl;
        }
    }
    return 0;
}
