/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if(root->val==key){
            if(root->left==NULL&&root->right==NULL){
                delete root;
                return NULL;
            }else if(root->left!=NULL&&root->right==NULL){
                auto retNode=root->left;
                delete root;
                return retNode;
            }else if(root->left==NULL&&root->right!=NULL){
                auto retNode=root->right;
                delete root;
                return retNode;
            }else{
                auto leftChild=root->left;
                auto rightChild=root->right;
                delete root;
                TreeNode* cur =rightChild;
                while(cur->left!=NULL) cur=cur->left;
                cur->left=leftChild;
                return rightChild;
            }
        }else{
            if(key<root->val) root->left=deleteNode(root->left,key);
            if(key>root->val) root->right=deleteNode(root->right,key);
            return root;
        }
    }
};
// @lc code=end

