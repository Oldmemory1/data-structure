#include <bits/stdc++.h>
using namespace std;
const double INF = 1e20;
struct point{
	double x,y;
}a[100005],b[100005];
bool compareY(point a,point b){
    return a.y<b.y;
}
bool compareXY(point a,point b){			//按照x从小到大，x相等y从小到大排序
	return(a.x==b.x?a.y<b.y:a.x<b.x);
}

double distance(point a,point b){
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
double Search (int low,int high){
    int c=0;
    if(low==high)return INF;
    if(high-low==1)return distance(a[low],a[high]);
    int mid=(low+high)/2;   
    double x=min(Search(low,mid),Search(mid+1,high));  //min(左半区间最小值, 右半区间最小值)
    for(int i=low;i<=high;i++){
        if(fabs(a[i].x-a[mid].x)<=x)b[c++]=a[i];
    }
    sort(b,b+c,compareY);
    for(int i=0;i<c;i++){
        for(int j=i+1;j<c;j++){
            if(b[j].y-b[i].y>=x)break;  //乐观剪枝，y的差值已经超过d就没有计算意义
            x=min(x,distance(b[i],b[j]));
        }
    }
    return x;
}
int main(){
	int n;
	while(~scanf("%d",&n) && n){
		for(int i = 0;i < n;i++){
			scanf("%lf%lf",&a[i].x,&a[i].y);
		}
		sort(a,a+n,compareXY);
		double ans = Search(0,n-1)/2;
		printf("%.2f\n",ans);
	}
	return 0;
} 
