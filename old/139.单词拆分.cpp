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
        unordered_set<string> hashSet;
        for(auto it:wordDict){
            hashSet.emplace(it);
        }
    }
};
// @lc code=end

