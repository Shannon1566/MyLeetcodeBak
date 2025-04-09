/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include"0.cpp"
// @lc code=start
class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;
    bool isPalindrome(string &s,int head,int tail){
        // [head,tail]
        while(head<=tail){
            if(s[head]==s[tail]){
                head++;
                tail--;
            }else return false;
        }
        return true;
    }
    void backtracking(string &s,int stratIndex){
        if(stratIndex>=s.size()){
            result.push_back(path);
            return;
        }

        for(int i=stratIndex;i<s.size();i++){
            if(isPalindrome(s,stratIndex,i)){
                string str=s.substr(stratIndex,i-stratIndex+1);
                path.emplace_back(str);
                backtracking(s,i+1);
                path.pop_back();
            }            
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        backtracking(s,0);
        return result;
    }
};
// @lc code=end

