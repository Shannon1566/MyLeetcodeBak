/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include "0.cpp"
// @lc code=start 
class Solution {
    struct MyCmp{
        bool operator()(const pair<int, int>& a,const pair<int, int>& b){
            return a.second>b.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hashMap;
        for(int it:nums){
            hashMap[it]++;
        }
        priority_queue<pair<int,int>,vector<pair<int, int>>,MyCmp> priQue;

        for(auto it:hashMap){
            priQue.push(it);
            if(priQue.size()>k)
                priQue.pop();
        }

        vector<int> result;
        while(!priQue.empty()){
            result.emplace_back(priQue.top().first);
            priQue.pop();
        }
        return result;
    }
};
// @lc code=end

