/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    
    int sumOfLeftLeaves(TreeNode *root) {
        
        if (root == NULL) return 0;
        if (root->left==NULL&&root->right==NULL) return 0;
        
        int leftValue=sumOfLeftLeaves(root->left);
        if (root->left!=NULL&&root->left->left==NULL&&root->left->right==NULL){
            leftValue=root->left->val;
        }

        int rightValue=sumOfLeftLeaves(root->right);
        return leftValue+rightValue;
        
    }
};
// @lc code=end
int main(){
    vector<int> nodes = {3,9,20,-1,-1,15,7}; // -1 代表 null
    TreeNode* root = buildTree(nodes);
    Solution sol;
    sol.sumOfLeftLeaves(root);
}