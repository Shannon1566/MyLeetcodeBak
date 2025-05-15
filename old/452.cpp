/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */
#include "0.cpp"
// @lc code=start
class Solution {
    static bool cmp(const vector<int>& a,const vector<int>& b){
        return a[0]<b[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size()==0) return 0;
        sort(points.begin(),points.end(),cmp);

        int result=1;
        for (int  i = 1; i < points.size(); i++)
        {
            if (points[i][0]>points[i-1][1]){
                result++;
            } 
            else{
                points[i][1]=min(points[i-1][1],points[i][1]);
            }
        }

        return result;
    }
};
// @lc code=end

int main(){
    Solution sol;
    std::vector<std::vector<int>> vec = {
        {10, 16},
        {2, 8},
        {1, 6},
        {7, 12}
    };
    sol.findMinArrowShots(vec);
    return 0;
}