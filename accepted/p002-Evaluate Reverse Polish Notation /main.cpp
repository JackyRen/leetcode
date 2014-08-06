#include "solution.h"
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;
string join(const vector<string>& strs,string wrapper,string spliter){
    string ret = "";
    for(auto i = strs.begin();i!=strs.end();++i){
        ret += wrapper + *i + wrapper + spliter;
    }
    return ret;
}
int main(){
    Solution s;
    vector< vector<string> > strs = {
        {"2", "1", "+", "3", "*"},
        {"4", "  13", "5", " / ", "+"},
        {"3","-4","+"}
    };
    for(auto iter = strs.begin();iter!=strs.end();++iter){
        cout<<join(*iter,"'"," ")<<" -> " << s.evalRPN(*iter) <<endl;
    }
}