/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

示例 1：
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 

示例 2：
输入：height = [4,2,0,3,2,5]
输出：9
 

提示：
n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/


/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
  if (height.length === 0) {
    return 0;
  }
  const len = height.length;
  let res = 0;

  let left = 0, right = len - 1;
  let l_max = height[0], r_max = height[len - 1];
  while(left <= right) {
    l_max = Math.max(l_max, height[left]);
    r_max = Math.max(r_max, height[right]);

    if (l_max < r_max) {
      res += l_max - height[left++];
    } else {
      res += r_max - height[right--];
    }
  }

  return res;
};