#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 1000000002ll
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=880,K=1000010000;
int n,m,k;
int a[N],pv[N];
ll f[N][N];
struct node{
	int x,y,v;
}d[N*N];int d0;
bool cmp(node a,node b)
{
	return(a.v<b.v);
}
void run()
{
	f[1][0]=1;
	fo(i,2,n+m)
	{
		if(!pv[i])fo(j,0,i)
				f[i][j]=f[i-1][j+1]+((j==0)?(0):(f[i-1][j-1]));
		if(pv[i]==1)fo(j,0,i)
				f[i][j]=f[i-1][j+1];
		if(pv[i]==-1)fo(j,1,i)
				f[i][j]=f[i-1][j-1];
		fo(j,0,i)f[i][j]=min(f[i][j],oo);
	}
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	fo(i,1,n) fo(j,1,m)
	{
		int x=i,y=j,v;
		scanf("%d",&v);
		d[++d0].x=x,d[d0].y=y,d[d0].v=v;
	}
	sort(d+1,d+1+d0,cmp);
	fo(i,1,d0)
	{
		if(!pv[d[i].x+d[i].y])
		{
			memset(f,0,sizeof f);
			pv[d[i].x+d[i].y]=-1;
			run();
			if(f[n+m][0]<k) pv[d[i].x+d[i].y]=1,k-=f[n+m][0];	
		}
	}
	fo(i,1,n) 
	{
		fo(j,1,m)
			putchar((pv[i+j]==-1)?('('):(')'));
		puts("");
	}
	return 0;
}








