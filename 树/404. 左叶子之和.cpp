/*
计算给定二叉树的所有左叶子之和。

示例：

    3
   / \
  9  20
    /  \
   15   7
在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
*/


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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int result = 0;  // 用来记左叶子之和，递归会重新清0，因为发现先前记录的结点不是左叶子
        if (root->left) {
            if (!root->left->left && !root->left->right) {
                result += root->left->val;
            } else {
                result += sumOfLeftLeaves(root->left);
            }
        }
        if (root->right) {
            result += sumOfLeftLeaves(root->right);
        }
        return result;
    }
};
