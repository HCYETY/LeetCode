给你一个整数数组nums（下标从 0 开始）。每一次操作中，你可以选择数组中一个元素，并将它增加1。
比方说，如果nums = [1,2,3]，你可以选择增加nums[1]得到nums = [1,3,3]。
请你返回使nums严格递增的最少操作次数。

我们称数组nums是 严格递增的，当它满足对于所有的0 <= i < nums.length - 1都有nums[i] < nums[i+1]。一个长度为 1的数组是严格递增的一种特殊情况。


示例 1：
输入：nums = [1,1,1]
输出：3
解释：你可以进行如下操作：
1) 增加 nums[2] ，数组变为 [1,1,2] 。
2) 增加 nums[1] ，数组变为 [1,2,2] 。
3) 增加 nums[2] ，数组变为 [1,2,3] 。

示例 2：
输入：nums = [1,5,2,4,1]
输出：14

示例 3：
输入：nums = [8]
输出：0


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int len = nums.size(), runs = 0;
        if(len <= 1)
            return runs;
        for(int i = 1; i < len; i++) {
            if(nums[i-1] >= nums[i]) {
                int flag = nums[i-1] + 1 - nums[i];
                runs +=  flag;
                nums[i] = nums[i-1] + 1;
            }
        }
        return runs;
    }
};
