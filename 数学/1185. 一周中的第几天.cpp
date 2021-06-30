/*
����һ�����ڣ��������һ���㷨���ж����Ƕ�Ӧһ���е���һ�졣
����Ϊ����������day��month �� year���ֱ��ʾ�ա��¡��ꡣ
�����صĽ���������⼸��ֵ�е�һ�� {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}��

ʾ�� 1��
���룺day = 31, month = 8, year = 2019
�����"Saturday"

ʾ�� 2��
���룺day = 18, month = 7, year = 1999
�����"Sunday"

ʾ�� 3��
���룺day = 15, month = 8, year = 1993
�����"Sunday"

��ʾ��
����������һ������ 1971 �� 2100 ��֮�����Ч���ڡ�
*/


class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        if(month == 1 || month == 2) {
            month+=12;
            year--;
        }
        int iWeek = (day + 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400) % 7;  //��ķ����ɭ���㹫ʽ
        string result[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday"};
        return result[iWeek];
    }
};
