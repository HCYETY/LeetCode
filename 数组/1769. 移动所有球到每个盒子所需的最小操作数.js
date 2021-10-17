/*
有 n 个盒子。给你一个长度为 n 的二进制字符串 boxes ，其中 boxes[i] 的值为 '0' 表示第 i 个盒子是 空 的，而 boxes[i] 的值为 '1' 表示盒子里有 一个 小球。
在一步操作中，你可以将 一个 小球从某个盒子移动到一个与之相邻的盒子中。第 i 个盒子和第 j 个盒子相邻需满足 abs(i - j) == 1 。
注意，操作执行后，某些盒子中可能会存在不止一个小球。

返回一个长度为 n 的数组 answer ，其中 answer[i] 是将所有小球移动到第 i 个盒子所需的 最小 操作数。
每个 answer[i] 都需要根据盒子的 初始状态 进行计算。
 

示例 1：
输入：boxes = "110"
输出：[1,1,3]
解释：每个盒子对应的最小操作数如下：
1) 第 1 个盒子：将一个小球从第 2 个盒子移动到第 1 个盒子，需要 1 步操作。
2) 第 2 个盒子：将一个小球从第 1 个盒子移动到第 2 个盒子，需要 1 步操作。
3) 第 3 个盒子：将一个小球从第 1 个盒子移动到第 3 个盒子，需要 2 步操作。将一个小球从第 2 个盒子移动到第 3 个盒子，需要 1 步操作。共计 3 步操作。

示例 2：
输入：boxes = "001011"
输出：[11,8,5,4,3,4]

提示：
n == boxes.length
1 <= n <= 2000
boxes[i] 为 '0' 或 '1'
*/


/**
 * @param {string} boxes
 * @return {number[]}
 */
// 方法一：滑动窗口
// 1、建立 dp 存储盒子的最小操作数，先求出第一个盒子的 minOperations ，同时记录当前及其右边的 1 的数量
// 2、然后依次求 1 到 最后一个盒子，每次向右移动的时候，①dp[j] 会比 dp[j-1] 的 minOperations 减少 right 个（单个盒子少左移了一次，有 n 个则少左移 n 次）；②同时 dp[j] 会比 dp[j-1] 的 minOperations 增加 left 个。也就说，在从 index = 1 开始遍历的时候，要维护 right 和 left 。
// 3、观察规律可以得知状态转移方程为：dp[j] = dp[j-1] - right + left
var minOperations = function(boxes) {
  const len = boxes.length;
  let dp = [0], right = 0;
  for (let i = 0; i < len; i++) {
    if (boxes[i] === '1') {
      dp[0] += i;
      right += 1;
    }
  }
  let left = 0;
  for (let j = 1; j < len; j++) {
    if (boxes[j-1] === '1') {
      left += 1;
      right -= 1;
    }
    dp[j] = dp[j-1] - right + left;
  }
  return dp;
};

// 方法二：遍历查找
var minOperations = function(boxes) {
  let answer = [];
  for (let i = 0; i < boxes.length; i++) {
    let count = 0;
    for (let j = 0; j < boxes.length; j++) {
      if (i === j) {
        continue;
      } else {
        if (boxes[j] === "1") {
          count += Math.abs(j - i);
        }
      }
    }
    answer[i] = count;
  }
  return answer;
};