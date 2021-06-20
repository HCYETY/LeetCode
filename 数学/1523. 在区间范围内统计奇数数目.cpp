/*
���������Ǹ����� low �� high �����㷵�� low �� high ֮�䣨�������ߣ���������Ŀ��

ʾ�� 1��
���룺low = 3, high = 7
�����3
���ͣ�3 �� 7 ֮����������Ϊ [3,5,7] ��

ʾ�� 2��
���룺low = 8, high = 10
�����1
���ͣ�8 �� 10 ֮����������Ϊ [9] ��

��ʾ��
0 <= low <= high <= 10^9
*/


// һ��һ���ж�
class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        while(low <= high) {
            if(low % 2) {
                count++;
                low += 2;
            } else {
                low++;
            }
        }
        return count;
    }
};
// ��ż�ΰ룬���߽�
class Solution {
public:
    int countOdds(int low, int high) {
        int odd = high - low + 1;
        if(odd % 2) {
            if(high % 2) {
                return odd / 2 + 1;
            }
        }
        return odd / 2;
    }
};
