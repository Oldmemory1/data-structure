#include<iostream>  
#include<stack>  
#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
using namespace std;  
  
int main(){  
    int high_priority[128]={0};//运算符优先级  
    high_priority['+']=1;  
    high_priority['-']=1;  
    high_priority['*']=2;  
    high_priority['/']=2;  
    high_priority['^']=3;  
    high_priority['(']=4;  
    high_priority[')']=5;  
    high_priority['#']=-1;  
    int N;  
    scanf("%d",&N);  
    for(int i=1;i<=N;i++){  
        stack<char> calculation;  
        while(1){  
            char p;  
            cin>>p;  
            switch(high_priority[p]){  
            case 0:  
                //cout<<p;  
                printf("%c",p);  
                break;  
            case 5:  
                while(calculation.top()!='('){  
                    cout<<calculation.top();  
                    calculation.pop();  
                }  
                calculation.pop();  
                break;  
            case -1:  
                while(!calculation.empty()){  
                    cout<<calculation.top();  
                    calculation.pop();  
                }  
                goto end;  
            default:  
                while(!calculation.empty()&&high_priority[calculation.top()]>=high_priority[p]){  
                    if(p=='^'){break;}  
                    if(calculation.top()=='('){break;}  
                    //cout<<calculation.top();  
                    printf("%c",calculation.top());  
                    calculation.pop();  
                }  
                calculation.push(p);  
            }  
        }  
        end:;  
        //cout<<endl;  
        printf("\n");  
    }  
    return 0;  
}  
