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
        ListNode* pre=nullptr;
        ListNode* nxt=nullptr;
        while(head!=nullptr){
            nxt=head->next;
            head->next=pre;
            pre=head;
            head=nxt;
        }
        return pre;
    }
};
// @lc code=end

