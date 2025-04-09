/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode* pre=nullptr;
        ListNode* cur=head;
        ListNode* nxt=head->next;
        while(1){
            cur->next=pre;
            pre=cur;
            cur=nxt;
            if(nxt==NULL) break;
            else nxt=nxt->next;
        }
        return pre;
    }
};
// @lc code=end

