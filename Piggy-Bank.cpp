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
    int t;
    cin>>t;
    while(t--){
	  int e,f;
	  cin>>e>>f;
	  int m = f-e;
	  int n;
	  cin>>n;
	  for(int i=0;i<n;i++){
	  	cin>>v[i]>>w[i];
	  }
	  for(int i=1;i<=m;i++){
	  	dp[i] = Inf;          //当未装物品时，只有dp[0]符合，其他置为正无穷或者负无穷
	  }
	  for(int i=0;i<n;i++){   //考虑前i个物品
	  	for(int j=0;j<=m;j++){//考虑背包称重为j 的时候
			if(j>=w[i]){       //如果物品能够放进去
				dp[j] = min(dp[j],dp[j-w[i]]+v[i]);
			}
		  }
	  }
	  if(dp[m]==Inf){
	  	cout<<"This is impossible."<<endl;
	  }else{
	  	cout<<"The minimum amount of money in the piggy-bank is "<<dp[m]<<"."<<endl;
	  }

	}

	return 0;
}
