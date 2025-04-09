/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */
#include "0.cpp"
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// @lc code=start


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur=head;
        while(cur){
            Node* newNode=new Node(cur->val);
            newNode->next=cur->next;
            cur->next=newNode;
            cur=cur->next->next;
        }
        cur=head;
        while(cur){
            cur->next->random=cur->random==nullptr?nullptr:cur->random->next;
            cur=cur->next->next;
        }

        cur=head;
        Node* dummyHead=new Node(-1);
        Node* curNew=dummyHead;
        while(cur){
            curNew->next=cur->next;
            cur->next=cur->next->next;
            cur=cur->next;
            curNew=curNew->next;
        }
        return dummyHead->next;
    }
};
// @lc code=end

