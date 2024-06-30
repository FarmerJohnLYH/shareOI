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
const int N=300300,M=900900;
int n,m,A,B;
int bz[N];
int st[N],en[N];
struct node{
	int x,y;
}a[N];
struct edge{
	int to,nex;
}e[M*2];
int las[N],tot;
int ans=0;
void link(int x,int y)
{
	e[++ tot].to=y,e[tot].nex=las[x];
	las[x]=tot;
}
void dfs(int x,int tp)
{
	bz[x]=tp;
	if(a[x].x==A) ++ans;
	for (int tmp=las[x];tmp;tmp=e[tmp].nex)
	if(bz[e[tmp].to]!=tp)
	{
		int to=e[tmp].to;
		dfs(to,tp);
	}
}
bool cmp(int x,int y)
{
	return(a[x].y<a[y].y);	
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d%d%d",&n,&m,&A,&B);
	fo(i,1,n)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[i].x=x,a[i].y=y;
		if(x==0) st[++st[0]]=i;
		if(x==A) en[++en[0]]=i;
	}
	sort(st+1,st+1+st[0],cmp);
	sort(en+1,en+1+en[0]);
	fo(i,1,m)
	{
		int x,y,tp;
		scanf("%d%d%d",&x,&y,&tp);
		link(x,y);
		if(tp-1) link(y,x);
	}
	fd(i,st[0],1)
	{
		ans=0;
		dfs(st[i],i);
		printf("%d\n",ans);
	}
	return 0;
}
