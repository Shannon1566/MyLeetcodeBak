/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;
// @lc code=start

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            if (s.length()==0) return 0;
            unordered_set<char> set;
            int currentLength=0,maxLength=0;
            int left=0, right=0;
            for(right=0;right<s.length();right++){
                char ch=s[right];
                while(set.count(ch)){
                    set.erase(s[left]);
                    left++;
                }
                set.insert(ch);
                maxLength=max(maxLength,right-left+1);
                
            }
            return maxLength;
        }
    };
// @lc code=end

