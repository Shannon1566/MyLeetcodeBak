/*
 * @lc app=leetcode.cn id=2278 lang=cpp
 *
 * [2278] 字母在字符串中的百分比
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int percentageLetter(string s, char letter) {
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==letter) cnt++;
        }
        return cnt*100/s.size();
    }
};
// @lc code=end

