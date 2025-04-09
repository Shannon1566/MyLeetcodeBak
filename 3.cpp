/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0;
        int result=0;
        unordered_set<char> hashSet;
        // [left,ringt]
        for(right=0;right<s.length();right++){
            
            while(hashSet.find(s[right])!=hashSet.end()){
                hashSet.erase(s[left]);
                left++;
            }
            hashSet.emplace(s[right]);
            result=max(result,right-left+1);
        }
        return result;
    }
};
// @lc code=end
int main(){
    Solution sol;
    sol.lengthOfLongestSubstring("dvdf");
    return 0;
}
