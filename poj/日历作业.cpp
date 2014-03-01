/*
author: ����
studentID: 1000012801
environment: Dev-C++ 4.9.2
time: 2012-10-1	
*/

#include<iostream>
#include<string>
#include<iomanip> 

using namespace std;

//�洢��ʾ�·ݵ��ַ���
const string months[13]={"", "January","February","March",
					"April","May","June","July","August",
					"September","October","November","December"};

//�洢��ʾÿ��������������
const int daysNumber[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

//�洢��ʾһ�ܸ�����ַ���
const string dayString[7]={"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};

//Month������ΪDate���ṩ��������
class Month{
public:
	//�����·ݶ�Ӧ��Ӣ�ﵥ��
	string getMonth(int monthNumber);
	//�����·�����Ӧ������
	int getDaysNumber(int yearNumber, int monthNumber);
	//���شӹ�Ԫ0�굽��һ���¿�ʼ��������
	int getTotalDays(int yearNumber,int monthNumber);
	//�ж�һ���Ƿ�Ϊ����
	bool isLeapYear(int yearNumber);
};

//������������ȡ���롢��ʾ����
class Date{
private:
	//���
	int year;
	//�·�
	int month;
	//����������
	int daysCounter;
	//month�·ݵ�����
	int daysNumberOfMonth;
	//Month���ʵ��
	Month monthInstance;
	//�ж������Ƿ�Ϸ�
	bool isValidInput();
public:
	//��ȡ����
	void getInput();
	//��ʾ����
	void showCalendar();
};


//��������ִ�����
int main(){
	Date date;	
	while(1){
		//��ȡ����
		date.getInput();
		//��ʾ����
		date.showCalendar();
		system("pause");
		system("cls");
	}	
	return 0;
}




//�����·ݶ�Ӧ��Ӣ�ﵥ��
string Month::getMonth(int monthNumber){
	if(monthNumber<0 ||monthNumber>12)
		return "out of range!";
	return months[monthNumber];
}

//�����·�����Ӧ������
int Month::getDaysNumber(int yearNumber, int monthNumber){
	if(monthNumber<0 ||monthNumber>12)
		return -1;
	//��Ҫ��2�½��е�������
	if(monthNumber!=2)
		return daysNumber[monthNumber];
	//�����򷵻�29��
	if(isLeapYear(yearNumber)==true)
		return 29;
	//ƽ���򷵻�28��
	else return 28;
}

//�ж�һ���Ƿ�Ϊ����
bool Month::isLeapYear(int yearNumber){
	if(yearNumber%4!=0)
		return false;
	if(yearNumber%100==0 && yearNumber%400!=0)
		return false;
	return true;
}

//���شӹ�Ԫ0�굽��һ���¿�ʼ��������
int Month::getTotalDays(int yearNumber, int monthNumber){	
	int counter=0;
	//�ӹ�ԪԪ�꿪ʼ��
	for(int i=0;i<yearNumber;i++){
		if(isLeapYear(i)==true)
			counter+=366;
		else counter+=365;
	}
	//�Ե�ǰ��ݽ��м���
	for(int i=1;i<monthNumber;i++){
		counter+=getDaysNumber(yearNumber,i);
	}
	return counter;
}


//��ȡ����
void Date::getInput(){
	while(1){
		cout<<"���������£���ʽΪ���� �¡���: ";
		cin>>year>>month;
		//������Ч���������
		if(isValidInput()==true)
			break;
		//����Ϊ��Ч��������������
		else{
			cout<<"����������Ч��"<<endl;
			system("pause");
			system("cls");
			continue;
		}
	}
}

//��ʾ����
void Date::showCalendar(){
	//��Ч���벻������·���ʾ
	if(isValidInput() == false)
		return;
	//��ȡ�ӹ�ԪԪ�꿪ʼ��������
	daysCounter=monthInstance.getTotalDays(year,month);
	daysCounter+=5;
	daysCounter%=7;
	//��ȡ���µ�������
	daysNumberOfMonth=monthInstance.getDaysNumber(year,month);
	//��ʼ������������֤ÿ�߸���ʾ��������һ������
	int tmpCounter=0;
	cout<<monthInstance.getMonth(month)<<endl;
	//�����ʾ���ڼ����ַ���
	for(int i=0;i<7;i++){
		cout<<setw(4)<<dayString[i];
	}
	cout<<endl;
	//�����հ׵�����
	for(int i=0;i<daysCounter;i++){
		cout<<setw(4)<<" ";
		tmpCounter++;
	}
	//��ʾ����
	for(int i=0;i<daysNumberOfMonth;i++){
		if(tmpCounter%7==0 && tmpCounter!=0)
			cout<<endl;
		cout<<setw(4)<<i+1;
		tmpCounter++;
	}
	cout<<endl;
	return;
}

//�ж������Ƿ���Ч
bool Date::isValidInput(){
	if((this->year)<0 || (this->month)<=0 ||(this->month)>12)
		return false;	
	return true;
}
