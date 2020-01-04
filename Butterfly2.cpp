#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define N 1005
int pre[N*2];

int findPre(int k){
	if(k!=pre[k]){
		pre[k] = findPre(pre[k]);
	}
	return pre[k];
}
void join(int x,int y){
	int fx = findPre(x);
	int fy = findPre(y);
	pre[fx] = fy;
}
int main(){
	int n,k;
	while(cin>>n>>k){
	bool flag = false;
	for(int i=0;i<2*n;i++){
		pre[i] = i;
	}
	for(int i=0;i<k;i++){
		int tag,x,y;
		scanf("%d%d%d",&x,&y,&tag);
		if(flag){
			continue;
		}
		if(tag==0){
			if(findPre(x)==findPre(y+n)||findPre(x+n)==findPre(y)){
				flag = true;
			}else{
				join(x,y);
				join(x+n,y+n);
			}
		}else{
			if(findPre(x)==findPre(y)||findPre(x+n)==findPre(y+n)){
				flag = true;
			}else{
				join(x,y+n);
				join(x+n,y);
			}

		}
	}
		if(flag){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
		
	}
	
	
	

	return 0;
}
