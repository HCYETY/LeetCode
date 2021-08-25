/*
����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ����������λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�

ʾ����
���룺nums = [1,2,3,4]
�����[1,3,2,4]
ע��[3,1,2,4] Ҳ����ȷ�Ĵ�֮һ��

��ʾ��
0 <= nums.length <= 50000
1 <= nums[i] <= 10000
*/


class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int len = nums.size(), left = 0, right = len - 1;
        while (left <= right) {
            if (nums[left] % 2 == 0 && nums[right] % 2 != 0) {
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            } else if (nums[left] % 2 != 0){
                left++;
            } else if (nums[right] % 2 == 0) {
                right--;
            }
        }
        return nums;
    }
};
