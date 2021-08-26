/*
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
请找出数组中任意一个重复的数字。

示例 1：
输入：[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3

限制：
2 <= n <= 100000
*/


// 解法一：“作弊”行为
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
         sort(nums.begin(), nums.end());
         for (int i = 1; i < nums.size(); i++) {
             if (nums[i] == nums[i-1]) {
                 return nums[i];
             }
         }
         return -1;
    }
};
// 解法二：哈希表标识
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map <int, bool> um;
        for (int num : nums) {
            if (um[num]) return num;
            um[num] = true;
        }
        return -1;
    }
};
// 解法三：原地交换
// 思路：遍历数组过程中，第一次遇到数字 x 时，将其交换至索引 x 处；
// 而当第二次遇到数字 x 时，一定有 nums[x] = x ，此时即可得到一组重复数字。
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            // 此数字已在对应索引位置，无需交换，因此跳过
            if (nums[i] == i) {
                i++;
                continue;
            }
            // 索引 nums[i] 处和索引 i 处的元素值都为 nums[i] ，即第二次遇到数字，此时找到一组重复值，返回此值 nums[i]
            if (nums[nums[i]] == nums[i]) {
                return nums[i];
            }
            // 第一次遇到数字，交换索引为 i 和 nums[i] 的元素值，将此数字交换至对应索引位置
            swap(nums[i], nums[nums[i]]);
        }
        return -1;
    }
};
