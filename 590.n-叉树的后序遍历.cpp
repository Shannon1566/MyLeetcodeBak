/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
 */
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
// @lc code=start

class Solution
{
public:
    vector<int> result;
    void post(Node *node)
    {
        if (node == NULL)
            return;
        
        int childSize = node->children.size();
        for (int i = 0; i < childSize; i++)
        {
            post(node->children[i]);
        }
        result.emplace_back(node->val);
        return;
    }
    vector<int> postorder(Node *root)
    {
        post(root);
        return result;
    }
};
// @lc code=end
