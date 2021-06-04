/*
给定只含 "I"（增大）或 "D"（减小）的字符串 S ，令 N = S.length。
返回 [0, 1, ..., N] 的任意排列 A 使得对于所有 i = 0, ..., N-1，都有：

如果 S[i] == "I"，那么 A[i] < A[i+1]
如果 S[i] == "D"，那么 A[i] > A[i+1]

示例 1：
输入："IDID"
输出：[0,4,1,3,2]

示例 2：
输入："III"
输出：[0,1,2,3]

示例 3：
输入："DDI"
输出：[3,2,0,1]

提示：
1 <= S.length <= 10000
S 只包含字符 "I" 或 "D"。
*/

/*思路：
遇到‘I’时，就把deque容器中的最小值压进ans数组，然后移除最小值；这样一来肯定可以保证A[i] < A[i+1]
遇到‘D’时，就把deque容器中的最大值压进ans数组，然后移除最大值；这样一来肯定可以保证A[i] > A[i+1]
于是每次遍历s字符串，根据情况拿出容器里剩余数的最大值或最小值。
注意：每次拿到最大值或最小值后，要记得将该值移除，在下次遍历时才可以拿到剩余数的最大/小值。
*/
class Solution {
public:
    vector<int> diStringMatch(string s) {
        deque<int> myqueue;
        vector<int> ans;
        for(int i = 0; i <= s.size(); i++) {
            myqueue.push_back(i);
        }
        for(int ch : s) {
            if(ch == 'I') {
                ans.push_back(myqueue.front());
                myqueue.pop_front();
            } else if(ch == 'D') {
                ans.push_back(myqueue.back());
                myqueue.pop_back();
            }
        }
        if(!myqueue.empty()){
            ans.push_back(myqueue.front());
            myqueue.pop_back();
        }
        return ans;
    }
};
