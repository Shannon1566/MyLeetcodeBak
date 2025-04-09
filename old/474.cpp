/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // 容量为m和n的背包最多装dp[][]个
        vector<int> zero(strs.size(),0);
        vector<int> one(strs.size(),0);
        for(int i=0;i<strs.size();i++){
            string str=strs[i];
            for(int j=0;j<str.length();j++){
                if(str[j]=='0') zero[i]++;
                if(str[j]=='1') one[i]++;
            }
        }
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int k=0;k<strs.size();k++){
            for(int i=m;i>=zero[k];i--){
                for(int j=n;j>=one[k];j--){
                    dp[i][j]=max(dp[i][j],dp[i-zero[k]][j-one[k]]+1);
                }
            }
        }
        
        return dp[m][n];
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<string> strs({"10","0","1"});
    sol.findMaxForm(strs,5,3);
    return 0;
}