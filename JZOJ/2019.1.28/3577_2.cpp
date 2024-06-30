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
struct node{
	int x,y,id;
}a[N];
struct edge{
	int to,nex,tor,nexr;
}e[M*2];
int las[N],tot,lasr[N];
void link(int x,int y)
{
	e[++ tot].to=y,e[tot].nex=las[x];
	las[x]=tot;
	e[tot].tor=x,e[tot].nexr=lasr[y];
	lasr[y]=tot;
}
bool cmp(node x,node y)
{
	return((x.x<y.x)||(x.x==y.x&&x.y<y.y));	
}
int id[N];
int vis[N];
void del(int x)
{
	if(vis[x])return;
	vis[x]=1;
	for (int tmp=las[x];tmp;tmp=e[tmp].nex)
		del(e[tmp].to);
}
int gt[N][2];
void dfs(int x,int col,int typ)
{
	if(gt[x][typ])return;
	gt[x][typ]=col;
	for (int tmp=lasr[x];tmp;tmp=e[tmp].nexr)
	{
		int to=e[tmp].tor;
		dfs(to,col,typ);
	}
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&A,&B);
	fo(i,1,n)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[i].x=x,a[i].y=y;
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	fo(i,1,n) id[a[i].id]=i;
	fo(i,1,m)
	{
		int x,y,t;
		scanf("%d%d%d",&x,&y,&t);
		x=id[x],y=id[y];
		link(x,y);
		if(t==2) link(y,x);
	}
	memset(vis,0,sizeof vis);
	fo(i,1,n)
		if(a[i].x==0)
			del(i);
	int flag=0;
	int tot=0;
	fo(i,1,n)
	if(a[i].x==A&&vis[i])
		dfs(i,++tot,0);
	fd(i,n,1)
	if(a[i].x==A&&vis[i])
		dfs(i,tot--,1);
	fd(i,n,1)
	if(a[i].x==0)
	{
		if(gt[i][1]*gt[i][0]==0||gt[i][1]<gt[i][0])
			printf("%d\n",0);
		else
			printf("%d\n",gt[i][1]-gt[i][0]+1);
	}
}

