#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef pair<int,int> PI;
const int N=505000,P=N*8,mx=6e7;
int n,m;
int fa[N],d[N];
int t[P],tot,sn[P][2];
int dfn[N],sz[N],dn[N];
vector<PI> to[N],pv[N];
int ans[N],cnt;
int rt=1;
void init(int x)
{
	sz[x]=1;dfn[x]=++cnt;dn[cnt]=x;
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(to[x][i].fi!=fa[x])
	{
		to[x][i].fi[fa]=x;
		to[x][i].fi[d]=d[x]+to[x][i].se;
		init(to[x][i].fi);
		sz[x]+=sz[to[x][i].fi];
	}
}
void cg(int &x,int l,int r,int p,int v)
{
	if(!x) x=++tot;
	if(l==r)
	{
		t[x]+=v;
		return;
	}
	int mid=(l+r)>>1;
	if(p>mid) cg(sn[x][1],mid+1,r,p,v);
	else cg(sn[x][0],l,mid,p,v);
	t[x]=t[sn[x][0]]+t[sn[x][1]];
}
int find(int x,int l,int r,int ti)
{
	if(l==r) return l;
	int mid=(l+r)>>1;
	if(ti<=t[sn[x][0]]) return find(sn[x][0],l,mid,ti);
	else return find(sn[x][1],mid+1,r,ti-t[sn[x][0]]);
}
void ins(int x,int f,int va)
{
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(to[x][i].fi!=fa[x]&&i!=f)
	{
		int tt=to[x][i].fi;
		fo(v,dfn[tt],dfn[tt]+sz[tt]-1) 
			cg(rt,-mx,mx,d[dn[v]]-2*d[x],va);
	}
}
void dfs(int x)
{
	ins(x,-1,1);
	for(int p=pv[x].size()-1,i=0;i<=p;++i)
		ans[pv[x][i].se]=find(rt,-mx,mx,pv[x][i].fi)+d[x];
	ins(x,-1,-1);
	cg(rt,-mx,mx,d[x]-2*d[x],1);
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(to[x][i].fi!=fa[x])
	{
		ins(x,i,1);
		dfs(to[x][i].fi);
		ins(x,i,-1);
	}
	cg(rt,-mx,mx,d[x]-2*d[x],-1);
}
int main()
{
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d%d",&n,&m);tot=1;
	fo(i,1,n-1)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		to[x].push_back(mp(y,c));to[y].push_back(mp(x,c));
	}
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		pv[x].push_back(mp(y,i));
	}
	init(1);
	dfs(1);
	fo(i,1,m) printf("%d\n",ans[i]);
	return 0;
}








