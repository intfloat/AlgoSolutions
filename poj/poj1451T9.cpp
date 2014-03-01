#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

//�ֵ�����ÿ���ڵ��д洢Ȩ�غ�ָ�������� 
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
			//�����ֵ��ѯ�������� 
			query_dic(query);
			cout<<endl; 			
		} 
		delete_tree(&root);		
		cout<<endl;
	}
	return 0;
}

//��ʼ��һ���½��ڵ�Ĺ��� 
void initial(node* tmp){
	for(int i=0;i<26;i++){
		tmp->ptr[i]=NULL;
		tmp->weight[i]=0;
	}
	return;
}

//��һ���µĵ��ʲ��뵽�ֵ����У�ͬʱ����Ȩֵ 
int build_tree(char str[30],int wei){
	int len=strlen(str),cur=0;
	int pos; 
	node* tmp=&root;
	//��ÿ�����ʵ���ĸ��������ֵ����� 
	while(len--){
		pos=str[cur++]-'a';
		if(tmp->ptr[pos]==NULL){
			tmp->ptr[pos]=new node;
			initial(tmp->ptr[pos]);
		}
		//��ͬǰ׺��Ȩ����� 
		tmp->weight[pos]+=wei;
		tmp=tmp->ptr[pos];
	}
	return 0;
}

//���в�ѯ����������������ĵĲ��� 
int query_dic(char query[30]){
	int len=strlen(query),weight;
	int min_pos,max_pos,max_weight,tmp;
	query[len-1]='\0'; len--;
	
	//Ϊ���������������ϵ�׼�� 
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
	//���в��ҵĹ��� 
	for(int i=0;i<len;i++){
		//��ʱ����ʧ�� 
		if(find==false){
			cout<<"MANUALLY"<<endl;
			continue;
		}
		max_weight=-1;	
		tmp=q.size();		
		for(int j=0;j<tmp;j++){
			tmp_ele=q.front();
			q.pop();
			//Ѱ��������յ� 
			search(&min_pos,&max_pos,query[i]);				
			//��һ�����������п���������г��� 
			for(int k=min_pos;k<=max_pos;k++){				
				if(tmp_ele.pt->ptr[k]!=NULL){
					element* ele_ptr=new element;					
					ele_ptr->pt=tmp_ele.pt;
					ele_ptr->v=tmp_ele.v;
					(ele_ptr->v).push_back('a'+k);
					//�������ֵ 
					if((ele_ptr->pt->weight[k])>max_weight){
						max_weight=ele_ptr->pt->weight[k];
						max_ele=*ele_ptr;
					}
					ele_ptr->pt=ele_ptr->pt->ptr[k];					
					q.push(*ele_ptr);					
				}
			}
		}
		//��Ӧ�ڲ���ʧ�ܵ����� 
		if(q.empty()==true){
			find=false;
			//cout<<"���簡��"<<endl; 
			cout<<"MANUALLY"<<endl;
		}		
		//���ҳɹ� 
		else{		
			int length=max_ele.v.size();
			for(int k=0;k<length;k++)
				cout<<(max_ele.v)[k];			
			cout<<endl;
		}					
	}	
	return 0;
} 

//���������յ�Ĺ��� 
int search(int* min_pos,int* max_pos,char num){
	int goal=num-'2';
	//���������Ƶ�ö�ٷ��������� 
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

//�ݹ�ɾ���ֵ�����ֻ�������ڵ� 
int delete_tree(node* tmp_root){
	for(int i=0;i<26;i++){
		//�Ƚ�����ɾ������ɾ�����ڵ� 
		if(tmp_root->ptr[i]!=NULL)
			delete_tree(tmp_root->ptr[i]);
	}
	if(tmp_root!=(&root))
		delete tmp_root;
	return 0;
}
