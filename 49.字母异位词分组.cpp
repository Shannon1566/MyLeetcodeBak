/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> hashMap;
        for(auto str:strs){
            string strIndex=str;
            sort(strIndex.begin(),strIndex.end());
            auto it=hashMap.find(strIndex);
            if(it!=hashMap.end()){
                it->second.emplace_back(str);
            }else{
                hashMap.emplace(strIndex,vector<string>{str});
            }
        }
        for(auto it:hashMap){
            result.emplace_back(it.second);
        }
        return result;
    }
};
// @lc code=end

