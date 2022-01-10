/*
����������С�ֱ�Ϊ m �� n �����򣨴�С�������� nums1 �� nums2��
�����ҳ���������������������� ��λ�� ��
�㷨��ʱ�临�Ӷ�Ӧ��Ϊ O(log (m+n)) ��

ʾ�� 1��
���룺nums1 = [1,3], nums2 = [2]
�����2.00000
���ͣ��ϲ����� = [1,2,3] ����λ�� 2

ʾ�� 2��
���룺nums1 = [1,2], nums2 = [3,4]
�����2.50000
���ͣ��ϲ����� = [1,2,3,4] ����λ�� (2 + 3) / 2 = 2.5

ʾ�� 3��
���룺nums1 = [0,0], nums2 = [0,0]
�����0.00000

ʾ�� 4��
���룺nums1 = [], nums2 = [1]
�����1.00000

ʾ�� 5��
���룺nums1 = [2], nums2 = []
�����2.00000

��ʾ��
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
