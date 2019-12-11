#include <iostream>
#include <vector>
#include <string>
using namespace std;

double sum(vector<string> &vec)
{
    double sav = 0;
    for(auto str:vec){
        sav += stod(str);
    }
    return sav;
}

int main()
{
	vector<string> vec = {"13.00", "12.00", "10.00"};
	cout<<sum(vec)<<endl;
	return 0;
}
