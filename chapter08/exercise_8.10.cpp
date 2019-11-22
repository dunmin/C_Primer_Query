#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;
vector<string> string_list;

int main()
{
    ifstream infile("test");
    if(infile){
        string line;
        while(getline(infile, line)){
            string_list.push_back(line);
        }
        for(auto &mid: string_list){
            istringstream in_line(mid);
            string x;
            while(in_line>>x){
                cout<<x<<",";
            }
            cout<<endl;
        }
    }
    return 0;
}
