����һ���������ַ��� s �����ַ��� ����ǰ���� ��
��� s ������ һ���������� '1' ��ɵ��ֶ� ������ true??? �����򣬷��� false ��

ʾ�� 1��
���룺s = "1001"
�����false
���ͣ��ַ����е� 1 û���γ�һ�������ֶΡ�

ʾ�� 2��
���룺s = "110"
�����true


class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i = 1; i < s.size(); i++)
            if(s[i-1]=='0' && s[i]=='1')
                return false;
        return true;
    }
};
