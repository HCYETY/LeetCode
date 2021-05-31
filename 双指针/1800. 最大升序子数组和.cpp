/*
给你一个正整数组成的数组 nums ，返回 nums 中一个 升序 子数组的最大可能元素和。
子数组是数组中的一个连续数字序列。
已知子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，若对所有 i（l <= i < r），numsi < numsi+1 都成立，则称这一子数组为 升序 子数组。注意，大小为 1 的子数组也视作 升序 子数组。

示例 1：
输入：nums = [10,20,30,5,10,50]
输出：65
解释：[5,10,50] 是元素和最大的升序子数组，最大元素和为 65 。

示例 2：
输入：nums = [10,20,30,40,50]
输出：150
解释：[10,20,30,40,50] 是元素和最大的升序子数组，最大元素和为 150 。

示例 3：
输入：nums = [12,17,15,13,10,11,12]
输出：33
解释：[10,11,12] 是元素和最大的升序子数组，最大元素和为 33 。

示例 4：
输入：nums = [100,10,1]
输出：100

提示：
1 <= nums.length <= 100
1 <= nums[i] <= 100
*/


class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = 0, max_sum = 0, left = 0, right = 1;
        bool sign = true;
        while(left < nums.size()) {
            // 首先加上起始位置值
            if(sign) {
                sum = 0;   // 说明遇到非升序的元素，sum 要重新计值
                sum += nums[left];
            }
            if(right < nums.size() && nums[left] < nums[right]) {
                sum += nums[right];
                sign = false;  // 防止进入上一个判断语句，导致 sum 重新计值
            }
            else {
                sign = true;
            }
            left = right;
            right++;
            // 更新最大值
            max_sum = max(sum, max_sum);
        }
        return max_sum;
    }
};
