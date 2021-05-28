/*
给你两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。
请你找出 nums1 中每个元素在 nums2 中的下一个比其大的值。
nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。

示例 1:
输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于 num1 中的数字 4 ，你无法在第二个数组中找到下一个更大的数字，因此输出 -1 。
    对于 num1 中的数字 1 ，第二个数组中数字1右边的下一个较大数字是 3 。
    对于 num1 中的数字 2 ，第二个数组中没有下一个更大的数字，因此输出 -1 。

示例 2:
输入: nums1 = [2,4], nums2 = [1,2,3,4].
输出: [3,-1]
解释:
    对于 num1 中的数字 2 ，第二个数组中的下一个较大数字是 3 。
    对于 num1 中的数字 4 ，第二个数组中没有下一个更大的数字，因此输出 -1 。

提示：
1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104
nums1和nums2中所有整数 互不相同
nums1 中的所有整数同样出现在 nums2 中

进阶：你可以设计一个时间复杂度为 O(nums1.length + nums2.length) 的解决方案吗？
*/


//思路：先找出 nums1 的数字在 nums2 中对应的下一个更大的数字找出来，然后放到哈希表中，以供后面 nums1 直接使用即可

//具体流程如下：
//1.创建一个临时栈，一个哈希表，然后遍历 nums2。
//2.若当前栈无数据，则当前数字入栈备用。
//3.若当前栈有数据，则用当前数字与栈顶比较：
//  3.1 当前数字 > 栈顶，代表栈顶对应下一个更大的数字就是当前数字，则将该组数字对应关系，记录到哈希表。
//  3.2 当前数字 < 栈顶，当前数字压入栈，供后续数字判断使用。
//4.这样，我们就可以看到哈希表中存在部分 nums2 数字的对应关系了，而栈中留下的数字，代表无下一个更大的数字，我们全部赋值为 -1 ，然后存入哈希表即可。
//5.遍历 nums1nums1，直接询问哈希表拿对应关系即可。
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int>num_map;
        stack<int> mystack;
        for(int i = 0; i < nums2.size(); i++) {
            while(!mystack.empty() && mystack.top() < nums2[i]) {
                num_map[mystack.top()] = nums2[i];
                mystack.pop();
            }
            mystack.push(nums2[i]);
        }
        while(!mystack.empty()) {
            num_map[mystack.top()] = -1;
            mystack.pop();
        }
        for(int i = 0; i < nums1.size(); i++) {
            ans.push_back(num_map[nums1[i]]);
        }
        return ans;
    }
};
