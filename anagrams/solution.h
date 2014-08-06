#include <vector>
#include <functional>
#include <cassert>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    inline void transform(string& str){
        sort(str.begin(),str.end());
    }
    vector<string> anagrams(vector<string> &strs) {
        map<string,vector<string> > ret;
        for(auto iter = strs.begin();iter!=strs.end();++iter){
            string a = *iter;
            transform(a);
            auto mapIter = ret.find(a);
            if(mapIter == ret.end()){
                ret.insert(pair<string,std::vector<string> > (a,std::vector<string>({*iter})));
            }else{
                mapIter->second.push_back(*iter);
            }
        }
        vector<string> r;
        for(auto mapIter = ret.begin();mapIter!=ret.end();++mapIter){
            if(mapIter->second.size()>1){
                r.insert(r.end(),mapIter->second.begin(),mapIter->second.end());
            }
        }
        return r;
    }
};