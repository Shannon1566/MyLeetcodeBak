/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1==NULL && root2==NULL) return NULL;
        if (root1==NULL && root2!=NULL) return root2;
        if (root1!=NULL && root2==NULL) return root1;
        if (root1!=NULL && root2!=NULL){
            root1->val+=root2->val;
            root1->left=mergeTrees(root1->left,root2->left);
            root1->right=mergeTrees(root1->right,root2->right);
            return root1;
        }
        return root1;
    }
};
// @lc code=end

int main(){
    vector<int> nodes1 = {1,3,2,5}; // -1 代表 null
    vector<int> nodes2 = {2,1,3,-1,4,-1,7}; // -1 代表 null
    TreeNode* root1 = buildTree(nodes1);
    TreeNode* root2 = buildTree(nodes2);
    Solution sol;
    sol.mergeTrees(root1,root2);
}