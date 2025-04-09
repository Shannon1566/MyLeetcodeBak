/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int left=0,up=0,right=matrix[0].size()-1,down=matrix.size()-1;

        while(1){
            for(int i=left;i<=right;i++) result.emplace_back(matrix[up][i]);
            up++;
            if(up>down) break;
            for(int i=up;i<=down;i++) result.emplace_back(matrix[i][right]);
            right--;
            if(right<left) break;
            for(int i=right;i>=left;i--) result.emplace_back(matrix[down][i]);
            down--;
            if(down<up) break;
            for(int i=down;i>=up;i--) result.emplace_back(matrix[i][left]);
            left++;
            if(left>right) break;
        }        
        return result;
    }
};
// @lc code=end

