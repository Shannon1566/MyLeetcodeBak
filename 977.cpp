/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int head=0,tail=n-1;
        vector<int> ans(n);
        for (int i=n-1;i>=0;i--){
            if(nums[head]*nums[head]<(long long)nums[tail]*nums[tail])
            {
                ans[i]=nums[tail]*nums[tail];
                tail--;
            }else{
                ans[i]=nums[head]*nums[head];
                head++;
            }
        }
        return ans;
    }
};
// @lc code=end
int main() {
    // 测试代码

    Solution solution;

    vector<int> nums = {-4,-1,0,3,10};
    // 调用解题函数并输出结果
    vector<int> result = solution.sortedSquares(nums);
    // cout << "Result: " << result << endl;

    return 0;
}
