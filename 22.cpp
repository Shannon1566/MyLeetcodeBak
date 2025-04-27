/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include "0.cpp"
// @lc code=start
class Solution {
    int leftCnt=0;
    int rightCnt=0;
    string path;
    vector<string> result;
    void backtracking(int n){
        if(leftCnt==n&&rightCnt==n){
            result.emplace_back(path);
            return ;
        }
        if(leftCnt<n){
            path.push_back('(');
            leftCnt++;
            backtracking(n);
            leftCnt--;
            path.pop_back();
        }

        if(rightCnt<leftCnt){
            path.push_back(')');
            rightCnt++;
            backtracking(n);
            rightCnt--;
            path.pop_back();
        }
        return ;
    }
public:
    vector<string> generateParenthesis(int n) {
        backtracking(n);
        return result;
    }
};
// @lc code=end
int main(){
    Solution sol;
    sol.generateParenthesis(3);
}
