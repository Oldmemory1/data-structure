#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5; 
int n,a[N],b[N],k=0,flag=0;
 
void Search_Bin(int left,int right){
	int mid=(left+right)/2;
	if(left<=right){
		if(a[mid]==mid){
			b[k++]=mid;
			Search_Bin(left,mid-1);
			Search_Bin(mid+1,right);
		}
		else if(a[mid]<mid){
			if(flag==0) Search_Bin(mid+1,right);
			else Search_Bin(left,mid-1);
		}
		else if(a[mid]>mid){
			if(flag==0) Search_Bin(left,mid-1);
			else Search_Bin(mid+1,right);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	if(a[0]>a[n-1]) flag=1;
	Search_Bin(0,n-1);
	if(k>0){
		sort(b,b+k);
		for(int i=0;i<k;i++) printf("%d ",b[i]);
		printf("\n");
	}
	else printf("No \n");
}
