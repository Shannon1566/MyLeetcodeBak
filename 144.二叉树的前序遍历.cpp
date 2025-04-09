/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start

class Solution
{
public:
    void trav(TreeNode *node,vector<int> &result){
        if (node==nullptr) return ;
        result.emplace_back(node->val);
        trav(node->left,result);
        trav(node->right,result);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        trav(root,result);
        return result;
    }
};
// @lc code=end
