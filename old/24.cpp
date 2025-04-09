/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* bummyHead=new ListNode(0);
        bummyHead->next=head;
        auto curPtr=bummyHead;
        while(curPtr->next!=nullptr){
            if (curPtr->next->next==nullptr) return bummyHead->next;
            ListNode* firstNode=curPtr->next;
            ListNode* secondNode=curPtr->next->next;
            ListNode* thirdNode=secondNode->next;
            
            curPtr->next=secondNode;
            secondNode->next=firstNode;
            firstNode->next=thirdNode;

            curPtr=curPtr->next->next;

        }
        return bummyHead->next;
    }
};
// @lc code=end
int main(){
    ListNode* head=createLinkedList({1,2,3,4});
    Solution solution;
    solution.swapPairs(head);
    return 0;
}

