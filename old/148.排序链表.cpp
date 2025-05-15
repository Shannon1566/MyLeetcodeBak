/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
private:
    ListNode* midNode(ListNode* head){
        ListNode* pre=head;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast&&fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre->next=nullptr;
        return slow;
    }
    ListNode* mergeList(ListNode* l1,ListNode* l2){
        ListNode dummy;
        ListNode* cur=&dummy;
        while(l1&&l2){
            if(l1->val<l2->val){
                cur->next=l1;
                l1=l1->next;
            }else{
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        cur->next=l1?l1:l2;
        return dummy.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) 
            return head;
        ListNode* head2 =midNode(head);
        head=sortList(head);
        head2=sortList(head2);
        return mergeList(head,head2);
    }
};
// @lc code=end

