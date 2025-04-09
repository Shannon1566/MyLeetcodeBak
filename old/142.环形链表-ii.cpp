/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
struct ListNode
{
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* createLinkedList(const std::vector<int>& nums) {
    if (nums.empty()) return nullptr;
    
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    
    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    
    return head;
}
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
    ListNode *detectCycle(ListNode *head) {
        // unordered_set<ListNode *> set;
        // ListNode * curPtr=head;
        // while(curPtr!=nullptr){
        //     auto it=set.find(curPtr);
        //     if(it!=set.end()){
        //         return curPtr;
        //     }else{
        //         set.insert(curPtr);
        //     }
        //     curPtr=curPtr->next;
        // }
        // return nullptr;

        ListNode *fast =head;
        ListNode *slow =head;
        while(fast!=nullptr&&fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if (slow==fast){
                auto index1=fast;
                auto index2=head;
                while (index1!=index2)
                {
                    index1=index1->next;
                    index2=index2->next;
                }
                return index1;
                
            }
        }
        return nullptr;
        
        
    }
};
// @lc code=end

