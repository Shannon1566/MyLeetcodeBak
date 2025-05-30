/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* createPerfectBinaryTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root) return root;
        int size = 0;
        vector<int> results;
        queue<Node *> que;
        root->next=NULL;
        que.push(root);
        size++;
        if (!root)
            return root;
        while (!que.empty())
        {
            int size2 = size;
            size = 0;
            for (int i = 0; i < size2; i++)
            {
                Node *cur = que.front();
                que.pop();
                if(i==size2-1){
                    cur->next=NULL;
                }else{
                    cur->next=que.front();
                }
                
                
                if (cur->left)
                {
                    que.push(cur->left);
                    size++;
                }
                if (cur->right)
                {
                    que.push(cur->right);
                    size++;
                }
            }
        }
        return root;
    }
};
// @lc code=end
int main(){
    Solution sol;
    sol.connect(createPerfectBinaryTree());
    return 0;
}