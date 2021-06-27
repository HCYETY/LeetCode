/*
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。
 
示例 1：
输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。

示例 2：
输入：digits = [4,3,2,1]
输出：[4,3,2,2]
解释：输入数组表示数字 4321。

示例 3：
输入：digits = [0]
输出：[1]

提示：
1 <= digits.length <= 100
0 <= digits[i] <= 9
*/


/**
 * @param {number[]} digits
 * @return {number[]}
 */
 var plusOne = function(digits) {
    const len = digits.length;
    // 处理最高位 < 9 ，所有或个别低位 + 1 的情况，即不需要增加新的位数
    for(let i = len - 1; i >= 0; i--) {
        digits[i]++;
        digits[i] %= 10;
        if(digits[i]!=0)
            return digits;
    }
    // 处理所有位数（包括最高位）在 + 1 后都需进位的情况，即需要扩增新的最高位数
        // _=>0 是Lambda表达式，在这里的作用是把整个数组所有元素的值置为0.
    digits = [...Array(len + 1)].map(_=>0);
        // [1, 2, 3].map(_ => 0) // [0, 0, 0]
        // 等价于
        // [1, 2, 3].map(item => {
        //   return 0
        // })
    digits[0] = 1;
    return digits;
}; 