/*
�Գ��� ��ָ���Ա���������ÿһλ������������
���磬128 ��һ���Գ�������Ϊ 128 % 1 == 0��128 % 2 == 0��128 % 8 == 0��
���У��Գ������������ 0 ��

�����ϱ߽���±߽����֣����һ���б��б��Ԫ���Ǳ߽磨���߽磩�����е��Գ�����

ʾ�� 1��
���룺
�ϱ߽�left = 1, �±߽�right = 22
����� [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]

ע�⣺
ÿ����������ı߽�����?1 <= left <= right <= 10000��
ͨ������31,814�ύ����42,000
*/


class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector <int> ans;
        for(int i = left; i <= right; i++) {
				// ���� 10 �� 10 �ı���
            if(i % 10 == 0) continue;
            int temp = i;
            while(temp != 0) {
                // ע�⴦����0������
                if (temp % 10 == 0 || i % (temp % 10) != 0) break;
                temp /= 10;
            }
            if(temp == 0)
                ans.push_back(i);
        }
        return ans;
    }
};
