/*
����һ������ nums����������ÿ��Ԫ�� nums[i]������ͳ�������б���С���������ֵ���Ŀ��
������֮������ÿ�� nums[i] �����������Ч�� j ������������ j ���� j != i �� nums[j] < nums[i] ��
��������ʽ���ش𰸡�

ʾ�� 1��
���룺nums = [8,1,2,2,3]
�����[4,0,1,1,3]
���ͣ�
���� nums[0]=8 �����ĸ�����С�����֣���1��2��2 �� 3����
���� nums[1]=1 �����ڱ���С�����֡�
���� nums[2]=2 ����һ������С�����֣���1����
���� nums[3]=2 ����һ������С�����֣���1����
���� nums[4]=3 ������������С�����֣���1��2 �� 2����

ʾ�� 2��
���룺nums = [6,5,4,8]
�����[2,1,0,3]

ʾ�� 3��
���룺nums = [7,7,7,7]
�����[0,0,0,0]

��ʾ��
2 <= nums.length <= 500
0 <= nums[i] <= 100
*/


class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> cnt(101, 0);
        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
        }
        for (int i = 1; i <= 100; i++) {
            cnt[i] += cnt[i - 1];
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            res.push_back(nums[i] == 0 ? 0: cnt[nums[i]-1]);
        }
        return res;
    }
};
