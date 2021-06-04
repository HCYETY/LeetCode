/*
����һ������ n�������æ���㲢���ظ���������λ����֮�����롸��λ����֮�͡��Ĳ

ʾ�� 1��
���룺n = 234
�����15
���ͣ�
��λ��֮�� = 2 * 3 * 4 = 24
��λ��֮�� = 2 + 3 + 4 = 9
��� = 24 - 9 = 15

ʾ�� 2��
���룺n = 4421
�����21
���ͣ�
��λ��֮�� = 4 * 4 * 2 * 1 = 32
��λ��֮�� = 4 + 4 + 2 + 1 = 11
��� = 32 - 11 = 21

��ʾ��
1 <= n <= 10^5
*/


class Solution {
public:
    int subtractProductAndSum(int n) {
        int multiply = 1, increment = 0;
        while(n != 0) {
            multiply *= (n % 10);
            increment += (n % 10);
            n /= 10;
        }
        return multiply - increment;
    }
};
