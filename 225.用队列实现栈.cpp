/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include <iostream>
#include <stack>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;
// @lc code=start
class MyStack {
public:
    queue<int> q1,q2;

    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int temp;
        while(q1.size()!=1){
            temp=q1.front();
            q1.pop();
            q2.push(temp);           
        }
        int output=q1.front();
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return output;
    }
    
    int top() {
        int temp;
        while(!q1.empty()){
            temp=q1.front();
            q1.pop();
            q2.push(temp);           
        }

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return temp;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

