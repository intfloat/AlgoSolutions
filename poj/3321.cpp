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

// Node for segment tree
struct Node{
	int l, r;
	Node *leftChild, *rightChild;
	int sum;
};
Node node[500000];

struct Apple{
	int first;
	int second;
	int value;
};
Apple apple[200000];
vector<int> v[100005];
int n, m;
int p;
int ptr;

// Get middle element
int getMiddle(int l, int r){
	return (l+r)/2;
}

// Build segment tree
void buildTree(Node *root, int left, int right){
	root->l = left;
	root->r = right;
	root->sum = right-left+1;
	if(left == right)
		return;
	// Build left subtree
	p++;
	root->leftChild = node+p;
	buildTree(root->leftChild, left, getMiddle(left, right));
	// Build right subtree
	p++;
	root->rightChild = node+p;
	buildTree(root->rightChild, getMiddle(left, right)+1, right);
	return;
}

// Query the sum from left to right, inclusive
int query(Node *root, int left, int right){
	if((root->l)==left && (root->r)==right)
		return root->sum;
	if(right <= getMiddle(root->l, root->r))
		return query(root->leftChild, left, right);
	else if(left > getMiddle(root->l, root->r))
		return query(root->rightChild, left, right);
	else{
		return query(root->leftChild, left, getMiddle(root->l, root->r))+query(root->rightChild,
				getMiddle(root->l, root->r)+1, right);
	}
	return 0;
	
}

// Depth first search, current node and its parent
void dfs(int cur, int parent){
	apple[cur].first = ptr;
	ptr++;
	int length = v[cur].size();
	// Visit its children
	for(int i=0; i<length; i++){
		// Can revisit its parent
		if(v[cur][i] != parent)
			dfs(v[cur][i], cur);
	}
	apple[cur].second = ptr;
	ptr++;
	return;
}

// Increase index-th element by value
void change(Node *root, int index, int value){
	root->sum += value;
	if((root->l) == (root->r))
		return;	
	// Get into its left subtree
	if(index <= getMiddle(root->l, root->r))
		change(root->leftChild, index, value);
	// Get into its right subtree
	else
		change(root->rightChild, index, value);
	return;
}

int main(){	
	int x, y;
	scanf("%d", &n);
	for(int i=0; i<n-1; i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	// Initialize apples
	for(int i=1; i<=n; i++){
		apple[i].first = -1;
		apple[i].second = -1;
		apple[i].value = 1;
	}
	ptr = 1; 
	p = 0;
	// Current node and its parent node
	dfs(1, -1);
	buildTree(node, 1, 2*n);
	// Get query numbers
	scanf("%d", &m);
	int tmp;
	// Response to every query
	for(int i=0; i<m; i++){
		char command[10];
		scanf("%s", command);
		scanf("%d", &tmp);
		if(command[0] == 'C'){
			if(apple[tmp].value == 1){
				// Decrease by 1
				change(node, apple[tmp].first, -1);
				change(node, apple[tmp].second, -1);
				apple[tmp].value = 0;
			}
			else{
				// Increase by 1
				change(node, apple[tmp].first, 1);
				change(node, apple[tmp].second, 1);
				apple[tmp].value = 1;
			}
		}
		else{
			printf("%d\n", query(node, apple[tmp].first, apple[tmp].second)/2);
		}
	}
	system("pause");
	return 0;
}
