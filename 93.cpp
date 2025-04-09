/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    vector<string> result;
    vector<int> path;
    // bool isValidIP(string &s,int head,int tail){
    //     if (head==tail) return true;
    //     if (head>tail) return false;
    //     if (s[head]=='0') return false;
    //     string str=s.substr(head,tail-head+1);
    //     int num=stoi(str);
    //     if(num<=255&&num>=0) return true;
    //     else return false;
    // }
    int getIPset(string &s,int head,int tail){
        if(tail-head>3) return -1;
        if(head>tail) return -1;
        if(s[head]=='0'&&head!=tail) return -1;
        string str=s.substr(head,tail-head+1);
        int num=stoll(str);
        if (num>=0&&num<=255) return (int)num;
        return -1;
    }
    void backtracking(string &s,int startIndex,int IPSet){
        if(IPSet>4) return;
        if(startIndex==s.size()&&IPSet==4){
            string pathString=to_string(path[0])+"."+to_string(path[1])+"."+to_string(path[2])+"."+to_string(path[3]);
            result.emplace_back(pathString);
            return;
        }
        for(int i=startIndex;i<s.size();i++){
            int num=getIPset(s,startIndex,i);
            if(num!=-1){
                path.emplace_back(num);
                backtracking(s,i+1,IPSet+1);
                path.pop_back();
            }
        }
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        backtracking(s,0,0);
        return result;
    }
};
// @lc code=end

int main(){
    Solution sol;
    sol.restoreIpAddresses("0000");
    return 0;
}