/*
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

示例 1：
输入：root = [1,null,2,3]
输出：[1,2,3]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]

示例 4：
输入：root = [1,2]
输出：[1,2]

示例 5：
输入：root = [1,null,2]
输出：[1,2]

提示：
树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100

进阶：递归算法很简单，你可以通过迭代算法完成吗？
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
// 递归
class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val);    // 中
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};
//迭代
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
    	  if (root == NULL) return result;
        stack<TreeNode*> st;
        vector<int> result;
        st.push(root);                               // 先将根节点压进栈
        while (!st.empty()) {
            TreeNode* node = st.top();               // 得到根节点 或是 有孩子的父节点
            st.pop();
            result.push_back(node->val);
            if (node->right) st.push(node->right);   // 如果有右孩子，则入栈（空节点不入栈）
            if (node->left) st.push(node->left);     // 如果有左孩子，则入栈（空节点不入栈）
        }
        return result;
    }
};
