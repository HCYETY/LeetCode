/*
����nums������0��n������������������ȱ��һ����
���д�����ҳ��Ǹ�ȱʧ�����������а취��O(n)ʱ���������

ע�⣺�����������ԭ�������Ķ�

ʾ�� 1��
���룺[3,0,1]
�����2

ʾ�� 2��
���룺[9,6,4,2,3,5,7,0,1]
�����8
*/

//���
//˼·���Ȳ�������ͣ��úͼ�ȥnums�����ÿ��Ԫ�أ�ʣ�µ�ֵ����ȱʧ��ֵ
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int length = nums.size();
        int sum = (0 + length) * (length + 1) / 2;
        for(int i = 0; i < length; i++) {
            sum -= nums[i];
        }
        return sum;
    }
};
//λ�������

