#include <iostream>
#include <vector>
#include <string>
using namespace std;

string replace_str(string &s, const string &old_val, const string &new_val)
{
    string::iterator curr = s.begin();
    while(s.end()-curr>old_val.size()){
        if(old_val==string(curr, curr+old_val.size())){
            s.erase(curr, curr+old_val.size());
            s.insert(curr,new_val.begin(), new_val.end());
            curr = curr + old_val.size();
        }
        else {
            curr++;
        }
    }
    return s;
}

int main()
{
	string s = "12434123143", old_val="12", new_val="13";
	cout<<replace_str(s, old_val, new_val)<<endl;
	return 0;
}
