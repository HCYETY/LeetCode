/*
�������� n����˳���ӡ���� 1 ������ n λʮ���������������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999��

ʾ�� 1:
����: n = 1
���: [1,2,3,4,5,6,7,8,9]

˵����
�÷���һ�������б��������ӡ
n Ϊ������
*/


class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> numArray;
        int allNum = pow(10, n);
        for(int i = 1; i < allNum; i++) {
            numArray.push_back(i);
        }
        return numArray;
    }
};
