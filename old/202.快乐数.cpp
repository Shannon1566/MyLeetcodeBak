/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include"0.h"
// @lc code=start
class Solution {
    int calu(int n){
        int sum=0;
        while(n){
            sum+=pow((n%10),2);
            n=n/10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> hashSet;
        while(1){
            if(n==1) return true;
            n=calu(n);
            auto it=hashSet.find(n);
            if(it!=hashSet.end()){
                return false;
            }else{
                hashSet.emplace(n);
            }
        }
        return true;
    }
};
// @lc code=end

