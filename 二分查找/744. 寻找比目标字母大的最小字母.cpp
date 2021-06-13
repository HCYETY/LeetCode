/*
给你一个排序后的字符列表 letters ，列表中只包含小写英文字母。
另给出一个目标字母 target，请你寻找在这一有序列表里比目标字母大的最小字母。
在比较时，字母是依序循环出现的。举个例子：
如果目标字母 target = 'z' 并且字符列表为 letters = ['a', 'b']，则答案返回 'a'

示例：
输入:
letters = ["c", "f", "j"]
target = "a"
输出: "c"

输入:
letters = ["c", "f", "j"]
target = "c"
输出: "f"

输入:
letters = ["c", "f", "j"]
target = "d"
输出: "f"

输入:
letters = ["c", "f", "j"]
target = "g"
输出: "j"

输入:
letters = ["c", "f", "j"]
target = "j"
输出: "c"

输入:
letters = ["c", "f", "j"]
target = "k"
输出: "c"

提示：
letters长度范围在[2, 10000]区间内。
letters 仅由小写字母组成，最少包含两个不同的字母。
目标字母target 是一个小写字母。
*/


// 线性扫描：
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (char c: letters)
            if (c > target) return c;
        return letters[0];
    }
};
// 二分查找：
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
		  int len = letters.size();
        int left = 0, right = len;
        while(left < right) {
            int mid = (right - left) / 2 + left;
            if(letters[mid] <= target) left = mid + 1;
            else right = mid;
        }
        return letters[left % len];
    }
};
// 记录存在的字母：
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int seen[27] = {0};
        for(char c: letters)
            seen[c - 'a'] = 1;
        while (true) {
            target++;
            if (target > 'z') target = 'a';
            if (seen[target - 'a'] == 1) return target;
        }
    }
};
