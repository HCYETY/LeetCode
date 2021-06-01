/*
给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。# 代表退格字符。
注意：如果对空文本输入退格字符，文本继续为空。

示例 1：
输入：S = "ab#c", T = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。

示例 2：
输入：S = "ab##", T = "c#d#"
输出：true
解释：S 和 T 都会变成 “”。

示例 3：
输入：S = "a##c", T = "#a#c"
输出：true
解释：S 和 T 都会变成 “c”。

示例 4：
输入：S = "a#c", T = "b"
输出：false
解释：S 会变成 “c”，但 T 仍然是 “b”。

提示：
1 <= S.length <= 200
1 <= T.length <= 200
S 和 T 只含有小写字母以及字符 '#'。

进阶：
你可以用 O(N) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？
*/


//用栈版
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stS, stT;
        for(int ch : s) {
            if(ch != '#') {
                stS.push(ch);
            } else {
                if(stS.empty()) {
                    continue;
                }
                stS.pop();
            }
        }
        for(int ar : t) {
            if(ar != '#') {
                stT.push(ar);
            } else {
                if(stT.empty()) {
                    continue;
                }
                stT.pop();
            }
        }
        if(stS.size() != stT.size()) return false;
        while(!stS.empty() && !stT.empty()) {
            if(stS.top() != stT.top()) return false;
            else {
                stS.pop();
                stT.pop();
            }
        }
        return true;
    }
};
//双指针版
/*
思路及算法：
一个字符是否会被删掉，只取决于该字符后面的退格符，而与该字符前面的退格符无关。
因此当我们逆序地遍历字符串，就可以立即确定当前字符是否会被删掉。

具体地，我们定义 skip 表示当前待删除的字符的数量。每次我们逆序遍历到一个字符：
1.若该字符为退格符，则我们需要多删除一个普通字符，我们让 skip 加 1；
2.若该字符为普通字符：
- 若 skip 为 0，则说明当前字符不需要删去；
- 若 skip 不为 0，则说明当前字符需要删去，然后 skip 减 1。
*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1, j = t.length() - 1;
        int skipS = 0, skipT = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') {
                    skipS++, i--;
                } else if (skipS > 0) {
						// 发现不是'#'，但skipS不为0，应该被删除，于是直接进行下次循环判断，代表该值被删去
                    skipS--, i--;
                } else {
                    break;
                }
            }
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++, j--;
                } else if (skipT > 0) {
                    skipT--, j--;
                } else {
                    break;
                }
            }
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) {
                    return false;
                }
            } else {
                if (i >= 0 || j >= 0) {
                    return false;
                }
            }
				// 执行到这里，说明s[i]==s[j]，则i--、j--，进行下次循环判断
            i--, j--;
        }
        return true;
    }
};
