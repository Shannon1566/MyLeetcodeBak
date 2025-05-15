/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        for (int i=0;i<bills.size();i++){
            switch (bills[i])
            {
            case 5:
                five++;
                break;
            case 10:
                five--;
                ten++;
                break;
            case 20:
                if(ten>0) {
                    ten--;
                    five--;
                }else{
                    five-=3;
                }
                break;  
            default:
                break;
            }
            if (five<0||ten<0) return false;
        }
        return true;
    }
};
// @lc code=end

