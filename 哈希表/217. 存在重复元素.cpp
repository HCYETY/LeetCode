/*
给定一个整数数组，判断是否存在重复元素。
如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。

示例 1:
输入: [1,2,3,1]
输出: true

示例 2:
输入: [1,2,3,4]
输出: false

示例 3:
输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
*/


// 解法一：排序
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
         sort(nums.begin(), nums.end());
         for (int i = 1; i < nums.size(); i++) {
             if (nums[i] == nums[i-1]) {
                 return true;
             }
         }
         return false;
    }
};
// 解法二：哈希表
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
         unordered_set<int> s;
         for (int number : nums) {
             if (s.find(number) != s.end()) {
                 return true;
             }
             s.insert(number);
         }
         return false;
    }
};
// 解法三：数组标识（理论上应该是可以的，但不知道为什么不能通过）
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        vector <int> dp(len, 0);
        for (int i = 0; i < len; i++) {
            dp[nums[i]]++;
            if(dp[nums[i]] > 1) {
                return true;
            }
        }
        return false;
    }
};
