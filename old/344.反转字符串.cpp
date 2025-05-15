/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int head=0;
        int tail=s.size()-1;
        while(head<tail){
            int temp=0;
            temp=s[head];
            s[head]=s[tail];
            s[tail]=temp;
            head++;
            tail--;
        }

    }
};
// @lc code=end

