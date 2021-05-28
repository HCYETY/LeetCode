/*
给定一个只包括 '('，')'，'{'，'}'，'['，']'?的字符串 s ，判断字符串是否有效。

有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。

示例 1：
输入：s = "()"
输出：true

示例2：
输入：s = "()[]{}"
输出：true

示例3：
输入：s = "(]"
输出：false

示例4：
输入：s = "([)]"
输出：false

示例5：
输入：s = "{[]}"
输出：true

提示：
1 <= s.length <= 104
s 仅由括号 '()[]{}' 组成
*/

class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        if(len % 2 != 0) return false;
        stack<char>mystack;
        for(int i = 0; i < len; i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                mystack.push(s[i]);
            }
            else if(s[i] == ')') {
                if(!mystack.empty()  && mystack.top() == '(') mystack.pop();
                else return false;
            }
            else if(s[i] == ']') {
                if(!mystack.empty()  && mystack.top() == '[') mystack.pop();
                else return false;
            }
            else if(s[i] == '}') {
                if(!mystack.empty()  && mystack.top() == '{') mystack.pop();
                else return false;
            }
        }
        return mystack.empty();
    }
};
