/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
// @lc code=start

class Solution {
public:
    int getHeight(TreeNode * node){
        if (node==NULL) return 0;
        else{
            int leftHeight=getHeight(node->left);
            int rightHeight=getHeight(node->right);
              
            if(leftHeight==-1||rightHeight==-1) return -1;


            if (abs(leftHeight-rightHeight)<=1){
                return max(leftHeight,rightHeight)+1;
            }else{
                return -1;
            }
        }
    }
    bool isBalanced(TreeNode* root) {
        return getHeight(root)!=-1;
    }
};
// @lc code=end

