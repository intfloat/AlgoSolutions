//Memory Time 
//3000K  0MS 

#include<iostream>
#include<queue>
#include<cmath>
#include<string.h>
using namespace std;

class oper  //��¼ÿ���������(ֻ�����λ�ͻ�λ��������������ֵ��С�ĸı����)���õ��������е�״̬
{
public:
	int num[6];  //��step��������� "���ִ�"
	int state;  //��step��������� "���ִ�����λ�õķ���״̬" ,��ֵ��ӦVistState���������ֱ�Ϊ0~9
	int pos;  //��step�������� "��������ִ��е�λ��" ���ֱ�Ϊ0~5
	int step; //��ǰ������ "����"
};

int VistState[10][6]=    /*����״̬���飬ͨ��swap0��swap1�����Ʋ����õ���"���ִ�����λ�õķ���״̬"*/
{                        /*һ�д���һ�ַ���״̬��1��ʾ���ִ���λ�ñ������ˣ�0��ʾû�з���*/

	1,0,0,0,0,0,  /*����״̬0: ��ʼ״̬(pos=0)*/
	1,1,0,0,0,0,  /*����״̬1: ״̬0ͨ�����Ʋ����õ�(pos=1)������״̬1ͨ��swap0�����õ�(pos=1)*/
	1,1,1,0,0,0,  /*����״̬2: ״̬1ͨ�����Ʋ����õ�(pos=2)������״̬2ͨ��swap0�����õ�(pos=2)*/
	1,1,1,1,0,0,  /*����״̬3: ״̬2ͨ�����Ʋ����õ�(pos=3)������״̬3ͨ��swap0�����õ�(pos=3)*/
	1,1,1,1,1,0,  /*����״̬4: ״̬3ͨ�����Ʋ����õ�(pos=4)������״̬4ͨ��swap0�����õ�(pos=4)*/
	1,0,0,0,0,1,  /*����״̬5: ״̬0ͨ��swap1�����õ�(pos=0)������״̬5ͨ��swap0�����õ�(pos=0)*/
	1,1,0,0,0,1,  /*����״̬6: ״̬1ͨ��swap1�����õ�(pos=1)������״̬5ͨ�����Ʋ����õ�(pos=1),����״̬6ͨ��swap0�����õ�(pos=1)*/
	1,1,1,0,0,1,  /*����״̬7: ״̬2ͨ��swap1�����õ�(pos=2)������״̬6ͨ�����Ʋ����õ�(pos=2),����״̬7ͨ��swap0�����õ�(pos=2)*/
	1,1,1,1,0,1,  /*����״̬8: ״̬3ͨ��swap1�����õ�(pos=3)������״̬7ͨ�����Ʋ����õ�(pos=3),����״̬8ͨ��swap0�����õ�(pos=3)*/
	1,1,1,1,1,1   /*����״̬9: ״̬4ͨ��swap1�����õ�(pos=4)������״̬8ͨ�����Ʋ����õ�(pos=4),����״̬9ͨ�����Ʋ����õ�(pos=5),
	                           ����״̬4ͨ�����Ʋ����õ�(pos=5)������״̬9ͨ��swap0�����õ�������״̬9ͨ��swap1�����õ�*/
};   
     /*����ע�⵽:swap0����ǰ��,���λ��pos����,����״̬���� ; swap0����ǰ��,pos����;
                  ���Ʋ�����,pos+1  ; �������Ʋ���                                   */

int comb[720][8];  //��¼ĳ�����ִ�num��ȫ������������(��������ֵ���䣬λ�ò�ͬ)����6!=720��
                   //comb[][0~5]=num[0~5], comb[][6]=state , comb[][7]=step
int idx=0;  //comb��������
bool vist[6][6][6][6][6][6][6][10];  //��ǳ��ֹ���״̬��ǰ6άΪ���ִ�num[]����7άΪ������ڵ�λ��pos����8άΪ����״̬state

void BFS(void);  //��������"ͨ��λ�ƺͻ�λ����"�õ����������״̬
bool CheckVist(oper* a);   //״̬���
void ChangeVist(oper* a);  //״̬���

