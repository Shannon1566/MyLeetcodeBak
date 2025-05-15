/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

#include <iostream>
#include <stack>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// @lc code=start
class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {
        
    }
    
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        int output;
        while(!stIn.empty()){
            stOut.push(stIn.top());
            stIn.pop();
        }
        output=stOut.top();
        stOut.pop();

        while(!stOut.empty()){
            stIn.push(stOut.top());
            stOut.pop();
        }
        return output;
    }
    
    int peek() {
        int output;
        while(!stIn.empty()){
            stOut.push(stIn.top());
            stIn.pop();
        }
        output=stOut.top();

        while(!stOut.empty()){
            stIn.push(stOut.top());
            stOut.pop();
        }
        return output;
    }
    
    bool empty() {
        return stIn.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

