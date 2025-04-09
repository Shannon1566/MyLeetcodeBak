/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    vector<pair<int,int>> space;
    bool isValid(int row,int col,char k,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if (board[row][i]==k) return false;
            if (board[i][col]==k) return false;
        }
        int boxRow=(row/3)*3;
        int boxCol=(col/3)*3;
        for (int i=boxRow;i<boxRow+3;i++)
            for(int j=boxCol;j<boxCol+3;j++){
                if (board[i][j]==k) return false;
            }
        return true;
    }
    bool backtracking(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if (board[i][j]!='.') continue;
                for (char k='1';k<='9';k++){
                    if (isValid(i,j,k,board)){
                        board[i][j]=k;
                        if(backtracking(board)) return true;
                        board[i][j]='.';
                    }
                }
                return false;
            }
            
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};
// @lc code=end