int main(void)
{
	memset(vist,false,sizeof(vist));
	BFS();  //Ԥ����: ��ÿһ�����к͹�굽����������������Ҫ"��λ�ͻ�λ�Ĳ�����"��(�˹����������޹�)

	char Init_ANum[6];  //��ʼ�ַ���
	int Init_DNum[6];   //��ʼ���ִ�
	char Aim_ANum[6];   //Ŀ���ַ���
	int Aim_DNum[6];    //Ŀ�����ִ�
	
	while(cin>>Init_ANum>>Aim_ANum)
	{
		for(int k=0;k<6;k++)   //�ַ���ת��Ϊ���ִ�
		{
			Init_DNum[k]=Init_ANum[k]-'0';
			Aim_DNum[k]=Aim_ANum[k]-'0';
		}

		int MinOper=1000000;  //��str�õ�aim������Ҫ�Ĳ�����
		for(int i=0;i<idx;i++)
		{
			int cnt=comb[i][7];  //comb[i][7]=step,Ϊ��λ�ͻ�λ���ܲ�����
			bool flag=true;
			for(int j=0;j<6;j++)
			{                //comb[i][6]=state
				if(!VistState[ comb[i][6] ][j] && (Init_DNum[ comb[i][j] ]!=Aim_DNum[j]))  //str[]��aim[]��λ��j������ֵ���ȣ��Ҹ�λ��û�б����ʹ�
				{
					flag=false;  //comb[i]������Ҫ��
					break;
				}
				else
					cnt+=(int)abs((Init_DNum[ comb[i][j] ] - Aim_DNum[j])*1.0);  //��ͬһλ�ã�ֵ�ı�Ĵ���(ÿһ�ı�1)���ǲ�����
			}

			if(flag)
				MinOper=MinOper<cnt?MinOper:cnt;
		}

		cout<<MinOper<<endl;
	}

	return 0;
}

/*��������"ͨ��λ�ƺͻ�λ����"�õ����������״̬*/
void BFS(void)
{
	oper a,b;
	queue<oper>Q;
	
	for(int i=0;i<6;i++)
		a.num[i]=i;
	a.pos=a.state=a.step=0;

	Q.push(a);  //���
	ChangeVist(&a);

	while(!Q.empty())
	{
		a=Q.front(); //ȡ��β
		Q.pop();  //��βԪ�س���

		/*��¼����������*/

		for(int k=0;k<6;k++)
			comb[idx][k]=a.num[k];
		comb[idx][6]=a.state;
		comb[idx++][7]=a.step;

		if(a.pos>0)  //swap0����ǰ��������ע��swap0����ǰ��ķ���״̬���䣬���λ��Ҳ����
		{            //������账��b.state��b.pos

			/*swap0����*/

			b=a;  //����
			b.step=a.step+1;
			swap(b.num[0],b.num[b.pos]);  //����num��0λ���posλ
			if(!CheckVist(&b))  //״̬���
			{
				ChangeVist(&b);
				Q.push(b);    //���
			}
		}

		if(a.pos<5)  //����right��swap1����ǰ������
		{
			/*right������ע����λ��pos��ı�*/

			b=a;
			b.step=a.step+1;
			b.pos++;
			if(b.state<9)
				b.state++;

			if(!CheckVist(&b))  //״̬���
			{
				ChangeVist(&b);
				Q.push(b);    //���
			}

			/*swap1����,ע����λ��pos����*/

			b=a;
			b.step=a.step+1;
			swap(b.num[5],b.num[b.pos]);  //����num��5λ���posλ
			if(b.state<5)
				b.state+=5;

			if(!CheckVist(&b))  //״̬���
			{
				ChangeVist(&b);
				Q.push(b);    //���
			}
		}
	}
	return;
}

/*״̬���*/
bool CheckVist(oper* a)
{
	int* p=a->num;
	return vist[*p][*(p+1)][*(p+2)][*(p+3)][*(p+4)][*(p+5)][a->pos][a->state];
}

/*״̬���*/
void ChangeVist(oper* a)
{
	int* p=a->num;
	vist[*p][*(p+1)][*(p+2)][*(p+3)][*(p+4)][*(p+5)][a->pos][a->state]=true;
	return;
}
