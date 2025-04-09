/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head==nullptr){
            return head;
        }
        ListNode* curPtr=head;
        ListNode* prePtr=nullptr;
        ListNode* nextPtr=curPtr->next;
        while (curPtr!=nullptr){
            nextPtr=curPtr->next;
            curPtr->next=prePtr;
            prePtr=curPtr;
            curPtr=nextPtr;
        }
        return prePtr;
    }
};
// @lc code=end

int main(){
    ListNode* head=createLinkedList({1,2,3,4,5});
    Solution solution;
    solution.reverseList(head);
    return 0;
}
