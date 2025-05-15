/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x==1) return 1;
        int high = x;
        int low = 0;
        while (high-low!=1)
        {
            int mid = (high - low) / 2 + low;
            if ((long long)mid *mid == x)
            {
                return mid;
            }
            else
            {
                if ((long long)mid * mid > x)
                {
                    high = mid;
                }
                else
                {
                    low = mid;
                }
            }
        }
        return low;
    }
};
// @lc code=end
