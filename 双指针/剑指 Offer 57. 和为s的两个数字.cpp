/*
����һ����������������һ������s���������в�����������ʹ�����ǵĺ�������s��
����ж�����ֵĺ͵���s�����������һ�Լ��ɡ�

ʾ�� 1��
���룺nums = [2,7,11,15], target = 9
�����[2,7] ���� [7,2]

ʾ�� 2��
���룺nums = [10,26,30,31,47,60], target = 40
�����[10,30] ���� [30,10]

���ƣ�
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (target > sum) {
                left++;
            } else if (target < sum) {
                right--;
            } else {
                return {nums[left], nums[right]};
            }
        }
        return {};
    }
};
