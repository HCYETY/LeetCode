/*
����������ĸ��ڵ� root ���������ڵ�ֵ�� ǰ�� ������

ʾ�� 1��
���룺root = [1,null,2,3]
�����[1,2,3]

ʾ�� 2��
���룺root = []
�����[]

ʾ�� 3��
���룺root = [1]
�����[1]

ʾ�� 4��
���룺root = [1,2]
�����[1,2]

ʾ�� 5��
���룺root = [1,null,2]
�����[1,2]

��ʾ��
���нڵ���Ŀ�ڷ�Χ [0, 100] ��
-100 <= Node.val <= 100

���ף��ݹ��㷨�ܼ򵥣������ͨ�������㷨�����
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
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val);    // ��
        traversal(cur->left, vec);  // ��
        traversal(cur->right, vec); // ��
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};
//����
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
    	  if (root == NULL) return result;
        stack<TreeNode*> st;
        vector<int> result;
        st.push(root);                               // �Ƚ����ڵ�ѹ��ջ
        while (!st.empty()) {
            TreeNode* node = st.top();               // �õ����ڵ� ���� �к��ӵĸ��ڵ�
            st.pop();
            result.push_back(node->val);
            if (node->right) st.push(node->right);   // ������Һ��ӣ�����ջ���սڵ㲻��ջ��
            if (node->left) st.push(node->left);     // ��������ӣ�����ջ���սڵ㲻��ջ��
        }
        return result;
    }
};
