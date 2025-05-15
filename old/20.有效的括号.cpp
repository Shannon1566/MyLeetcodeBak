/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include "0.cpp"
// @lc code=start
class Solution {
    unordered_map<char,char> pairs={
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
public:
    bool isValid(string s) {
        
        stack<char> stk;
        int n=s.length();
        
        for(char c:s){
            if(pairs.count(c)){
                if(stk.empty()||stk.top()!=pairs[c]){
                    return false;
                }
                stk.pop();
            }else{
                stk.push(c);
            }
        }
        return stk.empty();
    }
};
// @lc code=end

