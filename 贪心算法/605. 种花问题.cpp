������һ���ܳ��Ļ�̳��һ���ֵؿ���ֲ�˻�����һ����ȴû�С����ǣ���������ֲ�����ڵĵؿ��ϣ����ǻ�����ˮԴ�����߶�����ȥ��

����һ����������??flowerbed ��ʾ��̳�������� 0 �� 1 ��ɣ����� 0 ��ʾû��ֲ����1 ��ʾ��ֲ�˻�������һ����?n ���ܷ��ڲ�������ֲ��������������?n?�仨�����򷵻� true �������򷵻� false��

?

ʾ�� 1��

���룺flowerbed = [1,0,0,0,1], n = 1
�����true
ʾ�� 2��

���룺flowerbed = [1,0,0,0,1], n = 2
�����false


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0; i<flowerbed.size(); i+=2) {
            if(flowerbed[i]==0) {
                if(i==flowerbed.size()-1 || flowerbed[i+1]==0) {
                    n--;
                } else {
                    i++;
                }
            }
        }
        return n<=0;
    }
};
