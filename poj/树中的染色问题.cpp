#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

vector<int> edge[1005];
//存储最小值以及次小值和相对应的颜色 
struct MinimumTwo{
	int firMini,secMini;
	int firColorOrder,secColorOrder;
};
MinimumTwo minimum[1005];
int colorValue[1005];
int nodeNumber,colorNumber;

void dfs(int n,int pr);
int cmp(const void*elem1, const void* elem2){
	return *((int *)elem1)-*((int *)elem2);
}

int main(){
	//int nodeNumber,colorNumber;
	int x,y;
	cin>>nodeNumber>>colorNumber;
	for(int i=0;i<nodeNumber;i++)
		edge[i].clear();
	//读入数据 
	for(int i=0;i<nodeNumber-1;i++){
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for(int i=0;i<colorNumber;i++)
		cin>>colorValue[i]; 
	qsort(colorValue,colorNumber,sizeof(int),cmp); 
	dfs(1,-1);
	/*for(int i=1;i<=nodeNumber;i++){
		cout<<i<<": "<<minimum[i].firMini<<" "<<minimum[i].secMini<<endl;
		cout<<i<<": color: "<<minimum[i].firColorOrder<<" "<<minimum[i].secColorOrder<<endl; 
		//cout<<i<<": color: "<<minimum[i].secColorOrder<<" "<<minimum[i].secColorOrder<<endl; 
	}*/
	cout<<minimum[1].firMini<<endl;
	system("pause");
	return 0;
}

void dfs(int n,int pr){
	int len=edge[n].size();
	//cout<<n<<" len: "<<len<<endl;
	//递归的边界情形 
	if(len==1&&edge[n][0]==pr){
		minimum[n].firMini=colorValue[0];
		minimum[n].secMini=colorValue[1];
		minimum[n].firColorOrder=0;
		minimum[n].secColorOrder=1;
		return;
	}
	for(int i=0;i<len;i++){
		if(edge[n][i]==pr)
			continue;
		dfs(edge[n][i],n); 
	}
	//int minValue=99999999;
	minimum[n].firMini=999999;
	minimum[n].secMini=999999;
	//minimum[n].firColorOrder=0;
	//minimum[n].secColorOrder=1;
	for(int i=0;i<colorNumber;i++){
		//累加器初始化 
		int sumValue=0;
		for(int j=0;j<len;j++){
			if(edge[n][j]==pr)
				continue;
			//颜色冲突，只能选次小值 
			if(minimum[edge[n][j]].firColorOrder==i)
				sumValue+=minimum[edge[n][j]].secMini;
			else
				sumValue+=minimum[edge[n][j]].firMini; 
		}
		sumValue+=colorValue[i];
		//if(sumValue<minValue)
		if(sumValue<minimum[n].firMini){
			minimum[n].secMini=minimum[n].firMini;
			minimum[n].secColorOrder=minimum[n].firColorOrder;
			minimum[n].firMini=sumValue;
			minimum[n].firColorOrder=i;
		}
		else if(sumValue<minimum[n].secMini){
			minimum[n].secMini=sumValue;
			minimum[n].secColorOrder=i;
		}
	}
	return;
}
