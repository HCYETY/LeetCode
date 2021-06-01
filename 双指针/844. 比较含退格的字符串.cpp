/*
���� S �� T �����ַ����������Ƿֱ����뵽�հ׵��ı��༭�����ж϶����Ƿ���ȣ������ؽ����# �����˸��ַ���
ע�⣺����Կ��ı������˸��ַ����ı�����Ϊ�ա�

ʾ�� 1��
���룺S = "ab#c", T = "ad#c"
�����true
���ͣ�S �� T ������ ��ac����

ʾ�� 2��
���룺S = "ab##", T = "c#d#"
�����true
���ͣ�S �� T ������ ������

ʾ�� 3��
���룺S = "a##c", T = "#a#c"
�����true
���ͣ�S �� T ������ ��c����

ʾ�� 4��
���룺S = "a#c", T = "b"
�����false
���ͣ�S ���� ��c������ T ��Ȼ�� ��b����

��ʾ��
1 <= S.length <= 200
1 <= T.length <= 200
S �� T ֻ����Сд��ĸ�Լ��ַ� '#'��

���ף�
������� O(N) ��ʱ�临�ӶȺ� O(1) �Ŀռ临�ӶȽ����������
*/


//��ջ��
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
//˫ָ���
/*
˼·���㷨��
һ���ַ��Ƿ�ᱻɾ����ֻȡ���ڸ��ַ�������˸����������ַ�ǰ����˸���޹ء�
��˵���������ر����ַ������Ϳ�������ȷ����ǰ�ַ��Ƿ�ᱻɾ����

����أ����Ƕ��� skip ��ʾ��ǰ��ɾ�����ַ���������ÿ���������������һ���ַ���
1.�����ַ�Ϊ�˸������������Ҫ��ɾ��һ����ͨ�ַ��������� skip �� 1��
2.�����ַ�Ϊ��ͨ�ַ���
- �� skip Ϊ 0����˵����ǰ�ַ�����Ҫɾȥ��
- �� skip ��Ϊ 0����˵����ǰ�ַ���Ҫɾȥ��Ȼ�� skip �� 1��
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
						// ���ֲ���'#'����skipS��Ϊ0��Ӧ�ñ�ɾ��������ֱ�ӽ����´�ѭ���жϣ������ֵ��ɾȥ
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
				// ִ�е����˵��s[i]==s[j]����i--��j--�������´�ѭ���ж�
            i--, j--;
        }
        return true;
    }
};
