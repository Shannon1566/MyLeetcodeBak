/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0,col=matrix.size()-1;
        while(row<matrix[0].size()&&col>=0){
            if(matrix[row][col]==target){
                return true;
            }else if(matrix[row][col]<target){
                col--;
            }else{
                row++;
            }
        }
        return false;
    }
};
// @lc code=end

