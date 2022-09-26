/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <stdlib.h>  
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  
NODE * find( NODE * , int * );  
void outputring( NODE * );  
void change( int , int , NODE * );  
void outputring( NODE * pring )  
{   NODE * p;  
    p = pring;  
    if ( p == NULL )  
        printf("NULL");  
    else  
        do  {   printf("%d", p->data);  
            p = p->next;  
        } while ( p != pring );  
    printf("\n");  
    return;  
}  
  
int main()  
{   int n, m;  
    NODE * head, * pring;  
  
    scanf("%d%d", &n, &m);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
  
    change( n, m, head );  
    pring = find( head, &n );  
    printf("ring=%d\n", n);  
    outputring( pring );  
  
    return 0;  
}  
  
/* Here is waiting for you. 
void change( int n, int m, NODE * head ) 
{  
} 
 
NODE * find( NODE * head, int * n ) 
{ 
} 
*/  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  
前置代码
view plainprint?
/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <stdlib.h>  
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  
NODE * find( NODE * , int * );  
void outputring( NODE * );  
void change( int , int , NODE * );  
void outputring( NODE * pring )  
{   NODE * p;  
    p = pring;  
    if ( p == NULL )  
        printf("NULL");  
    else  
        do  {   printf("%d", p->data);  
            p = p->next;  
        } while ( p != pring );  
    printf("\n");  
    return;  
}  
  
int main()  
{   int n, m;  
    NODE * head, * pring;  
  
    scanf("%d%d", &n, &m);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
  
    change( n, m, head );  
    pring = find( head, &n );  
    printf("ring=%d\n", n);  
    outputring( pring );  
  
    return 0;  
}  
  
#include <math.h>  
void change(int n,int m,NODE *head){    
    NODE *swap=(NODE*)malloc(sizeof(NODE));    
    swap->data=-1;/*swap作为一个节点，存储的数据为-1，后面的为NULL*/     
    swap->next=NULL;    
    NODE *tail=head,*extail=swap;    
    int remain=n%m;/*n除以m的余数*/     
    int res;    
    while(true){    
        NODE *p=swap,*q=head;    
        res=(remain*10)/m;    
        remain=(remain*10)%m;    
        while(p->next!=NULL){    
            if((p->data==remain&&q->data==res)||(p->data==remain&&res==0)){    
                if(remain==0){    
                    tail->next=NULL;/*能除尽直接返回*/    
                    return;    
                }    
                tail->next=q;/*找到了相同的余数，并且商一样，直接循环链表*/    
                return;    
            }    
            p=p->next;    
            q=q->next;    
        }    
        if((p->data==remain&&q->data==res)||(p->data==remain&&res==0)){    
            if(remain==0){    
                tail->next=NULL;    
                return;    
            }    
            tail->next=q;    
            return;    
        }/*注意要监测最后一项，否则会出错*/    
        NODE *t=(NODE*)malloc(sizeof(NODE));    
        tail->next=t;    
        t->data=res;    
        t->next=NULL;    
        tail=t;    
        NODE *e=(NODE*)malloc(sizeof(NODE));    
        extail->next=e;    
        e->data=remain;    
        e->next=NULL;    
        extail=e;    
    }    
}  
NODE * find( NODE * head, int * n )   
{   
   NODE *check=head;  
   while(check!=NULL){  
      NODE *base=(NODE*)malloc(sizeof(NODE));  
      base->next=head;  
      base->data=-1;   
      if(check->next==NULL){  
        *n=0;  
        return check->next;  
        }  
      check=check->next;   
      while(base!=check){  
  
        base=base->next;  
        if(check->next==base){  
         int count=0;  
  
         while(base!=check){  
            base=base->next;  
            count++;  
           }  
           count++;  
           *n=count;  
         return check->next;       
        }      
      }    
        
   }   
   /**n=0; 
   return NULL;*/  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */ 
