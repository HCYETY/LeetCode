/*
�������������������� nums1 �� nums2�����㽫 nums2 �ϲ��� nums1 �У�ʹ nums1 ��Ϊһ���������顣
��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n ������Լ��� nums1 �Ŀռ��С���� m + n�������������㹻�Ŀռ䱣������ nums2 ��Ԫ�ء�

ʾ�� 1��
���룺nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
�����[1,2,2,3,5,6]

ʾ�� 2��
���룺nums1 = [1], m = 1, nums2 = [], n = 0
�����[1]

��ʾ��
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[i] <= 109
*/

//���㷨�ռ��Ͽɽ�һ���Ż�����Ϊ�½���һ������
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ans[m + n];
        int pointer1 = 0, pointer2 = 0;
        while(pointer1 < m || pointer2 < n) {
				// ����nums1�Ŀռ���m + n����������ʱ�����Ŀռ��С��m
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
//�Ż�����㷨��ֱ����nums1�����Ͻ�������
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
