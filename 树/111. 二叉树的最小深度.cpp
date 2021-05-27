/*
����һ�����������ҳ�����С��ȡ�
��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������

˵����Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

ʾ�� 1��
���룺root = [3,9,20,null,null,15,7]
�����2

ʾ�� 2��
���룺root = [2,null,3,null,4,null,5,null,6]
�����5

��ʾ��
���нڵ����ķ�Χ�� [0, 105] ��
-1000 <= Node.val <= 1000
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
    int minDepth(TreeNode* root) {
        // ���ȣ��ڵ�Ϊ�գ�ֱ�ӷ���0
        if(root == nullptr) return 0;
        int m1 = minDepth(root->left);
        int m2 = minDepth(root->right);
        //1.������Ӻ��Һ��Ӷ�Ϊ�յ������ֱ�ӷ���m1+m2+1
        //2.������Ӻ��Һ��Ӵ�������һ��Ϊ�յ������Ҳֱ�ӷ���m1+m2+1
        //3.�������Ϊ�գ����ؽ�С���+1
        return root->left == nullptr || root->right == nullptr ? m1 + m2 + 1 : min(m1,m2) + 1;
    }
};
