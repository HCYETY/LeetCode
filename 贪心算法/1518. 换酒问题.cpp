С�����������ڴ������� numExchange ���վ�ƿ���Զһ�һƿ�¾ơ��㹺���� numBottles ƿ�ơ�

����ȵ��˾�ƿ�еľƣ���ô��ƿ�ͻ��ɿյġ�

������� ��� �ܺȵ�����ƿ�ơ�

���룺numBottles = 9, numExchange = 3
�����13
���ͣ�������� 3 ���վ�ƿ�һ� 1 ƿ�ơ�
��������ܺȵ� 9 + 3 + 1 = 13 ƿ�ơ�

���룺numBottles = 15, numExchange = 4
�����19
���ͣ�������� 4 ���վ�ƿ�һ� 1 ƿ�ơ�
��������ܺȵ� 15 + 3 + 1 = 19 ƿ�ơ�
ʾ�� 3��

���룺numBottles = 5, numExchange = 5
�����6
ʾ�� 4��

���룺numBottles = 2, numExchange = 3
�����2


class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count=0, kong=0;
        for(int i=0; i<numBottles; i++) {
            count++;
            kong++;
            if(kong % numExchange == 0) {
                kong = 0;
                count++;
                kong++;
            }
        }
        return count;
    }
};
