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
#define N 20005
#define Inf 0x3f3f3f3f

int data[N];
int mergeSort(int d[],int len){
	if(len==1){
		return 0;
	}
	int l = len/2;
	int lNum = mergeSort(d,l);       //��߲��ֵ��������
	int rNum = mergeSort(d+l,len-l); //�ұ߲��ֵ��������
	 sort(d,d+l);
	 sort(d+l,d+len);
	int sta = l;
	int total = lNum+rNum;
	for(int i=0;i<l;i++){
		for(int j=sta;j<len;j++){
			if(d[i]>d[j]){
				total += l-i;  //�������ź�����ߵ�Ԫ�ش����ұߵ�Ԫ��ʱ�����ʣ�µ����е�Ԫ�ض����ڡ�
				sta++;
			}else{
				break; //������䣬�ᳬʱ
			}
		}
	}
	return total;
	
}
int main() {

 int n;
 while(cin>>n&&n){
 	memset(data,0,sizeof(data));
 	for(int i=0;i<n;i++){
 		scanf("%d",&data[i]);
	 }
	int total =  mergeSort(data,n);
	cout<<total<<endl;
	 
 }


  return 0;
}
