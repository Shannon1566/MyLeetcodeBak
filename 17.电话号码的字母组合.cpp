/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include "0.cpp"
// @lc code=start
class Solution {
    const string MAPPING[10]= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    string path;
    void dfs(string& digits,int curIndex){
        if(curIndex==digits.size()){
            result.emplace_back(path);
            return;
        }
        for(char c:MAPPING[digits[curIndex]-'0']){
            path.push_back(c);
            dfs(digits,curIndex+1);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits=="") return result;
        dfs(digits,0);
        return result;
    }
};
// @lc code=end

