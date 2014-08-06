#include <vector>
#include <functional>
#include <cassert>
#include <iostream>
#include <map>

using namespace std;
class Solution {
public:
    map<string,function<int(int,int)> > calcs;
    typedef pair<string,function<int(int,int)> > cfp;
    void trim(string &s){
        int i = 0,j=s.length();
        while(s[i]==' ')i++;
        while(s[j-1]==' ')j--;
        s = s.substr(i,j-i);
    }
    int parseInt(const string& s){
        int ret = 0,i = 0;
        if (s[0]=='-'){
            i=1;
        }
        for(; i < s.length() ; i++){
            ret = ret*10 + s[i] - '0';
        }
        return s[0]=='-'?-ret:ret;
    }
    void init(){
        calcs.insert( cfp("+", [](int x,int y){return x+y;}));
        calcs.insert( cfp("-", [](int x,int y){return x-y;}));
        calcs.insert( cfp("*", [](int x,int y){return x*y;}));
        calcs.insert( cfp("/", [](int x,int y){return x/y;}));
    }
    int evalRPN(vector<string> &tokens) {
        init();
        vector<int> numberStack;
        for(auto iter = tokens.begin() ; tokens.end()!=iter;++iter){
            trim(*iter);
            auto calcIter = calcs.find(*iter);
            //cout<<"*** "<<*iter<<"  "<<charId<<endl;
            if(calcIter==calcs.end()){
                numberStack.push_back(parseInt(*iter));
            }
            else{
                int b = numberStack.back();
                numberStack.pop_back();
                int a = numberStack.back();
                numberStack.pop_back();
                numberStack.push_back(calcIter->second(a,b));
            }
        }
        assert(numberStack.size()==1);
        return numberStack.back();
    }
};
