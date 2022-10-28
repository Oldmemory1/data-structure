#include <bits/stdc++.h>  
  
  
typedef struct BiTNode {  
    int data;  
    struct BiTNode *LeftChild, *RightChild;  
} BiTNode,*BiTree;   
  
  
BiTree SearchBST(BiTree T,int key){   
  
    if (key<T->data){  
        if(T->LeftChild==NULL)return T;  
        else return SearchBST(T->LeftChild,key);  
    }  
    else{  
        if(T->RightChild==NULL)return T;  
        else return SearchBST(T->RightChild,key);  
    }  
}  
  
void printTree(BiTree T,int step){  //step从0开始 T从根开始  
    if(T->LeftChild!=NULL)printTree(T->LeftChild,step+1);  //左  
    for(int k=0;k<step;k++)printf("    ");  
    printf("%d\n",T->data);                          //根  
    if(T->RightChild!=NULL)printTree(T->RightChild,step+1);  //右  
}  
  
void printMidSequence(BiTree T){  //中序遍历 T为根结点  
    if(T->LeftChild!=NULL)printMidSequence(T->LeftChild);  
    printf(" %d",T->data);  
    if(T->RightChild!=NULL)printMidSequence(T->RightChild);  
}  
  
int main(){  
    int key;  
    scanf("%d",&key);  
    BiTree root=(BiTree)malloc(sizeof(BiTNode));  
    root->data=key;  
    root->LeftChild=root->RightChild=NULL;  
    while(scanf("%d",&key)&&key!=0){  
        BiTree t=SearchBST(root,key); //查找key，返回key的指针位置  
        if(key<t->data){  
            t->LeftChild=(BiTree)malloc(sizeof(BiTNode));  
            t->LeftChild->data=key;  
            t->LeftChild->LeftChild=t->LeftChild->RightChild=NULL;  
        }  
        else{  
            t->RightChild=(BiTree)malloc(sizeof(BiTNode));  
            t->RightChild->data=key;  
            t->RightChild->LeftChild=t->RightChild->RightChild=NULL;  
        }  
    }  
    printTree(root,0);  
    printf("\n");  
    printMidSequence(root);  
    printf("\n");  
    return 0;  
}  
