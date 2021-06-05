/*
给定一个Excel表格中的列名称，返回其相应的列序号。

例如，
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
    ...
    
示例 1:
输入: "A"
输出: 1

示例 2:
输入: "AB"
输出: 28

示例 3:
输入: "ZY"
输出: 701

示例4：
输入: "FXD"
输出: 4684
*/


class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for(int i = 0; i < columnTitle.size(); i++) {
				// C++中字母转为ASCII码：(int)a
				// C++中ASCII码转为字母：(char)a
            int num = (int)columnTitle[i] - 64;
            ans = ans * 26 + num;
        }
        return ans;
    }
};
