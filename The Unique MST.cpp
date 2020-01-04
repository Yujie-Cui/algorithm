#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define N 10005
int pre[N];
bool first;
bool isUni;
struct node{
	int s,e,w;
	int use;
}g[N];
int findPre(int k){
	if(k!=pre[k]){
		pre[k] = findPre(pre[k]);
	}
	return pre[k];
}
bool cmp(node a, node b){
	if(a.w!=b.w){
		return a.w<b.w;
	}
	return a.use<b.use;
}
int mst(int n){
	int total = 0;
	for(int i=0;i<n;i++){
		int x = g[i].s;
		int y = g[i].e;
		int fx = findPre(x);
		int fy = findPre(y);
		if(fx==fy){
			continue;
		}else{
			total+=g[i].w;
			pre[fx] = fy;
			if(first){
				g[i].use = 1;
			}else{
				if(g[i].use==0){
				  isUni = false;
				}
			}
		}
	}
	return total;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		first = true;
		isUni = true;
		for(int i=0;i<=n;i++){
			pre[i] = i;
		}
		for(int i=0;i<m;i++){
			int s,e,w;
			cin>>g[i].s>>g[i].e>>g[i].w;
			g[i].use = 0;
		}
		sort(g,g+m,cmp);
		int total1 =mst(m);
		first = false;
		sort(g,g+m,cmp);
		for(int i=0;i<=n;i++){
			pre[i] = i;
		}
		int total2 = mst(m);
		if(isUni){
			cout<<total1<<endl;
		}else{
			cout<<"Not Unique!"<<endl;
		}
	}
	return 0;
}
