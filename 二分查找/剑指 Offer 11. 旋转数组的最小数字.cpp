/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。

示例 1：
输入：[3,4,5,1,2]
输出：1

示例 2：
输入：[2,2,2,0,1]
输出：0
*/


// 解法一：一次遍历
// 由于数组是 只存在一次断层的 递增，故如果从头遍历时，当前元素值>上一个元素值，即可断定当前元素为数组最小值
class Solution {
public:
    int minArray(vector<int>& numbers) {
        for (int i = 1; i < numbers.size(); i++) {
            if (numbers[i] < numbers[i-1]) {
                return numbers[i];
            }
        }
		  // 如果数组不存在断层，即完全递增，则数组的开始便是最小值
        return numbers[0];
    }
};
// 解法二：二分查找
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            // int m = (i + j) / 2;
            int m = i + (j - i) / 2;  // 较好的中位值取法
            if (numbers[m] > numbers[j]) i = m + 1;
            else if (numbers[m] < numbers[j]) j = m;
            else j--;
        }
        return numbers[i];
    }
};
