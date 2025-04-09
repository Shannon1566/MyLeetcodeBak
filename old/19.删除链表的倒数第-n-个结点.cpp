/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curNode=head;
        ListNode* nextNNode=head;
        for(int i=0;i<n;i++){
            nextNNode=nextNNode->next;
        }
        if(nextNNode==nullptr){
            return head->next;
        }
        while(nextNNode->next!=nullptr){
            curNode=curNode->next;
            nextNNode=nextNNode->next;
        }

        curNode->next=curNode->next->next;  
        return head;
    }
};
// @lc code=end

