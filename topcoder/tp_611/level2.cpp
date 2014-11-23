#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <cassert>

using namespace std;

class Egalitarianism2 {
public:
	int len;
	double graph[25][25], ori[25][25];	
	double minStdev(vector <int>, vector <int>);
	double enclidean(int x1, int x2, int y1, int y2){
		// use type conversion to avoid overflow
		double res = (double)(x1-x2)*(x1-x2)+(double)(y1-y2)*(y1-y2);
		return sqrt(res);
	}
	double solve(double m){		
		for(int i=0; i<len; i++){
			for(int j=0; j<len; j++){
				double tmp = ori[i][j];
				graph[i][j] = (tmp-m)*(tmp-m);				
			}
		}
		bool visited[25];
		int parent[25];
		double dis[25];
		memset(visited, false, sizeof(visited));
		memset(parent, 0, sizeof(parent));
		for(int i=0; i<25; i++) dis[i] = graph[0][i];
		visited[0] = true;
		// use Prim's algorithm to find minimum spanning tree
		double avg = 0;
		for(int i=0; i<len-1; i++){
			int t = -1;
			double mdis = 1e100;
			for(int j=0; j<len; j++){
				if(visited[j]) continue;
				if(dis[j]<mdis){
					mdis = dis[j];
					t = j;
				}
			}
			assert(t>=0);			
			visited[t] = true;
			avg += ori[parent[t]][t]/(len-1);
			// update distance vector
			for(int j=0; j<len; j++){
				if(visited[j]==false && graph[t][j]<dis[j]){
					dis[j] = graph[t][j];
					parent[j] = t;
				}
			}// end for loop
		}// end external for loop

		// avg = avg/(len-1);
		double dev = 0;
		for(int i=1; i<len; i++){
			dev += (ori[parent[i]][i]-avg)*(ori[parent[i]][i]-avg);
		}
		dev = dev/(len-1);
		dev = sqrt(dev);
		return dev;
	}// end method solve
};

double Egalitarianism2::minStdev(vector <int> x, vector <int> y) {
	len = x.size();	
	vector<double> edge;
	edge.clear();
	for(int i=0; i<25; i++)
		for(int j=0; j<25; j++) ori[i][j] = 0;
	for(int i=0; i<len; i++){
		for(int j=i+1; j<len; j++){
			double tmp = enclidean(x[i], x[j], y[i], y[j]);
			edge.push_back(tmp);
			ori[i][j] = tmp;
			ori[j][i] = tmp;
		}
	}
	int t = edge.size();
	double res = 1e100;
	for(int i=0; i<t; i++){
		for(int j=i+1; j<t; j++){
			double m = (edge[i]+edge[j])/2;
			res = min(res, solve(m));
		}
	}
	return res;
}

// <%:testing-code%>
//Powered by [KawigiEdit] 2.0!