/*
����һ��ֻ���� '('��')'��'{'��'}'��'['��']'?���ַ��� s ���ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺
�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�

ʾ�� 1��
���룺s = "()"
�����true

ʾ��2��
���룺s = "()[]{}"
�����true

ʾ��3��
���룺s = "(]"
�����false

ʾ��4��
���룺s = "([)]"
�����false

ʾ��5��
���룺s = "{[]}"
�����true

��ʾ��
1 <= s.length <= 104
s �������� '()[]{}' ���
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
