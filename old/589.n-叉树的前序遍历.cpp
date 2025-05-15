/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
// @lc code=start



class Solution {
public:
    vector<int> result;
    void pre(Node* node){
        if (node==NULL) return ;
        result.emplace_back(node->val);
        int childSize=node->children.size();
        for(int i=0;i<childSize;i++){
            pre(node->children[i]);
        }
        return;

    }
    vector<int> preorder(Node* root) {
        pre(root);
        return result;
    }
};
// @lc code=end

