#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define x first
#define y second
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=5050;
int n,m;
int nex[N*2],las[N],to[N*2],tot;
int bz[N][N];
pair<int,int> a[N*2];int a0;
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
int d[N],ans[N],d0,vis[N];
void update()
{
	int flag=0;
	fo(i,1,n)
		if(d[i]!=ans[i]) 
		{
			if(d[i]<ans[i]) 
				flag=1;
			break;
		}
	if(flag) fo(i,1,n) ans[i]=d[i];
}
void run(int x,int f)
{
	vis[x]=1;
	d[++d0]=x;
	for(int tp=las[x];tp;tp=tp[nex])
	if(!bz[x][to[tp]] && to[tp]!=f && !vis[to[tp]])
		run(to[tp],x);
}
int pp[N][N];
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[++a0].x=x,a[a0].y=y;
		a[++a0].x=y,a[a0].y=x;
	}
	sort(a+1,a+1+a0);
	tot=1;
	fd(i,a0,1) link(a[i].y,a[i].x);
	memset(ans,127,sizeof ans);
	if(m==n-1)
	{
		run(1,0);
		update();
		fo(i,1,n) 
			printf("%d ",ans[i]);
		return 0;
	}
	fo(i,1,a0) 
	{
		if(pp[a[i].x][a[i].y]) continue;
		memset(vis,0,sizeof vis);
		d0=0;
		bz[a[i].x][a[i].y]=bz[a[i].y][a[i].x]=pp[a[i].x][a[i].y]=pp[a[i].y][a[i].x]=1;
		run(1,0);
		bz[a[i].x][a[i].y]=bz[a[i].y][a[i].x]=0;
		if(d0==n)
			update();
	}
	fo(i,1,n) 
		printf("%d ",ans[i]);
	return 0;
}








