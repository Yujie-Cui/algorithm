#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<stdio.h>
using namespace std;
#define Inf 0x3f3f3f3f
#define N 100005

struct node{
	int h;     //�߶�
	int m;     //�������
	int num;   //����
}g[N];
int used[N];  
int dp[N];    //dp[j] = 1��ʾ���Դﵽj�߶�

bool cmp(node a,node b){
	return a.m<b.m;
}
int main(){

int n;
cin>>n;
for(int i=0;i<n;i++){
	cin>>g[i].h>>g[i].m>>g[i].num;
}
int maxx= 0;
memset(dp,0,sizeof(dp));
sort(g,g+n,cmp);
dp[0] = 1;
for(int i=0;i<n;i++){
	memset(used,0,sizeof(used));     // used[j] ��ʾ��j�߶�ʱ�õ�ʯ��i������
	for(int j= g[i].h;j<=g[i].m;j++){
		if(dp[j-g[i].h]==1&&!dp[j]&&(used[j-g[i].h]+1<=g[i].num)){
			dp[j] = 1;
			used[j] = used[j-g[i].h]+1;
			maxx = max(maxx,j);
		}
	}
}

cout<<maxx<<endl;


return 0;

}
