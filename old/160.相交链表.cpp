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
        unordered_set<ListNode*> setA;
        while(headA){
            setA.emplace(headA);
            headA=headA->next;
        }
        while(headB){
            auto it=setA.find(headB);
            if(it!=setA.end()){
                return headB;
            }else{
                headB=headB->next;
            }
        }
        return nullptr;
    }
};
// @lc code=end

