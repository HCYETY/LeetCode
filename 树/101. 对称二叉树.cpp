/*
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
    1
   / \
  2   2
 / \ / \
3  4 4  3

但是下面这个?[1,2,2,null,3,null,3] 则不是镜像对称的:
    1
   / \
  2   2
   \   \
   3    3

进阶：
你可以运用递归和迭代两种方法解决这个问题吗？
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
//  递归
class Solution {
public:
    bool check(TreeNode*a, TreeNode*b) {
        if(!a && !b) return true;
        if(!a || !b) return false;
        return a->val == b->val && check(a->left, b->right) && check(a->right, b->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};
//  迭代
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
    bool check(TreeNode*a, TreeNode*b) {
        queue <TreeNode*> my_queue;
        my_queue.push(a);
        my_queue.push(b);
        while(!my_queue.empty()) {
            TreeNode* u = my_queue.front();
            my_queue.pop();
            TreeNode* v = my_queue.front();
            my_queue.pop();
            if(!u && !v) continue;
            if((!u || !v) || (u->val != v->val)) return false;
            my_queue.push(u->left);
            my_queue.push(v->right);
            my_queue.push(u->right);
            my_queue.push(v->left);
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};
