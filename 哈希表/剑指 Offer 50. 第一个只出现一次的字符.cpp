/*
���ַ��� s ���ҳ���һ��ֻ����һ�ε��ַ������û�У�����һ�����ո�
s ֻ����Сд��ĸ��

ʾ��1 :
s = "abaccdeff"
���� "b"

ʾ��2 ��
s = ""
���� " "

���ƣ�
0 <= s �ĳ��� <= 50000
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
