/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include "0.h"
// @lc code=start
class Solution {
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 长度为i的字符串能通过字典表示吗？
        vector<bool> dp(s.length()+1,false);
        dp[0]=true;
        unordered_set<string> wordSet(wordDict.begin(),wordDict.end());

        for(int i=1;i<=s.length();i++){
            for(int j=0;j<i;j++){
                string str=s.substr(j,i-j);
                if(dp[j]&&wordSet.find(str)!=wordSet.end())
                    dp[i]=true;
            }
        }
        return dp[s.length()];
    }
};
// @lc code=end

