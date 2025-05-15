/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include "0.cpp"
// @lc code=start
class Solution {
    vector<vector<string>> result;
    vector<string> cheeseBoard;
    bool isValid(int n,int row,int col,vector<string> cheeseBoard){
        for(int i=0;i<row;i++){
            if(cheeseBoard[i][col]=='Q')
                return false;
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(cheeseBoard[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(cheeseBoard[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void backtracking(int n,int curRow,vector<string> cheeseBoard){
        if(curRow==n){
            result.emplace_back(cheeseBoard);
        }
        for(int col=0;col<n;col++){
            if(isValid(n,curRow,col,cheeseBoard)){
                cheeseBoard[curRow][col]='Q';
                backtracking(n,curRow+1,cheeseBoard);
                cheeseBoard[curRow][col]='.';
            }
        }
        return ;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        cheeseBoard=vector<string>(n,string(n,'.'));
        backtracking(n,0,cheeseBoard);
        return result;
    }
};
// @lc code=end

