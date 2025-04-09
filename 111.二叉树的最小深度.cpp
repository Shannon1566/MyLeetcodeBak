/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int result=INT32_MAX;
    void trv(TreeNode *node,int curDeepth){
        if (node==NULL) return;
        if (node->left==NULL&&node->right==NULL){
            result=min(curDeepth,result);
        }else{
            trv(node->left,curDeepth+1);
            trv(node->right,curDeepth+1);
        }
        return;
    }
    int minDepth(TreeNode* root) {
        // int deepLength=0;
        // if(root==NULL) return 0;
        // queue<TreeNode*> que;
        // que.push(root);
        // while(!que.empty()){
        //     int size=que.size();
        //     deepLength++;
        //     for(int i=0;i<size;i++){
        //         TreeNode* cur=que.front();
        //         que.pop();
        //         if(cur->left!=NULL) que.push(cur->left);
        //         if(cur->right!=NULL) que.push(cur->right);
        //         if(cur->left==NULL&&cur->right==NULL) return deepLength;
        //     }
            
        // }
        // return deepLength;
        if (root==NULL) return 0;
        trv(root,1);
        return result;
    }
};
// @lc code=end

