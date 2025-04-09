/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
#include "0.cpp"
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* result=new ListNode();
        ListNode* cur=result;
        int cnt=0,a=0,b=0;
        while(l1||l2){
            if(l1){
                a=l1->val;
                l1=l1->next;
            }else a=0;
            if(l2){
                b=l2->val;
                l2=l2->next;
            }else b=0;
            ListNode* node=new ListNode((a+b+cnt)%10);
            cnt=(a+b+cnt)/10;

            cur->next=node;
            cur=node;
        }
        if (cnt!=0){
            ListNode* node=new ListNode(cnt);
            cur->next=node;
        } 
        return result->next;
    }
};
// @lc code=end
