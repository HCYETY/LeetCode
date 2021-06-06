/*
编写一个算法来判断一个数 n 是不是快乐数。

快乐数」定义为：
对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果 可以变为 1，那么这个数就是快乐数。

如果 n 是快乐数就返回 true ；不是，则返回 false 。

示例 1：
输入：19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

示例 2：
输入：n = 2
输出：false

提示：
1 <= n <= 231 - 1
*/


// 解法1：unordered_set
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> record;
		  // count(key)	在容器中查找值为 key 的元素的个数。
        while(n != 1 && !record.count(n)) {
				// insert()	向容器中添加新元素。
            record.insert(n);
            n = judge(n);
        }
        return n == 1;
    }
    int judge(int n) {
        int sum = 0;
        while(n) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
};
// 解法2： 利用快慢指针
class Solution {
public:
    bool isHappy(int n) {
		  // 快指针先走一步
        int slow = n, fast = judge(n);
        while(fast != 1 && slow != fast) {
            // 慢指针步长为一，快指针步长为二
            slow = judge(slow);
            fast = judge(judge(fast));
        }
        return fast == 1;

    }
    int judge(int n) {
        int sum = 0;
        while(n > 0) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
};
