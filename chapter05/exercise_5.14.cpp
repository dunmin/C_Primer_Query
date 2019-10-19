#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    //freopen("test.txt","r",stdin);
    string str;
    string str_before = "";
    int coun = 1;
    cin>>str_before;
    string str_max = str_before;
    int coun_max = coun;
    while(cin>>str){
        if(str!=str_before){
            coun = 1;
        }
        else{
            coun++;
            if(coun>coun_max){
                coun_max = coun;
                str_max = str;
            }
        }
        str_before = str;
    }
    cout<<str_max<<" "<<coun_max<<endl;

    return 0;
}
