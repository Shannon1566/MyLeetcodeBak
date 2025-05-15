/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode * node=root;
        if(node==nullptr) return result;
        st.push(root);
        while (!st.empty()){
            node=st.top();
            st.pop();
            result.emplace_back(node->val);
            
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        };

        reverse(result.begin(),result.end());
        return result;
    }
};
// @lc code=end
