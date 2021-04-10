����ĳ��������ǰ���������������Ľ�������ؽ��ö����������������ǰ���������������Ľ���ж������ظ������֡�

���磬����
ǰ����� preorder =?[3,9,20,15,7]
������� inorder = [9,3,15,20,7]
�������µĶ�������

    3
   / \
  9  20
    /  \
   15   7

���ƣ�
0 <= �ڵ���� <= 5000


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n==0) return NULL;

        int left_len = -1;
        for(int i=0; i<n; i++) {
            if(inorder[i] == preorder[0]) {
                left_len = i;
                break;
            }
        }
        int right_len = n - left_len - 1;

        TreeNode* node = new TreeNode();
        node->val = preorder[0];
        node->left = buildTree(preorder + 1, inorder);
        node->right = buildTree(preorder + left_len + 1, inorder + left_len + 1);
        return node;
    }
};
