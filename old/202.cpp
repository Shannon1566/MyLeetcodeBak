/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        int sum=n;
        while (sum!=1){
            n=sum;
            sum=0;
            while(n){
                sum+=pow((n%10),2);
                n=n/10;
            }
            if (set.find(sum)==set.end()){
                set.insert(sum);
            }else{
                return false;
            }
                
        }
        return true;
    }
};
// @lc code=end

int main(){
    Solution solution;
    solution.isHappy(19);
    return 0;
}