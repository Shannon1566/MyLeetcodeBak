/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
#include"0.leetcode.cpp"
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
    TreeNode* build(vector<int> &preorder,vector<int> &inorder,int beginPre,int endPre,int beginIn,int endIn){
        if(beginIn==endIn) return NULL;
        TreeNode* root=new TreeNode(preorder[beginPre]);
        int inorderValueIndex=beginIn;
        for(inorderValueIndex=beginIn;inorderValueIndex<endIn;inorderValueIndex++){
            if(inorder[inorderValueIndex]==preorder[beginPre]) break;
        }
        root->left=build(preorder,inorder,beginPre+1,beginPre+1+inorderValueIndex-beginIn,beginIn,inorderValueIndex);
        root->right=build(preorder,inorder,beginPre+1+inorderValueIndex-beginIn,endPre,inorderValueIndex+1,endIn);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size()==0) return NULL;
        TreeNode* root=build(preorder,inorder,0,preorder.size(),0,inorder.size());
        return root;
    }
};
// @lc code=end

