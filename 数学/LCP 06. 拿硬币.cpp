/*
桌上有 n 堆力扣币，每堆的数量保存在数组 coins 中。我们每次可以选择任意一堆，拿走其中的一枚或者两枚，求拿完所有力扣币的最少次数。

示例 1：
输入：[4,2,1]
输出：4
解释：第一堆力扣币最少需要拿 2 次，第二堆最少需要拿 1 次，第三堆最少需要拿 1 次，总共 4 次即可拿完。

示例 2：
输入：[2,3,10]
输出：8

限制：
1 <= n <= 4
1 <= coins[i] <= 10
*/

// 优化前：老实减去2（因为要求最少次数，故每次都拿最多数量的力扣币）
class Solution {
public:
    int minCount(vector<int>& coins) {
        int count = 0;
        for(int value : coins) {
            while(value > 0) {
                count++;
                value -= 2;
            }
        }
        return count;
    }
};
// 优化后：由数学常识易得
class Solution {
public:
    int minCount(vector<int>& coins) {
        int count = 0;
        for(int value : coins) {
            int num = value / 2;
            if(value % 2 == 0)
                count += num;
            if(value % 2 != 0)
                count += (num + 1);
        }
        return count;
    }
};
