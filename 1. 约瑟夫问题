#include<cstdio>  
#include<cstdlib>  
#include<iostream>  
#include<cstring>  
using namespace std;  
int main(){  
    long long n,k,m;  
  
      scanf("%lld,%lld,%lld",&n,&k,&m);       
      if(n<1||m<1||k<1){  
            cout << "n,m,k must bigger than 0." <<endl;  
            return 0;  
      }else if(k>n){  
            cout<<"k should not bigger than n."<<endl;  
            return 0;  
      }  
  
    long long array[n];  
    for(long long i=0;i<n;i++){  
        array[i]=1;  
    }  
    long long *p=&array[k-1];  
  
    long long q=0;  
    long long check=n;  
    for(long long po=1;po<=n;po++){  
  
  
        while(q<m){  
        if(*p==1){  
            q++;  
  
        }     
            if(q==m){  
                int x=p-&array[0];  
                if(n<=10){  
                if(po!=n){  
                printf("%d ",x+1);                    
                }else{  
                    printf("%d\n",x+1);  
                }                     
                }else if(n>10){  
                    if(po%10==0){  
                        printf("%d\n",x+1);  
                    }else if(po!=n){  
                        printf("%d ",x+1);  
                    }else if(po==n){  
                        printf("%d\n",x+1);  
                    }  
                }  
  
  
                *p=0;  
                q=0;  
                break;  
            }         
        if(p!=&array[n-1]){  
            p++;  
  
        }else{  
            p=&array[0];    
  
        }  
        }  
  
  
          
  
    }  
    return 0;   
}  
