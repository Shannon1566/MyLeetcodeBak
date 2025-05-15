/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int sLength=s.length();
        int maxbegin=0;
        int maxlen=0;
        for (int i=0;i<sLength;i++){
            for (int j=i;j<sLength;j++){
                if (validPalindromic(s,i,j) && (j-i+1>maxlen)){
                    maxlen=j-i+1;
                    maxbegin=i;
                }
                    
            }
        }
        return s.substr(maxbegin,maxlen);
    }

    bool validPalindromic(string s,int left,int right)
    {
        while(left < right)
        {
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end

