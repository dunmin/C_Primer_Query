#include <iostream>
#include <string>
#include <list>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <fstream>
#include <cctype>


int main()
{
    std::fstream file("test");
    std::map<std::string, int> dict;
    std::string word;
    while(file>>word){
        for(auto &x:word){
            if(isalpha(x)){
                x = tolower(x);
            }
        }
        std::string::iterator iter;
        while((iter = remove_if(word.begin(), word.end(), ispunct))!=word.end()){
            word.erase(iter,word.end());

        }
        ++dict[word];
    }
    for(auto x:dict){
        std::cout<<x.first<<" "<<x.second<<std::endl;
    }
    return 0;
}
