/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */
#include "0.cpp"
// @lc code=start
class MedianFinder {
    priority_queue<int, vector<int>,less<int>> left;//多存一个
    priority_queue<int ,vector<int>,greater<int>> right;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size()==right.size()){
            left.push(num);
            right.push(left.top());
            left.pop();
        }else{
            right.push(num);
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size()==right.size())
            return (double)(left.top()+right.top())/2;
        else
            return (double)right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

