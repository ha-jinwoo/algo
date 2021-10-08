#include <bits/stdc++.h>
using namespace std;
 
string str_day[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
int month_day[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
 
// 윤년인지 여부 
void IsLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        month_day[1] = 29;
}
 
// 날짜이름
string getDayName(int year, int month, int day)
{
    int total_day = 0;
    
    // 년
    IsLeapYear(year);
 
    // 달
    for(int i=1; i<month; i++)
    {
        total_day += month_day[i-1];
    }
    // 일
    total_day += day-1;
 
    // 2016.1.1 = 금
    int answer_day = (5 + total_day) % 7;
 
    return str_day[answer_day];
}

string solution(int a, int b) {
    return getDayName(2016,a,b);
}