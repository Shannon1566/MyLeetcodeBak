/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ptr=head;
        while (ptr != NULL&&ptr->val==val){
            ptr=ptr->next;
        }
        head=ptr;
        while(ptr != NULL&&ptr->next!=NULL){
            if (ptr->next->val==val){
              ptr->next=ptr->next->next;
              continue;
            }
            ptr=ptr->next;
        }
        return head;
    }
};
// @lc code=end

int main(){
    ListNode* head=createLinkedList({1,2,6,3,4,5,6});
    Solution solution;
    solution.removeElements(head,6);
    return 0;
}
