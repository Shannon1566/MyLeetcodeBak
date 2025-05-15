/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_multiset<int> map1;
        vector<int> result;
        for (int i = 0; i < n1; i++)
        {
            map1.insert(nums1[i]);
        }

        for(int num:nums2){
            auto it=map1.find(num);
            if (it!=map1.end()){
                result.emplace_back(num);
                map1.erase(it);
            }
        }
        return result;
        
    }
};
// @lc code=end
int main(){
    Solution solution;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    solution.intersect(nums1,nums2);
    return 0;
}