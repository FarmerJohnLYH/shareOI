#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 1039062143
#define fo(i,x,y) for (int i=(x),GG=(y);i<=GG;++i)
#define fd(i,x,y) for (int i=(x),GG=(y);i>=GG;--i)
#define fi first
#define se second
using namespace std;
typedef pair<int,int> PI;
const int N=100100*2,M=N*4;
int m,n,c;
int v[N],fa[22][N],dep[N],ans[N],li[N],bi[N];
vector<int> to[N];
struct que{
	int x,y,m;
	int p,id;
}q[N];int q0;
int root;
vector<que> t[N];
void dfs(int x)
{
	fo(i,0,to[x].size()-1)
	if(to[x][i]!=fa[0][x])
	{
		fa[0][to[x][i]]=x;dep[to[x][i]]=dep[x]+1;
		dfs(to[x][i]);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int d=dep[x]-dep[y];
	fo(i,0,20)if((1<<i)&d) x=fa[i][x];
	if(x==y)return(x);
	fd(i,20,0)if(fa[i][x]!=fa[i][y]) x=fa[i][x],y=fa[i][y];
	return(fa[0][x]);
}
struct segment{
	int t[M];
	int mn[M],mx[M];
	int flag;
	void cng(int x,int l,int r,int p,int v)
	{
		if(l==r)
		{
			mx[x]=mn[x]=v,t[x]=0;
			return;
		}
		int mid=(l+r)>>1;
		if(p<=mid)cng(x<<1,l,mid,p,v);
		else cng(x<<1|1,mid+1,r,p,v);
		mx[x]=max(mx[x<<1],mx[x<<1|1]);mn[x]=min(mn[x<<1],mn[x<<1|1]);
		if(!flag)t[x]=max(max(t[x<<1],t[x<<1|1]),mx[x<<1|1]-mn[x<<1]);
		else t[x]=max(max(t[x<<1],t[x<<1|1]),mx[x<<1]-mn[x<<1|1]);
	}
	int qmn(int x,int l,int r,int ql,int qr)
	{
		if(l>=ql&&r<=qr)return(mn[x]);
		int mid=(l+r)>>1,rt=oo;
		if(ql<=mid) rt=min(rt,qmn(x<<1,l,mid,ql,qr));
		if(qr>mid) rt=min(rt,qmn(x<<1|1,mid+1,r,ql,qr));
		return rt;
	}
	int qmx(int x,int l,int r,int ql,int qr)
	{
		if(l>=ql&&r<=qr)return(mx[x]);
		int mid=(l+r)>>1,rt=-oo;
		if(ql<=mid) rt=max(rt,qmx(x<<1,l,mid,ql,qr));
		if(qr>mid) rt=max(rt,qmx(x<<1|1,mid+1,r,ql,qr));
		return rt;
	}
	int query(int x,int l,int r,int ql,int qr)
	{
		if(l>=ql&&r<=qr)return(t[x]);
		int mid=(l+r)>>1,rt=0,a=0,b=0;
		if(!flag)
		{
			if(ql<=mid) rt=max(rt,query(x<<1,l,mid,ql,qr)),a=qmn(x<<1,l,mid,ql,qr);
			if(qr>mid) rt=max(rt,query(x<<1|1,mid+1,r,ql,qr)),b=qmx(x<<1|1,mid+1,r,ql,qr);
			if(ql<=mid&&qr>mid) rt=max(rt,b-a);
		}
		else
		{
			if(ql<=mid) rt=max(rt,query(x<<1,l,mid,ql,qr)),a=qmx(x<<1,l,mid,ql,qr);
			if(qr>mid) rt=max(rt,query(x<<1|1,mid+1,r,ql,qr)),b=qmn(x<<1|1,mid+1,r,ql,qr);
			if(ql<=mid&&qr>mid) rt=max(rt,a-b);
		}
		return rt;
	}
	void clear(int x,int l,int r,int p)
	{
		if(l==r)
		{
			mx[x]=-oo,mn[x]=oo,t[x]=0;
			return;
		}
		int mid=(l+r)>>1;
		if(p<=mid)clear(x<<1,l,mid,p);
		else clear(x<<1|1,mid+1,r,p);
		mx[x]=max(mx[x<<1],mx[x<<1|1]);
		mn[x]=min(mn[x<<1],mn[x<<1|1]);
		if(flag)t[x]=max(max(t[x<<1],t[x<<1|1]),mx[x<<1]-mn[x<<1|1]);
		else t[x]=max(max(t[x<<1],t[x<<1|1]),mx[x<<1|1]-mn[x<<1]);
	}
}tr,te;
void solve(int x)
{
	tr.cng(1,1,m,dep[x],v[x]),te.cng(1,1,m,dep[x],v[x]);
	fo(i,0,t[x].size()-1)
	{
		que q=t[x][i];
		if(q.p==q.x) 
		{
			ans[q.id]=max(ans[q.id],te.query(1,1,m,dep[q.m],dep[q.p]));
			li[q.id]=te.qmn(1,1,m,dep[q.m],dep[q.p]);	
		}
		if(q.p==q.y)
		{
			ans[q.id]=max(ans[q.id],tr.query(1,1,m,dep[q.m],dep[q.p]));
			bi[q.id]=tr.qmx(1,1,m,dep[q.m],dep[q.p]);
		}
	}
	fo(i,0,to[x].size()-1)
	if(to[x][i]!=fa[0][x]) solve(to[x][i]);
	tr.clear(1,1,m,dep[x]),te.clear(1,1,m,dep[x]);
}
int main()
{
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	freopen("D:/LiuYuanHao/b.out","w",stdout);
	tr.flag=0,te.flag=1;
	scanf("%d%d%d",&m,&n,&c);
	fo(i,1,m) scanf("%d",&v[i]);
	fo(i,1,n-1) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		to[x].push_back(y),to[y].push_back(x);
		root=x;
	} 
	n=m;
	fo(i,1,c)
	{
		int k,x,y;
		scanf("%d%d%d",&k,&x,&y);
		if(k==1) to[x].push_back(y),to[y].push_back(x);
		else q[++q0].x=x,q[q0].y=y,q[q0].id=q0,ans[q0]=0,bi[i]=-oo,li[i]=oo;	
	}
	dep[root]=1;
	dfs(root);
	m=1;fo(i,1,n)m=max(m,dep[i]);
	fo(l,1,20) fo(i,1,n) fa[l][i]=fa[l-1][fa[l-1][i]];
	fo(i,1,q0)
	{
		q[i].m=lca(q[i].x,q[i].y);
		q[i].p=q[i].x;t[q[i].x].push_back(q[i]);
		q[i].p=q[i].y;t[q[i].y].push_back(q[i]);
	}
	fo(i,1,m)tr.clear(1,1,m,i),te.clear(1,1,m,i);
	solve(root);
	fo(i,1,q0) printf("%d\n",max(ans[i],bi[i]-li[i]));
	return 0;
}











