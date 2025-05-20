/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */
#include "0.h"
// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for(auto it:stones) sum+=it;
        int target=sum/2;
        vector<int> dp(target+1,0);

        for(int i=0;i<stones.size();i++){
            for(int j=target;j>=stones[i];j--){
                dp[j]=max(dp[j],dp[j-stones[i]]+stones[i]);
            }
        }

        return sum-2*dp[target];
    }
};
// @lc code=end

