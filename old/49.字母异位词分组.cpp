/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>> hashmap;
        vector<vector<string>> result;

        for (int i=0;i<n;i++){
            string key=strs[i];
            sort(key.begin(),key.end());
            hashmap[key].emplace_back(strs[i]);
        }

        for (auto it=hashmap.begin();it!=hashmap.end();it++){
            result.emplace_back(it->second);
        }
        
        return result;
    }
};
// @lc code=end

