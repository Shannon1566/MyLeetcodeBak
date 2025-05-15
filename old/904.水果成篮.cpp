/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0;
        int ans=0;
        int subLength=0;
        unordered_map<int,int> cnt;
        int n=fruits.size();
        for (int j=0;j<n;j++){
            cnt[fruits[j]]++;
            while(cnt.size()>2){
                auto it =cnt.find(fruits[i]);
                it ->second--;
                if (it->second==0) cnt.erase(fruits[i]);
                i++;
            }
            subLength=j-i+1;
            ans=max(ans,subLength);
        }
        return ans;
    }
};
// @lc code=end

