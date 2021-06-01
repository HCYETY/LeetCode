/*
������ʹ��һ��ľ�彨����ˮ�塣���������͵�ľ�壬���г��Ƚ϶̵�ľ�峤��Ϊshorter�����Ƚϳ���ľ�峤��Ϊlonger��
���������ʹ��k��ľ�塣��дһ��������������ˮ�����п��ܵĳ��ȡ�
���صĳ�����Ҫ��С�������С�

���룺
shorter = 1
longer = 2
k = 3
����� [3,4,5,6]
���ͣ�
����ʹ�� 3 �� shorter���õ���� 3��ʹ�� 2 �� shorter �� 1 �� longer���õ���� 4 ���Դ����ƣ��õ����ս����

��ʾ��
0 < shorter <= longer
0 <= k <= 100000
*/


class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if(k == 0) {
            return vector <int> ();
        }
        if(shorter == longer) {
            return vector <int> (1, shorter * k);
        }
        vector<int> ans(k + 1);
        for(int i = 0; i <= k; ++i) {
            ans[i] = shorter * (k - i) + longer * i;
        }
        return ans;
    }
};
