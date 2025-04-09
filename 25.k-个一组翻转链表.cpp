/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyHead=new ListNode(0,head);
        int n=0;
        ListNode* p0 = dummyHead;
        ListNode* cur=head;
        while(cur){
            n++;
            cur=cur->next;
        }

        ListNode* pre=dummyHead;
        cur=head;
        while(n>=k){
            for(int i=0;i<k;i++){
                ListNode* nxt=cur->next;
                cur->next=pre;
                pre=cur;
                cur=nxt;
            }
            n=n-k;

            ListNode* nxt = p0->next;
            p0->next->next = cur;
            p0->next = pre;
            p0 = nxt;
        }

        return dummyHead->next;
    }
};
// @lc code=end

