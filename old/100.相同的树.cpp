/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */
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
    bool compare(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL && q != NULL) return false;
        if (p != NULL && q == NULL) return false;

        if (p->val != q->val) return false;
        bool leftCompare = compare(p->left, q->left);
        bool rightCompare = compare(p->right, q->right);
        return leftCompare && rightCompare;
    }
    bool isSameTree(TreeNode *p, TreeNode *q) {
        return compare(p, q);
    }
};
// @lc code=end
