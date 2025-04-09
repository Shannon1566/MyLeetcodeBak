/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
 */
#include"0.cpp"
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
    int cnt=0;
    // 0无覆盖 1有摄像头 2有覆盖
    int trav(TreeNode* node){
        if (node==NULL) return 2;
        
        int leftState=trav(node->left);
        int rightState=trav(node->right);
        
        if(leftState==0||rightState==0){
            cnt++;
            return 1;
        }
        if(leftState==2&&rightState==2) return 0;
        if(leftState==1||rightState==1) return 2;
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        cnt=0;
        if(trav(root)==0) cnt++;
        return cnt;
    }
};
// @lc code=end

