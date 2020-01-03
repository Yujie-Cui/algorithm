#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include <queue>
#include <vector>
#include<list>
#include <algorithm>
#include<iostream>
#include<math.h>
using namespace std;
#define N 1005
#define Inf 0x3f3f3f3f
struct node{
	int s,e,r,v;
	//s是活动开始时间，e是活动结束时间，r是活动结束加上休息时间，v是收益
}g[N];
int dp[N];//以第i个活动结束的最大收益
bool cmp(node a, node b){
		return a.e<b.e;
}
int main() {
   memset(dp,0,sizeof(dp));
  int n,m,r;
  cin>>n>>m>>r;
  for(int i=0;i<m;i++){
	 cin>>g[i].s>>g[i].e>>g[i].v;
	 g[i].r = g[i].e  +  r ;
  }
  sort(g,g+m,cmp);
  int maxx = -1;
  for(int i= 0;i<m;i++){
	 dp[i] = g[i].v;       //只有当前活动时候的收益
	for(int j=0;j<i;j++){
		if(g[j].r<=g[i].s&&g[i].e<=n){
			dp[i] = max(dp[i],dp[j]+g[i].v);
			maxx = max(maxx,dp[i]);
		}
		
	}
  }
  cout<<maxx<<endl;

  return 0;
}






