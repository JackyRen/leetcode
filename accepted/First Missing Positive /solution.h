#include <vector>
#include <functional>
#include <cassert>
#include <iostream>

using namespace std;
class Solution {
public:
    int * data;
    int n_;
    inline bool isVisited(int i)const{
        //cout<<"isVisited["<<i<<"]"<<"  "<<data[i-1]<<endl;
        return (i<=0 || i>n_ || data[i-1] == i);
        
    }
    void try_visit(int i){
        //cout<<"try_visit  "<<i<<endl;
        int cur = 0;
        while(!isVisited(i)){
            //cout<<"inner try_visit  "<<i<<endl;
            int v = data[i-1];
            data[i-1] = cur;
            if(!isVisited(v)){
                cur = i = data[v-1];
                data[v-1] = v;
            }
            else break;
        }
    }
    int firstMissingPositive(int A[], int n) {
        data = A;
        n_ = n;
        for(int i = 1 ; i<= n ; ++i){
            try_visit(i);
        }
        for(int i = 1; i <= n ; i++){
            //cout<<" *** "<<i<<" "<<data[i-1]<<endl;
            if(!isVisited(i)){
                return i;
            }
        }
        return n+1;
    
    }
};