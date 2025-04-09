/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int childPtr=g.size()-1;
        int cookiePtr=s.size()-1;
        int cnt=0;
        while(childPtr>=0&&cookiePtr>=0){
            if(g[childPtr]<=s[cookiePtr]){
                cnt++;
                childPtr--;
                cookiePtr--;
            }else{
                childPtr--;
            }
        }
        return cnt;
    }
};
// @lc code=end
int main(){
    Solution sol;
    vector<int>g={1,2,3};
    vector<int>s={1,1};
    sol.findContentChildren(g,s);
    return 0;
}
