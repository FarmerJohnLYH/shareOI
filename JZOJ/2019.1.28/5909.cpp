// #pragma GCC optimize(2) 
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=800800;
int n,m,q,va[N],tot,cnt,dn;
int top[N],sz[N],mv[N],dfn[N],low[N];
int dep[N],nex[N*2],pre[N*2],las[N],to[N*2],fr[N*2];
void link(int x,int y)
{
	to[++tot]=y,fr[tot]=x,nex[tot]=las[x];
	if(las[x])pre[las[x]]=tot;
	las[x]=tot;
}
int t[N*4],ctt[N*2];
void del(int x)
{
	if(x==2098||x==2099)
		printf("");
	if(!(fr[x])) return;
	nex[pre[x]]=nex[x];
	if(!nex[x]) las[fr[x]]=pre[x];
	else pre[nex[x]]=pre[x];
	fr[x]=0;
}
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
int bze[N*2];
void dfs(int x,int f)
{
	low[x]=dfn[x]=++dn;
	for(int tp=las[x];tp;tp=tp[nex])
	{
		if(!to[tp][dfn])
		{
			dfs(to[tp],tp^1);
			low[x]=min(low[x],low[to[tp]]);
		}
		else 
		if(tp!=f)low[x]=min(low[x],dfn[to[tp]]);
		if(tp!=f) if(low[to[tp]]>dfn[x]) bze[tp]=bze[tp^1]=1;
	}
}
int col[N];
void run(int x,int f)
{
	for(int tp=las[x];tp;tp=tp[nex])
	if(!bze[tp])
	{
		if(tp[to]!=f&&!col[tp[to]])
		{
			col[tp[to]]=col[x],++ctt[col[x]];
			run(tp[to],x);
		}
		del(tp),del(tp^1);
	}
}
int fa[N];
void work(int x)
{
	dep[x]=dep[fa[x]]+1;
	sz[x]=1;
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=fa[x])
	{
		to[tp][fa]=x;
		work(to[tp]);
		sz[x]+=to[tp][sz];
		if(mv[x]==0||mv[x][sz]<to[tp][sz]) mv[x]=to[tp];
	}
}
int d0;
void nfd(int x)
{
	dfn[x]=++d0;
	dep[x]=dep[fa[x]]+1;
	if(mv[x])
	{
		top[mv[x]]=top[x];
		mv[x][fa]=x;
		nfd(mv[x]);
	}
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=fa[x]&&mv[x]!=to[tp])
	{
		to[tp][fa]=x;
		top[to[tp]]=to[tp];
		if(to[tp]==1048)
			printf("");
		nfd(to[tp]);
	}
}
priority_queue<int> qu[N],de[N];
void cg(int x,int l,int r,int p,int v)
{
	if(l==r) 
	{
		t[x]=v;
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)cg(x<<1,l,mid,p,v);
	else cg(x<<1|1,mid+1,r,p,v);
	t[x]=min(t[x<<1],t[x<<1|1]);
}
int query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
		return(t[x]);
	int mid=(l+r)>>1,rt=oo;
	if(mid>=ql) rt=min(rt,query(x<<1,l,mid,ql,qr));
	if(mid<qr) rt=min(rt,query(x<<1|1,mid+1,r,ql,qr));
	return rt;
}
int find(int x,int y,int &la)
{
	int rt=min(va[x],va[y]);
	if(dep[top[x]]<dep[top[y]])swap(x,y);
	while(top[x]!=top[y])
	{
		rt=min(rt,query(1,1,cnt,dfn[top[x]],dfn[x]));
		x=top[x][fa];
		if(dep[top[x]]<dep[top[y]])swap(x,y);
	}
	if(dep[x]<dep[y]) swap(x,y);
	rt=min(rt,query(1,1,cnt,dfn[y],dfn[x]));
	la=y;
	return rt;
}
int main()
{
	freopen("paoshang.in","r",stdin);
	freopen("paoshang.out","w",stdout);
//	freopen("D:/LiuYuanHao/c.in","r",stdin);
//	freopen("D:/LiuYuanHao/c.out","w",stdout);
	n=read(),m=read(),cnt=n;tot=1;
	fo(i,1,n) scanf("%d",&va[i]);
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y),link(y,x);
	}
	dfs(1,0);
	fo(i,1,n) if(!col[i]) 
		col[i]=++cnt,ctt[cnt]=1,run(i,0);
	fo(x,1,n) if(ctt[col[x]]>1)link(x,col[x]),link(col[x],x);
	work(1);memset(dfn,0,sizeof dfn);
	d0=0;top[1]=1;
	memset(fa,0,sizeof fa),memset(dep,0,sizeof dep);
	nfd(1);
	memset(t,127,sizeof t);
	fo(i,1,n) 
	{
		cg(1,1,cnt,dfn[i],va[i]);
		if(fa[i]>n)
			qu[fa[i]-n].push(-va[i]);
	}
	fo(i,n+1,cnt) 
		if(!qu[i-n].empty())
			cg(1,1,cnt,dfn[i],-qu[i-n].top());
	q=read();
	fo(i,1,q)
	{
		char ch=getchar();while(ch!='C'&&ch!='Q')ch=getchar();
		int x=read(),y=read();
		if(ch=='C')
		{
			if(fa[x]>n)
			{	
				int p=fa[x]-n;
				de[p].push(-va[x]);
				va[x]=y;
				cg(1,1,cnt,dfn[x],va[x]);
				qu[p].push(-va[x]);
				while(!de[p].empty()&&qu[p].top()==de[p].top())qu[p].pop(),de[p].pop();
				cg(1,1,cnt,dfn[fa[x]],-qu[p].top());
			}else 
			{
				va[x]=y;
				cg(1,1,cnt,dfn[x],va[x]);
			}
		}
		else
		{
			int la;
			int mn=find(x,y,la);
			if(la>n) mn=min(mn,fa[la][va]);
			printf("%d\n",(va[x]-mn));
		}
	}
	return 0;
}








