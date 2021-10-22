/*
给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

示例 1：
输入：[3,2,3]
输出：[3]

示例 2：
输入：nums = [1]
输出：[1]

示例 3：
输入：[1,1,1,3,3,2,2,2]
输出：[1,2]
 
提示：
1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 
进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。
*/


/**
 * @param {number[]} nums
 * @return {number[]}
 */
var majorityElement = function(nums) {
  let res = [];
  if (nums === null || nums.length === 0){
    return res;
  }
  let cand1 = nums[0], count1 = 0;
  let cand2 = nums[0], count2 = 0;
  for (let num of nums) {
    if (cand1 === num) {
      count1++;
      continue;
    }
    if (cand2 === num) {
      count2++;
      continue;
    }

    if (count1 === 0) {
      cand1 = num;
      count1++;
      continue;
    }
    if (count2 === 0) {
      cand2 = num;
      count2++;
      continue;
    }

    count1--;
    count2--;
  }
  count1 = 0, count2 = 0;
  for (let num of nums) {
    if (cand1 === num) {
      count1++;
    } else if (cand2 === num) {
      count2++;
    }
  }
  if (count1 > nums.length / 3) {
    res.push(cand1);
  }
  if (count2 > nums.length / 3) {
    res.push(cand2);
  }
  return res;
};