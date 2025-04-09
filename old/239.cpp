/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <iostream>
#include <stack>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <deque>
using namespace std;
// @lc code=start

class Solution
{
public:
    class MyQueue
    {
    public:
        deque<int> que;
        void pop(int value)
        {
            if (!que.empty() && que.front() == value)
            {
                que.pop_front();
            }
        }

        void push(int value)
        {
            while (!que.empty() && value > que.back())
            {
                que.pop_back();
            }
            que.push_back(value);
        }

        int front()
        {
            return que.front();
        }
    };
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result;
        MyQueue que;
        for (int i = 0; i < k; i++)
        {
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for (int i = k; i < nums.size() ; i++)
        {
            
            que.pop(nums[i-k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};
// @lc code=end
int main(){
    Solution sol;
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    int k=3;
    sol.maxSlidingWindow(nums,k);
    return 0;
}