/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        if (head==NULL) return false;
        if (head->next==NULL) return false;
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast!=slow){
            if(fast==NULL || fast->next==NULL) return false;
            fast=fast->next->next;
            slow=slow->next;
            
        }
        return true;
    }
};
// @lc code=end

