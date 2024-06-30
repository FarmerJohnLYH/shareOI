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
const int N=500500;
int n,m,q;
int son[N][4];//[0]重儿子
struct node{
	int x;
	bool bz[3];//是否为1 是否为2
}t[N*4];
int dfn[N*4],sz[N*4],fa[N*4];
int top[N*4],lz[N*4];
int v[N],w[N];
int tot;
void insert(int x,int l,int r,int p,int v)
{
	if(l==r) 
	{
		t[w[p]=x].x=v;
		if(v==1)t[x].bz[1]=1;else 
		if(v==2)t[x].bz[2]=2;
		return;
	}
	int mid=(l+r)>>1;
	if(p>mid)insert(x<<1|1,mid+1,r,p,v);
	else insert(x<<1,l,mid,p,v);
	t[x].bz[1]=t[x<<1].bz[1]&&t[x<<1|1].bz[2];
	t[x].bz[2]=t[x<<1].bz[2]&&t[x<<1|1].bz[2];
}
void dfs(int x,int ft,int tp)
{
	if(tp)
	{
		fa[x]=ft,sz[x]=1;
		fo(i,1,3)
		{
			dfs(son[x][i],x,tp);
			sz[x]+=sz[son[x][i]];
			if(sz[son[x][i]]>sz[son[x][0]]) son[x][0]=son[x][i];
		}
		return;
	}
	if(x<=n)son[x][0][top]=x[top],dfn[x]=++tot,dfs(son[x][0],x,tp);
	fo(i,1,3)
	{
		if(son[x][i]!=son[x][0])dfs(son[x][i],x,tp);
		v[x]+=(son[x][i][v])?1:0;
	}
	if(x<=n)insert(1,1,n,x,v[x]);
}
void dlzy(int x)
{
	int ls=x<<1,rs=x<<1|1;
	lz[ls]+=lz[x],lz[rs]+=lz[x];
	lz[x]=0;
}
int query(int x,int l,int r,int ql,int qr,int qv)
{
	if(lz[x]!=0)dlzy(x);
	if(l>r||ql>qr)return 0;
	if(l==ql&&r==qr&&t[x].bz[qv]) return l;
	if(l==r) return 0;
	int rt=0,tp=0,vl=0,vr=0;
	int mid=(l+r)>>1;
	if(qr>mid)
	{
		vr=query(x<<1|1,mid+1,r,max(ql,mid+1),qr,qv);
		if(vr!=max(ql,mid+1)) return vr;
	}
	if(ql<=mid) 
	{
		vl=query(x<<1,l,mid,ql,min(mid,qr),qv);
		return vl;	
	}
	return vr;
}
void add(int x,int l,int r,int ql,int qr,int qv)
{
	if(l==ql&&r==qr)
	{
		lz[x]+=qv;
		if(t[x].bz[1]&&qv==1) t[x].bz[2]=1,t[x].bz[1]=0;
		if(t[x].bz[2]&&qv==-1) t[x].bz[1]=1,t[x].bz[2]=0;
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid) add(x<<1,l,mid,ql,min(qr,mid),qv);
	if(qr>mid) add(x<<1|1,mid+1,r,max(ql,mid+1),qr,qv);
}
int main()
{
//	 freopen("D:/LiuYuanHao/b.in","r",stdin);
	freopen("neuron.in","r",stdin);
	freopen("neuron.out","w",stdout);
	scanf("%d",&n);m=n*3+1;
	fo(i,1,n*4) top[i]=i;
	fo(i,1,n) fo(j,1,3)scanf("%d",&son[i][j]);
	dfs(1,0,1),dfs(1,0,0);
	scanf("%d",&q);
	while(q--)
	{
		int x;
		scanf("%d",&x);
		int en=x[w],st=top[en];
		int tmp=0;
		while((tmp=query(1,1,n,dfn[st],dfn[en],1+v[x]/*Ѱ����*/))==st)
		{
			add(1,1,n,tmp,en,(v[x])?(-1):(1));
			en=fa[st],st=top[en];
		}
		add(1,1,n,tmp,en,(v[x])?(-1):(1));
		v[x]=1^v[x];
		printf("%d\n",1[w][t].x);
	}
	return 0;
}











