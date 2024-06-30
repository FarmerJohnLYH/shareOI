#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define mp make_pair
#define fi first
#define se second
#define pb push
using namespace std;
typedef pair<int,int> PI;
const int N=100100;
int n,m;
int fa[N],sz[N],dis[N],c[N];
char ch;
priority_queue<int> qu[N],de[N];
vector<int> to[N];
vector<PI> tw[N];
int vis[N],mv[N],m0,all;
int rt;
void dfs(int x,int f)
{
	sz[x]=1;mv[x]=0;
	if(rt)tw[x].push_back(mp(rt,dis[x]));
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(!to[x][i][vis]&&to[x][i]!=f)
	{
		dis[to[x][i]]=dis[x]+1;
		dfs(to[x][i],x);
		sz[x]+=to[x][i][sz];
		mv[x]=max(mv[x],to[x][i][sz]);
	}
	mv[x]=max(mv[x],all-sz[x]);
	if(m0==0||mv[m0]>mv[x]) m0=x;
}
void solve(int x)
{
	vis[x]=1;
	rt=x;
	dfs(x,0);
	rt=0;
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(!to[x][i][vis])
	{
		all=to[x][i][sz];m0=0;
		dfs(to[x][i],0);
		solve(m0);
	}
}
int query(int x)
{
	int t[2],t0=0;t[0]=t[1]=0;
	while(t0<=1)
	{
		if(qu[x].empty())
		{
			fo(i,0,t0-1) qu[x].pb(t[i]);
			return 0;
		}
		t[t0]=qu[x].top();
		if(!de[x].empty()&&de[x].top()==t[t0]) de[x].pop(),qu[x].pop();
		else ++t0,qu[x].pop();
	}
	return(t[0]+t[1]);
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		to[x].push_back(y),to[y].push_back(x);
	}
	solve(1);
	fo(x,1,n) 
	{
		c[x]=1;
		int cc=1;
			for(int p=tw[x].size()-1,i=0;i<=p;++i)
			{
				int y=tw[x][i].fi,v=tw[x][i].se;
				if(cc) qu[y].pb(v);
				else de[y].pb(v);
			}
	}
	scanf("%d",&m);
	while(m--)
	{
		ch=getchar();while(ch!='C'&&ch!='G')ch=getchar();
		if(ch=='G') 
		{
			int t1=0,t2=0,ans=0;
			fo(i,1,n)
				ans=max(ans,query(i));
			printf("%d\n",ans);
		}
		if(ch=='C')
		{
			int x,cc;
			scanf("%d",&x);
			cc=(c[x]^=1);
			for(int p=tw[x].size()-1,i=0;i<=p;++i)
			{
				int y=tw[x][i].fi,v=tw[x][i].se;
				if(cc) qu[y].pb(v);
				else de[y].pb(v);
			}
		}
	}
	return 0;
}








