/*
给你一个按 YYYY-MM-DD 格式表示日期的字符串 date，请你计算并返回该日期是当年的第几天。

通常情况下，我们认为 1 月 1 日是每年的第 1 天，1 月 2 日是每年的第 2 天，依此类推。每个月的天数与现行公元纪年法（格里高利历）一致。

示例 1：
输入：date = "2019-01-09"
输出：9

示例 2：
输入：date = "2019-02-10"
输出：41

示例 3：
输入：date = "2003-03-01"
输出：60

示例 4：
输入：date = "2004-03-01"
输出：61

提示：
date.length == 10
date[4] == date[7] == '-'，其他的 date[i] 都是数字。
date 表示的范围从 1900 年 1 月 1 日至 2019 年 12 月 31 日。
*/


// 方法一：不调用任何函数
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

// 方法二：调用函数
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
