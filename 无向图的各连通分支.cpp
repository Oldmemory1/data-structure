#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<cstring> 
using namespace std;
class Node{
    private:
    int Data;
    public:
    int LinkList[9];
	Node* NextNode;
	bool Visited;
    public:
	int GetData(){
	    return this->Data;
    }
	void SetData(int num){
		this->Data=num;
		this->NextNode=NULL;
		for(int j=0;j<9;j++){
			this->LinkList[j]=-1;
		}
		this->Visited=false;
	}	
};
int cmp(const void *a,const void* b){
	return *(int*)a-*(int*)b;
}
int main(){
	int Total,i;
	scanf("%d",&Total);
	Node *temp=new Node;
	Node *Start=new Node;
	for(i=0;i<Total;i++){
		if(i==0){
			Node *NewNode=new Node;
			NewNode->SetData(i);
			temp=NewNode;
			Start=NewNode;
		}else{
			Node *NewNode=new Node;
			NewNode->SetData(i);
			temp->NextNode=NewNode;
			temp=temp->NextNode; 
		}
	}
	/*for(;Start!=NULL;Start=Start->NextNode){
		cout<<Start->GetData()<<endl;
		cout<<Start->LinkList[0]<<endl;
	}*/
	while(true){
		int left,right;

		scanf("%d",&left);
		if(left==-1){
			break;
	    }
		scanf("%d",&right);		
		//printf("%d %d\n",left,right);
        Node *Check=Start;
        for(Check=Start;Check!=NULL;Check=Check->NextNode){
        	if(Check->GetData()==left){
        		for(int j=0;j<9;j++){
        			if(Check->LinkList[j]==-1){
        				Check->LinkList[j]=right;
        				break;
					}
				}
			}
			if(Check->GetData()==right){
				for(int j=0;j<9;j++){
					if(Check->LinkList[j]==-1){
						Check->LinkList[j]=left;
						break;
					}
				}
			} 	
		}
	}
	Node *CheckALL=new Node;
	CheckALL=Start;
	while(CheckALL!=NULL){
		qsort(CheckALL->LinkList,9,sizeof(int),cmp);
		CheckALL=CheckALL->NextNode; 
	}
	CheckALL=Start;
	/*while(CheckALL!=NULL){
		printf("内部数据：%d\n",CheckALL->GetData());
		printf("连接点:");
		for(int j=0;j<9;j++){
			if(CheckALL->LinkList[j]==-1){
				continue;
			}else{
				printf("%d,",CheckALL->LinkList[j]);
			}
		}
		
		printf("\n");
		CheckALL=CheckALL->NextNode;
	}*/
	queue<Node*> List1;//当前应该遍历的 
	queue<Node*> List2;
	queue<int> SearchResult;
	Node *FirstIn=new Node;
	Node *BFS=new Node;
	
    while(true){
    	CheckALL=Start;
    	FirstIn=Start;
    	for(FirstIn=Start;FirstIn!=NULL;FirstIn=FirstIn->NextNode){
    		if(FirstIn->Visited==false){
    			List1.push(FirstIn);
    			SearchResult.push(FirstIn->GetData());
				break;
			}
		}
		if(FirstIn==NULL){
			break;
		}
		while(List1.empty()==false){
			BFS=List1.front();
			List1.pop();
			int num;
			BFS->Visited=true;
			for(int j=0;j<9;j++){
				num=BFS->LinkList[j];
				if(num!=-1){
					for(CheckALL=Start;CheckALL!=NULL;CheckALL=CheckALL->NextNode){
						if(CheckALL->GetData()==num&&CheckALL->Visited==false){
							CheckALL->Visited=true;
							List2.push(CheckALL);
							SearchResult.push(CheckALL->GetData());
							break;
						}
					}
				}
			}
			if(List1.empty()==true&&List2.empty()==true){
				//这里输出队列SearchResult里面所有数据之后，马上把SearchResultPop干净
				char OutputChar;
				 
				while(SearchResult.empty()==false){
					OutputChar=SearchResult.front();
					SearchResult.pop();
					if(SearchResult.empty()==true){
						printf("%d\n",OutputChar);
					}else{
						printf("%d-",OutputChar);
					}
				} 
				break;
			}
			if(List1.empty()==true&&List2.empty()==false){
				Node* storage=new Node;
				while(List2.empty()==false){
					storage=List2.front();
					List2.pop();
					List1.push(storage);
				}
			}
		}
	}	
	 
	
	return 0;
}
