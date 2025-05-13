/*
 * @lc app=leetcode.cn id=3335 lang=cpp
 *
 * [3335] 字符串转换后的长度 I
 */
#include "0.cpp"
// @lc code=start
class Solution {
    const int mod =1e9+7;
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> dp(26);
        int sum=0;
        for(char c:s){
            dp[c-'a']++;
        }

        for(int i=0;i<t;i++){
            int cnt_z=dp[25];
            for(int i=25;i>0;i--){
                dp[i]=dp[i-1];
            }
            dp[0]=cnt_z;
            dp[1]=(dp[1]+cnt_z)%mod;
            
        }

        int ans=0;
        for(int i=0;i<26;i++){
            ans=(ans+dp[i])%mod;
        }
        return ans;

    }
};
// @lc code=end

