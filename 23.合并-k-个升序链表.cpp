/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val>b->val;
        };
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq; 
        for(auto it:lists){
            if (it)
                pq.push(it);
        }
        ListNode dummy;
        ListNode* cur=&dummy;
        while(!pq.empty()){
            ListNode* minNode=pq.top();
            pq.pop();
            if(minNode->next)
                pq.push(minNode->next);
            cur->next=minNode;
            cur=cur->next;
        }
        return dummy.next; 
    }
};
// @lc code=end

