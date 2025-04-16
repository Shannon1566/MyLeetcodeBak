/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */
#include "0.cpp"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        queue<TreeNode*> que;
        que.emplace(root);
        int curCnt=1;
        int nxtCnt=0;
        vector<int> result;
        int leftElement;
        if (root==nullptr) return result;
        while(!que.empty()){
            while(curCnt){
                if(que.front()->left){
                    nxtCnt++;
                    que.emplace(que.front()->left);
                }
                if(que.front()->right){
                    nxtCnt++;
                    que.emplace(que.front()->right);
                }
                leftElement=que.front()->val;
                curCnt--;
                que.pop();
            }
            result.emplace_back(leftElement);
            curCnt=nxtCnt;
            nxtCnt=0;
        }
        return result;
    }
};
// @lc code=end

