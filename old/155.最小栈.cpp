/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include "0.cpp"
// @lc code=start
class MinStack {
    struct Node
    {
        int val;
        Node* nxt;
        Node* pre;
        int stackMin=INT32_MAX;
        Node() :val(0),nxt(nullptr),pre(nullptr){}
        Node(int x) :val(x),nxt(nullptr),pre(nullptr){}
    };
    Node* nodeTop=nullptr;
public:
    MinStack() {
        nodeTop=new Node(0);
    }
    
    void push(int val) {
        auto newNode=new Node(val);
        newNode->stackMin=nodeTop->stackMin;
        nodeTop->nxt=newNode;
        newNode->pre=nodeTop;
        nodeTop=newNode;
        if(newNode->val<newNode->stackMin){
            newNode->stackMin=val;
        }
        return ;
    }
    
    void pop() {
        nodeTop=nodeTop->pre;
        delete nodeTop->nxt;
    }
    
    int top() {
        return nodeTop->val;
    }
    
    int getMin() {
        return nodeTop->stackMin;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

