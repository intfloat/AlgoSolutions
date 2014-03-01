//应时刻关注指针指向的变化 
#include<iostream>
#include<cstring>
using namespace std;
struct Node{
	Node *left,*right;
	char ele;
};
int pre(Node *root);
int main(){
	Node *root,*tem;
	bool end=false;
	int len;
	char tmp[100],ch[100];
	while(1){
		root=NULL;
		if(end==true)
			break;
		ch[0]='\0';
		while(cin>>tmp){
			if(strlen(tmp)==1&&tmp[0]=='*')
				break;
			if(strlen(tmp)==1&&tmp[0]=='$'){
				end=true;
				break;
			}
			strcat(ch,tmp);
		}
		len=strlen(ch);	
		for(int i=len-1;i>=0;i--){			
			if(root==NULL){
				root=new Node;
				root->ele=ch[i];
				root->left=NULL;
				root->right=NULL;
				continue;
			}
			tem=root;
			while(1){
				if(ch[i]<root->ele&&root->left!=NULL)
					root=root->left;
				else if(ch[i]>root->ele&&root->right!=NULL)
					root=root->right;
				if(ch[i]<root->ele&&root->left==NULL){
					root->left=new Node;
					root->left->ele=ch[i];
					root->left->left=NULL;
					root->left->right=NULL;
					break;
				}
				else if(ch[i]>root->ele&&root->right==NULL){
					root->right=new Node;
					root->right->ele=ch[i];
					root->right->left=NULL;
					root->right->right=NULL;
					break;
				}
			}		
			root=tem;
		}
		pre(root);
		cout<<endl;
	}
	return 0;
} 

int pre(Node *root){
	if(root!=NULL){		
		cout<<root->ele;
		pre(root->left);
		pre(root->right);
	}
	return 0;
}
