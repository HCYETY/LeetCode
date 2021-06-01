/*
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。

示例 1：
输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]

示例 2：
输入：nums1 = [1], m = 1, nums2 = [], n = 0
输出：[1]

提示：
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[i] <= 109
*/

//该算法空间上可进一步优化，因为新建了一个数组
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ans[m + n];
        int pointer1 = 0, pointer2 = 0;
        while(pointer1 < m || pointer2 < n) {
				// 假设nums1的空间是m + n，但遍历的时候，它的空间大小是m
            if(pointer1 == m) {
                ans[pointer1 + pointer2 - 1] = nums2[pointer2++];
            } else if(pointer2 == n) {
                ans[pointer1 + pointer2 - 1] = nums1[pointer1++];
            } else if(nums1[pointer1] < nums2[pointer2]) {
                ans[pointer1 + pointer2 - 1] = nums1[pointer1++];
            } else {
                ans[pointer1 + pointer2 - 1] = nums2[pointer2++];
            }
        }
        for(int i = 0; i != m + n; i++) {
            nums1[i] = ans[i];
        }
    }
};
//优化后的算法，直接在nums1数组上进行排序
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pointer1 = m - 1, pointer2 = n - 1, cur = m + n - 1;
        while(pointer1 >= 0 || pointer2 >= 0) {
            if(pointer1 == -1) {
                nums1[cur--] = nums2[pointer2--];
            } else if(pointer2 == -1) {
                nums1[cur--] = nums1[pointer1--];
            } else if(nums1[pointer1] > nums2[pointer2]) {
                nums1[cur--] = nums1[pointer1--];
            } else {
                nums1[cur--] = nums2[pointer2--];
            }
        }
    }
};
