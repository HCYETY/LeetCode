/*
����һ������������ values������ values[i] ��ʾ�� i ���۹⾰������֣������������� i �� j ֮��� ���� Ϊ j - i��
һ�Ծ��㣨i < j����ɵĹ۹���ϵĵ÷�Ϊ values[i] + values[j] + i - j ��Ҳ���Ǿ��������֮�� ��ȥ ��������֮��ľ��롣
����һ�Թ۹⾰����ȡ�õ���߷֡�

ʾ�� 1��
���룺values = [8,1,5,2,6]
�����11
���ͣ�i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11

ʾ�� 2��
���룺values = [1,2]
�����2

��ʾ��
2 <= values.length <= 5 * 104
1 <= values[i] <= 1000
*/


class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, mx = values[0] + 0;
        for (int j = 1; j < values.size(); ++j) {
            // ���� mx �Ѿ��������±�ֵ��������ֻ��Ҫ��ȥ values[i] ���±�ֵ����
            ans = max(ans, mx + values[j] - j);
            // �߱�����ά��
            // ע�⣺����� j ����һ��ѭ���� j �Ѿ���һ����
            mx = max(mx, values[j] + j);
        }
        return ans;
    }
};
