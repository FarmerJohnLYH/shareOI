#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),GG=(y);i<=GG;++i)
#define fd(i,x,y) for (int i=(x),GG=(y);i>=GG;--i)
#define fi first 
#define se second 
#define mp make_pair
using namespace std;
typedef pair<int,int> PI;
const int N=50500;
int n,m;
vector<PI> to[N];
struct node{
	int l,r,mx,ot;
	node(int l_=0,int r_=0,int mx_=0,int ot_=0){l=l_,r=r_,mx=mx_,ot=ot_;}
};
int w[N*22],g[22][N*22],w0;
bool operator <(node a,node b)
{
	return(w[a.ot]+w[a.mx]<w[b.ot]+w[b.mx]);
} 
priority_queue<node> q;
int sz[N],vis[N];
PI cor;int all;
void init(int x,int f)
{
	sz[x]=1;
	fo(i,0,to[x].size()-1)
	if(!to[x][i].fi[vis]&&to[x][i].fi!=f)
	{
		init(to[x][i].fi,x);
		sz[x]+=sz[to[x][i].fi];				
	}
}
void find(int x,int f)
{
	int mx=0;
	fo(i,0,to[x].size()-1)
	if(!to[x][i].fi[vis]&&to[x][i].fi!=f)
	{
		find(to[x][i].fi,x);
		mx=max(mx,to[x][i].fi[sz]);
	}
	mx=max(all-sz[x],mx);
	if(mx<cor.se) cor.se=mx,cor.fi=x;
}
int le,ri;
int pmx,tmp;
void dfs(int x,int f,int d)
{
	w[++w0]=d;
	if(w[tmp]<d) tmp=w0;
	q.push(node(le,ri,w0,pmx));
	fo(i,0,to[x].size()-1)
	if(!to[x][i].fi[vis]&&to[x][i].fi!=f)
		dfs(to[x][i].fi,x,d+to[x][i].se);	
}
void solve(int root)
{
	cor.se=oo;
	init(root,0);
	all=sz[root];
	find(root,0);
	w[pmx=tmp=le=ri=++w0]=0;
	int p=cor.fi;
	cor.fi[vis]=1;
	fo(i,0,to[p].size()-1)
	if(!to[p][i].fi[vis])
	{
		dfs(to[p][i].fi,p,to[p][i].se);
		ri=w0,pmx=tmp;
	}
	fo(i,0,to[p].size()-1)
	if(!to[p][i].fi[vis]) solve(to[p][i].fi);
}
int lg[N*20];
int fm(int l,int r)
{
	int p=lg[r-l+1]-1;
	return(g[p][l][w]>g[p][r-(1<<p)+1][w])?g[p][l]:g[p][r-(1<<p)+1];
}
int main()
{
//	freopen("D:/LiuYuanHao/c.in","r",stdin);
//	freopen("D:/LiuYuanHao/c.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,n-1)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		to[x].push_back(mp(y,c)),to[y].push_back(mp(x,c));
	}
	memset(vis,0,sizeof vis);
	solve(1);
	fo(i,1,w0) g[0][i]=i,lg[i]=lg[i>>1]+1;
	fo(j,1,20) fo(i,1,w0)
			if(i+(1<<(j-1))-1>w0) g[j][i]=(g[j-1][i][w]>w[g[j][i-1]])?g[j-1][i]:g[j][i-1];
			else g[j][i]=(g[j-1][i][w]>w[g[j-1][i+(1<<(j-1))]])?g[j-1][i]:g[j-1][i+(1<<(j-1))];
	fo(i,1,m)
	{
		node tp=q.top();q.pop();
		printf("%d\n",w[tp.ot]+w[tp.mx]);
		if(tp.ot>tp.l) q.push(node(tp.l,tp.ot-1,tp.mx,fm(tp.l,tp.ot-1)));
		if(tp.ot<tp.r) q.push(node(tp.ot+1,tp.r,tp.mx,fm(tp.ot+1,tp.r)));
	}
	return 0;
}











