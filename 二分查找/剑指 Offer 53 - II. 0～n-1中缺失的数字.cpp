/*
һ������Ϊn-1�ĵ������������е��������ֶ���Ψһ�ģ�����ÿ�����ֶ��ڷ�Χ0��n-1֮�ڡ�
�ڷ�Χ0��n-1�ڵ�n������������ֻ��һ�����ֲ��ڸ������У����ҳ�������֡�

ʾ�� 1:
����: [0,1,3]
���: 2

ʾ�� 2:
����: [0,1,2,3,4,5,6,7,9]
���: 8

���ƣ�
1 <= ���鳤�� <= 10000
*/


// �ⷨһ�����Բ���
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return len;
    }
};
// �ⷨ�������ֲ���
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
