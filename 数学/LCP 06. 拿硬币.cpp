/*
������ n �����۱ң�ÿ�ѵ��������������� coins �С�����ÿ�ο���ѡ������һ�ѣ��������е�һö������ö���������������۱ҵ����ٴ�����

ʾ�� 1��
���룺[4,2,1]
�����4
���ͣ���һ�����۱�������Ҫ�� 2 �Σ��ڶ���������Ҫ�� 1 �Σ�������������Ҫ�� 1 �Σ��ܹ� 4 �μ������ꡣ

ʾ�� 2��
���룺[2,3,10]
�����8

���ƣ�
1 <= n <= 4
1 <= coins[i] <= 10
*/

// �Ż�ǰ����ʵ��ȥ2����ΪҪ�����ٴ�������ÿ�ζ���������������۱ң�
class Solution {
public:
    int minCount(vector<int>& coins) {
        int count = 0;
        for(int value : coins) {
            while(value > 0) {
                count++;
                value -= 2;
            }
        }
        return count;
    }
};
// �Ż�������ѧ��ʶ�׵�
class Solution {
public:
    int minCount(vector<int>& coins) {
        int count = 0;
        for(int value : coins) {
            int num = value / 2;
            if(value % 2 == 0)
                count += num;
            if(value % 2 != 0)
                count += (num + 1);
        }
        return count;
    }
};
