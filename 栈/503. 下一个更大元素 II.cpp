/*
给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。

示例 1:
输入: [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数；
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
注意: 输入数组的长度不会超过 10000。
*/


//模拟出环形数组的效果，一般是通过 % 运算符求模（余数），获得环形特效
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int>ans(len);
        stack<int>mystack;
        // 假装这个数组长度翻倍了
        for(int i = 2 * len - 1; i >= 0; i--) {
            while(!mystack.empty() && mystack.top() <= nums[i%len]) {
                mystack.pop();
            }
            ans[i%len] = mystack.empty() ? -1 : mystack.top();
            mystack.push(nums[i%len]);
        }
        return ans;
    }
};
