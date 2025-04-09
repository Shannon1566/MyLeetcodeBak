/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *buildTree(const vector<int> &nodes) {
    if (nodes.empty() || nodes[0] == -1)
        return nullptr;

    queue<TreeNode *> que;
    TreeNode *root = new TreeNode(nodes[0]);
    que.push(root);
    int i = 1;

    while (!que.empty() && i < nodes.size()) {
        TreeNode *cur = que.front();
        que.pop();

        // 构建左子节点
        if (i < nodes.size() && nodes[i] != -1) {
            cur->left = new TreeNode(nodes[i]);
            que.push(cur->left);
        }
        i++;

        // 构建右子节点
        if (i < nodes.size() && nodes[i] != -1) {
            cur->right = new TreeNode(nodes[i]);
            que.push(cur->right);
        }
        i++;
    }
    return root;
}
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
    void trav(TreeNode *node, vector<int> &path, vector<string> &results) {
        path.emplace_back(node->val);
        if (node->left == NULL && node->right == NULL) {
            string result = "";
            result += to_string(path[0]);
            for (int i = 1; i < path.size(); i++) {
                result += "->";
                result += to_string(path[i]);
            }
            results.emplace_back(result);

            return;
        }
        if (node->left) {
            trav(node->left, path, results);
            path.pop_back();
        }
        if (node->right) {
            trav(node->right, path, results);
            path.pop_back();
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> results;
        vector<int> path;
        if(root==NULL) return results;
        trav(root, path, results);
        return results;
    }
};
// @lc code=end
