/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */
#include "0.cpp"
// @lc code=start
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head,*slow=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                ListNode* ptr=head;
                while(ptr!=fast){
                    ptr=ptr->next;
                    fast=fast->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};
// @lc code=end

