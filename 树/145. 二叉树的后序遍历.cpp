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
//��������������ң����������������У���ô����ֻ��Ҫ����һ����������Ĵ���˳�򣬾ͱ��������ı���˳��Ȼ���ڷ�תresult���飬����Ľ��˳������������ˣ�
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
    	  if (root == NULL) return result;
        stack<TreeNode*> st;
        vector<int> result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left) st.push(node->left); // �����ǰ������������һ����ջ˳�� ���սڵ㲻��ջ��
            if (node->right) st.push(node->right); // �սڵ㲻��ջ
        }
//      reverse�������ڷ�ת��[first,last)��Χ�ڵ�˳�򣨰���firstָ���Ԫ�أ�������lastָ���Ԫ�أ���reverse����û�з���ֵ
        reverse(result.begin(), result.end()); // �������ת֮����������е�˳����
        return result;
    }
};
