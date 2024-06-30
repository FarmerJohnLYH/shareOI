#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=33*2,M=N*2*2;
int n,m,p;
int S,T;
int w[N][N];
int cs[N][N],f[N][N];
int d[N*10],dis[N];
int vis[N],pre[N],ans;
int spfa()
{
	//每次只走一条路径
	memset(dis,138,sizeof dis);
	memset(vis,0,sizeof vis);
	int hd=0,tl=1;
	d[1]=S;dis[S]=0;
	vis[S]=1;
	while(hd++<tl)
	{
		int x=d[hd];
		fo(i,1,n+m+2)
		if(x!=i&&f[x][i]>0&&dis[x]+cs[x][i]>dis[i])
		{
			pre[i]=x;
			dis[i]=dis[x]+cs[x][i];
			if(!vis[i]) vis[i]=1,d[++tl]=i;
		}
		vis[x]=0;
	}
	if(dis[T]<0)return 0;
	int x=T,tp=oo;
	while(x!=S)
	{
		tp=min(tp,f[pre[x]][x]);
		x=pre[x];
	}
	x=T;
	while(x!=S)
	{
		f[pre[x]][x]-=tp,f[x][pre[x]]+=tp;
		x=pre[x];
	}
	ans+=dis[T];
	return 1;
}
int main()
{
	freopen("pick.in","r",stdin);
	freopen("pick.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	S=n+m+1,T=n+m+2;
	fo(i,1,n) fo(j,1,m) 
	{
		scanf("%d",&w[i][j]);
		f[i][j+n]=1;
		cs[i][j+n]=w[i][j];
		cs[j+n][i]=-w[i][j];
	}
	fo(i,1,n) f[S][i]=2;
	fo(i,1+n,n+m) f[i][T]=2;
	while(spfa());
	printf("%d\n",ans);
	return 0;
}











