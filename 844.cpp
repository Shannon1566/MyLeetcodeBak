/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        delString(s);
        delString(t);
        return (s==t);

    }
    
    void delString(string &s){
        int slow=0;
        for (int fast=0;fast<s.length();fast++){
            if (s[fast]!='#'){
                s[slow]=s[fast];
                slow++;
            }else{
                if(slow>0) slow--;
            }

        }
        s.resize(slow);
    }
};
// @lc code=end

int main() {
    // 测试代码

    Solution solution;


    // 调用解题函数并输出结果
    int result = solution.backspaceCompare("ab#c","ad#c");
    cout << "Result: " << result << endl;

    return 0;
}