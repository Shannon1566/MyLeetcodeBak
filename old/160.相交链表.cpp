/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */
#include "0.h"
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
        int LengthA=0,LengthB=0;
        ListNode* curA=headA;
        while(curA){
            LengthA++;
            curA=curA->next;
        }
        ListNode* curB=headB;
        while(curB){
            LengthB++;
            curB=curB->next;
        }

        curA=headA;
        curB=headB;
        int diff=LengthA-LengthB;
        if(LengthA>LengthB){
            for(int i=0;i<diff;i++){
                curA=curA->next;
            }
        }else{
            for(int i=0;i<abs(diff);i++)
                curB=curB->next;
        }

        while(curA){
            if(curA==curB) return curA;
            curA=curA->next;
            curB=curB->next;
        }
        return nullptr;
    }
};
// @lc code=end

