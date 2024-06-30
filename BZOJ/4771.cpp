 #pragma GCC optimize(2)
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=2*400400;
int T,n,m;
int c[N],fa[20][N],last;
int tot,nex[N],las[N],to[N];
int rot[N],dep[N],dfn[N];
int t[N*8],cnt,lz[N*8];
int tim,sz[N],sn[N*8][2];
vector<int> ve[N];
void clear(int n)
{
	tim=0;
	last=0;
	tot=cnt=0;
	fo(i,1,n) 
	{
		fa[0][i]=0;
		rot[i]=dfn[i]=dep[i]=0;
		las[i]=sz[i]=0;
	}
	fo(i,1,n) 
		while(!ve[i].empty())ve[i].pop_back();
}
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
int mxd;
void dfs(int x)
{
	dfn[x]=++tim,sz[x]=1;
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=fa[0][x])
	{
		int tt=to[tp];
		fa[0][tt]=x,dep[tt]=dep[x]+1;
		mxd=max(mxd,dep[tt]);
		dfs(tt);
		sz[x]+=sz[tt];
	}
}
bool cmp(int x,int y)
{
	return(dfn[x]<dfn[y]);
}
void add(int &x,int l,int r,int p,int v)
{
	if(l>r)return;
	if(!x) 
	{
		x=++cnt;
		t[x]=lz[x]=0;
		sn[x][0]=sn[x][1]=0;
	}
	if(l==r)
	{
		lz[x]+=v;
		return;
	}
	int mid=(l+r)>>1;
	if(p>mid) add(sn[x][1],mid+1,r,p,v);
	else add(sn[x][0],l,mid,p,v);
	t[x]=lz[x];
	fo(i,0,1) if(sn[x][i])
		t[x]+=sn[x][i][lz]+sn[x][i][t];
}
int query(int x,int l,int r,int ql,int qr)
{
	if(!x)return 0;
	if(l>r)return 0;
	if(ql<=l&&r<=qr) return(t[x]+lz[x]);
	int mid=(l+r)>>1,rt=0;
	if(ql<=mid) rt=(rt+query(sn[x][0],l,mid,ql,qr));
	if(qr>mid) rt=(rt+query(sn[x][1],mid+1,r,ql,qr));
	return rt;
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int d=dep[x]-dep[y];
	fo(i,0,18)if((1<<i)&d) 
		x=fa[i][x];
	if(x==y)return(x);
	fd(i,18,0) if(fa[i][x]!=fa[i][y])
		x=fa[i][x],y=fa[i][y];
	return(fa[0][x]);
}
int lowbit(int x){return(x&(-x));}
int Query(int x,int l,int r)
{
	int rt=0;
	for(;x;x-=lowbit(x))
		rt+=query(rot[mxd-x+1],1,n,l,r);
	return rt;
}
void Add(int x,int l,int r)
{
	for(;x<=n;x+=lowbit(x))
		add(rot[mxd-x+1],1,n,l,r);
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		if(!n||!m)
		{
			fo(i,1,m)printf("0\n");
			continue;
		}
		clear(n);
		fo(i,1,n) scanf("%d",&c[i]),ve[c[i]].push_back(i);
		fo(i,1,n-1) scanf("%d",&fa[0][i+1]),link(fa[0][i+1],i+1);
		dep[1]=1;
		mxd=1;
		dfs(1);
		fa[0][1]=1;
		fo(i,1,18) fo(x,1,n)
			fa[i][x]=fa[i-1][fa[i-1][x]];
		fo(i,1,n)
		if(!ve[i].empty())
		{
			sort(ve[i].begin(),ve[i].end(),cmp);
			Add(dep[ve[i][0]],ve[i][0][dfn],1);
			int p=ve[i].size();
			fo(j,1,p-1)
			{
				int x=ve[i][j],y=lca(x,ve[i][j-1]);
				Add(x[dep],dfn[x],1);
				Add(x[dep],dfn[y],-1);
			}
		}
		fo(i,1,m)
		{
			int x,d;
			scanf("%d%d",&x,&d);x^=last,d^=last;d=min(mxd,d);
			int ans=Query(dep[x]+d,dfn[x],dfn[x]+sz[x]-1);
			printf("%d\n",ans);last=ans;
		}
	}
	return 0;
}











