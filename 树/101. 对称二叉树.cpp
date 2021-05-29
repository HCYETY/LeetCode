/*
����һ����������������Ƿ��Ǿ���ԳƵġ�

���磬������ [1,2,2,3,4,4,3] �ǶԳƵġ�
    1
   / \
  2   2
 / \ / \
3  4 4  3

�����������?[1,2,2,null,3,null,3] ���Ǿ���ԳƵ�:
    1
   / \
  2   2
   \   \
   3    3

���ף�
��������õݹ�͵������ַ���������������
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
//  �ݹ�
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
//  ����
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
