/*
���������������������Ҷ��֮�͡�

ʾ����

    3
   / \
  9  20
    /  \
   15   7
������������У���������Ҷ�ӣ��ֱ��� 9 �� 15�����Է��� 24
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
        int result = 0;  // ��������Ҷ��֮�ͣ��ݹ��������0����Ϊ������ǰ��¼�Ľ�㲻����Ҷ��
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
