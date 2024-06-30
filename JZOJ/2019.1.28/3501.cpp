#pragma GCC optimize(2)
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef double db;
typedef pair<int,int> PI;
const int N=200200;
int n;
int to[N*2],nex[N*2],las[N];
int f[N],ans[N],F[N];
int tot;
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
int st[N][18];
int qry(int l,int r)
{
	if(l>r)return 0;
	int len=(db)log(r-l+1)/(db)log(2);
	return(max(st[l][len],st[r-(1<<len)+1][len]));
}
void solve(int x,int fa)
{
	vector<PI> g;g.clear();
	for(int tp=las[x];tp;tp=tp[nex])
		if(tp[to]!=fa)
		{
			solve(tp[to],x);
			g.push_back(mp(f[tp[to]],tp[to]));
		}
	sort(g.begin(),g.end());
	int p=g.size(),rt=0;
	fo(i,0,p-1) f[x]=max(f[x],g[i].fi+p-i);
	g.clear();
}
void work(int x,int fa)
{
	vector<PI> g;g.clear();
	for(int tp=las[x];tp;tp=tp[nex])
		if(tp[to]!=fa)
			g.push_back(mp(f[tp[to]],tp[to]));
	int p=g.size(),rt=0;
	g.push_back(mp(F[x],0));
	sort(g.begin(),g.end());++p;
	fo(i,0,p-1) st[i][0]=g[i].fi+p-i;
	fo(l,1,17) fo(i,0,p-1)
		if(i+(1<<(l-1))<=p-1)st[i][l]=max(st[i][l-1],st[i+(1<<(l-1))][l-1]);
		else if(i==0)st[i][l]=st[i][l-1];
		else st[i][l]=max(st[i][l-1],st[i-1][l]);
	fo(i,0,p-1)
	{
		if(g[i].se)
		F[g[i].se]=max(qry(0,i-1)-1,qry(i+1,p-1)); 
	}
	g.clear();
	for(int tp=las[x];tp;tp=tp[nex])
		if(tp[to]!=fa)
			work(tp[to],x);
}
int ft[N];
int main()
{
	freopen("news.in","r",stdin);
	freopen("news.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d",&n);
	fo(i,2,n) 
	{
		int fa;
		scanf("%d",&fa);
		link(i,fa),link(fa,i);
		ft[i]=fa;
	}
	F[1]=-oo;
	solve(1,0);ans[0]=ans[1]=f[1];
	work(1,0);
	vector<int> g;
	fo(i,2,n)
	{
		g.clear();
		for(int tp=las[i];tp;tp=tp[nex])
		if(ft[i]!=tp[to]) g.push_back(f[tp[to]]);
		g.push_back(F[i]);
		sort(g.begin(),g.end());
		int p=g.size();
		fo(j,0,p-1) ans[i]=max(ans[i],g[j]+p-j);
		ans[0]=min(ans[0],ans[i]);	
	}
	printf("%d\n",ans[0]+1);
	fo(i,1,n)if(ans[0]==ans[i])
		printf("%d ",i);
	printf("\n");
	return 0;
}











