#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    string word_pre;
    cin>>word_pre;
    string word;
    while(cin>>word){
        if(word==word_pre&&isalpha(word[0])){
                break;
        }
        else {
            word_pre = word;
            continue;
        }
    }

    return 0;
}