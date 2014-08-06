#include "solution.h"
#include "libs.h"
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    Solution s;
    vector< vector<string> > strs = {
        {"cat","rye","aye","dog", "god","cud","cat","old","fop","bra"},
        {"4", "13", "5", "31", "+"},
        {"5","5","5"}
    };
    for(auto iter = strs.begin();iter!=strs.end();++iter){
        auto ret = s.anagrams(*iter);
        cout<<join(ret,"\"",",")<<endl;
        
    }
}