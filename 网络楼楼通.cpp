#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int Building[1001];
struct node{
    int from,to,cost;
}CableList[5005]; 
struct Rule{
    bool operator()(const node &A, const node &B)const{
        return A.cost<B.cost;
    }
};
void init(int cable){      //定义开头节点 每个人的开头节点都是自己
    for(int i=0;i<=cable;i++)Building[i]=i;
}
int find(int a){         //查找节点的开头节点
    if(Building[a]==a)return a;  //自己就是开头节点说明该节点没被使用过
    return Building[a]=find(Building[a]);   //如果被使用过，就不断递归去找开头节点
}
int judge(int a,int b){   //判断两个相连的节点是否成环
    if(find(a)!=find(b)){ //如果 a，b节点的开头节点不一样
        Building[find(a)]=find(b);        //则将a节点的开头设置为 b
        return 1;
    }
    return 0;
}
void kruskal(int building,int cable){   //kruskal 克鲁斯卡尔算法，计算最小生成树
    int sideselected=0,totalcost=0;
    init(cable);
    sort(CableList,CableList+cable,Rule());    //依成本顺序排列
    for(int i=0;i<cable;i++){
        if(judge(CableList[i].from,CableList[i].to)){   //如果两个相连节点的开头节点不一样
            sideselected++;                                   //选择该边
            totalcost+=CableList[i].cost;                     //更新成本
        }
        if(sideselected==building-1)break;
    }
    printf("%d\n",sideselected==building-1?totalcost:-1);
}
int main(){
    int building,cable;
    scanf("%d %d",&building,&cable);
    for(int i=0;i<cable;i++) scanf("%d %d %d",&CableList[i].from,&CableList[i].to,&CableList[i].cost);
    kruskal(building,cable);
    return 0;
}
