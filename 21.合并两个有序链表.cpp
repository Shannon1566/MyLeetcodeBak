/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* hummyHead=new ListNode();
        ListNode* pre=hummyHead;
        while(list1&&list2){
            if(list1->val<list2->val){
                pre->next=list1;
                list1=list1->next;
            }else{
                pre->next=list2;
                list2=list2->next;
            }
            pre=pre->next;
        }
        pre->next=list1==nullptr?list2:list1;
        return hummyHead->next;
        // if(list1==nullptr) return list2;
        // if(list2==nullptr) return list1;
        // ListNode* tmp=new ListNode();
        // if(list1->val<list2->val){
        //     tmp->val=list1->val;
        //     tmp->next=mergeTwoLists(list1->next,list2);
        // }else{
        //     tmp->val=list2->val;
        //     tmp->next=mergeTwoLists(list1,list2->next);
        // }
        // return tmp;
    }
};
// @lc code=end

