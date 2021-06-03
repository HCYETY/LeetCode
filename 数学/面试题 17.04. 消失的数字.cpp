/*
数组nums包含从0到n的所有整数，但其中缺了一个。
请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？

注意：本题相对书上原题稍作改动

示例 1：
输入：[3,0,1]
输出：2

示例 2：
输入：[9,6,4,2,3,5,7,0,1]
输出：8
*/

//求和
//思路：等差数列求和，用和减去nums数组的每个元素，剩下的值就是缺失的值
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int length = nums.size();
        int sum = (0 + length) * (length + 1) / 2;
        for(int i = 0; i < length; i++) {
            sum -= nums[i];
        }
        return sum;
    }
};
//位运算求解

