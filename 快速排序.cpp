#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
int mid[100],k=0,a[1000];
void InsertSort(int a[],int left,int right){ //插入排序
    int temp,j;
    for(int i=left + 1; i<=right; i++){
        temp=a[i];
        for(j=i-1;j>=0&&a[j]>temp;j--)a[j+1]=a[j];
        if (j!=i-1)a[j+1]=temp;
    }
}

int median3(int numbers[], int left, int right){
    int mid = (left+right)/2;
    int temp[3];
    temp[2] = numbers[right];
    temp[1] = numbers[mid];
    temp[0] = numbers[left];
    for(int i=0;i<3;i++)
        for(int j=i+1;j<3;j++)
            if(temp[i]>temp[j]){
                int a = temp[i];
                temp[i]=temp[j];
                temp[j]=a;
            }
    numbers[left] = temp[0];
    numbers[right] = temp[1];
    numbers[mid] = temp[2];
    return temp[1];
}

void QuickSort(int A[],int Left,int Right){
    if (Right-Left<5) InsertSort(A,Left,Right); //cutoff=5
    else{
        /*改进的快速排序*/
        mid[k++]=median3(A,Left,Right);
        int Pivot=A[Right]; /* 选择枢轴*/
        int i=Left,j=Right-1; 
        while(true){ 
            while (i<j&&A[i]<Pivot)i++;/* 从左扫描 */
            while (i<j&Pivot<A[j])j--; /* 从右扫描 */
            if(i<j){
                swap(A[i],A[j]); 
                i++,j--;
            }/* 部分调整 */
            else break; /* 调整完成 */
        } 
        if(A[i]>=Pivot){
            A[Right]=A[i];
            A[i]=Pivot;
        }
        //swap(A[i],A[Right-1]); /* 存储pivot*/
        QuickSort(A,Left,i-1); /* 递归的对左边进行快速排序 */
        QuickSort(A,i+1,Right); /*递归对右边进行快速排序 */
    }
}

int main(){
    int i=-1;
    char x[20];
    while(1){
        scanf("%s",x);
        if(strcmp(x,"#")==0)break;
        a[++i]=atoi(x);
    }
    QuickSort(a,0,i);
    printf("After Sorting:\n"); 
    for(int j=0;j<=i;j++)printf("%d ",a[j]);
    printf("\nMedian3 Value:\n"); 
    if(k>0){
        for(int j=0;j<k;j++)printf("%d ",mid[j]);
        printf("\n");
    }
    else printf("none\n");
    return 0;
}
