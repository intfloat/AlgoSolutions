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

struct Node{
	int l, r;
	Node *leftChild, *rightChild;
	long long sum;
	long long inc;
};
Node node[1000005];
int n, q;
int ptr;

int getMiddle(int l, int r){
	return (l+r)/2;
}

void buildTree(Node *root, int left, int right){
	root->l = left;
	root->r = right;
	root->sum = 0;
	root->inc = 0;
	if(left == right)
		return;
	ptr++;
	root->leftChild = node+ptr;
	// Build left child segment tree
	buildTree(root->leftChild, left, getMiddle(left, right));
	ptr++;
	root->rightChild = node+ptr;
	// Build right child segment tree
	buildTree(root->rightChild, getMiddle(left, right)+1, right);
	return;
}

// Insert element into segment tree
void insert(Node *root, int index, int value){
	root->sum += value;
	if((root->l)==index && (root->r)==index)
		return;
	if(index <= getMiddle(root->l, root->r))
		insert(root->leftChild, index, value);
	else
		insert(root->rightChild, index, value);		
	return;
}

void add(Node *root, int left, int right, int value){
	if((root->l)==left && (root->r)==right){
		root->inc += value;
		return;
	}
	root->sum += (right-left+1)*value;
	if(right <= getMiddle(root->l, root->r))
		add(root->leftChild, left, right, value);
	else if(left > getMiddle(root->l, root->r))
		add(root->rightChild, left, right, value);
	else{
		add(root->leftChild, left, getMiddle(root->l, root->r), value);
		add(root->rightChild, getMiddle(root->l, root->r)+1, right, value);
	}
	return;
}

long long query(Node *root, int left, int right){
	//cout<<"left: "<<left<<" right: "<<right<<endl;
	if((root->l)==left && (root->r)==right)
		return (root->sum)+(right-left+1)*(root->inc);
	root->sum += ((root->r)-(root->l)+1)*(root->inc);
	add(root->leftChild, root->l, getMiddle(root->l, root->r), root->inc);
	add(root->rightChild, getMiddle(root->l, root->r)+1, root->r, root->inc);
	root->inc = 0;
	if(right <= getMiddle(root->l, root->r))
		return query(root->leftChild, left, right);
	else if(left > getMiddle(root->l, root->r))
		return query(root->rightChild, left, right);
	else{
		return query(root->leftChild, left, getMiddle(root->l, root->r))
				+query(root->rightChild, getMiddle(root->l, root->r)+1, right);
	}
	return 0;
}

int main(){	
	ptr = 0;
	scanf("%d%d", &n, &q);
	buildTree(node, 1, n);
	int tmp;
	for(int i=1; i<=n; i++){
		scanf("%d", &tmp);
		insert(node, i, tmp);
	}
	char command[10];
	int a, b, c;
	for(int i=0; i<q; i++){
		scanf("%s", &command);
		scanf("%d%d", &a, &b);
		//cout<<"a: "<<a<<" b: "<<b<<endl;
		if(command[0] == 'C'){
			scanf("%d", &c);
			add(node, a, b, c);
		}
		else
			printf("%I64d\n", query(node, a, b));		
	}
	//system("pause");
	return 0;
}
