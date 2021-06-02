/*
统计所有小于非负整数 n 的质数的数量。

示例 1：
输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

示例 2：
输入：n = 0
输出：0

示例 3：
输入：n = 1
输出：0

提示：
0 ≤ n ≤ 5 * 106
*/


// 方法一：枚举
class Solution {
public:
    bool isPrime(int x) {
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n) {
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            ans += isPrime(i);
        }
        return ans;
    }
};
// 方法二：埃氏筛
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        //初始默认所有数为质数
        vector<bool> sign(n, true);
        for (int i = 2; i < n; i++) {
            if (sign[i]) {
                count++;
                for (int j = i + i; j < n; j += i) {
                    //排除不是质数的数
                    sign[j] = false;
                }
            }
        }
        return count;
    }
};

