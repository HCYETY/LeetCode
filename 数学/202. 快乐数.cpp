/*
��дһ���㷨���ж�һ���� n �ǲ��ǿ�������

������������Ϊ��
����һ����������ÿһ�ν������滻Ϊ��ÿ��λ���ϵ����ֵ�ƽ���͡�
Ȼ���ظ��������ֱ���������Ϊ 1��Ҳ������ ����ѭ�� ��ʼ�ձ䲻�� 1��
��� ���Ա�Ϊ 1����ô��������ǿ�������

��� n �ǿ������ͷ��� true �����ǣ��򷵻� false ��

ʾ�� 1��
���룺19
�����true
���ͣ�
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

ʾ�� 2��
���룺n = 2
�����false

��ʾ��
1 <= n <= 231 - 1
*/


// �ⷨ1��unordered_set
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> record;
		  // count(key)	�������в���ֵΪ key ��Ԫ�صĸ�����
        while(n != 1 && !record.count(n)) {
				// insert()	�������������Ԫ�ء�
            record.insert(n);
            n = judge(n);
        }
        return n == 1;
    }
    int judge(int n) {
        int sum = 0;
        while(n) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
};
// �ⷨ2�� ���ÿ���ָ��
class Solution {
public:
    bool isHappy(int n) {
		  // ��ָ������һ��
        int slow = n, fast = judge(n);
        while(fast != 1 && slow != fast) {
            // ��ָ�벽��Ϊһ����ָ�벽��Ϊ��
            slow = judge(slow);
            fast = judge(judge(fast));
        }
        return fast == 1;

    }
    int judge(int n) {
        int sum = 0;
        while(n > 0) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
};
