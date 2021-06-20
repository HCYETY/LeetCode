/*
给你两个非负整数 low 和 high 。请你返回 low 和 high 之间（包括二者）奇数的数目。

示例 1：
输入：low = 3, high = 7
输出：3
解释：3 到 7 之间奇数数字为 [3,5,7] 。

示例 2：
输入：low = 8, high = 10
输出：1
解释：8 到 10 之间奇数数字为 [9] 。

提示：
0 <= low <= high <= 10^9
*/


// 一个一个判断
class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        while(low <= high) {
            if(low % 2) {
                count++;
                low += 2;
            } else {
                low++;
            }
        }
        return count;
    }
};
// 奇偶参半，看边界
class Solution {
public:
    int countOdds(int low, int high) {
        int odd = high - low + 1;
        if(odd % 2) {
            if(high % 2) {
                return odd / 2 + 1;
            }
        }
        return odd / 2;
    }
};
