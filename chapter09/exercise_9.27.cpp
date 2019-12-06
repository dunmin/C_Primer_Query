#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
using namespace std;


int main()
{
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    forward_list<int> a(begin(ia), end(ia));
    auto now = a.begin(), prev = a.before_begin();
    while(now!=a.end()){
        if(*now%2){
            now = a.erase_after(prev);
        }
        else {
            prev = now;
            now++;
        }
    }
    for(auto x:a){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
