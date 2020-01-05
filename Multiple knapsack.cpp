#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<stdio.h>
using namespace std;
#define Inf 0x3f3f3f3f
#define N 10005

struct node{
	int value;
	int volumn;
}g[N];
int dp[N];
int main(){

 int v,m;
 cin>>v>>m;
 memset(dp,0,sizeof(dp));
 memset(g,0,sizeof(g));
 int cnt = 0;
 for(int i=0;i<m;i++){
	int temp = 1;
	int num,volumn,value;
	cin>>num>>volumn>>value;
	while(num-temp>0){//进行拆分
		g[cnt].volumn = temp*volumn;
		g[cnt].value = temp*value;
		cnt++;
		num = num - temp;
        temp = temp*2;
	}
	    g[cnt].volumn = num*volumn;
		g[cnt].value = num*value;
		cnt++;
 }
 for(int i=0;i<cnt;i++){//按0-1背包进行求解
 	for(int j=v;j>=g[i].volumn;j--){
 		dp[j] = max(dp[j],dp[j-g[i].volumn]+g[i].value);
	 }
 }
 cout<<dp[v]<<endl;


return 0;

}
