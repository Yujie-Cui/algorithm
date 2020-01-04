#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define N 50001
int pre[N*3];
int findPre(int k){
	if(k!=pre[k]){
		pre[k]=findPre(pre[k]);
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
	cin>>n>>k;
	for(int i=1;i<=3*n;i++){
		pre[i] = i;
	}
	int total=0;
	for(int i=0;i<k;i++){
		int tag,x,y;
		cin>>tag>>x>>y;
		if(x>n||x<1||y>n||y<1||(tag==2&&x==y)){
			total++;
			continue;
		}
		if(tag==1){
			if(findPre(x)==findPre(y+n)||findPre(x+n)==findPre(y)){
				total++;
				continue;
			}
			join(x,y);
			join(x+n,y+n);
			join(x+2*n,y+2*n);
		}else{
			if(findPre(x)==findPre(y)||findPre(x+n)==findPre(y)){
				total++;
				continue;
			}
			join(x,y+n);
			join(x+n,y+2*n);
			join(x+2*n,y);
		}
	}
	cout<<total<<endl;
	return 0;
}
