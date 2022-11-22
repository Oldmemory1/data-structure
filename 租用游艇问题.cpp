#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
int main()
{
    int num,i,j,k,tmp;
    cin>>num;
    vector< vector<int> >List;
    vector<int>line;
    for(i=0;i<num-1;i++)
    {
        List.push_back(line);
        for(j=0;j<=i;j++)         //在容器前面添加些0，从而使List[i][j]表示从第i个出租站到第j个出租站所需的金额
        {                         //同时也去除无效的表示，比如List[0][0]直接赋值为0，从而使后面的计算更方便
            List[i].push_back(0);
        }
        for(j=i+1;j<num;j++)
        {
            cin>>tmp;
            List[i].push_back(tmp);    //从i+1个出租站到第j+1个出租站所需金额
        }
    }
    for(k=2;k<num;k++)    //从两个出租站开始，逐步计算每几个出租站之间的最优解，最终计算num-1个出租站合并的最优解
    {
        for(i=0;i<num-k;i++)
        {
            int mark=i+k;
            for(j=i+1;j<mark;j++)
            {
                if(List[i][j]+List[j][mark]<List[i][mark])    //例如List[0][1]+List[1][2]<List[0][2],则改变List[0][2]的值
                {
                    List[i][mark]=List[i][j]+List[j][mark];
                }
            }
        }
    }
    cout<<List[0][num-1]<<endl;
    return 0;
}
