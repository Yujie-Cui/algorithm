#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<stdio.h>
using namespace std;
#define Inf 0x3f3f3f3f
#define N 100005

struct node{
   int value;  //硬币的面值
   int num;    //硬币的数量
}g[N];
int used[N];  
int dp[N];    //dp[j] = 1 为总和为j是可以达到的

int main(){
  int n,m;
  while(cin>>n>>m){
  	if(n==0&&m==0){
  		break;
	  }
memset(g,0,sizeof(g));
memset(dp,0,sizeof(dp));
for(int i=0;i<n;i++){
  	cin>>g[i].value;
  }
for(int i=0;i<n;i++){
  	cin>>g[i].num;
  }
  dp[0] = 1;
  int total = 0;
  for(int i=0;i<n;i++){
  	memset(used,0,sizeof(used)); //used[j]   表示总和为i时第i个硬币使用的数量
  	for(int j=g[i].value;j<=m;j++){
  		if(dp[j-g[i].value]==1&&!dp[j]&&(used[j-g[i].value]+1<=g[i].num)){
  			dp[j] = 1;
  			used[j] = used[j-g[i].value]+1;
  			total++;
		  }
	  }

  }
  	
  	cout<<total<<endl;
  	
  }
  

  
return 0;

}
