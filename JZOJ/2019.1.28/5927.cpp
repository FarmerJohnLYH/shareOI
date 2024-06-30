#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fi first
#define se second
using namespace std;
const int N=100100,D=2000200,M=D*4*2;
typedef long long ll;
typedef pair<int,int> PI;
int T,n,typ;
ll L,s,t;
int di[D];
int to[M],nex[M],las[D],v[M];
int tot,m,p[D];
priority_queue<PI> qu;
void link(int x,int y,int va)
{
	to[++tot]=y,nex[tot]=las[x],v[tot]=va,las[x]=tot;
}
void dij()
{
	while(!qu.empty()) qu.pop();
	memset(di,127,sizeof di);
	di[s]=0;
	qu.push(make_pair(0,s));
	while(!qu.empty())
	{
		PI a=qu.top();qu.pop();
		for(int tp=las[a.se];tp;tp=tp[nex])
		if(di[tp[to]]>=oo)
		{
			di[tp[to]]=(-a.fi)+tp[v];
			qu.push(make_pair(-di[tp[to]],tp[to]));
			if(to[tp]==t)return;
		}
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
//	freopen("D:/LiuYuanHao/c1.in","r",stdin);
//	freopen("D:/LiuYuanHao/c.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		tot=0;
		memset(p,0,sizeof p);
		memset(las,0,sizeof las);
		scanf("%d%d%lld%lld%lld",&typ,&n,&L,&s,&t);	
//		p[s]++,p[s+1]--,p[t]++,p[t]--;
		m=max(s+1,t+1);
		fo(i,1,n)
		{
			int le,ri;
			scanf("%d%d",&le,&ri);
			++p[le],--p[ri];
			if(i==n)m=max(m,ri);
		}
		fo(i,1,m) 
			p[i]+=p[i-1];
		fo(i,1,m) 
		{
			if(p[i]>0) link(i,i+1,1),link(i+1,i,1);
			if(i+L<=m&&((p[i+L]+p[i+L-1])>0||(typ==0))) link(i,i+L,0),link(i+L,i,0);
		}
		dij();
		if(di[t]>=oo)printf("-1\n");
		else printf("%d\n",di[t]);
	}
	return 0;
}


