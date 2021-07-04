/*
�����������ʹ�ü��������������� name��ż�����ڼ����ַ� c ʱ���������ܻᱻ���������ַ����ܱ����� 1 �λ��Ρ�
�㽫�������������ַ� typed���������Ӧ�Ŀ�����������ѵ����֣�����һЩ�ַ����ܱ�����������ô�ͷ��� True��

ʾ�� 1��
���룺name = "alex", typed = "aaleex"
�����true
���ͣ�'alex' �е� 'a' �� 'e' ��������

ʾ�� 2��
���룺name = "saeed", typed = "ssaaedd"
�����false
���ͣ�'e' һ����Ҫ���������Σ����� typed ������в���������

ʾ�� 3��
���룺name = "leelee", typed = "lleeelee"
�����true

ʾ�� 4��
���룺name = "laiden", typed = "laiden"
�����true
���ͣ����������е��ַ������Ǳ�Ҫ�ġ�

ʾ�� 5��
���룺name = "alex", typed = "aaleelx"
�����false

ʾ�� 6��
���룺name = "alex", typed = "aaleexa"
�����false

��ʾ��
name.length <= 1000
typed.length <= 1000
name �� typed ���ַ�����Сд��ĸ��
*/


// �Լ�д���е����࣬����ò��Ч�ʺ͹ٽ�һ��
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int left = 0, right = 0, sign = name[0];
        while(left < name.size() && right < typed.size()) {
            if(typed[right] == name[left]) {
                sign = typed[right];
                left++;
                right++;
            } else if(typed[right] != name[left] && typed[right] != sign) {
                return false;
            } else if(typed[right] != name[left] && typed[right] == sign) {
                right++;
            }
        }
        while(right < typed.size()) {
            if(typed[right] == sign) {
                sign = typed[right];
                right++;
            } else {
                return false;
            }
        }
        if(left == name.size() && right == typed.size()) return true;
        return false;
    }
};
// �ٽ⣬��Ȼ���ŵö�
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (j < typed.length()) {
            if (i < name.length() && name[i] == typed[j]) {
                i++;
                j++;
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            } else {
                return false;
            }
        }
        return i == name.length();
    }
};
