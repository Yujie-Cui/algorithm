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
	for(int i=0;i<n;i++){//����ǰi����Ʒ
		for(int j=m;j>=0;j--){//��������Ϊj��ʱ��
			if(j>=w[i]){//�����Ʒ�ܹ��Ž�����
				dp[j] = max(dp[j],dp[j-w[i]]+v[i]);//���Ƿ��벻�ŵ����ֵ
			}
		}
	}
	cout<<dp[m]<<endl;

	return 0;
}
