/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int cnt=0;
        ListNode* hummyHead=new ListNode();
        ListNode* pre=hummyHead;
        while(l1||l2||cnt){
            int a=0,b=0;
            if (l1) a=l1->val;
            if (l2) b=l2->val;
            
            int sum=a+b+cnt;
            cnt=sum/10;
            sum=sum%10;
            ListNode* cur= new ListNode(sum);
            pre->next=cur;
            pre=cur;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }

        return hummyHead->next;
    }
};
// @lc code=end

