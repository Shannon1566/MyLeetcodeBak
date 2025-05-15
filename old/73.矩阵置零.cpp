/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row;
        unordered_set<int> col;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    row.emplace(i);
                    col.emplace(j);
                }
            }
        }
        for(auto it:row){
            for(int j=0;j<matrix[0].size();j++){
                matrix[it][j]=0;
            }
        }
        for(auto it:col){
            for(int i=0;i<matrix.size();i++){
                matrix[i][it]=0;
            }
        }
        return ;
    }
};
// @lc code=end

