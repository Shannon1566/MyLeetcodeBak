/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA=headA,*curB=headB;
        while(1){
            if(curA=curB) return curA;
            if(curA=nullptr)
                curA=headB;
            else
                curA=curA->next;
            if(curB=nullptr)
                curB=headA;
            else
                curB=curB->next;
        }
        return nullptr;
    }
};
// @lc code=end

