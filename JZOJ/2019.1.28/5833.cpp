#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fi first
#define se second
using namespace std;
typedef pair<int,int> PI;
const int N=400400;
int n,m;
vector<int> to[N];
int fa[N],gs[N],a[N],b[N];
int sz[N],rot[N];
PI t[N*10];
int tot;
int sn[N][2];
PI smx(PI a,PI b)
{
	if(a.fi==0)return(b);if(b.fi==0)return(a);
	if(a.se>b.se) return(a); 
	else if(a.se<b.se)return(b);
	else if(a.fi<b.fi) return(a); 
	else return(b);
}
void add(int &x,int l,int r,int p,int v)
{
	if(!x) x=++tot;
	if(l==r)
	{
		t[x].fi=p,t[x].se+=v;
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid) add(sn[x][0],l,mid,p,v);
	else add(sn[x][1],mid+1,r,p,v);
	t[x]=smx(t[sn[x][0]],t[sn[x][1]]);
	if(t[sn[x][0]].fi==t[sn[x][1]].fi) 
		t[x]=smx(t[x],make_pair(t[sn[x][0]].fi,t[sn[x][0]].se+t[sn[x][1]].se));
}
void comb(int fx,int fy)
{
	t[fx]=smx(t[fx],t[fy]);
	fo(i,0,1)
	if(sn[fy][i]) 
	{
		if(!sn[fx][i]) sn[fx][i]=sn[fy][i];
		else 
		{
			if(sn[fx][i][t].fi==sn[fy][i][t].fi) 
				t[fx]=smx(t[fx],make_pair(sn[fx][i][t].fi,sn[fx][i][t].se+sn[fy][i][t].se));
			comb(sn[fx][i],sn[fy][i]);
		}
		t[fx]=smx(t[fx],t[sn[fx][i]]);
	}
	if(t[sn[fx][0]].fi==t[sn[fx][1]].fi) 
		t[fx]=smx(t[fx],make_pair(t[sn[fx][0]].fi,t[sn[fx][0]].se+t[sn[fx][1]].se));
}
void init(int x)
{
	add(rot[x],1,m,a[x],b[x]);
	int mx=0;
	sz[x]=1;
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(to[x][i]!=fa[x])
	{
		to[x][i][fa]=x;
		init(to[x][i]);
		sz[x]+=sz[to[x][i]];
		if(sz[to[x][i]]>sz[mx]) mx=to[x][i];
	}
	gs[x]=mx;
}
PI ans[N];
void dfs(int x)
{
	if(rot[gs[x]]) 
	{
		dfs(gs[x]);
		comb(rot[x],gs[x][rot]);
	}
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(to[x][i]!=fa[x]&&to[x][i]!=gs[x])
	{
		dfs(to[x][i]);
		comb(rot[x],to[x][i][rot]);
	}
	ans[x]=rot[x][t];
}
int main()
{
//	freopen("endless.in","r",stdin);
//	freopen("endless.out","w",stdout);
	freopen("D:/LiuYuanHao/a1.in","r",stdin);
	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,n-1)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		to[u].push_back(v),to[v].push_back(u);
	}
	fo(i,1,n) scanf("%d%d",&a[i],&b[i]);
	init(1);
	dfs(1);
	fo(i,1,n) printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}











