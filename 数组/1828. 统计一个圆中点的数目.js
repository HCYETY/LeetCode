/*
给你一个数组 points ，其中 points[i] = [xi, yi] ，表示第 i 个点在二维平面上的坐标。多个点可能会有 相同 的坐标。
同时给你一个数组 queries ，其中 queries[j] = [xj, yj, rj] ，表示一个圆心在 (xj, yj) 且半径为 rj 的圆。

对于每一个查询 queries[j] ，计算在第 j 个圆 内 点的数目。如果一个点在圆的 边界上 ，我们同样认为它在圆 内 。
请你返回一个数组 answer ，其中 answer[j]是第 j 个查询的答案。
 

示例 1：
输入：points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
输出：[3,2,2]

示例 2：
输入：points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
输出：[2,3,2,4]

提示：
1 <= points.length <= 500
points[i].length == 2
0 <= x​​​​​​i, y​​​​​​i <= 500
1 <= queries.length <= 500
queries[j].length == 3
0 <= xj, yj <= 500
1 <= rj <= 500
所有的坐标都是整数。
*/


// 思路：这道题要我们求圆内的点，根据高中的知识可以联想到用勾股定理求半径。
// 更加具体地说，就是先获取 points 的点和 queries 的圆心，求出两点之间的距离，如果这个距离大于 queries 圆的半径，就说明 points 该点在圆内，否则不在圆内。
// 两点之间的距离公式为：（x1-x2)^2 + (y1-y2)^2 = r^2；代码实现则为：Math.pow(x1-x2, 2) + Math.pow(y1-y2, 2)。
/**
 * @param {number[][]} points
 * @param {number[][]} queries
 * @return {number[]}
 */
var countPoints = function(points, queries) {
  let answer = [];
  for (let o of queries) {
    let count = 0;
    for (let x of points) {
      const redius = Math.pow(x[0]-o[0], 2) + Math.pow(x[1]-o[1], 2);
      if (redius <= o[2] * o[2]) {
        count++;
      }
    }
    answer.push(count);
  }
  return answer;
};