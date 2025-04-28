/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include "0.cpp"
// @lc code=start
class Solution {
    vector<vector<string>> result;
    vector<string> path;
    bool isPalindrome(const string& s,int left,int right){
        while(left<=right){
            if(s[left]!=s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    void backtracking(const string& s,int startIndex){
        if(startIndex>=s.size()){
            result.emplace_back(path);
            return ;
        }
        for(int i=startIndex;i<s.size();i++){
            if(isPalindrome(s,startIndex,i)){
                string str=s.substr(startIndex,i-startIndex+1);
                path.push_back(str);
                backtracking(s,i+1);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        backtracking(s,0);
        return result;
    }
};
// @lc code=end

