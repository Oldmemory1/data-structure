#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<cstring> 
using namespace std;
class Link{
	private:
	int Data;

	public:
	Link* NextLink;
	public:
	int GetData(){
		return this->Data;
	}
	void SetData(int n){
		this->Data=n;
	}
};
class Node{
	private:
	char Data;
	int Number;

	public:
	Node* NextNode;
	Link* LinkList;
	bool IsVisited;
	public:
	char GetData(){
        return this->Data;	
	}
	int GetNumber(){
		return this->Number;
	}
	void SetNumberAndData(char input,int num){
		this->Data=input;
		this->Number=num;
		this->IsVisited=false;
		this->NextNode=NULL;
		this->LinkList=NULL;
	}
 
}; 

int main(){
	char input;
	int num=0;
	Node *check=new Node;
	Node *start=new Node;
	while(true){
		input=getchar();
        if(input=='*'){
			break;
		}else if(input=='\n'){
			continue;
		}else{
			Node* Anode=new Node;
			Anode->SetNumberAndData(input,num);
			Anode->LinkList=NULL;
		    if(num==0){
			    start=Anode;
			    check=Anode;
		    }else{
			    check->NextNode=Anode;
			    check=check->NextNode;
		    }
		}
		num++;
	}
	Link* CheckLink=new Link; 
	while(true){
		int num1,num2;
		scanf("%d,%d",&num1,&num2);
		check=start;
        if(num1==-1||num2==-1){
        	break;
		}else{
		    while(true){
			    if(check->GetNumber()==num1){
				    if(check->LinkList==NULL){//临接链表啥也没有，那就第一个存储下数据 
					    Link* temp=new Link;
					    temp->SetData(num2);
					    temp->NextLink=NULL;
					    check->LinkList=temp;
				    }else{				   	    
				   	    CheckLink=check->LinkList;
						Link *tempA=new Link;
						tempA->SetData(num2);
						Link *change=new Link;
						change=check->LinkList;
						check->LinkList=tempA;
						tempA->NextLink=change; 
				   	    
				   }
				   break;
			    }else{
			   	    check=check->NextNode;
			    }
		    }	
			check=start;
			while(true){
			    if(check->GetNumber()==num2){

				    if(check->LinkList==NULL){//临接链表啥也没有，那就第一个存储下数据 

					    Link* temp=new Link;
					    temp->SetData(num1);
					    temp->NextLink=NULL;
					    check->LinkList=temp;


				    }else{

				   	    
				   	    CheckLink=check->LinkList;
						Link *tempA=new Link;
						tempA->SetData(num1);
						Link *change=new Link;
						change=check->LinkList;
						check->LinkList=tempA;
						tempA->NextLink=change; 
				   	    
				   }
				   break;
			    }else{
			   	    check=check->NextNode;
			    }				
			}
					
		}
	}

	Node* BFS=new Node;
	queue <Node*> List1;
	queue <Node*> List2;
	queue <char> Search;
	//List1.push(start);
	Node* Find=new Node;
	Node* temps=new Node;
	Node* FindFirstIn=new Node;
	Node* CheckAllVisit=new Node;
	/*List1.push(start);
	Search.push(start->GetData());*/ 
	
while(true){
	FindFirstIn=start;
	for(CheckAllVisit=start;CheckAllVisit!=NULL;CheckAllVisit=CheckAllVisit->NextNode){
		if(CheckAllVisit->IsVisited==false){
			List1.push(CheckAllVisit);
			Search.push(CheckAllVisit->GetData());
			break;
		}
	}
	if(CheckAllVisit==NULL){
		break;
	}
	while(List1.empty()==false){
		BFS=List1.front();
		List1.pop();
		BFS->IsVisited=true;
		//Search.push(BFS->GetData());
		Link* SearchLink=BFS->LinkList;
		int num;
		while(SearchLink!=NULL){
			num=SearchLink->GetData();
			for(Find=start;Find!=NULL;Find=Find->NextNode){
				if(Find->GetNumber()==num&&Find->IsVisited==false){
					Search.push(Find->GetData());
					Find->IsVisited=true;
					List2.push(Find);
				}else{
					continue;
				}
			}			
			SearchLink=SearchLink->NextLink;
		}
		if(List2.empty()==true&&List1.empty()==true){
			break;
		}
		if(List1.empty()==true){
			while(List2.empty()==false){
                temps=List2.front();
                List2.pop();
                List1.push(temps);
			}
		}
	}		
}


	printf("the ALGraph is\n");
	while(start!=NULL){ 
	    if(start->LinkList==NULL){
	    	printf("%c\n",start->GetData());
		}else{
		   printf("%c ",start->GetData());
		   while(start->LinkList!=NULL){
		    	if(start->LinkList->NextLink==NULL){
			    printf("%d\n",start->LinkList->GetData());				
			    }else{
			    printf("%d ",start->LinkList->GetData());				
			    } 
                start->LinkList=start->LinkList->NextLink;
		    } 			
		} 

		start=start->NextNode;

	}	
	char output;
	printf("the Breadth-First-Seacrh list:");
	while(Search.empty()==false){
		output=Search.front();
		cout<<output;
		Search.pop();
	}
	printf("\n");
	return 0;
}
