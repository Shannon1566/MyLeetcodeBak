/*
 * @lc app=leetcode.cn id=2918 lang=cpp
 *
 * [2918] 数组的最小相等和
 */
#include "0.cpp"
// @lc code=start
class Solution {
    void countSum(vector<int> &nums, long long &minSum, long long &cnt){
        int n=nums.size();
        minSum=0;
        cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                minSum++;
                cnt++;
            }
            minSum+=nums[i];
        }
        return ;
    }
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long minSum1,minSum2,cnt1,cnt2;
        countSum(nums1,minSum1,cnt1);
        countSum(nums2,minSum2,cnt2);
        if(minSum1<minSum2&&cnt1==0) return -1;
        if(minSum2<minSum1&&cnt2==0) return -1;
        return max(minSum1,minSum2);
    }
};
// @lc code=end

