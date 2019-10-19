#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> seq1 = {1,2,3,4,5,6,7,8};
    vector<int> seq2 = {1,2,3,4};
    if(seq1.size()>seq2.size()){
        swap(seq1,seq2);
    }
    decltype(seq1.size()) i;
    for(i=0;i<seq1.size();i++){
        if(seq1[i]!=seq2[i])
            break;
    }
    if(i<seq1.size()){
        cout<<"NO"<<endl;
    }
    else {
        cout<<"YES"<<endl;
    }

    return 0;
}
