/*
 * @lc app=leetcode.cn id=2843 lang=cpp
 *
 * [2843] 统计对称整数的数目
 */
#include "0.cpp"
// @lc code=start
class Node{
public:
    int key;
    int val;
    Node* nxt;
    Node* pre;

    Node(int k=0,int v=0):key(k),val(v) {}
};
class Solution {
    bool isValid(int i){
        string str=to_string(i);
        if(str.size()%2!=0) return false;
        int midIndex =str.size()/2;
        int left=0;
        int right=0;
        for(int i=0;i<midIndex;i++){
            left+=str[i]-'0';
            right+=str[midIndex+i]-'0';
        }
        return  left==right;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            if(isValid(i)) 
                cnt++;
        }
        return cnt;
    }
};
// @lc code=end

