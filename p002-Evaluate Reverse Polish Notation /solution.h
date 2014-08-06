#include <vector>
#include <functional>
#include <cassert>
#include <iostream>

using namespace std;
class Solution {
public:
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
    int calc(int a,int b,int op){
        vector<function<int(int,int)> > calcs ={
            [](int x,int y){return x+y;},
            [](int x,int y){return x-y;},
            [](int x,int y){return x*y;},
            [](int x,int y){return x/y;}
        };
        int ret = calcs[op](a,b);
        //cout<<a<<" "<<b<<"    "<<op<<" -> "<<ret<<endl;
        return ret;
    }
    int parseChar(const string& s){
        if(s.length()!=1)
            return -1;
        vector<char> chars = {'+','-','*','/'};
        for(auto i = chars.begin() ; i != chars.end(); ++i){
            if (s[0] == *i)
                return i-chars.begin();
        }
        return -1;
    }
    int evalRPN(vector<string> &tokens) {
        vector<int> numberStack;
        for(auto iter = tokens.begin() ; tokens.end()!=iter;++iter){
            trim(*iter);
            int charId = parseChar(*iter);
            //cout<<"*** "<<*iter<<"  "<<charId<<endl;
            if(charId==-1){
                numberStack.push_back(parseInt(*iter));
            }
            else{
                int b = numberStack.back();
                numberStack.pop_back();
                int a = numberStack.back();
                numberStack.pop_back();
                numberStack.push_back(calc(a,b,charId));
            }
        }
        assert(numberStack.size()==1);
        return numberStack.back();
    }
};