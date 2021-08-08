/*
数组的每个下标作为一个阶梯，第 i 个阶梯对应着一个非负数的体力花费值 cost[i]（下标从 0 开始）。
每当爬上一个阶梯都要花费对应的体力值，一旦支付了相应的体力值，就可以选择向上爬一个阶梯或者爬两个阶梯。

请找出达到楼层顶部的最低花费。在开始时，你可以选择从下标为 0 或 1 的元素作为初始阶梯。
 

示例 1：
输入：cost = [10, 15, 20]
输出：15
解释：最低花费是从 cost[1] 开始，然后走两步即可到阶梯顶，一共花费 15 。

示例 2：
输入：cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
输出：6
解释：最低花费方式是从 cost[0] 开始，逐个经过那些 1 ，跳过 cost[3] ，一共花费 6 。

提示：
2 <= cost.length <= 1000
0 <= cost[i] <= 999
*/


/**
 * @param {number[]} cost
 * @return {number}
 */
// 最初的想法是用 count 标识最少体力值，但发现难以维护，后来就用数组标识
// 法一
 var minCostClimbingStairs = function(cost) {
    let len = cost.length, res = new Array(len);
    res[0] = cost[0];
    res[1] = cost[1];
    for(let i = 2; i < len; i++) {
        res[i] = Math.min(res[i-1], res[i-2]) + cost[i];
    }
    return Math.min(res[len-1], res[len-2]);
};
// 法二：法一的优化，因为 res[i] 只和 res[i-2], res[i-1] 有关，所以只用 2 个变量就行了.
var minCostClimbingStairs = function(cost) {
    let len = cost.length;
    let res_0 = cost[0], res_1 = cost[1];
    for(let i = 2; i < len; i++) {
        const tmp = res_1;
        res_1 = Math.min(res_0, res_1) + cost[i];
        res_0 = tmp;
    }
    return Math.min(res_0, res_1);
};