/*
����һ�������������飬Ԫ�ظ�����ͬ�Ұ��������У���дһ���㷨������һ�ø߶���С�Ķ�����������

ʾ��:
������������: [-10,-3,0,5,9],
һ�����ܵĴ��ǣ�[0,-3,9,-10,null,5]�������Ա�ʾ��������߶�ƽ�������������

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
    // left ��ʾ��ߵķ�Χ��right ��ʾ�ұߵķ�Χ
    TreeNode* dfs(vector<int>& nums, int left, int right) {
        if (left <= right) {
            // ȡ�е���Ϊ��ǰ���ڵ�
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
