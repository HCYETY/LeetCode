/*
�����������飬��дһ���������������ǵĽ�����

ʾ�� 1��
���룺nums1 = [1,2,2,1], nums2 = [2,2]
�����[2]

ʾ�� 2��
���룺nums1 = [4,9,5], nums2 = [9,4,9,8,4]
�����[9,4]

˵����
�������е�ÿ��Ԫ��һ����Ψһ�ġ�
���ǿ��Բ�������������˳��
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int length1 = nums1.size(), length2 = nums2.size();
        int index1 = 0, index2 = 0;
        vector<int> intersection;
        while (index1 < length1 && index2 < length2) {
            int num1 = nums1[index1], num2 = nums2[index2];
            if (num1 == num2) {
                // ��֤����Ԫ�ص�Ψһ��
                if (!intersection.size() || num1 != intersection.back()) {
                    intersection.push_back(num1);
                }
                index1++;
                index2++;
            } else if (num1 < num2) {
                index1++;
            } else {
                index2++;
            }
        }
        return intersection;
    }
};
