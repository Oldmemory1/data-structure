#include <bits/stdc++.h>
using namespace std;
void max_heapify(int arr[], int start, int end) {  //建立大根堆
    //建立父节点指标和子节点指标
    int father = start;
    int son = father*2+1;
    while (son<=end){  //若子节点指标在范围内才做比较
        if (son + 1 <= end && arr[son] < arr[son + 1]){son++;} //先比较两个子节点大小，选择最大的
        if (arr[father] > arr[son])return; //如果父节点大子节点代表调整完毕，直接跳出函数
        else{//否则交换父子内容再继续子节点和孙节点比较
            swap(arr[father],arr[son]);
            father = son;
            son = father*2+1;
        }
    }
}
void heap_sort(int arr[], int len) {   //排序堆
    int k=1; 
    for (int i=len/2-1; i>=0; i--)max_heapify(arr,i,len-1);
    for(int i=0;i<len;i++)printf("%d ",arr[i]);
    printf("\n");
    for (int i=len-1;i>0;i--){     
        swap(arr[0],arr[i]);
        max_heapify(arr,0,i-1);
        if(k<=2){
            for(int i=0;i<len-k;i++)printf("%d ",arr[i]);
            printf("\n");
        }
        k++;
        
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    heap_sort(a,n);
    return 0;
}
