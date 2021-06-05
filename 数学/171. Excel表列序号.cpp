/*
����һ��Excel����е������ƣ���������Ӧ������š�

���磬
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
    ...
    
ʾ�� 1:
����: "A"
���: 1

ʾ�� 2:
����: "AB"
���: 28

ʾ�� 3:
����: "ZY"
���: 701

ʾ��4��
����: "FXD"
���: 4684
*/


class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for(int i = 0; i < columnTitle.size(); i++) {
				// C++����ĸתΪASCII�룺(int)a
				// C++��ASCII��תΪ��ĸ��(char)a
            int num = (int)columnTitle[i] - 64;
            ans = ans * 26 + num;
        }
        return ans;
    }
};
