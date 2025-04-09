/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        
        if (obstacleGrid[m-1][n-1]==1||obstacleGrid[0][0]==1) return 0;

        vector<vector<int>> dp(m,vector<int>(n));

        dp[0][0]=1;
        

        for(int row=0;row<m&&obstacleGrid[row][0] == 0;row++){
            dp[row][0]=1;
        }
        for(int col=0;col<n&&obstacleGrid[0][col] == 0;col++){
            dp[0][col]=1;
        }

        for(int row=1;row<m;row++){
            for(int col=1;col<n;col++){
                if(obstacleGrid[row][col]==0){
                    dp[row][col]=dp[row-1][col]+dp[row][col-1];
                }else{
                    dp[row][col]=0;
                }
            }
        }

        for (const auto& row : dp) {
            // 内层范围for循环遍历该行的每个元素
            for (int element : row) {
                std::cout << element << " ";
            }
            std::cout << std::endl;
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

int main(){
    Solution sol;
    std::vector<std::vector<int>> obstacleGrid = {
        {0, 1},
        {0, 0}
    };
    sol.uniquePathsWithObstacles(obstacleGrid);

    return 0;
}
