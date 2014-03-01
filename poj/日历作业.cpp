/*
author: 王亮
studentID: 1000012801
environment: Dev-C++ 4.9.2
time: 2012-10-1	
*/

#include<iostream>
#include<string>
#include<iomanip> 

using namespace std;

//存储表示月份的字符串
const string months[13]={"", "January","February","March",
					"April","May","June","July","August",
					"September","October","November","December"};

//存储表示每个月天数的整数
const int daysNumber[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

//存储表示一周各天的字符串
const string dayString[7]={"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};

//Month类用来为Date类提供基本服务
class Month{
public:
	//返回月份对应的英语单词
	string getMonth(int monthNumber);
	//返回月份所对应的天数
	int getDaysNumber(int yearNumber, int monthNumber);
	//返回从公元0年到这一个月开始的总天数
	int getTotalDays(int yearNumber,int monthNumber);
	//判断一年是否为闰年
	bool isLeapYear(int yearNumber);
};

//日期类用来获取输入、显示日历
class Date{
private:
	//年份
	int year;
	//月份
	int month;
	//天数计数器
	int daysCounter;
	//month月份的天数
	int daysNumberOfMonth;
	//Month类的实例
	Month monthInstance;
	//判断输入是否合法
	bool isValidInput();
public:
	//获取输入
	void getInput();
	//显示日历
	void showCalendar();
};


//主函数的执行入口
int main(){
	Date date;	
	while(1){
		//获取输入
		date.getInput();
		//显示日历
		date.showCalendar();
		system("pause");
		system("cls");
	}	
	return 0;
}




//返回月份对应的英语单词
string Month::getMonth(int monthNumber){
	if(monthNumber<0 ||monthNumber>12)
		return "out of range!";
	return months[monthNumber];
}

//返回月份所对应的天数
int Month::getDaysNumber(int yearNumber, int monthNumber){
	if(monthNumber<0 ||monthNumber>12)
		return -1;
	//需要对2月进行单独讨论
	if(monthNumber!=2)
		return daysNumber[monthNumber];
	//闰年则返回29天
	if(isLeapYear(yearNumber)==true)
		return 29;
	//平年则返回28天
	else return 28;
}

//判断一年是否为闰年
bool Month::isLeapYear(int yearNumber){
	if(yearNumber%4!=0)
		return false;
	if(yearNumber%100==0 && yearNumber%400!=0)
		return false;
	return true;
}

//返回从公元0年到这一个月开始的总天数
int Month::getTotalDays(int yearNumber, int monthNumber){	
	int counter=0;
	//从公元元年开始加
	for(int i=0;i<yearNumber;i++){
		if(isLeapYear(i)==true)
			counter+=366;
		else counter+=365;
	}
	//对当前年份进行计算
	for(int i=1;i<monthNumber;i++){
		counter+=getDaysNumber(yearNumber,i);
	}
	return counter;
}


//获取输入
void Date::getInput(){
	while(1){
		cout<<"请输入年月（格式为“年 月”）: ";
		cin>>year>>month;
		//检验有效则继续进行
		if(isValidInput()==true)
			break;
		//输入为无效年月则重新输入
		else{
			cout<<"输入数据无效！"<<endl;
			system("pause");
			system("cls");
			continue;
		}
	}
}

//显示日历
void Date::showCalendar(){
	//无效输入不会进行月份显示
	if(isValidInput() == false)
		return;
	//获取从公元元年开始的总天数
	daysCounter=monthInstance.getTotalDays(year,month);
	daysCounter+=5;
	daysCounter%=7;
	//获取该月的总天数
	daysNumberOfMonth=monthInstance.getDaysNumber(year,month);
	//初始化计数器，保证每七个显示结果后面跟一个换行
	int tmpCounter=0;
	cout<<monthInstance.getMonth(month)<<endl;
	//输出表示星期几的字符串
	for(int i=0;i<7;i++){
		cout<<setw(4)<<dayString[i];
	}
	cout<<endl;
	//先填充空白的区域
	for(int i=0;i<daysCounter;i++){
		cout<<setw(4)<<" ";
		tmpCounter++;
	}
	//显示日历
	for(int i=0;i<daysNumberOfMonth;i++){
		if(tmpCounter%7==0 && tmpCounter!=0)
			cout<<endl;
		cout<<setw(4)<<i+1;
		tmpCounter++;
	}
	cout<<endl;
	return;
}

//判断输入是否有效
bool Date::isValidInput(){
	if((this->year)<0 || (this->month)<=0 ||(this->month)>12)
		return false;	
	return true;
}
