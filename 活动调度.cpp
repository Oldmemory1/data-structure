#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>  
#include<cmath> 
using namespace std;
int Start[1000000];
int End[1000000];
int main(){
	int ClassRoomCount=0,ActivityNumber=0,TempCount=0,i=0,j=0;
	scanf("%d",&ActivityNumber);
	for(int t=0;t<ActivityNumber;t++){
		scanf("%d %d",&Start[t],&End[t]);
	}
	sort(Start,Start+ActivityNumber);
	sort(End,End+ActivityNumber);
	while(j<ActivityNumber&&i<ActivityNumber){
		if(Start[i]<End[j]){
			TempCount++;
			i++;
			ClassRoomCount=max(ClassRoomCount,TempCount);
		}else if(Start[i]>End[j]){
			TempCount--;
			j++;
		}else{
			j++;
			i++;
			ClassRoomCount=max(ClassRoomCount,TempCount);
		}
	}
	cout<<ClassRoomCount;
	return 0; 
} 
