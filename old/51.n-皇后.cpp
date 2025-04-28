/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    vector<vector<string>> result;
    bool isValid(vector<string> &cheeseBoard,int row,int col,int n){
        for(int i=0;i<n;i++){
            if(cheeseBoard[row][i]=='Q') return false;
        }
        for (int i = 0; i < n; i++)
        {
            if(cheeseBoard[i][col]=='Q') return false;
        }
        for (int i=-n;i<n;i++){
            int checkRow=row+i;
            int checkCol=col+i;
            if(checkRow>=0&&checkRow<n&&checkCol>=0&&checkCol<n){
                if(cheeseBoard[checkRow][checkCol]=='Q') return false;
            }
        }
        for (int i=-n;i<n;i++){
            int checkRow=row+i;
            int checkCol=col-i;
            if(checkRow>=0&&checkRow<n&&checkCol>=0&&checkCol<n){
                if(cheeseBoard[checkRow][checkCol]=='Q') return false;
            }
        }
        return true;   
    }
    void backtracking(vector<string> &cheeseBoard,int row,int n) {
        if (row==n){
            result.emplace_back(cheeseBoard);
            return;
        }
        for(int col=0;col<n;col++)
            if (isValid(cheeseBoard,row,col,n)){
                cheeseBoard[row][col]='Q';
                backtracking(cheeseBoard,row+1,n);
                cheeseBoard[row][col]='.';
            }   
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> cheeseBoard(n, string(n, '.'));
        backtracking(cheeseBoard,0,n);
        return result;
    }
};
// @lc code=end
