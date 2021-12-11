/*
给你一个整数数组 nums 和一个整数 k 。你需要找到 nums 中长度为 k 的 子序列 ，且这个子序列的 和最大 。
请你返回 任意 一个长度为 k 的整数子序列。
子序列 定义为从一个数组里删除一些元素后，不改变剩下元素的顺序得到的数组。

示例 1：
输入：nums = [2,1,3,3], k = 2
输出：[3,3]
解释：
子序列有最大和：3 + 3 = 6 。

示例 2：
输入：nums = [-1,-2,3,4], k = 3
输出：[-1,3,4]
解释：
子序列有最大和：-1 + 3 + 4 = 6 。

示例 3：
输入：nums = [3,4,3,3], k = 2
输出：[3,4]
解释：
子序列有最大和：3 + 4 = 7 。
另一个可行的子序列为 [4, 3] 。
 
提示：
1 <= nums.length <= 1000
-105 <= nums[i] <= 105
1 <= k <= nums.length
*/


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSubsequence = function(nums, k) {
  const n = nums.length;
  let ans = new Array(k), maxNum = nums[0], index = new Array(n);
  for (let j = 0; j < n; j++) {
    if (nums[j] >= maxNum) {
      maxNum = nums[j];
      index[j] = nums[j];
    }
  }
  for (let i = index.length - 1; i >= 0 && k > 0; i--) {
    if (index[i]) {
      ans[k - 1] = index[i];
      k--;
    }
  }
  return ans;
};