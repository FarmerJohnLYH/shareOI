#pragma GCC optimize(2) 
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fi first
#define se second
using namespace std;
typedef pair<int,int> PI;
const int N=100100,C=11;
int n;
int dfn[N];
struct node{
	int c[C];
	vector<PI> ve;
	int v[C];
}t[N*4];
int top[N],sz[N],fa[N],gry[N],dep[N];
vector<int> to[N];
void dfs(int x)
{
	sz[x]=1;
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(fa[x]!=to[x][i])
	{
		to[x][i][fa]=x;
		to[x][i][dep]=dep[x]+1;
		dfs(to[x][i]);
		sz[x]+=sz[to[x][i]];
		if(gry[x]==-1||to[x][gry[x]][sz]<=to[x][i][sz]) gry[x]=i;
	}
}
int cnt;
void work(int x)
{
	dfn[x]=++cnt;
	if(gry[x]!=-1)
	{
		top[to[x][gry[x]]]=top[x];
		work(to[x][gry[x]]);
	}
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(fa[x]!=to[x][i]&&i!=gry[x])
	{
		top[to[x][i]]=to[x][i];
		work(to[x][i]);
	}
}
void build(int x,int l,int r)
{
	if(l>r)return;
	fo(i,0,9)t[x].c[i]=i;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
}
void down(int x)
{
	if(t[x].ve.empty())return;
	int p=t[x].ve.size();
	fo(i,0,p-1)
	{
		PI y=t[x].ve[i];
		fo(k,0,1)
		{
			int q=x<<1|k;
			swap(t[q].c[y.fi],t[q].c[y.se]);
			t[q].ve.push_back(y);
		}
	}
	while(!t[x].ve.empty()) t[x].ve.pop_back();
}
void update(int x)
{
	fo(co,0,9) 
		t[x].v[t[x].c[co]]=t[x<<1].v[t[x<<1].c[co]]+t[x<<1|1].v[t[x<<1|1].c[co]];
}
void cg(int x,int l,int r,int p,int cl,int va)
{
	if(l==r)
	{
		fo(i,0,9) t[x].v[i]=0;
		t[x].v[t[x].c[cl]]=va;
		return;
	}else down(x);
	int mid=(l+r)>>1;
	if(p<=mid) cg(x<<1,l,mid,p,cl,va);
	else cg(x<<1|1,mid+1,r,p,cl,va);
	update(x);
}
void init()
{
	int c[N],v[N];
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&c[i]);
	fo(i,1,n) scanf("%d",&v[i]);
	fo(i,1,n-1) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		++x,++y;
		to[x].push_back(y),to[y].push_back(x);
	}
	dep[1]=1;
	dfs(1);
	top[1]=1;
	work(1);
	build(1,1,cnt);
	fo(i,1,n)
		cg(1,1,cnt,dfn[i],c[i],v[i]);
}
void swp(int x,int l,int r,int ql,int qr,int vx,int vy)
{
	if(l<r) down(x);
	if(ql<=l&&r<=qr)
	{
		t[x].ve.push_back(make_pair(vx,vy));
		swap(t[x].c[vx],t[x].c[vy]);
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid) swp(x<<1,l,mid,ql,qr,vx,vy);
	if(qr>mid) swp(x<<1|1,mid+1,r,ql,qr,vx,vy);
	update(x);
}
int qry(int x,int l,int r,int ql,int qr,int qc)
{
	if(l<r)down(x);
	if(ql<=l&&r<=qr)
		return(t[x].v[t[x].c[qc]]);
	int mid=(l+r)>>1,rt=0;
	if(ql<=mid) rt+=qry(x<<1,l,mid,ql,qr,qc);
	if(qr>mid) rt+=qry(x<<1|1,mid+1,r,ql,qr,qc);
	update(x);
	return rt;
}
int m;char st[10];
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	memset(gry,255,sizeof gry);
	init();	
	scanf("%d",&m);
	while(m--)
	{
		int x,y,v;
		scanf("%s %d%d%d",st+1,&x,&y,&v);
		if(st[1]=='S') ++x,cg(1,1,cnt,dfn[x],y,v);
		if(st[1]=='C') ++x,swp(1,1,cnt,dfn[x],dfn[x]+sz[x]-1,y,v);
		if(st[1]=='A')
		{
			++x,++y;
			int ans=0;
			while(x!=y) 
			{
				if(top[x]!=top[y])
				{
					if(dep[top[x]]<dep[top[y]]) swap(x,y);
					ans+=qry(1,1,cnt,dfn[top[x]],dfn[x],v);
					x=fa[top[x]];
				}
				else 
				{
					if(dep[x]<dep[y]) swap(x,y);
					ans+=qry(1,1,cnt,dfn[y]+1,dfn[x],v);
					x=y;
				}
			}
			ans+=qry(1,1,cnt,dfn[x],dfn[x],v);
			printf("%d\n",ans);
		}
	}
	return 0;
}








