/*
����һ������������������ ���� ������

ʾ��:
����: [1,null,2,3]
   1
    \
     2
    /
   3
���: [3,2,1]

����: �ݹ��㷨�ܼ򵥣������ͨ�������㷨�����
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
// �ݹ�
class Solution {
public:
    void postorder(TreeNode* root, vector<int> &ans) {
        if(!root) return;
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};
//����
