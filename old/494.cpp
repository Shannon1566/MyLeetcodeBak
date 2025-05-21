/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */
#include "0.h"
// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if((sum+target)%2==1) return 0;
        if(abs(target)>sum) return 0;
        int left=(sum+target)/2;
        vector<int> dp(left+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=left;j>=nums[i];j--){
                dp[j]+=dp[j-nums[i]];
            }
            for(auto it:dp) cout<<it<<' ';
            cout<<endl;
        }
        return dp[left];
    }
};
// @lc code=end
int main(){
    Solution sol;
    vector<int> nums{1,1,1,1,1};
    sol.findTargetSumWays(nums,3);
    return 0;
}
