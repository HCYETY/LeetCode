/*
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。
s 只包含小写字母。

示例1 :
s = "abaccdeff"
返回 "b"

示例2 ：
s = ""
返回 " "

限制：
0 <= s 的长度 <= 50000
*/


class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<int, int> frequency;
        for (char ch : s) {
            ++frequency[ch];
        }
        for (char oh : s) {
            if (frequency[oh] == 1) {
                return oh;
            }
        }
        return ' ';
    }
};
