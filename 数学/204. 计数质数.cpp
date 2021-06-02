/*
ͳ������С�ڷǸ����� n ��������������

ʾ�� 1��
���룺n = 10
�����4
���ͣ�С�� 10 ������һ���� 4 ��, ������ 2, 3, 5, 7 ��

ʾ�� 2��
���룺n = 0
�����0

ʾ�� 3��
���룺n = 1
�����0

��ʾ��
0 �� n �� 5 * 106
*/


// ����һ��ö��
class Solution {
public:
    bool isPrime(int x) {
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n) {
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            ans += isPrime(i);
        }
        return ans;
    }
};
// ������������ɸ
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        //��ʼĬ��������Ϊ����
        vector<bool> sign(n, true);
        for (int i = 2; i < n; i++) {
            if (sign[i]) {
                count++;
                for (int j = i + i; j < n; j += i) {
                    //�ų�������������
                    sign[j] = false;
                }
            }
        }
        return count;
    }
};

