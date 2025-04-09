/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n));

        if (m==1||n==1) return 1;
        
        dp[0][1]=1;
        dp[1][0]=1;

        for(int row=2;row<m;row++){
            dp[row][0]=dp[row-1][0];
        }

        for(int col=2;col<n;col++){
            dp[0][col]=dp[0][col-1];
        }
        for(int row=1;row<m;row++)
            for(int col=1;col<n;col++){
                dp[row][col]=dp[row-1][col]+dp[row][col-1];
            }
        
        // for (const auto& row : dp) {
        //     // 内层范围for循环遍历该行的每个元素
        //     for (int element : row) {
        //         std::cout << element << " ";
        //     }
        //     std::cout << std::endl;
        // }
        return dp[m-1][n-1];
    }
};
// @lc code=end
int main(){
    Solution sol;
    sol.uniquePaths(3,7);

    return 0;
}
