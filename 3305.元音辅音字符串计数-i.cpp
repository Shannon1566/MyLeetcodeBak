/*
 * @lc app=leetcode.cn id=3305 lang=cpp
 *
 * [3305] 元音辅音字符串计数 I
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    const string VOWEL = "aeiou";
    long long f(string &word, int k) {
        long long ans = 0;
        unordered_map<char, int> cnt1;
        int cnt2 = 0;
        int left = 0;
        for (char c : word) {
            if (VOWEL.find(c) != string::npos) {
                cnt1[c]++;
            } else {
                cnt2++;
            }
            while (cnt1.size() == 5 && cnt2 >= k) {
                if (VOWEL.find(word[left]) != string::npos) {
                    if (--cnt1[word[left]] == 0) cnt1.erase(word[left]);
                }else{
                    cnt2--;
                }
                left++;
            }
            ans += left;
        }
        return ans;
    }
    int countOfSubstrings(string word, int k) {
        return f(word, k) - f(word, k + 1);
    }
};
// @lc code=end
