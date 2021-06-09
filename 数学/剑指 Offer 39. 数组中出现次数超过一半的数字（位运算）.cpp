/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1:
输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2

限制：
1 <= 数组长度 <= 50000
*/


// 最优解：摩尔投票法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = 0, count = 0;
        for(int i : nums) {
            if(count == 0) num = i;
            count += i == num ? 1 : -1;
				// 等价于votes = votes + ( i == num ? 1 : -1);
        }
        return num;
    }
};
// 排序：中间位置的数 就是 出现次数最多的那个数，也就是 超过数组长度的一半的数
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
// 哈希
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int,int> arr;
        for(int i : nums) {
            arr[i]++;
            if(arr[i] > nums.size() / 2) {
                return i;
            }
        }
        return -1;
    }
};
