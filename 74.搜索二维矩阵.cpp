/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int left=0,right=n*m-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(matrix[mid/m][mid%m]==target)
                return true;
            if(matrix[mid/m][mid%m]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return false;
    }
};
// @lc code=end

