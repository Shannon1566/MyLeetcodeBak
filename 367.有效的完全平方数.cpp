/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num==1) return 1;
        int high = num;
        int low = 0;
        while (high-low!=1)
        {
            int mid = (high - low) / 2 + low;
            if ((long long)mid *mid == num)
            {
                return true;
            }
            else
            {
                if ((long long)mid * mid > num)
                {
                    high = mid;
                }
                else
                {
                    low = mid;
                }
            }
        }
        return false;
    }
};
// @lc code=end

