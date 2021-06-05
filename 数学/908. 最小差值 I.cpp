/*
给你一个整数数组 A，请你给数组中的每个元素 A[i] 都加上一个任意数字 x （-K <= x <= K），从而得到一个新数组 B 。
返回数组 B 的最大值和最小值之间可能存在的最小差值。

示例 1：
输入：A = [1], K = 0
输出：0
解释：B = [1]

示例 2：
输入：A = [0,10], K = 2
输出：6
解释：B = [2,8]

示例 3：
输入：A = [1,3,6], K = 3
输出：0
解释：B = [3,3,3] 或 B = [4,4,4]

提示：
1 <= A.length <= 10000
0 <= A[i] <= 10000
0 <= K <= 10000
*/


//没看题解前：
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int len = nums.size();
        if(len < 2) return 0;
        int diff = 0, max = 0, min = 0;
        sort(nums.begin(), nums.end());
        if(nums[len - 1] - nums[0] >= nums[0] + k) {
            nums[0] += k;
            nums[len-1] -= k;
            diff = nums[len-1] - nums[0];
            if(diff < 0) diff = 0;
        }
        return diff;
    }
};
//看了题解后：
/* 思路：
要得到最小差值，需 max(B)-min(B)，则应使原数组A中最大值和最小值尽量接近。
若max(A)与min(A)的差值大于2K，则在变换中应使max(A)-K, min(A)+K，此时结果为max(A)-min(A)-2K。
若差值小于等于2*K,则可使最终结果为0。
*/
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(nums[nums.size()-1] - nums[0] > 2 * k)
            return nums[nums.size()-1] - nums[0] - 2 * k;
				// 等价于 return (nums[nums.size() - 1] - k) - (nums[0] + k);
        return 0;
    }
};
