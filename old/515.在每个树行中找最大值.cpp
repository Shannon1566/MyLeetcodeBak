#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
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
// 根据层序遍历数组构建二叉树
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
}/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 */

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
    vector<int> largestValues(TreeNode* root) {
        int size=0;
        vector<int> results;
        queue<TreeNode*> que;
        que.push(root);
        size++;
        if (!root) return results;
        while(!que.empty()){
            int size2=size;
            size=0;
            int result=INT32_MIN;
            for(int i=0;i<size2;i++){
                TreeNode* cur=que.front();
                que.pop();
                result=cur->val>result?cur->val:result;
                if(cur->left){
                    que.push(cur->left);
                    size++;
                }
                if(cur->right){
                    que.push(cur->right);
                    size++;
                }
            }
            results.emplace_back(result);
        }
        return  results;
    
    }
};
// @lc code=end

