#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (int pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
int lowbit(int x) {return((x)&(-x));}
int min(int x,int y){return (x>y)?(y):(x);}
int max(int x,int y){return (x>y)?(x):(y);}
const int N=5050,Mo=16777216;
int n;
int a[N][N];
int cnt(int ax,int ay,int bx,int by)
{
	ax=max(ax,1),ay=max(ay,1);
	bx=min(bx,n),by=min(by,n);
	if(ax>bx||ay>by) return 0;
	return(a[bx][by]-a[ax-1][by]-a[bx][ay-1]+a[ax-1][ay-1]);
}
int p[N];
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n)
	{
		int x;
		scanf("%d",&x);
		p[i]=x;
		a[i][x]=1;
	}
	fo(i,1,n) fo(j,1,n)
		a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	int sum1=0,sum2=0,sum3=0;
	fo(i,1,n) fo(j,i+1,n)
	{
		if(p[i]>p[j])
		{
			sum1=(sum1+(cnt(1,1,i-1,p[j]-1))*(cnt(j+1,p[i]+1,n,n)))%Mo;
			sum3=(sum3+cnt(1,1,i-1,p[j]-1)*cnt(i+1,p[i]-1,j-1,p[j]+1))%Mo;
		}
		if(p[i]<p[j])
		{
			sum2=(sum2+(cnt(j+1,p[i]+1,n,p[j]-1))*cnt(1,1,i-1,p[i]-1))%Mo;//2 3
			printf("");
		}
	}
	printf("%d\n",(sum1-sum2-sum3+Mo*5)%Mo);
	return 0;
}
