����һ���������� nums ��
���һ������ (i,j) ���� nums[i] == nums[j] �� i < j ���Ϳ�����Ϊ����һ�� ������ ��
���غ����Ե���Ŀ��

ʾ�� 1��
���룺nums = [1,2,3,1,1,3]
�����4
���ͣ��� 4 ������ԣ��ֱ��� (0,3), (0,4), (3,4), (2,5) ���±�� 0 ��ʼ

ʾ�� 2��
���룺nums = [1,1,1,1]
�����6
���ͣ������е�ÿ�����ֶ��Ǻ�����

ʾ�� 3��
���룺nums = [1,2,3]
�����0


class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int hash[101] = {0};
        // memset(hash, 0, sizeof(int)*101);
        for (int value: nums)
            hash[value]++;
        int num = 0;
        for (int i = 1; i <= 100; ++i)
            num += hash[i] * (hash[i] - 1) / 2;
        return num;
    }
};
