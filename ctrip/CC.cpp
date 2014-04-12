#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <map>

using namespace std;
const int N=250;
map<int, int> xmap, ymap;
pair<int, int> p[N];
int r[N], g[N], b[N];
vector<int> xx, yy;
int cur_index;
int rans, gans, bans;

struct newtree{
	int left,right, r, g, b;
	int getnewmid(){
	   return (left+right)/2;
	}
};
struct tree{
	int left,right;
	newtree newtt[4*N];
	int getmid(){
	  return (left+right)/2;
	}
}tt[4*N];

void built_treey(int lp,int rp,int posx,int posy){
	tt[posx].newtt[posy].left=lp;
	tt[posx].newtt[posy].right=rp;
	tt[posx].newtt[posy].r=255;
	tt[posx].newtt[posy].g=255;
	tt[posx].newtt[posy].b=255;
	if(lp==rp)return;
	int mid=tt[posx].newtt[posy].getnewmid();
	built_treey(lp,mid,posx,posy*2);
	built_treey(mid+1,rp,posx,posy*2+1);
}
void built_treex(int lp,int rp,int pos){
	tt[pos].left=lp;
	tt[pos].right=rp;
	built_treey(1,ymap.size(),pos,1);
	if(lp==rp)return;
	int mid=tt[pos].getmid();
	built_treex(lp,mid,pos*2);
	built_treex(mid+1,rp,pos*2+1);
}
void update_y(int y1,int y2,int posx,int posy){
	if(tt[posx].newtt[posy].left==y1&&tt[posx].newtt[posy].right==y2){
	  tt[posx].newtt[posy].r = r[cur_index];
	  tt[posx].newtt[posy].g = g[cur_index];
	  tt[posx].newtt[posy].b = b[cur_index];
	  return;
	}
	int mid=tt[posx].newtt[posy].getnewmid();
	if(y2<=mid)
		update_y(y1,y2,posx,posy*2);
	else if(y1>mid)
		update_y(y1,y2,posx,posy*2+1);
	else{
	  update_y(y1,mid,posx,posy*2);
	  update_y(mid+1,y2,posx,posy*2+1);
	}
}
void update_x(int x1,int x2,int y1,int y2,int pos){	
	// cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
	if(tt[pos].left==x1&&tt[pos].right==x2){
	  update_y(y1,y2,pos,1);
	  return;
	}
	int mid=tt[pos].getmid();
	if(x2<=mid)
		update_x(x1,x2,y1,y2,pos*2);
	else if(x1>mid)
		update_x(x1,x2,y1,y2,pos*2+1);
	else{
	   update_x(x1,mid,y1,y2,pos*2);
	   update_x(mid+1,x2,y1,y2,pos*2+1);
	}
}
void find_y(int y,int posx,int posy){	
	if (tt[posx].newtt[posy].left) {
		rans = tt[posx].newtt[posy].r;
		gans = tt[posx].newtt[posy].g;
		bans = tt[posx].newtt[posy].b;
		cout<<"test: "<<rans<<" "<<gans<<" "<<bans<<endl;
		cout<<"pos: "<<posx<<" "<<posy<<endl;
	}
	if(tt[posx].newtt[posy].left==tt[posx].newtt[posy].right) {		
		return;
	}
	int mid=tt[posx].newtt[posy].getnewmid();
	if(y>mid)
		find_y(y,posx,posy*2+1);
	else
		find_y(y,posx,posy*2);
}
void find_x(int x,int y,int pos){
	find_y(y,pos,1);
	if(tt[pos].left==tt[pos].right)
		return;
	int mid=tt[pos].getmid();
	if(x>mid)
		find_x(x,y,pos*2+1);
	else
		find_x(x,y,pos*2);
}
int main(){	
	int n, m;
	while(true){
		int index = 0;
		xx.clear(); yy.clear();
	  scanf("%d%d",&n,&m);
	  if (n==0 && m==0) break;
	  for (int i=0; i<n; i++) {
	  	cin>>p[index].first>>p[index].second;
	  	index++;
	  	cin>>p[index].first>>p[index].second;
	  	index++;
	  	cin>>r[i]>>g[i]>>b[i];
	  	xx.push_back(p[index-2].first);
	  	xx.push_back(p[index-1].first);
	  	yy.push_back(p[index-2].second);
	  	yy.push_back(p[index-1].second);
	  }
	  sort(xx.begin(), xx.end());
	  sort(yy.begin(), yy.end());
	  xmap.clear(); ymap.clear();
	  int xlen = xx.size();
	  int ylen = yy.size();
	  int cur = 1;
	  for (int i=0; i<xlen; i++){
	   	if (xmap.find(xx[i]) == xmap.end()) {
	   		xmap[xx[i]] = cur;
	   		cur++;
	   	}
	  }
	  cur = 1;
	  for (int i=0; i<ylen; i++) {
	  	if (ymap.find(yy[i]) == ymap.end()) {
	  		ymap[yy[i]] = cur;
	  		cur++;
	  	}
	  }
	  // cout<<"before building tree"<<endl;
	  built_treex(1,xmap.size(),1);	  
	  // cout<<"after building tree"<<endl;
	  // cout<<xmap.size()<<" "<<ymap.size()<<endl;
	  for (int i=0; i<2*n; i+=2) {
	  	cur_index = i/2;
	  	// cout<<"i: "<<i<<endl;	  	
	  	update_x(xmap[p[i].first], xmap[p[i+1].first], 
	  		ymap[p[i].second], ymap[p[i+1].second], 1);
	  }
	  // cout<<"after updating tree"<<endl;
	  for (int i=0; i<m; i++) {
	  	int x, y;
	  	cin>>x>>y;
	  	for (int j=2*n-2; j>=0; j-=2) {
	  		if (p[j].first<=x && p[j].second<=y 
	  			&& p[j+1].first>=x && p[j+1].second>=y){
	  			rans = gans = bans = 0;
	  			cout<<"query: "<<xmap[p[j].first]<<" "<<xmap[p[j+1].first]
	  			<<" "<<ymap[p[j].second]<<" "<<ymap[p[j+1].second]<<endl;
	  			find_x(xmap[p[j].first], ymap[p[j].second], 1);
	  			cout<<rans<<" "<<gans<<" "<<bans<<endl;
	  			break;
	  		}
	  	}
	  }

	 //  while(m--){
	 //    scanf("%s",ss);
		// if(ss[0]=='C'){
		//   scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		//   update_x(x1,x2,y1,y2,1);
		// }
		// else{
		//   scanf("%d%d",&x,&y);
		//   ans=0;
		//   find_x(x,y,1);
		//   printf("%d\n",ans);
		// }
	 //  }
	 //  puts("");
	}
	return 0;
}
