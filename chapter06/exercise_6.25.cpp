#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc,char *argv[])
{
    cout<<argc<<endl;
    for(int i=0;i<argc;i++){
        char *ch = argv[i];
        string str = "";
        while((*ch)!='\0'){
            str += *ch;
            ch++;
        }
        cout<<str<<endl;
    }
    return 0;
}
