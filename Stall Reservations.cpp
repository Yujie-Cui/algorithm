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

struct node{
	int s;    //��Ŀ�ʼʱ��
	int e;    //��Ľ���ʱ��
	int ind;  //ţ�����ţ���
	int l;    //ţ�����
	friend bool operator>(node a,node b){
		return a.e>b.e; //���ȶ��� ��ţ��Ľ���ʱ������
	}
}g[N];

bool cmp(node a,node b){
	return a.s<b.s;  //����ʼʱ������
}
bool cmp2(node a,node b){
	return a.l<b.l;  //��ţ���������
}
int main() {
   int n;
   while(cin>>n){
   	memset(g,0,sizeof(g));
   	for(int i=0;i<n;i++){
   	scanf("%d%d",&g[i].s,&g[i].e);
   	g[i].l = i;
   }
   sort(g,g+n,cmp);
   priority_queue<node,vector<node>,greater<node> > q;
   g[0].ind = 1;
   q.push(g[0]);
   int total = 1;
   for(int i=1;i<n;i++){
	  node b = q.top();
	  if(g[i].s<=b.e){
		  total++;
		  g[i].ind = total;
		  q.push(g[i]);
	  }else{
		q.pop();
		g[i].ind = b.ind;
		q.push(g[i]);
	  }
   	}
	cout<<total<<endl;
	sort(g,g+n,cmp2);
	for(int i=0;i<n;i++){
		cout<<g[i].ind<<endl;
	}
}
   
  return 0;
}






