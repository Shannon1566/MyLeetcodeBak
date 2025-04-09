/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
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
/*
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
*/

class Solution {
public:
    int result=0;
    void trv(Node* node,int curDeepth){
        if (node==NULL) return;
        else{
            result=max(curDeepth,result);
            int size=node->children.size();
            for (int i=0;i<size;i++){
                trv(node->children[i],curDeepth+1);
            }
            return ;
        }
    }
    int maxDepth(Node* root) {
        trv(root,1);
        return result;
    }
};
// @lc code=end

