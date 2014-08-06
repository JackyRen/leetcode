#include "solution.h"
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    Solution s;
    vector< vector<int> > data = {
        {1, 2, 0},
        {3,4,-1,1},
        {1,2,3,4},
        {5,-1,3,1,-2,2,-3,4}
    };
    for(auto iter = data.begin();iter!=data.end();++iter){
        cout<<s.firstMissingPositive(iter->data(),iter->size()) <<" ..."<<endl;
    }
}