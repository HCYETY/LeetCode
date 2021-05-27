/*
给定一个二叉树，返回它的 后序 遍历。

示例:
输入: [1,null,2,3]
   1
    \
     2
    /
   3
输出: [3,2,1]

进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
//迭代
//先序遍历是中左右，后续遍历是左右中，那么我们只需要调整一下先序遍历的代码顺序，就变成中右左的遍历顺序，然后在反转result数组，输出的结果顺序就是左右中了，
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
            if (node->left) st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
            if (node->right) st.push(node->right); // 空节点不入栈
        }
//      reverse函数用于反转在[first,last)范围内的顺序（包括first指向的元素，不包括last指向的元素），reverse函数没有返回值
        reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
        return result;
    }
};
