/*
给定一个有序整数数组，元素各不相同且按升序排列，编写一个算法，创建一棵高度最小的二叉搜索树。

示例:
给定有序数组: [-10,-3,0,5,9],
一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

          0
         / \
       -3   9
       /   /
     -10  5
*/


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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
    // left 表示左边的范围，right 表示右边的范围
    TreeNode* dfs(vector<int>& nums, int left, int right) {
        if (left <= right) {
            // 取中点作为当前根节点
            int mid = (left+right) >> 1;
            TreeNode* root = new TreeNode(nums[mid]);
            root -> left = dfs(nums, left, mid - 1);
            root -> right = dfs(nums, mid + 1, right);
            return root;
        } else {
            return nullptr;
        }
    }
};
