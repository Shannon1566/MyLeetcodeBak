/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include "0.cpp"
// @lc code=start
class Solution {

    class MyQue{
        public:
        deque<int> que;
        void pop(int value){
            if(!que.empty()&&value==que.front()){
                que.pop_front();
            }
        }
        void push(int value){
            while(!que.empty()&&que.back()<value){
                que.pop_back();
            }
            que.push_back(value);
        }
        int front(){
            return que.front();
        }    
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQue myQue;
        vector<int> result;
        for(int i=0;i<k;i++){
            myQue.push(nums[i]);
        }

       
        for(int i=k;i<nums.size();i++){
            result.emplace_back(myQue.front());
            myQue.pop(nums[i-k]);
            myQue.push(nums[i]);
        }
        result.emplace_back(myQue.front());
        return result;
        
    }
};
// @lc code=end

