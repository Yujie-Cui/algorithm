#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
#define Inf 0x3f3f3f3f
#define N 13666
int w[N],v[N];
int dp[N];
int main(){
	int n,m;
	cin>>n>>m;
	memset(w,0,sizeof(w));
	memset(v,0,sizeof(v));
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++){
		cin>>w[i]>>v[i];
	}
	for(int i=0;i<n;i++){//考虑前i个物品
		for(int j=m;j>=0;j--){//考虑重量为j的时候
			if(j>=w[i]){//如果物品能够放进背包
				dp[j] = max(dp[j],dp[j-w[i]]+v[i]);//考虑放与不放的最大值
			}
		}
	}
	cout<<dp[m]<<endl;

	return 0;
}
