/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */
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
    int maxDeepLength=0;
    void trav(TreeNode* node,int deepLength){
        if (node==NULL) return;
        maxDeepLength=max(maxDeepLength,deepLength);
        if (node->left) trav(node,deepLength+1);
        if (node->left) trav(node,deepLength+1);
        return ;
    }
    int maxDepth(TreeNode* root) {
        // int deepLength=0;
        // if(root==NULL) return 0;
        // queue<TreeNode*> que;
        // que.push(root);

        // int size=1;
        // while(!que.empty()){
        //     int size=que.size();
        //     for(int i=0;i<size;i++){
        //         TreeNode* cur=que.front();
        //         que.pop();
        //         if(cur->left!=NULL) que.push(cur->left);
        //         if(cur->right!=NULL) que.push(cur->right);
        //     }
        //     deepLength++;
        // }
        trav(root,0);
        return maxDeepLength;
    }
};
// @lc code=end

