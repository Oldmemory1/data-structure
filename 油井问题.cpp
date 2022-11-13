#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
vector<int> q;
int QuickSort(int l, int h) { 
    int low=l,high=h; 
    int pir=q[low]; 
    while(low<high){ 
        while(low<high && q[high]>=pir)--high;
        if(low<high)q[low++]=q[high];
        while (low<high && q[low]<=pir)++low;
        if(low<high)q[high--]=q[low]; 
    } // 交替扫描结束
   q[low]=pir; 
    return low; 
}
void Search(int well){
    int i=0,low=0,high=q.size()-1;
    while(1){
        i=QuickSort(low,high);
        if(i<well)low=i+1;
        else if(i>well)high=i-1;
        else break;
    }
}
int middle(int length){
    if(length%2==0)return length/2-1;
    else return length/2;
}
int main(){
    int x,y,n;
    while(scanf("%d,%d",&x,&y)!=EOF)q.push_back(y);
    n=middle(q.size());
    Search(n);
    printf("%d\n",q[n]);
    return 0;
}
