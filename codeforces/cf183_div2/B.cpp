#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct date
{
   int year;
   int month;
   int day;
};
bool isLeap(int aYear);  // 判断平年闰年
int daysGone(date aDate); // 计算一年的第几天

int main()
{
 	string str1, str2;
	cin>>str1>>str2;
	if(str1 > str2){
		string tmp = str1;
		str1 = str2;
		str2 = tmp;
	}
	int y1=0, m1=0, d1=0, y2=0, m2=0, d2=0;
	for(int i=0; i<4; i++){		
		y1 = y1*10+(str1[i]-'0');
		y2 = y2*10+(str2[i]-'0');
	}
	for(int i=5; i<7; i++){
		m1 = m1*10 +(str1[i]-'0');
		m2 = m2*10 + (str2[i]-'0');
	}
	for(int i=8; i<10; i++){
		d1 = d1*10 + (str1[i]-'0');
		d2 = d2*10 + (str2[i]-'0');
	}
	
   int days = 0;
   int days1 = 0;
   date a,b;
   a.year = y1; a.month = m1; a.day = d1;
   b.year = y2; b.month = m2; b.day = d2;   
   for (int i = a.year;i < b.year;i++)
   {
      if (isLeap(i))
        days1 += 366;
      else
        days1 += 365;
   }
   days = days1+daysGone(b)-daysGone(a);
//   days = days1 + daysGone(b) – daysGone(a);
    cout<<days<<endl;
    //system("pause");
   return 0;
}


bool isLeap(int aYear)
{
   if (((aYear % 4 == 0) && (aYear % 100 != 0)) || (aYear % 400 == 0))
      return true;
   else
      return false;
}
int daysGone(date aDate)
{
   int mDays(0);
   if (aDate.month > 1)
      for (int i = 1;i < aDate.month;i++)
        if (i == 4 || i == 6 || i == 9 || i == 11)
           mDays += 30;
        else if (i == 2)
           if (isLeap(aDate.year))
              mDays += 29;
           else
              mDays += 28;
        else
           mDays += 31;
   return mDays + aDate.day;
}



