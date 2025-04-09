/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* build(vector<int> &nums,int begin,int end){
        if(begin==end) return NULL;
        int maxIndex=0;
        int max=0;
        for(int i=begin;i<end;i++){
            if(nums[i]>max){
                maxIndex=i;
                max=nums[i];
            }
        }
        TreeNode* root=new TreeNode(max);
        
        root->left=build(nums,begin,maxIndex);
        root->right=build(nums,maxIndex+1,end);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return build(nums,0,nums.size());
    }
};
// @lc code=end
int main(){
    vector<int> nodes = {3,2,1,6,0,5}; // -1 代表 null
    TreeNode* root = buildTree(nodes);
    Solution sol;
    sol.constructMaximumBinaryTree(nodes);
}