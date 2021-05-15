����һ������ rectangles ������ rectangles[i] = [li, wi] ��ʾ�� i �����εĳ���Ϊ li �����Ϊ wi ��
������� k ͬʱ���� k <= li �� k <= wi ���Ϳ��Խ��� i �������гɱ߳�Ϊ k �������Ρ����磬���� [4,6] �����гɱ߳����Ϊ 4 �������Ρ�
�� maxLen Ϊ���ԴӾ�������rectangles �зֵõ��� ��������� �ı߳���
����ͳ���ж��ٸ������ܹ��г��߳�Ϊ maxLen �������Σ������ؾ��� ��Ŀ ��

ʾ�� 1��
���룺rectangles = [[5,8],[3,9],[5,12],[16,5]]
�����3
���ͣ��ܴ�ÿ���������г�����������α߳��ֱ��� [5,3,5,5] ��
��������εı߳�Ϊ 5 �������� 3 �������зֵõ���

ʾ�� 2��
���룺rectangles = [[2,3],[3,7],[4,3],[3,7]]
�����3


class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int max_len = 0, sum = 0;
        for(int i = 0; i < rectangles.size(); i++) {
            int big = min(rectangles[i][0], rectangles[i][1]);
            if(big > max_len) {
                max_len = big;
                sum = 1;
            } else if(big == max_len) {
                sum++;
            }
        }
        return sum;
    }
};
