/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prePath{1};
        for(int i=0;i<numRows;i++){
            vector<int> path(i+1,1);
            for(int j=1;j<=i-1;j++){
                path[j]=prePath[j-1]+prePath[j];
            }
            ans.emplace_back(path);
            prePath=path;
        }
        return ans;
    }
};
// @lc code=end

