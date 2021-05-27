/*
����һ���������ĸ��ڵ� root ���������� ���� ������
  
ʾ�� 1��
���룺root = [1,null,2,3]
�����[1,3,2]

ʾ�� 2��
���룺root = []
�����[]

ʾ�� 3��
���룺root = [1]
�����[1]

ʾ�� 4��
���룺root = [1,2]
�����[2,1]

ʾ�� 5��
���룺root = [1,null,2]
�����[1,2]

��ʾ��
���нڵ���Ŀ�ڷ�Χ [0, 100] ��
-100 <= Node.val <= 100

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
    void inorder(TreeNode* root, vector<int> &res) {
        if(!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};
//����
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	  stack<TreeNode*> st;
        vector<int> result;
        TreeNode* cur = root;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) { // ָ�������ʽڵ㣬���ʵ���ײ�
                st.push(cur); // �����ʵĽڵ�Ž�ջ
                cur = cur->left;                // ��
            } else {
                cur = st.top(); // ��ջ�ﵯ�������ݣ�����Ҫ��������ݣ��Ž�result����������ݣ�
                st.pop();
                result.push_back(cur->val);     // ��
                cur = cur->right;               // ��
            }
        }
        return result;
    }
};
