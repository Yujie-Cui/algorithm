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
#define N 50005
#define Inf 0x3f3f3f3f
int mid[N];
int post[N];
void findPre(int m[],int p[],int len){
	if(len==0){
		return ;
	}
	int index = -1;
	for(int i=0;i<len;i++){
		if(m[i]==p[len-1]){
			index = i;
			break;
		}
	}
	cout<<m[index]<<" ";
	findPre(m,p,index);
	findPre(m+index+1,p+index,len-index-1);
	return;
}
int main() {
	int len = 0;
	int d;
	while(cin>>d){
	  mid[len] = d;
	  len++;
	  char ch = cin.get();   //能够接收空格和换行符
	  if(ch=='\n'){
	  	break;
	  }
	}
	len = 0;
	while(cin>>d){
	  post[len] = d;
	  len++;
	  char ch = cin.get();
	  if(ch=='\n'){
	  	break;
	  }
	}
	findPre(mid,post,len);



  return 0;
}

