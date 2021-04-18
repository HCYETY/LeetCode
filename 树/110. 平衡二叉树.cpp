����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������

�����У�һ�ø߶�ƽ�����������Ϊ��
һ��������ÿ���ڵ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ��


ʾ�� 1��
���룺root = [3,9,20,null,null,15,7]
�����true

ʾ�� 2��
���룺root = [1,2,2,3,3,null,null,4,4]
�����false

ʾ�� 3��
���룺root = []
�����true


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
    int height(TreeNode *root) {
        if(!root) return 0;
        else return max(height(root->left), height(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        else {
            return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        }
    }
};
