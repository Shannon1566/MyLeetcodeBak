/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLength=s.size();
        int pLength=p.size();
        vector<int> result;
        unordered_map<char,int> map;
        for (int i=0;i<pLength;i++){
            map[p[i]]++;
        }
        for (int i=0;i<sLength-pLength+1;i++){
            unordered_map<char,int> map_zi;
            for (int j=i;j<i+pLength;j++){
                map_zi[s[j]]++;
            }
            if (map_zi==map) result.emplace_back(i);
        }
        return result;
    }
};
// @lc code=end
int main(){
    Solution solution;
    solution.findAnagrams("cbaebabacd","abc");
    return 0;
}
