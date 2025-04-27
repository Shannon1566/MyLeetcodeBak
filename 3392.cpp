/*
 * @lc app=leetcode.cn id=3392 lang=cpp
 * @lcpr version=30200
 *
 * [3392] 统计符合条件长度为 3 的子数组数目
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size()-2;i++){
            if((nums[i]+nums[i+2])*2==nums[i+1])
                cnt++;
        }
        return cnt;
    }
};
// @lc code=end
int main(){
    vector<int> nums={1,2,1,4,1};
    Solution sol;
    sol.countSubarrays(nums);
    return 0;
}



