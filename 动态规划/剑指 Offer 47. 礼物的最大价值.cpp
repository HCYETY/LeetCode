/*
��һ�� m*n �����̵�ÿһ�񶼷���һ�����ÿ�����ﶼ��һ���ļ�ֵ����ֵ���� 0����
����Դ����̵����Ͻǿ�ʼ�ø�����������ÿ�����һ��������ƶ�һ��ֱ���������̵����½ǡ�
����һ�����̼������������ļ�ֵ���������������õ����ټ�ֵ�����

ʾ�� 1:
����:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
���: 12
����: ·�� 1��3��5��2��1 �����õ�����ֵ������

��ʾ��
0 < grid.length <= 200
0 < grid[0].length <= 200
*/


// ˼·�����������ÿһ��Ԫ�أ���ͬ����/�е�Ԫ�ظ��ݲ�ͬ����������Ԫ��ֵ��
// �������У������Ԫ��Ϊǰ��Ԫ��ֵ�ĵ���
// �������У������Ԫ��Ϊǰ��Ԫ��ֵ�ĵ���
// ���������к��У������ҡ����ϵ��±�������ǰԪ��ֵΪ�����Ϸ�������������һ����ֵ+����ֵ
// �ⷨһ��
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if (i==0 && j==0) continue;
                else if (i==0) grid[i][j] += grid[i][j-1];
                else if (j==0) grid[i][j] += grid[i-1][j];
                else grid[i][j] = max(grid[i-1][j], grid[i][j-1]) + grid[i][j];
            }
        }
        return grid[row-1][col-1];
    }
};
// �ⷨһ���Ż����ȳ�ʼ���������е�ֵ�����⵱���鳤�ȹ���ʱÿ�ν��й����������е��ж�
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        for (int i = 1; i < col; i++)
            grid[0][i] += grid[0][i-1];
        for (int i = 1; i < row; i++)
            grid[i][0] += grid[i-1][0];
        for (int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                grid[i][j] += max(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[row-1][col-1];
    }
};
// �ⷨ��������չһ��һ���Խ���߽�����
// ��˵����һ��ʱ�ո��ӶȱȽⷨһ���󣬵�����߽������˼��������ս��
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector <vector<int>> dp(row+1, vector<int>(col+1,0) );
        for (int i = 1; i <= row; i++) {
            for (int j = 1;j <= col; j++) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
            }
         }
        return dp[row][col];
    }
};
