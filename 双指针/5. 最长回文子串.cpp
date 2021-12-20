/*
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ���

ʾ�� 1��
���룺s = "babad"
�����"bab"
���ͣ�"aba" ͬ���Ƿ�������Ĵ𰸡�

ʾ�� 2��
���룺s = "cbbd"
�����"bb"

ʾ�� 3��
���룺s = "a"
�����"a"

ʾ�� 4��
���룺s = "ac"
�����"a"

��ʾ��
1 <= s.length <= 1000
s �������ֺ�Ӣ����ĸ����д��/��Сд�����
*/


class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            // �� s[i] Ϊ���ĵ�������Ӵ�
            string s1 = palindrome(s, i, i);
            // �� s[i] �� s[i+1] Ϊ���ĵ�������Ӵ�
            string s2 = palindrome(s, i, i + 1);
            res = res.size() > s1.size() ? res : s1;
            res = res.size() > s2.size() ? res : s2;
        }
        return res;
    }
    string palindrome(string s, int left, int right) {
        // ��ֹ����Խ�磬ͬʱ�жϻ���
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
};
