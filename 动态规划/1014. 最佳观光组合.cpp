/*
给你一个正整数数组 values，其中 values[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的 距离 为 j - i。
一对景点（i < j）组成的观光组合的得分为 values[i] + values[j] + i - j ，也就是景点的评分之和 减去 它们两者之间的距离。
返回一对观光景点能取得的最高分。

示例 1：
输入：values = [8,1,5,2,6]
输出：11
解释：i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11

示例 2：
输入：values = [1,2]
输出：2

提示：
2 <= values.length <= 5 * 104
1 <= values[i] <= 1000
*/


class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, mx = values[0] + 0;
        for (int j = 1; j < values.size(); ++j) {
            // 由于 mx 已经加上了下标值，故这里只需要减去 values[i] 的下标值即可
            ans = max(ans, mx + values[j] - j);
            // 边遍历边维护
            // 注意：这里的 j 和下一次循环的 j 已经不一样了
            mx = max(mx, values[j] + j);
        }
        return ans;
    }
};
