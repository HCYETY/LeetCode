/*
�����������飬��дһ���������������ǵĽ�����

ʾ�� 1��
���룺nums1 = [1,2,2,1], nums2 = [2,2]
�����[2,2]

ʾ�� 2:
���룺nums1 = [4,9,5], nums2 = [9,4,9,8,4]
�����[4,9]

˵����
��������ÿ��Ԫ�س��ֵĴ�����Ӧ��Ԫ�������������г��ִ�������Сֵһ�¡�
���ǿ��Բ�������������˳��

���ף�
��������������Ѿ��ź����أ��㽫����Ż�����㷨��
��� nums1 �Ĵ�С�� nums2 С�ܶ࣬���ַ������ţ�
��� nums2 ��Ԫ�ش洢�ڴ����ϣ��ڴ������޵ģ������㲻��һ�μ������е�Ԫ�ص��ڴ��У������ô�죿
*/


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int left = 0, right = 0;
        while(left < nums1.size() && right < nums2.size()) {
            if(nums1[left] == nums2[right]) {
                ans.push_back(nums1[left]);
                left++;
                right++;
            } else if(nums1[left] < nums2[right]) {
                left++;
            } else {
                right++;
            }
        }
        return ans;
    }
};
