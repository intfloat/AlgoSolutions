//Memory Time 
//3000K  0MS 

#include<iostream>
#include<queue>
#include<cmath>
#include<string.h>
using namespace std;

class oper  //记录每步操作情况(只针对移位和换位操作，并不包括值大小的改变操作)，得到所有排列的状态
{
public:
	int num[6];  //第step步操作后的 "数字串"
	int state;  //第step步操作后对 "数字串各个位置的访问状态" ,其值对应VistState的行数，分别为0~9
	int pos;  //第step步操作后 "光标在数字串中的位置" ，分别为0~5
	int step; //当前操作的 "步数"
};

int VistState[10][6]=    /*访问状态数组，通过swap0、swap1与右移操作得到的"数字串各个位置的访问状态"*/
{                        /*一行代表一种访问状态，1表示数字串该位置被访问了，0表示没有访问*/

	1,0,0,0,0,0,  /*访问状态0: 初始状态(pos=0)*/
	1,1,0,0,0,0,  /*访问状态1: 状态0通过右移操作得到(pos=1)，或者状态1通过swap0操作得到(pos=1)*/
	1,1,1,0,0,0,  /*访问状态2: 状态1通过右移操作得到(pos=2)，或者状态2通过swap0操作得到(pos=2)*/
	1,1,1,1,0,0,  /*访问状态3: 状态2通过右移操作得到(pos=3)，或者状态3通过swap0操作得到(pos=3)*/
	1,1,1,1,1,0,  /*访问状态4: 状态3通过右移操作得到(pos=4)，或者状态4通过swap0操作得到(pos=4)*/
	1,0,0,0,0,1,  /*访问状态5: 状态0通过swap1操作得到(pos=0)，或者状态5通过swap0操作得到(pos=0)*/
	1,1,0,0,0,1,  /*访问状态6: 状态1通过swap1操作得到(pos=1)，或者状态5通过右移操作得到(pos=1),或者状态6通过swap0操作得到(pos=1)*/
	1,1,1,0,0,1,  /*访问状态7: 状态2通过swap1操作得到(pos=2)，或者状态6通过右移操作得到(pos=2),或者状态7通过swap0操作得到(pos=2)*/
	1,1,1,1,0,1,  /*访问状态8: 状态3通过swap1操作得到(pos=3)，或者状态7通过右移操作得到(pos=3),或者状态8通过swap0操作得到(pos=3)*/
	1,1,1,1,1,1   /*访问状态9: 状态4通过swap1操作得到(pos=4)，或者状态8通过右移操作得到(pos=4),或者状态9通过右移操作得到(pos=5),
	                           或者状态4通过右移操作得到(pos=5)，或者状态9通过swap0操作得到，或者状态9通过swap1操作得到*/
};   
     /*不难注意到:swap0操作前后,光标位置pos不变,访问状态不变 ; swap0操作前后,pos不变;
                  右移操作后,pos+1  ; 无需左移操作                                   */

int comb[720][8];  //记录某个数字串num的全部排列组合情况(各个数字值不变，位置不同)，共6!=720种
                   //comb[][0~5]=num[0~5], comb[][6]=state , comb[][7]=step
int idx=0;  //comb的行索引
bool vist[6][6][6][6][6][6][6][10];  //标记出现过的状态，前6维为数字串num[]，第7维为光标所在的位置pos，第8维为访问状态state

void BFS(void);  //搜索所有"通过位移和换位操作"得到的排列组合状态
bool CheckVist(oper* a);   //状态检查
void ChangeVist(oper* a);  //状态变更

int main(void)
{
	memset(vist,false,sizeof(vist));
	BFS();  //预处理: 对每一种排列和光标到达情况，求出最少需要"移位和换位的操作数"。(此过程与输入无关)

	char Init_ANum[6];  //初始字符串
	int Init_DNum[6];   //初始数字串
	char Aim_ANum[6];   //目标字符串
	int Aim_DNum[6];    //目标数字串
	
	while(cin>>Init_ANum>>Aim_ANum)
	{
		for(int k=0;k<6;k++)   //字符串转换为数字串
		{
			Init_DNum[k]=Init_ANum[k]-'0';
			Aim_DNum[k]=Aim_ANum[k]-'0';
		}

		int MinOper=1000000;  //从str得到aim最少需要的操作数
		for(int i=0;i<idx;i++)
		{
			int cnt=comb[i][7];  //comb[i][7]=step,为移位和换位的总操作数
			bool flag=true;
			for(int j=0;j<6;j++)
			{                //comb[i][6]=state
				if(!VistState[ comb[i][6] ][j] && (Init_DNum[ comb[i][j] ]!=Aim_DNum[j]))  //str[]与aim[]在位置j的数字值不等，且该位置没有被访问过
				{
					flag=false;  //comb[i]不符合要求
					break;
				}
				else
					cnt+=(int)abs((Init_DNum[ comb[i][j] ] - Aim_DNum[j])*1.0);  //在同一位置，值改变的次数(每一改变1)就是操作数
			}

			if(flag)
				MinOper=MinOper<cnt?MinOper:cnt;
		}

		cout<<MinOper<<endl;
	}

	return 0;
}

/*搜索所有"通过位移和换位操作"得到的排列组合状态*/
void BFS(void)
{
	oper a,b;
	queue<oper>Q;
	
	for(int i=0;i<6;i++)
		a.num[i]=i;
	a.pos=a.state=a.step=0;

	Q.push(a);  //入队
	ChangeVist(&a);

	while(!Q.empty())
	{
		a=Q.front(); //取队尾
		Q.pop();  //队尾元素出队

		/*记录所有组合情况*/

		for(int k=0;k<6;k++)
			comb[idx][k]=a.num[k];
		comb[idx][6]=a.state;
		comb[idx++][7]=a.step;

		if(a.pos>0)  //swap0操作前提条件，注意swap0操作前后的访问状态不变，光标位置也不变
		{            //因此无需处理b.state与b.pos

			/*swap0操作*/

			b=a;  //备份
			b.step=a.step+1;
			swap(b.num[0],b.num[b.pos]);  //交换num第0位与第pos位
			if(!CheckVist(&b))  //状态检查
			{
				ChangeVist(&b);
				Q.push(b);    //入队
			}
		}

		if(a.pos<5)  //右移right或swap1操作前提条件
		{
			/*right操作，注意光标位置pos会改变*/

			b=a;
			b.step=a.step+1;
			b.pos++;
			if(b.state<9)
				b.state++;

			if(!CheckVist(&b))  //状态检查
			{
				ChangeVist(&b);
				Q.push(b);    //入队
			}

			/*swap1操作,注意光标位置pos不变*/

			b=a;
			b.step=a.step+1;
			swap(b.num[5],b.num[b.pos]);  //交换num第5位与第pos位
			if(b.state<5)
				b.state+=5;

			if(!CheckVist(&b))  //状态检查
			{
				ChangeVist(&b);
				Q.push(b);    //入队
			}
		}
	}
	return;
}

/*状态检查*/
bool CheckVist(oper* a)
{
	int* p=a->num;
	return vist[*p][*(p+1)][*(p+2)][*(p+3)][*(p+4)][*(p+5)][a->pos][a->state];
}

/*状态变更*/
void ChangeVist(oper* a)
{
	int* p=a->num;
	vist[*p][*(p+1)][*(p+2)][*(p+3)][*(p+4)][*(p+5)][a->pos][a->state]=true;
	return;
}
