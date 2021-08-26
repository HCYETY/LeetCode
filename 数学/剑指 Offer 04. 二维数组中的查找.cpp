/*
��һ�� n * m �Ķ�ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
�����һ����Ч�ĺ���������������һ����ά�����һ���������ж��������Ƿ��и�������

ʾ��:
���о��� matrix ���£�
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
���� target = 5������ true��
���� target = 20������ false��

���ƣ�
0 <= n <= 1000
0 <= m <= 1000
*/


// ˼·��
// �Ӿ������Ͻǿ�ʼ��������ÿ��Ԫ�ؽ����ж�
// 1. �����ǰԪ��==Ŀ��ֵ��ֱ�ӷ���
// 2. �����ǰԪ��>Ŀ��ֵ��������-1����Ϊÿһ�ж����մ����ҵ�����˳������
// 3. �����ǰԪ��<Ŀ��ֵ��������+1����Ϊÿһ�ж����մ��ϵ��µ�����˳������
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int row = 0, col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0) {
            int num = matrix[row][col];
            if (num == target) return true;
				else if (num > target) col--;
            else  row++;
        }
        return false;
    }
};
// ��һ��˼·���Ӿ������½ǿ�ʼ����
// �޷���⣬��������˼·������������Ϊ������ʱ������ⷨ����������мӸ��жϿ��Թ����ⷨһȴ�üӸ��ж�
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
         int i = matrix.size() - 1, j = 0;
         while (i >= 0 && j < matrix[0].size()) {
             if (matrix[i][j] > target) i--;
             else if (matrix[i][j] < target) j++;
             else return true;
         }
         return false;
    }
};
