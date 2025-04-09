/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */
#include "0.leetcode.cpp"
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
    TreeNode *travBuild(vector<int>&inorder,vector<int> &postorder) {
        if (postorder.size()==0) return NULL;
        TreeNode *root = new TreeNode(postorder[postorder.size()-1]);


        int rootInorderIndex;
        for(rootInorderIndex=0;rootInorderIndex<inorder.size();rootInorderIndex++){
            if(inorder[rootInorderIndex]==postorder[postorder.size()-1]){
                break;
            }
        }
        vector<int> linorder(inorder.begin(),inorder.begin()+rootInorderIndex);
        vector<int> rinorder(inorder.begin()+rootInorderIndex+1,inorder.end());

        vector<int> lpostorder(postorder.begin(),postorder.begin()+(linorder.size()));
        vector<int> rpostorder(postorder.begin()+linorder.size(),postorder.end()-1);
        
        root->left=travBuild(linorder,lpostorder);
        root->right=travBuild(rinorder,rpostorder);
        
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0) return NULL;

        return travBuild(inorder, postorder);
    }
};
// @lc code=end
