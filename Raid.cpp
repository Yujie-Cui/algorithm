#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<stdio.h>
#include<math.h>
#include<iomanip>
using namespace std;
#define Inf 0x3f3f3f3f
#define N 10005

struct node{
	double x;
	double y;
	int flag;
}g[N];
double minn = Inf;
double dis(int index1,int index2){
	return (double)sqrt( pow(g[index1].x-g[index2].x,2)  + pow(g[index1].y-g[index2].y,2)          );
}
bool cmp(node a,node b){
	if(a.x!=b.x){
		return a.x<b.x;
	}else{
		return a.y<b.y;
	}
}
double absV(double a){
	if(a<0){
		return -a;
	}else{
		return a;
	}
}
double calDis(int sta,int end){
	if(sta>=end){
		return Inf;
	}
	int mid = (sta+end)/2;
	minn = min(minn,calDis(sta,mid));
	minn = min(minn,calDis(mid+1,end));
	for(int i =sta;i<=mid;i++){
		for(int j = mid+1;j<=end;j++){
			if(g[i].flag == g[j].flag){
				continue;
			}
			if(absV(g[i].x-g[j].x)>=minn||absV(g[i].y-g[j].y)>=minn){
				continue;
			}else{
				minn = min(minn,dis(i,j));
			}
		}
	}
	return minn;
	
}


int main(){

int t;
cin>>t;
while(t--){
	minn = Inf;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>g[i].x>>g[i].y;
		g[i].flag = 0;
	}
	for(int i=n;i<2*n;i++){
		cin>>g[i].x;
		cin>>g[i].y;
		g[i].flag = 1;
	}
	sort(g,g+2*n,cmp);
	double res = calDis(0,2*n-1);
	cout<<setiosflags(ios::fixed)<<setprecision(3)<<minn<<endl;
}


return 0;

}
