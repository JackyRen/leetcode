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
        return 0x435a3f34;
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
