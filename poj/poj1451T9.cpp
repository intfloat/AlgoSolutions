#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

//字典树的每个节点中存储权重和指针两部分 
struct node{
	node* ptr[26];
	int weight[26];
};
node root;

struct element{
	node* pt;
	vector<char> v;
};

int build_tree(char str[30],int wei);
int delete_tree(node* tmp_root);
int query_dic(char query[30]);
int search(int* min_pos,int* max_pos,char num);
void initial(node* tmp); 

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t,n,wei,query_num;
	char query[30],str[30];
	cin>>t;	
	for(int i=0;i<t;i++){
		initial(&root);
		cout<<"Scenario #"<<i+1<<":"<<endl;
		cin>>n;
		for(int j=0;j<n;j++){ 
			cin>>str>>wei;
			build_tree(str,wei);
		}		
		cin>>query_num;
		for(int j=0;j<query_num;j++){
			cin>>query;
			//进行字典查询并输出结果 
			query_dic(query);
			cout<<endl; 			
		} 
		delete_tree(&root);		
		cout<<endl;
	}
	return 0;
}

//初始化一个新建节点的过程 
void initial(node* tmp){
	for(int i=0;i<26;i++){
		tmp->ptr[i]=NULL;
		tmp->weight[i]=0;
	}
	return;
}

//将一个新的单词插入到字典树中，同时更新权值 
int build_tree(char str[30],int wei){
	int len=strlen(str),cur=0;
	int pos; 
	node* tmp=&root;
	//将每个单词的字母逐个插入字典树中 
	while(len--){
		pos=str[cur++]-'a';
		if(tmp->ptr[pos]==NULL){
			tmp->ptr[pos]=new node;
			initial(tmp->ptr[pos]);
		}
		//相同前缀，权重相加 
		tmp->weight[pos]+=wei;
		tmp=tmp->ptr[pos];
	}
	return 0;
}

//进行查询操作，本程序最核心的部分 
int query_dic(char query[30]){
	int len=strlen(query),weight;
	int min_pos,max_pos,max_weight,tmp;
	query[len-1]='\0'; len--;
	
	//为查找做变量定义上的准备 
	element ele;
	node* tmp_ptr,max_node;
	element max_ele,tmp_ele;
	queue<element> q;
	while(q.empty()==false)
		q.pop();
	ele.pt=&root;
	ele.v.clear();
	q.push(ele);
	
	bool find=true;
	//进行查找的过程 
	for(int i=0;i<len;i++){
		//此时查找失败 
		if(find==false){
			cout<<"MANUALLY"<<endl;
			continue;
		}
		max_weight=-1;	
		tmp=q.size();		
		for(int j=0;j<tmp;j++){
			tmp_ele=q.front();
			q.pop();
			//寻找起点与终点 
			search(&min_pos,&max_pos,query[i]);				
			//对一个按键的所有可能情况进行尝试 
			for(int k=min_pos;k<=max_pos;k++){				
				if(tmp_ele.pt->ptr[k]!=NULL){
					element* ele_ptr=new element;					
					ele_ptr->pt=tmp_ele.pt;
					ele_ptr->v=tmp_ele.v;
					(ele_ptr->v).push_back('a'+k);
					//更新最大值 
					if((ele_ptr->pt->weight[k])>max_weight){
						max_weight=ele_ptr->pt->weight[k];
						max_ele=*ele_ptr;
					}
					ele_ptr->pt=ele_ptr->pt->ptr[k];					
					q.push(*ele_ptr);					
				}
			}
		}
		//对应于查找失败的情形 
		if(q.empty()==true){
			find=false;
			//cout<<"悲剧啊！"<<endl; 
			cout<<"MANUALLY"<<endl;
		}		
		//查找成功 
		else{		
			int length=max_ele.v.size();
			for(int k=0;k<length;k++)
				cout<<(max_ele.v)[k];			
			cout<<endl;
		}					
	}	
	return 0;
} 

//搜索起点和终点的过程 
int search(int* min_pos,int* max_pos,char num){
	int goal=num-'2';
	//采用了最苦逼的枚举法。。。。 
	if(num<'7'){
		*min_pos=goal*3;
		*max_pos=*min_pos+2;
	}		
	else if(num=='7'){
		*min_pos='p'-'a';
		*max_pos='s'-'a';
	}
	else if(num=='8'){
		*min_pos='t'-'a';
		*max_pos='v'-'a';
	}
	else if(num=='9'){
		*min_pos='w'-'a';
		*max_pos='z'-'a';
	}
	else{
		*min_pos=0;
		*max_pos=0;
	}
	return 0;
} 

//递归删除字典树，只保留根节点 
int delete_tree(node* tmp_root){
	for(int i=0;i<26;i++){
		//先将子树删除，再删除根节点 
		if(tmp_root->ptr[i]!=NULL)
			delete_tree(tmp_root->ptr[i]);
	}
	if(tmp_root!=(&root))
		delete tmp_root;
	return 0;
}
