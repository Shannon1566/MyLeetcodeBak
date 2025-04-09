/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */
#include "0.cpp"
// @lc code=start
class Solution {
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }

public:
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        int maxIndex = -1;
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0&&k>0){
                nums[i] = -nums[i];
                k--;
            }
                
        }

        if (k % 2 == 1) nums[nums.size() - 1] *= -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        return sum;
    }
};
// @lc code=end
