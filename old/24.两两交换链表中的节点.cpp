/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */
#include "0.h"
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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr) return head;
        ListNode* dummyHead=new ListNode(0,head);
        ListNode* pre=dummyHead;
        ListNode* cur=head;
        ListNode* nxt=head->next;
        while(nxt){
            cur->next=nxt->next;
            pre->next=nxt;
            nxt->next=cur;
            
            pre=cur;
            cur=pre->next;
            if(cur==nullptr) break;
            nxt=cur->next;                   
        }
        return dummyHead->next;
    }
};
// @lc code=end

