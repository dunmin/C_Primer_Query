#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector<int> vec = {1,2,3,4,5};
    cout<<vec[0]<<endl;
    cout<<vec.at(0)<<endl;
    cout<<vec.front()<<endl;
    cout<<*vec.begin()<<endl;
    return 0;
}
