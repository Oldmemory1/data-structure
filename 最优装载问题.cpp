#include<cstdio>
#include<cstdlib>
#include<iostream> 
using namespace std;
int numbox,cargo,weight[101],currentweight=0,bestweight=0,x[101]={0},isLoaded[101]={0};

void backtrack(int i){      //搜索第i层结点
	if(i>numbox){           //到达叶节点
        if(currentweight>bestweight){    //更新最优装载重量 bestw
            bestweight=currentweight;
            for(int i=1;i<=numbox;i++)isLoaded[i]=x[i];
        }
        return;     
    }
	if(currentweight+weight[i]<=cargo){    //搜索左子树，即 x[i]=1
        x[i]=1;
		currentweight+=weight[i];           
		backtrack(i+1);
        x[i]=0;
		currentweight-=weight[i];      
	}
    backtrack(i+1);                     //搜索右子树
}

int main()
{
    scanf("%d %d",&cargo,&numbox);
    for(int i=1;i<=numbox;i++) scanf("%d",&weight[i]);
    backtrack(1);
	printf("%d\n",bestweight);
    for(int i=1;i<=numbox;i++) if(isLoaded[i])printf("%d ",i);
    printf("\n");
	return 0;
}
