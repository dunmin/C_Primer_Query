#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <vector>
#include <string>
#define NDEBUG
using namespace std;


vector<int> a = {1,2,3,4};

void scan(vector<int>::iterator v)
{
    #ifdef NDEBUG
    cout<<"size: "<<a.size()<<endl;
    #endif // NDEBUG
    if(v!=a.end()){
        cout<<*v<<endl;
        scan(++v);
    }
}

int main()
{

    scan(a.begin());
}
