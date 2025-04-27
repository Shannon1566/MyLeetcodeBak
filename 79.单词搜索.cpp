/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include "0.cpp"
// @lc code=start
class Solution {
    string path;
    vector<vector<bool>> used;
    int m;
    int n;
    bool backtracking(
                    vector<vector<char>>& board, 
                    string word, 
                    vector<vector<bool>> used,
                    int i,
                    int j
                ){
        if(path==word){
            return true;
        }
        

        return 
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        used=vector<vector<bool>>(board.size(),vector<bool>(board[0].size(),false));

        return backtracking(board,word,used,0,0);

    }
};
// @lc code=end

