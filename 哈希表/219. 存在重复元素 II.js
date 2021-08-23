/*
给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。

示例 1:
输入: nums = [1,2,3,1], k = 3
输出: true

示例 2:
输入: nums = [1,0,1,1], k = 1
输出: true

示例 3:
输入: nums = [1,2,3,1,2,3], k = 2
输出: false
*/


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
// 解法一：线性搜索
var containsNearbyDuplicate = function(nums, k) {
    for (let i = 0; i < nums.length - 1; i++) {
        for (let j = 1; (j <= k) && ((i + j) < nums.length); j++) {
            if (nums[i+j] == nums[i]) {
                return true;
            }
        }
    }
    return false;
};
// 解法二：哈希表
var containsNearbyDuplicate = function(nums, k) {
    const set = new Set();
    for(let i = 0; i < nums.length; i++) {
        // 在哈希表中搜索当前元素，如果找到了就返回 true。
        if(set.has(nums[i])) {
            return true;
        }
        // 在哈希表中插入当前元素。
        set.add(nums[i]);
        // 如果当前哈希表的大小超过了 kk， 删除哈希表中最旧的元素。
        if(set.size > k) {
            set.delete(nums[i - k]);
        }
    }
    return false;
};