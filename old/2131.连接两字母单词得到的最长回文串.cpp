/*
 * @lc app=leetcode.cn id=2131 lang=cpp
 *
 * [2131] 连接两字母单词得到的最长回文串
 */
#include "0.h"
// @lc code=start
class Solution {
public:
    int longestPalindrome(vector<string> &words) {
        int ans = 0;
        unordered_map<string, int> hashMap;
        for (string str : words) {
            auto it = hashMap.find(str);
            if (it != hashMap.end()) {
                ans += 4;
                hashMap[str]--;
                if (hashMap[str] == 0)
                    hashMap.erase(str);
            } else {
                string reverseStr = str;
                reverseStr[0] = str[1];
                reverseStr[1] = str[0];
                hashMap[reverseStr]++;
            }
        }
        for (auto it : hashMap) {
            if (it.first[0] == it.first[1])
                return ans += 2;
        }
        return ans;
    }
};
// @lc code=end
