/*
回旋镖定义为一组三个点，这些点各不相同且不在一条直线上。
给出平面上三个点组成的列表，判断这些点是否可以构成回旋镖。

示例 1：
输入：[[1,1],[2,3],[3,2]]
输出：true

示例 2：
输入：[[1,1],[2,2],[3,3]]
输出：false

提示：
points.length == 3
points[i].length == 2
0 <= points[i][j] <= 100
*/


// 思路：
// 判断三点是否同直线，直接思路就是判断斜率，斜率相同则三点共线。
// 假设三点分别为a(x1, y1), b(x2, y2), c(x3,y3)，三个点之间连成两条线，则
// a、b两点的斜率为 slope1 = (y2 - y1) / (x2 - x1)
// a、c两点的斜率为 slope2 = (y3 - y1) / (x3 - x1)
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
		// 以下是为了判断分母为 0 的情况，但失败了
	      // int k1 = 0, k2 = 0, k3 = 0;
	      // if(points[0][0] == 0) k1 = 1;
	      // else k1 = points[0][1] / points[0][0];
	      
	      // if(points[1][0] == 0) k2 = 1;
	      // else k2 = points[1][1] / points[1][0];
	      
	      // if(points[2][0] == 0) k3 = 1;
	      // else k3 = points[2][1] / points[2][0];
	      
	      // if(k1 == k2 && k1 == k2 && k2 == k3) return false;
	      // return true;
		//	正确的做法：交叉相乘
			// 将 slope1 == slope2 ，就可以进行交叉相乘
			// 这里将交叉相乘的结果单独定义
         int k1 = (points[1][1] - points[0][1]) * (points[2][0] - points[0][0]);
         int k2 = (points[2][1] - points[0][1]) * (points[1][0] - points[0][0]);
         return k1 != k2;
    }
};
