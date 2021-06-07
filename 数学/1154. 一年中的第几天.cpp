/*
����һ���� YYYY-MM-DD ��ʽ��ʾ���ڵ��ַ��� date��������㲢���ظ������ǵ���ĵڼ��졣

ͨ������£�������Ϊ 1 �� 1 ����ÿ��ĵ� 1 �죬1 �� 2 ����ÿ��ĵ� 2 �죬�������ơ�ÿ���µ����������й�Ԫ���귨�������������һ�¡�

ʾ�� 1��
���룺date = "2019-01-09"
�����9

ʾ�� 2��
���룺date = "2019-02-10"
�����41

ʾ�� 3��
���룺date = "2003-03-01"
�����60

ʾ�� 4��
���룺date = "2004-03-01"
�����61

��ʾ��
date.length == 10
date[4] == date[7] == '-'�������� date[i] �������֡�
date ��ʾ�ķ�Χ�� 1900 �� 1 �� 1 ���� 2019 �� 12 �� 31 �ա�
*/


// ����һ���������κκ���
class Solution {
public:
    int dayOfYear(string date) {
        // int year=0,month=0,day=0;
        // int k=1000;
        // for(int i = 0; i < 4; i++) {
        //     year += (date[i] - '0') * k;
        //     k /= 10;
        // }
        // k = 10;
        // for(int i = 5; i < 7; i++) {
        //     month += (date[i] - '0') * k;
        //     k /= 10;
        // }
        // k = 10;
        // for(int i = 8; i < date.size(); i++) {
        //     day += (date[i] - '0') * k;
        //     k /= 10;
        // }
        int year = 0, month = 0, day = 0;
        for(int i = 0; i < 3; ++i)
		  		year = (year + date[i] - '0') * 10;
        year += date[3] - '0';
        month = (date[5] - '0') * 10 + date[6] - '0';
        day = (date[8] - '0')*10 + date[9] - '0';
        int res = day;
        int p[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        for(int i = 0; i < month - 1; i++)
            res += p[i];
        if(month > 2)
            if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
                    res++;
        return res;
    }
};

// �����������ú���
class Solution {
public:
    int dayOfYear(string date) {
        int dayNum = 0;
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day =stoi(date.substr(8,2));

        vector<int> days_no_leap={0, 31,28, 31, 30, 31, 30, 31,31,30,31, 30, 31};
        vector<int> days_leap={0, 31,29, 31, 30, 31, 30, 31,31,30,31, 30, 31};
        if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
            dayNum = accumulate(days_leap.begin(),days_leap.begin()+month,day);
        }
        else{
            dayNum = accumulate(days_no_leap.begin(),days_no_leap.begin()+month,day);
        }
        return dayNum;
    }
};
