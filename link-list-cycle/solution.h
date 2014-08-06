#include <vector>
#include <functional>
#include <cassert>
#include <iostream>
#include <cassert>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getMark(ListNode *head){
        int minI=0x7fffffff,maxI=-0x80000000;
        ListNode *node = head;
        while(node->next){
            if(maxI < node->val){
                maxI = node->val;
            }
            if(minI > node->val){
                minI = node->val;
            }
            node = node->next;
            if(node == head)break;
        }
        if(maxI + 1 != minI ){
            return maxI + 1;
        }else{
            //just kidding
            //assert(false);
            return 0x435a3f34;
        }
    }
    ListNode *detectCycle(ListNode *head) {
        if(head && head->next){
            ListNode *node = head;
            int mark = getMark(head);
            while(node->next){
                if(node->val == mark){
                    return node;
                }
                node->val = mark;
                node = node->next;
            }
        }
        return NULL;
    }
};