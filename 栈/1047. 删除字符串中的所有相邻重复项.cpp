/*
������Сд��ĸ��ɵ��ַ���?S���ظ���ɾ��������ѡ��������������ͬ����ĸ����ɾ�����ǡ�
�� S �Ϸ���ִ���ظ���ɾ��������ֱ���޷�����ɾ����
����������ظ���ɾ�������󷵻����յ��ַ������𰸱�֤Ψһ��

ʾ����
���룺"abbaca"
�����"ca"
���ͣ�
���磬�� "abbaca" �У����ǿ���ɾ�� "bb" ��������ĸ��������ͬ�����Ǵ�ʱΨһ����ִ��ɾ���������ظ��֮�����ǵõ��ַ��� "aaca"��������ֻ�� "aa" ����ִ���ظ���ɾ�����������������ַ���Ϊ "ca"��

��ʾ��
1 <= S.length <= 20000
S ����СдӢ����ĸ��ɡ�
*/


class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int value : s) {
            if(st.empty() || value != st.top()) {
                st.push(value);
            } else {
                st.pop();
            }
        }
        string result = "";
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
