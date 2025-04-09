/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start

class Solution {
public:
    unordered_map<char,int> hashMap_t;
    unordered_map<char,int> hashMap_s;
    bool hasStringt(string &s,int head,int tail){       
        for(auto& pair :hashMap_t){
            if(hashMap_s[pair.first]<pair.second){
                return false;
            }
        }

        return true;
    }
    string minWindow(string s, string t) {
        int i=0;
        int sLength=s.length();
        int tLength=t.length();
        int result=INT32_MAX;
        int resultHead=0,resultTail=0;
        int subLength=0;
        for (int j=0;j<tLength;j++){
            hashMap_t[t[j]]++;
        }
        for (int j=0;j<sLength;j++){
            hashMap_s[s[j]]++;
            while(hasStringt(s,i,j)){
                subLength=j-i+1;
                // result=min(result,subLength);
                if (subLength<result){
                    result=subLength;
                    resultHead=i;
                    resultTail=j;
                }
                hashMap_s[s[i]]--;
                i++;
            }  
        }
        return result==INT32_MAX?"":s.substr(resultHead,result);
    }
};
// @lc code=end

int main() {
    // 测试代码

    Solution solution;


    // 调用解题函数并输出结果
    cout<<solution.minWindow("a","a")<<endl;


    return 0;
}