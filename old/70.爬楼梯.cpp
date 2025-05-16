/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n==1) return 1;
        int a=1,b=2,c;
        for(int i=3;i<=n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return b;

    }
};
// @lc code=end

