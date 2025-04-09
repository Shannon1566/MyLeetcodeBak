/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int cntZero = 0;
        int setZero = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                cntZero++;
                setZero = i;
            }
        }
        vector<int> answer(nums.size(), 0);
        if (cntZero >= 2)
            return answer;
        int32_t product = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (setZero == i) continue;
            product *= nums[i];
        }
        if (cntZero == 1) {
            answer[setZero] = product;
            return answer;
        } else {
            for (int i = 0; i < nums.size(); i++) {
                answer[i] = product / nums[i];
            }
        }
        return answer;
    }
};
// @lc code=end

int main() {
    Solution sol;
    vector<int> nums{1, 2, 3, 4};
    sol.productExceptSelf(nums);
    return 0;
}