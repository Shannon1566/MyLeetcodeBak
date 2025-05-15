/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1);//dp[j]:长度为j的字符串是否可以被字典表达
        dp[0]=true;
        //"apple" + "pen" + "apple" 才能组成 "applepenapple"
        // "apple" + "apple" + "pen" 或者 "pen" + "apple" + "apple" 是不可以的
        // 排列 先背包 后物品
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<i;j++){
                string word=s.substr(j,i-j);
                if (wordSet.find(word) != wordSet.end() && dp[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

