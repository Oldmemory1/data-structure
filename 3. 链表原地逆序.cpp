/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <iostream>  
using namespace std;  
  
typedef int ElemType;  
typedef struct node  
{   ElemType    data;  
    struct node * next;  
} NODE;  
typedef NODE * LinkList;  
  
void output( LinkList );  
void change( int, int, NODE * );  
LinkList createList( ElemType );  
void inverse( LinkList );   
  
LinkList createList( ElemType finish )  //finish：数据结束标记   
{  
    ElemType x;  
    NODE *newNode;   
    LinkList first = new NODE;   // 建立头结点  
    first->next = NULL;  
    first->data = finish;  
    cin >> x;                 // 约定以finish结束连续输入  
    while ( x != finish )  
    {  
        newNode = new NODE;      // 建立新结点  
        newNode->data = x;  
        newNode->next = first->next; // ①  
        first->next = newNode;       // ②  
        cin >> x;  
    }  
    return first;  
}  
  
void output( LinkList head )  
{   cout << "List:";  
    while ( head->next != NULL )  
    {   cout << head->next->data << ",";  
        head = head->next;  
    }  
    cout << endl;  
}  
  
int main(int argc, char** argv)   
{  
    LinkList head;  
  
    head = createList( -1 );  
    output( head );  
    inverse( head );  
    output( head );  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */ 
//begin    
void inverse( LinkList head){  
    NODE *newNode;  
    LinkList first=new NODE;  
    LinkList store=new NODE;  
    store->data=head->data;  
    store->next=head->next;  
    first->data=-1;  
    first->next=NULL;   
     for(;;store=store->next){  
        newNode=new NODE;  
        if(store->data==-1){  
          //donothing  
         }else{  
            newNode->next=first->next;  
            newNode->data=store->data;  
            first->next=newNode;  
         }  
         if(store->next==NULL){  
            break;  
         }   
     }    
    head->next=first->next;   
}  
//end
