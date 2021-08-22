/*
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

示例 1:
输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物

提示：
0 < grid.length <= 200
0 < grid[0].length <= 200
*/


// 思路：遍历数组的每一个元素，不同的行/列的元素根据不同的条件更新元素值：
// 对于首行，后面的元素为前面元素值的叠加
// 对于首列，后面的元素为前面元素值的叠加
// 对于其他行和列，从左到右、从上到下遍历，当前元素值为其正上方或正左方最大的那一个的值+本身值
// 解法一：
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
// 解法一的优化：先初始化首行首列的值，避免当数组长度过大时每次进行关于首行首列的判断
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
// 解法二：多扩展一行一列以解决边界问题
// 虽说这样一来时空复杂度比解法一更大，但解决边界问题的思想可以吸收借鉴
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
