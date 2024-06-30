#pragma GCC optimize(3)
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo ((db)213906214339062143)
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define abs(x) (((x)>0)?(x):(-(x)))
using namespace std;
typedef double db;
const int N=(110*2+1),M=N*2*2;
const db eps=0.00000000001;
int n,m,p;
int S,T;
db w[N][N];
db cs[N][N],dis[N];
int f[N][N],d[N*10];
int vis[N],pre[N];
int bz[N][N];
int a[N],b[N];
int min(int x,int y){return(x<y)?(x):(y);}
int spfa()
{
	//每次只走一条路�?
	fo(i,1,N-5) dis[i]=-oo;
	int hd=11,tl=12;
	d[12]=S;dis[S]=0;
	vis[S]=1;
	while(hd++<tl)
	{
		int x=d[hd];
		if(x==S||x==T)
		{
			fo(i,1,n+m+2)
			if(x!=i&&f[x][i]>0&&dis[x]+cs[x][i]-eps>dis[i])
			{
				pre[i]=x;
				dis[i]=dis[x]+cs[x][i];
				if(!vis[i]) 
				{
					vis[i]=1;
					d[++tl]=i;	
					if(dis[i]+eps<dis[d[hd+1]]) swap(d[tl],d[hd+1]);
				}
			}
		}
		else
		if(1<=x&&x<=n) 
		{
			fo(i,n+1,n+m+2)
			{
				if(x!=i&&f[x][i]>0&&dis[x]+cs[x][i]-eps>dis[i])
				{
					pre[i]=x;
					dis[i]=dis[x]+cs[x][i];
					if(!vis[i]) 
					{
						vis[i]=1;
					d[++tl]=i;	
					if(dis[i]+eps<dis[d[hd+1]]) swap(d[tl],d[hd+1]);
					}
				}
			}
		}
		else
		if(1+n<=x&&x<=n+m) 
		{
			fo(i,1,n+2)
			{
				if(i>n) i+=m;
				if(x!=i&&f[x][i]>0&&dis[x]+cs[x][i]-eps>dis[i])
				{
					pre[i]=x;
					dis[i]=dis[x]+cs[x][i];
					if(!vis[i]) 
					{
						vis[i]=1;
					d[++tl]=i;	
					if(dis[i]+eps<dis[d[hd+1]]) swap(d[tl],d[hd+1]);
					}
				}
				if(i>n) i-=m;
			}
		}
		vis[x]=0;
	}
	if(dis[T]<=-oo)return 0;
	int x=T,tp=213906214;
	while(x!=S)
	{
		tp=min(tp,f[pre[x]][x]);
		x=pre[x];
	}
	x=T;
	while(x!=S)
	{
		if(x-n>0&&x-n<=m&&pre[x]>=1&&pre[x]<=n) bz[pre[x]][x-n]=1;
		f[pre[x]][x]-=tp,f[x][pre[x]]+=tp; 
		if(bz[x][pre[x]-n]==1&&pre[x]-n>0&&pre[x]-n<=m&&x>=1&&x<=n) bz[x][pre[x]-n]=0;
		x=pre[x];
	}
	return 1;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d%d",&n,&m);
	S=n+m+1,T=n+m+2;
	fo(i,1,n) fo(j,1,m) 
	{
		scanf("%lf",&w[i][j]);w[i][j]=(db)log(w[i][j]);
		f[i][j+n]=1;
		cs[i][j+n]=w[i][j];
		cs[j+n][i]=-w[i][j];
	}
	fo(i,1,n) scanf("%d",&a[i]),f[S][i]=a[i];
	fo(i,1,m) scanf("%d",&b[i]),f[i+n][T]=b[i];
	while(spfa());
	fo(i,1,n) 
	{
		fo(j,1,m) putchar(bz[i][j]+'0');
		putchar('\n');
	}
	return 0;
}


