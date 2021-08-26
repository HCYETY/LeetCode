/*
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ����������������һ����ת�������ת�������СԪ�ء�
���磬���� [3,4,5,1,2] Ϊ [1,2,3,4,5] ��һ����ת�����������СֵΪ1��

ʾ�� 1��
���룺[3,4,5,1,2]
�����1

ʾ�� 2��
���룺[2,2,2,0,1]
�����0
*/


// �ⷨһ��һ�α���
// ���������� ֻ����һ�ζϲ�� �������������ͷ����ʱ����ǰԪ��ֵ>��һ��Ԫ��ֵ�����ɶ϶���ǰԪ��Ϊ������Сֵ
class Solution {
public:
    int minArray(vector<int>& numbers) {
        for (int i = 1; i < numbers.size(); i++) {
            if (numbers[i] < numbers[i-1]) {
                return numbers[i];
            }
        }
		  // ������鲻���ڶϲ㣬����ȫ������������Ŀ�ʼ������Сֵ
        return numbers[0];
    }
};
// �ⷨ�������ֲ���
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            // int m = (i + j) / 2;
            int m = i + (j - i) / 2;  // �Ϻõ���λֵȡ��
            if (numbers[m] > numbers[j]) i = m + 1;
            else if (numbers[m] < numbers[j]) j = m;
            else j--;
        }
        return numbers[i];
    }
};
