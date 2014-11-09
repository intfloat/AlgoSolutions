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

// Definition of node
struct Node{
	int l, r;
	Node *leftChild, *rightChild;
	int maxValue, minValue;
};
Node node[1000005];
int n, q;
int maxi, mini;
int counter;

// Build segment tree
void buildTree(Node* root, int left, int right){
	root->l = left;
	root->r = right;
	root->maxValue = INT_MIN;
	root->minValue = INT_MAX;
	if(left >= right)
		return;
	else{
		//build segment tree recurrsively
		counter++;
		root->leftChild = node+counter;
		buildTree(node+counter, left, (left+right)/2);
		counter++;
		root->rightChild = node+counter;
		buildTree(node+counter, (left+right)/2+1, right);		
	}
	return;
}

// Insert node into segment tree
void insert(Node* root, int index, int value){
	root->maxValue = max(root->maxValue, value);
	root->minValue = min(root->minValue, value);
	if(index==(root->l) && index==(root->r))
		return;
	if(index <= ((root->l)+(root->r))/2)
		insert(root->leftChild, index, value);
	else
		insert(root->rightChild, index, value);
	return;
	
}

// Query certain value from segment tree
void query(Node* root, int left, int right){
	//cout<<"left: "<<left<<" right: "<<right<<endl;
	if((root->l)==left && (root->r)==right){
		maxi = max(maxi, root->maxValue);
		mini = min(mini, root->minValue);
		return;
	}
	else if(right <= ((root->l)+(root->r))/2)
		query(root->leftChild, left, right);
	else if(left > ((root->l)+(root->r))/2)
		query(root->rightChild, left, right);
	else{
		query(root->leftChild, left, ((root->l)+(root->r))/2);
		query(root->rightChild, ((root->l)+(root->r))/2+1, right);
	}
	return;
}

int main(){	
	scanf("%d%d", &n, &q);
	int tmp;
	counter = 0;
	buildTree(node, 1, n);
	for(int i=1; i<=n; i++){
		scanf("%d", &tmp);
		insert(node, i, tmp);
	}
	int l, r;
	for(int i=0; i<q; i++){
		scanf("%d%d", &l, &r);
		maxi = INT_MIN;
		mini = INT_MAX;
		query(node, l, r);
		//cout<<"maxi: "<<maxi<<" mini: "<<mini<<endl;
		printf("%d\n",(maxi-mini));
	}
	system("pause");
	return 0;
}
