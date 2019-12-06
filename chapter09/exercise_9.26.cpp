#include <iostream>
#include <vector>
#include <list>
using namespace std;


int main()
{
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    vector<int> a(begin(ia), end(ia));
    list<int> b(begin(ia), end(ia));
    for(auto iter= a.begin();iter!=a.end();){
        if(*iter%2){
            ++iter;
        }
        else {
            iter = a.erase(iter);
        }
    }
    for(auto iter=b.begin();iter!=b.end();){
        if(*iter%2){
            iter = b.erase(iter);
        }
        else {
            ++iter;
        }
    }
    return 0;
}
