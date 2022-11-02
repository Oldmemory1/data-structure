#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;
int main(){
	int InCanteen,OutCanteen,number,n;
	scanf("%d",&n);
	getchar();
	char c;
	queue <char> List;
	for(int i=0;i<n;i++){
		InCanteen=0;
		OutCanteen=0;
		number=0;
		while(List.empty()!=true){
			List.pop();
		}
		while((c=getchar())!='\n'){
			List.push(c);
		}
		while(List.empty()==false){
			if(List.front()=='+'){
				++number;
				if(number>InCanteen){
					InCanteen=number;
				} 
			}else if(List.front()=='-'){
				--number;
				if(number<OutCanteen){
					OutCanteen=number;
				}
			}
			List.pop();
		}
		printf("%d\n",InCanteen-OutCanteen);
	}
} 
