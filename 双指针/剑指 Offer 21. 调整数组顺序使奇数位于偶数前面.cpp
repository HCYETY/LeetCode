/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

示例：
输入：nums = [1,2,3,4]
输出：[1,3,2,4]
注：[3,1,2,4] 也是正确的答案之一。

提示：
0 <= nums.length <= 50000
1 <= nums[i] <= 10000
*/


class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int len = nums.size(), left = 0, right = len - 1;
        while (left <= right) {
            if (nums[left] % 2 == 0 && nums[right] % 2 != 0) {
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            } else if (nums[left] % 2 != 0){
                left++;
            } else if (nums[right] % 2 == 0) {
                right--;
            }
        }
        return nums;
    }
};
