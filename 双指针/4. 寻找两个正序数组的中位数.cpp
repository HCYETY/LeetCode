/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
请你找出并返回这两个正序数组的 中位数 。
算法的时间复杂度应该为 O(log (m+n)) 。

示例 1：
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2

示例 2：
输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5

示例 3：
输入：nums1 = [0,0], nums2 = [0,0]
输出：0.00000

示例 4：
输入：nums1 = [], nums2 = [1]
输出：1.00000

示例 5：
输入：nums1 = [2], nums2 = []
输出：2.00000

提示：
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        double ans = 0;
        int left = 0, right = 0, i = 0;
        vector<int> stk(m + n);
        while (left < m && right < n) {
            if (nums1[left] < nums2[right]) {
                stk[i++] = nums1[left++];
            } else {
                stk[i++] = nums2[right++];
            }
        }
        while (left < m) {
            stk[i++] = nums1[left++];
        }
        while (right < n) {
            stk[i++] = nums2[right++];
        }

        int middle = (m + n) / 2;
        if ((m + n) % 2 == 0) {
            ans = ((double)stk[middle] + (double)stk[middle - 1]) / 2;
        } else {
            ans = (double)stk[middle];
        }
        return ans;
    }
};
