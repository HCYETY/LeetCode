/*
����һ���Ǹ����� num������������λ�ϵ�������ӣ�ֱ�����Ϊһλ����

ʾ��:
����: 38
���: 2
����: ��λ��ӵĹ���Ϊ��3 + 8 = 11, 1 + 1 = 2�� ���� 2 ��һλ�������Է��� 2��

����:
����Բ�ʹ��ѭ�����ߵݹ飬���� O(1) ʱ�临�Ӷ��ڽ�����������
*/


//�ݹ�
class Solution {
public:
    int addDigits(int num) {
        int ans = 0;
        while(num > 0) {
            ans += (num % 10);
            num /= 10;
        }
        if(ans > 9) return addDigits(ans);
        return ans;
    }
};

