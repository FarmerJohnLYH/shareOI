#include <queue>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (int i=(x),asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> PI;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N=3300,M=3300,P=100100;
priority_queue<int> qu;
int n,m;
int di[N][N];
struct node{
	int x,y,p,c;
	int id,st;
}a[N];
bool cmp(node a,node b)
{
	return(a.p>b.p||(a.p==b.p&&a.c>b.c)||((a.p==b.p&&a.c==b.c&&a.id<b.id)));
}
int ans;
int f[N];
int gf(int x)
{
	return (f[x]==x?x:f[x]=gf(f[x]));
}
int to[N],nex[N],las[N];
int fa[N],dep[N];
int bz[N];
int tot=0;
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=x[las];
	las[x]=tot;
}
void makeroot(int x,int d)
{
	bz[x]=1,dep[x]=d;
	for (int tp=x[las];tp;tp=tp[nex])
	if(!to[tp][bz])
	{
		to[tp][fa]=x;
		makeroot(to[tp],d+1);
	}
}
int du[N];
int TO[N],NEX[N],LAS[N];
int TOT;
void tplink(int x,int y)
{
	TO[++TOT]=y,NEX[TOT]=x[LAS];
	LAS[x]=TOT;
	++du[y];
}
void judge(int x,int y)
{
	if(a[y].p>=a[x].p) tplink(a[x].id,a[y].id);	
}
void mst()
{
	ans=0;
	fo(i,1,n) f[i]=i;
	fo(i,1,m)
	{
		int fx=gf(a[i].x),fy=gf(a[i].y);
		if(fx!=fy)
		{
			bz[a[i].id]=1;
			f[fx]=fy;
			ans+=a[i].c;
			memset(bz,0,sizeof bz);
			makeroot(a[i].x,1),makeroot(a[i].y,0);
			link(a[i].x,a[i].y);link(a[i].y,a[i].x);
			fa[a[i].x]=a[i].y;
		}
		else
		{
			fx=a[i].x,fy=a[i].y;
			if(dep[fx]<dep[fy]) swap(fx,fy);
			while(dep[fx]>dep[fy])
			{
				judge(di[fx][fa[fx]],i);
				fx=fa[fx];
			}
			while(fx!=fy)
			{
				judge(di[fx][fa[fx]],i);
				fx=fa[fx];
				judge(di[fy][fa[fy]],i);
				fy=fa[fy];
			}
		}
	}
}
int dt[2][N],d0[2];
int Ans[N],a0;
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,m)scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].p,&a[i].c),a[i].id=i;
	sort(a+1,a+1+m,cmp);
	fo(i,1,m)di[a[i].x][a[i].y]=di[a[i].y][a[i].x]=i; 
	mst();
	fo(i,1,m)
	if(du[i]==0) dt[0][++d0[0]]=i,qu.push(-i);
	int g=d0[0];
	int o=0;
	d0[1]=0;a0=0;
	printf("%d\n",ans);
	while(a0<m)
	{
		int x=-qu.top();qu.pop();
			for (int tp=LAS[x];tp;tp=tp[NEX])
				if((--du[tp[TO]])==0) 
					qu.push(-tp[TO]);
		Ans[++a0]=x;
	}
	fo(i,1,m) printf("%d ",Ans[i]);
	return 0;
}









