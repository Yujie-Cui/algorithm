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
#define N 500005
#define Inf 0x3f3f3f3f

int data[N];
long long mergeSort(int d[],int len){
	if(len==1){
		return 0;
	}
	int l = len/2;
	long long lNum = mergeSort(d,l);       //左边部分的逆序对数
	long long rNum = mergeSort(d+l,len-l); //右边部分的逆序对数
	 sort(d,d+l);
	 sort(d+l,d+len);
	int sta = l;
	long long total = lNum+rNum;
	for(int i=0;i<l;i++){
		for(int j=sta;j<len;j++){
			if(d[i]>d[j]){
				total += l-i;  //由于已排好序，左边的元素大于右边的元素时，左边剩下的所有的元素都大于。
				sta++;
			}else{
				break; //不加这句，会超时
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
	long long total =  mergeSort(data,n);//开long long ，否则会报错
	cout<<total<<endl;
	 
 }


  return 0;
}

