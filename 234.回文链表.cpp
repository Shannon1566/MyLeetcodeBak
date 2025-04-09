/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */
#include "0.cpp"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if(head->next==nullptr) return true;

        ListNode* fast=head;
        ListNode* slow=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* pre=nullptr;
        ListNode* nxt=nullptr;
        ListNode* cur=slow;

        while(cur){
            nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nxt;
        }

        ListNode* l1=head;
        ListNode* l2=pre;
        

        while(l1&&l2){
            if(l1->val!=l2->val)
                return false;
            {
                l1=l1->next;
                l2=l2->next;
            }
        }
        return true;
    }
};
// @lc code=end

