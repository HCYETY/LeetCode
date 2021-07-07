/*
给你两个 非递增 的整数数组 nums1 和 nums2 ，数组下标均 从 0 开始 计数。
下标对 (i, j) 中 0 <= i < nums1.length 且 0 <= j < nums2.length 。
如果该下标对同时满足 i <= j 且 nums1[i] <= nums2[j] ，则称之为 有效 下标对，该下标对的 距离 为 j - i 。
返回所有 有效 下标对 (i, j) 中的 最大距离 。如果不存在有效下标对，返回 0 。

一个数组 arr ，如果每个 1 <= i < arr.length 均有 arr[i-1] >= arr[i] 成立，那么该数组是一个 非递增 数组。

示例 1：
输入：nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
输出：2
解释：有效下标对是 (0,0), (2,2), (2,3), (2,4), (3,3), (3,4) 和 (4,4) 。
最大距离是 2 ，对应下标对 (2,4) 。

示例 2：
输入：nums1 = [2,2,2], nums2 = [10,10,1]
输出：1
解释：有效下标对是 (0,0), (0,1) 和 (1,1) 。
最大距离是 1 ，对应下标对 (0,1) 。

示例 3：
输入：nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]
输出：2
解释：有效下标对是 (2,2), (2,3), (2,4), (3,3) 和 (3,4) 。
最大距离是 2 ，对应下标对 (2,4) 。

示例 4：
输入：nums1 = [5,4], nums2 = [3,2]
输出：0
解释：不存在有效下标对，所以返回 0 。

提示：
1 <= nums1.length <= 105
1 <= nums2.length <= 105
1 <= nums1[i], nums2[j] <= 105
nums1 和 nums2 都是 非递增 数组
*/


// 双指针法
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int res = 0;
        // 每次循环 j 都要 + 1
        for(int j = 0; j < n2; ++j) {
            // 有两种情况：
            // ①如果当前nums1[i] <= nums2[j]，符合条件之一，i原地不动，看看nums2后面的元素会不会比当前的nums1[i]大。如果发现某个nums2[j]比当前的nums1[i]小，就进入循环判断
            // ②如果当前nums1[i] > nums2[j]，不满足条件，则需要i++。由于跳出while循环后由于有max()，所以不用担心 i > j 导致有效下标对的距离为负数的情况，只是这里不够优化，在 i>j 的时候 res 会保持不变。直到i <= j后才可能会出现新的变化。
            while (i < n1 && nums1[i] > nums2[j]){
                ++i;
            }
            if (i < n1){
                res = max(res, j - i);
            }
        }
        return res;
    }
};
// 和上面那种解法差不多
class Solution {
    public int maxDistance(int[] nums1, int[] nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int L = 0;
        int R = 0;
        while (L < len1 && R < len2) {
            if (nums1[L] > nums2[R]) {
                L++;
            }
            R++;
        }
        return R - L - 1 >= 0 ? R - L - 1 : 0;
    }
}

// 二分查找
class Solution {
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    int Max = 0;//不存在为0
    //在nums2中找最小的大于等于nums1[i]的值的下标（下标大于等于i）
    for(int i = 0; i < n1; ++i) {
        int l = i;
        int r = n2 - 1; //左闭右闭
        int ansi = -1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (nums2[mid] < nums1[i]) { //太小,找大数
                r = mid - 1;
            }
            else { //mid可行，查找是否有更小的mid
                ansi = mid;
                l = mid + 1;
            }
        }
        if (ansi != -1)
            Max = max(Max, abs(i - ansi));
    }
    return Max;
}
};

