#include<stdio.h>
typedef struct{
	int row;
	int col;
	int value;
}item;


int main(){
	int total_row,total_col,number;
	scanf("%d %d %d",&total_row,&total_col,&number);
	item matrix[number];
	item exchanged_matrix[number];
	int i=0;
	for(i=0;i<number;i++){
		scanf("%d %d %d",&matrix[i].row,&matrix[i].col,&matrix[i].value);
	}
	int num[total_col+1];
	int cpot[total_col+1];
	for(i=0;i<=total_col;i++){
		num[i]=0;
		cpot[i]=0;
	}
	for(i=0;i<number;i++){
		num[matrix[i].col]++;
	} 
	cpot[0]=1; 
	for(i=1;i<total_col+1;i++){
		cpot[i]=cpot[i-1]+num[i-1];
	}
	printf("num:");
	for(i=1;i<total_col+1;i++){
		printf("%d,",num[i]);
	}
	printf("\n");
	printf("cpot:");
	for(i=1;i<total_col+1;i++){
		printf("%d,",cpot[i]);
	} 
	printf("\n");
	int j=0;
	for(i=0;i<number;i++){
		j=cpot[matrix[i].col]-1;
		exchanged_matrix[j].row=matrix[i].col;
		exchanged_matrix[j].col=matrix[i].row;
		exchanged_matrix[j].value=matrix[i].value;
		cpot[matrix[i].col]++;
	}
	for(i=0;i<number;i++){
		printf("%d,%d,%d\n",exchanged_matrix[i].row,exchanged_matrix[i].col,exchanged_matrix[i].value);
	}
	
	
	
	
}
