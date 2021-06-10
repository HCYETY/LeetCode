/*
������������������ A �� B������ A ��ĩ�����㹻�Ļ���ռ����� B��
��дһ���������� B �ϲ��� A �����򡣳�ʼ�� A �� B ��Ԫ�������ֱ�Ϊ m �� n��

ʾ��:
����:
A = [1,2,3,0,0,0], m = 3
B = [2,5,6],       n = 3
���: [1,2,2,3,5,6]

˵��:
A.length == n + m
*/


class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int pa = m - 1, pb = n - 1;
        int tail = m + n - 1;
        int cur;
        while(pa >= 0 || pb >= 0) {
            if(pa == -1)
                cur = B[pb--];
            else if(pb == -1)
                cur = A[pa--];
            else if(A[pa] > B[pb])
                cur = A[pa--];
            else
                cur = B[pb--];
            A[tail--] = cur;
        }
    }
};
