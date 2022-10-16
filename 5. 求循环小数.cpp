/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  
void output( NODE *, int );  
void change( int, int, NODE * );  
  
void output( NODE * head, int kk )  
{   int k=0;  
  
    printf("0.");  
    while ( head->next != NULL && k<kk )  
    {   printf("%d", head->next->data );  
        head = head->next;  
        k ++;  
    }  
    printf("\n");  
}  
  
int main()  
{   int n, m,k;  
    NODE * head;  
  
    scanf("%d%d%d", &n, &m, &k);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
    change( n, m, head );  
    output( head,k );  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  

#include <math.h>  
#include<stdlib.h>  
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
