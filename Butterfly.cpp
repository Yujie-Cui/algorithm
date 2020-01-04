#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include <queue>
#include <vector>
#include<list>
#include <algorithm>
#include<iostream>
#include<math.h>
using namespace std;
#define N 100005
#define Inf 0x3f3f3f3f

struct node{
	int p;
	int r;
}g[N];
int findPre(int k){
	if(k==g[k].p){
		return k;
	}
   int y =g[k].p;
   int fx = findPre(g[k].p);
   g[k].p = fx;
   if(g[k].r == g[y].r){
	   g[k].r = 0;
   }else{
	   g[k].r = 1;
   }
	return g[k].p;
}
int main() {
   int n,m;
   while(cin>>n>>m){
   	
   	 for(int i=0;i<n;i++){
   	g[i].p = i;
   	g[i].r = 0;
   }
   bool flag = false;
   for(int i=0;i<m;i++){
	  int x,y,r;
	  scanf("%d%d%d",&x,&y,&r);
	  int xp = findPre(x);
	  int yp = findPre(y);
	  if(xp==yp){
		 if((g[x].r==g[y].r&&r==1)||(g[x].r!=g[y].r&&r==0)){
					flag = true;
		 }
	  }else{
	  		g[xp].p = yp;
		  	if(g[x].r==g[y].r){
		  		g[xp].r = r;
			  }else{
			  	g[xp].r = (r+1)%2;
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

