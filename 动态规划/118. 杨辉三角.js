/*
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
在「杨辉三角」中，每个数是它左上方和右上方的数的和。

示例 1:
输入: numRows = 5
输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

示例 2:
输入: numRows = 1
输出: [[1]]

提示:
1 <= numRows <= 30
*/


/**
 * @param {number} numRows
 * @return {number[][]}
 */

// 粗糙写法
var generate = function(numRows) {
    // 新建要返回的目标数组
    const dp = [];
    // dp数组赋初始值
    for(let i = 0; i < numRows; i++) {
        dp[i] = [];
        for(let j = 0; j <= i; j++) {
            dp[i][j] = 1;
        }
    }
    // 更新部分值
    for(let i = 2; i < numRows; i++) {
        for(let j = 1; j < i; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp;
};
// 优雅写法
var generate = function(numRows) {
    const ret = [];

    for (let i = 0; i < numRows; i++) {
        const row = new Array(i + 1).fill(1);
        for (let j = 1; j < row.length - 1; j++) {
            row[j] = ret[i - 1][j - 1] + ret[i - 1][j];
        }
        ret.push(row);
    }
    return ret;
};