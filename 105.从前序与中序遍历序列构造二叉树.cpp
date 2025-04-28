/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    unordered_map<int, int> index;

    TreeNode *buildT(vector<int> &preorder, vector<int> &inorder,
                     int pLeft, int pRight, int iLeft, int iRight) {
        if (pLeft > pRight)
            return nullptr;

        int pRoot = pLeft;                  
        int iRoot = index[preorder[pRoot]]; 

        TreeNode *node = new TreeNode(preorder[pRoot]);

        int sizeL = iRoot - iLeft; 

        node->left = buildT(preorder, inorder,
                            pLeft + 1, pLeft + sizeL,
                            iLeft, iRoot - 1);

        node->right = buildT(preorder, inorder,
                             pLeft + sizeL + 1, pRight,
                             iRoot + 1, iRight);

        return node;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }

        return buildT(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};

// @lc code=end
