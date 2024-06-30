#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo (1152921504606846975ll)
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=100100;
int n,m;
ll v[N],vd[N][2];
int d[N],d0;
int gs[N],fa[N];
int to[N*2],nex[N*2],las[N],tot;
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
int sz[N];
ll gg[N][2];
void dfs(int x)
{
	sz[x]=1;
	gg[x][1]=v[x];
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=fa[x])
	{
		to[tp][fa]=x;
		dfs(to[tp]);
		gg[x][0]+=max(gg[to[tp]][0],gg[to[tp]][1]);
		gg[x][1]+=gg[to[tp]][1];
		sz[x]+=to[tp][sz];
		if(gs[x]==0||sz[to[tp]]>sz[gs[x]]) gs[x]=to[tp];
	}
	if(gs[x]) vd[x][0]=gg[x][0]-max(gg[gs[x]][0],gg[gs[x]][1]),vd[x][1]=gg[x][1]-gg[gs[x]][1];;
}
struct node{
	ll a[2][2];
	node(ll a_=-oo,ll b_=-oo,ll c_=-oo,ll d_=-oo)
	{
		a[0][0]=a_,a[0][1]=b_,a[1][0]=c_,a[1][1]=d_;
	}
}ze,t[N*4];
node operator *(node a,node b)
{
	node c=node();
	fo(i,0,1) fo(j,0,1) fo(k,0,1)
		c[i][j]=max(c[i][j],a[i][k]+b[k][j]);
	return c;
}
int top[N],dfn[N];
void run(int x)
{
	d[++d0]=x;dfn[x]=d0;
	if(gs[x])top[gs[x]]=top[x],run(gs[x]);
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=fa[x]&&to[tp]!=gs[x])
		top[to[tp]]=to[tp],run(to[tp]);
}
void build(int x,int l,int r)//点l的权为d[x]的对应矩阵
{
	if(l==r)
	{
		t[x]=node(vd[d[x]][0],vd[d[x]][1],vd[d[x]][0],-oo);
		return;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	t[x]=t[x<<1]*t[x<<1|1];
}
int qp;node qv;
void cg(int x,int l,int r)
{
	if(l==r)
	{
		t[x]=qv;
		return;
	}
	int mid=(l+r)>>1;
	if(qp<=mid)cg(x<<1,l,mid);
	else cg(x<<1|1,mid+1,r);
	t[x]=t[x<<1]*t[x<<1|1];
}
int ql,qr;
node qry(int x,int l,int r)
{
	if(ql<=l&&r<=qr)return t[x];
	int mid=(l+r)>>1;node rt=node();
	if(ql<=mid) rt=rt*qry(x<<1,l,mid);
	if(qr>mid) rt=rt*qry(x<<1|1,mid+1,r);
	return rt;
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	ze=node(0,-oo,-oo,0);
	scanf("%d%d",&n,&m);
	fo(i,1,n) scanf("%lld",&v[i]);
	fo(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y),link(y,x);
	}
	dfs(1);run(1);
	build(1,1,n);
	while(m--)
	{
		int x,y;scanf("%d%d",&x,&y);
		ll det=v[x]-y;v[x]=y;
		qp=dfn[x];
		qv=node();
		cg(1,1,n);
	}
	return 0;
}








