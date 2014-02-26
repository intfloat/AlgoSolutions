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
	// Indicate whether the whole segment has been covered
	bool covered;
};
Node node[50000];
int hash[10000010];
int array[20005];
int ptr, n;

int getMiddle(int l, int r){
	return (l+r)/2;
}

void buildTree(Node *root, int left, int right){
	root->l = left;
	root->r = right;
	root->covered = false;
	if(left == right)
		return;
	ptr++;
	root->leftChild = node+ptr;
	buildTree(root->leftChild, left, getMiddle(left, right));
	ptr++;
	root->rightChild = node+ptr;
	buildTree(root->rightChild, getMiddle(left, right)+1, right);
	return;
}

bool query(Node *root, int left, int right){	
	if(root->covered == true)
		return false;
	if((root->l)==left && (root->r)==right){
		root->covered = true;
		return true;
	}
	bool tmp;
	if(right <= getMiddle(root->l, root->r))
		tmp = query(root->leftChild, left, right);
	else if(left > getMiddle(root->l, root->r))
		tmp = query(root->rightChild, left, right);
	else{
		bool tmp1 = query(root->leftChild, left, getMiddle(root->l, root->r));
		bool tmp2 = query(root->rightChild, getMiddle(root->l, root->r)+1, right);
		tmp = tmp1 || tmp2;
	}
	if((root->leftChild->covered)==true && (root->rightChild->covered)==true)
		root->covered = true;
	return tmp;
}
int main(){	
	int t;
	pair<int, int> post[10005];
	scanf("%d", &t);
	while(t--){
		ptr = 0;
		int index = 0;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d", array+index);			
			index++;
			scanf("%d", array+index);
			index++;
			post[i] = make_pair(array[index-2], array[index-1]);
		}
		sort(array, array+index);
		// Eliminate same elements
		int length = unique(array, array+index)-array;
		//cout<<"length: "<<length<<endl;
		// Process of hashing
		for(int i=0; i<length; i++)
			hash[array[i]] = i;
		buildTree(node, 0, length-1);
		int res = 0;
		for(int i=n-1; i>=0; i--){
			//cout<<hash[post[i].first]<<" "<<hash[post[i].second]<<endl;  
			if(query(node, hash[post[i].first], hash[post[i].second]) == true)
				res++;
		}
		printf("%d\n", res);
	}
	//system("pause");
	return 0;
}
