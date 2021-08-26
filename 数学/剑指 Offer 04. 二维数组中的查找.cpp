/*
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

示例:
现有矩阵 matrix 如下：
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。
给定 target = 20，返回 false。

限制：
0 <= n <= 1000
0 <= m <= 1000
*/


// 思路：
// 从矩阵右上角开始遍历，对每个元素进行判断
// 1. 如果当前元素==目标值，直接返回
// 2. 如果当前元素>目标值，则列数-1，因为每一行都按照从左到右递增的顺序排序
// 3. 如果当前元素<目标值，则行数+1，因为每一列都按照从上到下递增的顺序排序
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
// 另一种思路：从矩阵左下角开始遍历
// 无法理解，明明差不多的思路，当测试样例为空数组时，这个解法如果不在首行加个判断可以过，解法一却得加个判断
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
