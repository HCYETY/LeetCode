给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。

示例 1：
输入：x = 121
输出：true

示例 2：
输入：x = -121
输出：false
解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

示例 3：
输入：x = 10
输出：false
解释：从右向左读, 为 01 。因此它不是一个回文数。

示例 4：
输入：x = -101
输出：false


class Solution {
public:
    bool isPalindrome(int x) {
//    	如果x为负数或者个位数是0（0除外），那么这些数都不是回文数
        if(x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int revertedNumber = 0;
//        反转数字只需处理到原始数字位数的一半。而当原始数字小于或等于反转后的数字时，就意味着我们已经处理了一半位数的数字了。
        while(x > revertedNumber) {
//        	得到反转后的数字
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
//         当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
//         例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
//         由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
        return x == revertedNumber || x == revertedNumber  / 10;
    }
};
