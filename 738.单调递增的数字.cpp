/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string numS=to_string(n);
        int flag=numS.size();
        for(int i=numS.size()-1;i>0;i--){
            if(numS[i-1]>numS[i]){
                numS[i-1]--;
                flag=i;
            }
        }
        for(int i=flag;i<numS.size();i++){
            numS[i]='9';
        }
        return stoi(numS);
    }
};
// @lc code=end

