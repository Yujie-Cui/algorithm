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
	//s�ǻ��ʼʱ�䣬e�ǻ����ʱ�䣬r�ǻ����������Ϣʱ�䣬v������
}g[N];
int dp[N];//�Ե�i����������������
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
	 dp[i] = g[i].v;       //ֻ�е�ǰ�ʱ�������
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






