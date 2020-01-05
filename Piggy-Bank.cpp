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
	  	dp[i] = Inf;          //��δװ��Ʒʱ��ֻ��dp[0]���ϣ�������Ϊ��������߸�����
	  }
	  for(int i=0;i<n;i++){   //����ǰi����Ʒ
	  	for(int j=0;j<=m;j++){//���Ǳ�������Ϊj ��ʱ��
			if(j>=w[i]){       //�����Ʒ�ܹ��Ž�ȥ
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
