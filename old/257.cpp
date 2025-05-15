/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    queue<TreeNode*> que;
    TreeNode* root = new TreeNode(nodes[0]);
    que.push(root);
    int i = 1;

    while (!que.empty() && i < nodes.size()) {
        TreeNode* cur = que.front();
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
    vector<string> results;
    void trv(TreeNode* node,string result){
        if (node==NULL) return;
        if (node->left==NULL&&node->right==NULL){
            result+="->";
            result+=to_string(node->val);
            results.emplace_back(result);
            return;
        }else{
            result+="->";
            result+=to_string(node->val);
            trv(node->left,result);
            trv(node->right,result);
        }
        return ;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root==NULL) return results;
        string result="";
        result+=to_string(root->val);
        if (root->left==NULL&&root->right==NULL){
            results.emplace_back(result);
        }
        trv(root->left,result);
        trv(root->right,result);
        return results;
    }
};
// @lc code=end
int main(){
    vector<int> nodes = {1,2,3,-1,5}; // -1 代表 null
    TreeNode* root = buildTree(nodes);
    Solution sol;
    sol.binaryTreePaths(root);
    return 0;
}
