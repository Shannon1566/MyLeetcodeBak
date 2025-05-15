/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            if (nums.size()==0) return 0;
            int tail=nums.size()-1;
            int temp;
            for(int i=0;i<=tail;i++){
                if (nums[i]==val){
                    if (tail==0) return 0;
                    nums[i]=nums[tail];
                    tail--;
                    i--;
                    
                }
            }
            return tail+1;
        }
    };
// @lc code=end

int main() {
    // 测试代码

    Solution solution;

    // 定义测试用例
    vector<int> nums = {3,3};

    // 调用解题函数并输出结果
    int result = solution.removeElement(nums,3);
    cout << "Result: " << result << endl;

    return 0;
}