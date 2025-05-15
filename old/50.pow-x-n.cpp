/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        long long nn=n;
        if(n<0){
            nn=-nn;
            x=1/x;
        }
        double res=1;

        while(nn){
            if(nn&1){
                res*=x;
            }
            x *=x;
            nn>>=1;
        }
        return res;
    }
};
// @lc code=end

