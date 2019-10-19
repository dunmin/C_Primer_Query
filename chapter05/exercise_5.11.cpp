#include <iostream>

using namespace std;

int main()
{
    string str = "    aaa\t\naaa     asdfs";
    int tcoun = 0, ncoun = 0, coun = 0;
	for(auto x:str){
        switch (x){
            case '\t':
                tcoun++;
                break;
            case '\n':
                ncoun++;
                break;
            case ' ':
                coun++;
                break;
            default:{
                break;
            }
        }
	}
	cout<<tcoun<<" "<<ncoun<<" "<<coun<<endl;
    return 0;
}
