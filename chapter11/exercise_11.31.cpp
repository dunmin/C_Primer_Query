#include <iostream>
#include <string>
#include <list>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <set>
#include <fstream>
using namespace std;

int main()
{
    multimap<string, string> au_work{
		{ "alan", "DMA" },
		{ "pezy", "LeetCode" },
		{ "alan", "CLRS" },
		{ "wang", "FTP" },
		{ "pezy", "CP5" },
		{ "wang", "CPP-Concurrency" } };
    auto rang = au_work.equal_range("alan");
    for(auto iter = rang.first;iter!=rang.second;){
        cout<<iter->first<<" "<<iter->second<<endl;
        iter = au_work.erase(iter);
    }
    return 0;
}
