/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> value;
        int nums1, nums2;
        for (string token : tokens)
        {

            if (token.size()==1&&(token[0]<'0'||token[0]>'9')){
                nums2 = value.top();
                value.pop();
                nums1 = value.top();
                value.pop();
                switch (token[0])
                {
                case '+':
                    nums1 += nums2;
                    break;
                case '-':
                    nums1 -= nums2;
                    break;
                case '*':
                    nums1 *= nums2;
                    break;
                default:
                    nums1 /= nums2;
                    break;
                }
                value.push(nums1);
            }else{
                nums1=stoi(token);
                value.push(nums1);
            }
        }
        return value.top();
    }
};
// @lc code=end
int main(){
    Solution solution;
    vector<string> tokens={"4","13","5","/","+"};
    solution.evalRPN(tokens);
    return 0;
}