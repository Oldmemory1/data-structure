/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */    
  
#include <stdio.h>    
#include <stdlib.h>    
#include<math.h>   
#include<iostream>  
using namespace std;  
    
typedef struct node    
{   int    coef, exp;    
    struct node  *next;    
} NODE;    
    
void multiplication( NODE *, NODE * , NODE * );    
void input( NODE * );    
void output( NODE * );    
  
  
  
void multiplication(NODE *A,NODE *B,NODE *C){  
      
    NODE *pa,*pb,*t,*pr,*p,*q;  
    int k;  
    pa=A->next;  
  
    while(pa!=NULL){  
        pb=B->next;  
        while(pb!=NULL){  
            k=pa->exp+pb->exp;  
            if(fabs(pa->coef*pb->coef)<0.001){  
                k=0;  
            }   
            pr=C;  
            p=pr->next;  
            while(p!=NULL&&p->exp>k){  
                pr=p;  
                p=p->next;  
            }  
            if(p==NULL||p->exp<k){  
                q=(NODE *)malloc(sizeof(NODE));  
                q->coef=pa->coef*pb->coef;  
                q->exp=k;  
                pr->next=q;  
                q->next=p;  
            }  
            else{  
                p->coef+=pa->coef*pb->coef;  
                if(fabs(p->coef)<0.001&&p->exp!=0){  
                    pr->next=p->next;  
                    free(p);  
                }  
            }  
            pb=pb->next;   
        }  
        pa=pa->next;  
        //t=t->next;  
    }  
  
    pr=C;   
    NODE *check=(NODE*)malloc(sizeof(NODE));  
    check=NULL;   
    int i=0;   
    while(pr!=NULL){  
        if(i==0){  
            pr=pr->next;  
        }else{  
            NODE *temp=(NODE*)malloc(sizeof(NODE));  
            temp->next=check;  
            temp->exp=pr->exp;  
            temp->coef=pr->coef;  
            check=temp;  
            pr=pr->next;  
        }  
        i++;  
    }  
    C->next=check;  
    C->exp=-1;  
    C->coef=-1;  
  
}    
  
void input( NODE * head )    
{   int flag, sign, sum, x;    
    char c;    
    
    NODE * p = head;    
    
    while ( (c=getchar()) !='\n' )    
    {    
        if ( c == '<' )    
        {    sum = 0;    
             sign = 1;    
             flag = 1;    
        }    
        else if ( c =='-' )    
             sign = -1;    
        else if( c >='0'&& c <='9' )    
        {    sum = sum*10 + c - '0';    
        }    
        else if ( c == ',' )    
        {    if ( flag == 1 )    
             {    x = sign * sum;    
                  sum = 0;    
                  flag = 2;    
          sign = 1;    
             }    
        }    
        else if ( c == '>' )    
        {    p->next = ( NODE * ) malloc( sizeof(NODE) );    
             p->next->coef = x;    
             p->next->exp  = sign * sum;    
             p = p->next;    
             p->next = NULL;    
             flag = 0;    
        }    
    }    
}    
    
void output( NODE * head )    
{    
    while ( head->next != NULL )    
    {   head = head->next;    
        printf("<%d,%d>,", head->coef, head->exp );    
    }    
    printf("\n");    
}    
    
int main()    
{   NODE * head1, * head2, * head3;    
    
    head1 = ( NODE * ) malloc( sizeof(NODE) );    
    input( head1 );    
    
    head2 = ( NODE * ) malloc( sizeof(NODE) );    
    input( head2 );    
    
    head3 = ( NODE * ) malloc( sizeof(NODE) );    
    head3->next = NULL;    
    multiplication( head1, head2, head3 );    
    
    output( head3 );    
    return 0;    
}    
    
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  
