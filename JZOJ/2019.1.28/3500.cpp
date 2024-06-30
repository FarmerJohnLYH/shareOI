#pragma GCC optimize(2) 
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define oo 666666666666666ll
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=200200,M=500500*2;
int n,m,k;
int read()
{
	int x=0;char ch=getchar();
	while(!(ch>='0'&&ch<='9'))ch=getchar();
	while((ch>='0'&&ch<='9'))x=x*10+ch-'0',ch=getchar();
	return x;
}
struct node{
	int x;ll y;
	node(){}
	node(int x_=0,ll y_=0){x=x_,y=y_;}
};
bool operator <(node a,node b)
{
	return(!((a.y==b.y)?(a.x<b.x):(a.y<b.y)));
}
priority_queue<node> qu;
struct tu{
	ll dis[N];
	int to[M],nex[M],las[N];ll v[M];
	int S,T,tot;
	void link(int x,int y,ll c)
	{
		to[++tot]=y,nex[tot]=las[x],las[x]=tot,v[tot]=c;
	}
	ll p[N];
	void solve()
	{
		fo(i,1,n) p[i]=dis[i]=oo;
		while(!qu.empty())qu.pop();
		qu.push(node(S,p[S]=0));
		while(!qu.empty())
		{
			node nw=qu.top();qu.pop();
			if(dis[nw.x]<=nw.y)continue; 
			dis[nw.x]=nw.y;
			for(int tp=las[nw.x];tp;tp=tp[nex])
			if(tp[to][p]>dis[nw.x]+v[tp])
			{
				p[tp[to]]=dis[nw.x]+v[tp];
				qu.push(node(tp[to],dis[nw.x]+v[tp]));
			}
		}
	}
}t1,t2;
ll min(ll x,ll y){return(x<y)?(x):(y);}
int main()
{
	freopen("monogatari.in","r",stdin);
	freopen("monogatari.out","w",stdout);
//	freopen("D:/LiuYuanHao/a2.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
//	scanf("%d%d%d",&n,&m,&k);
	n=read(),m=read(),k=read();
	t1.S=t2.T=1,t1.T=t2.S=n;
	fo(i,1,m-1) 
	{
		int x=read(),y=read();ll c=read();
//		scanf("%d%d%lld",&x,&y,&c);
		t1.link(x,y,c),t1.link(y,x,c);
		t2.link(x,y,c),t2.link(y,x,c);
	}
	t1.solve(),t2.solve();
	int le=read(),ri=read();
//	scanf("%d%d",&le,&ri);
	fo(i,1,k)
	{
		ll x=read();
//		scanf("%lld",&x);
		ll ans=min(t1.dis[t1.T],min(t1.dis[le]+t2.dis[ri],t1.dis[ri]+t2.dis[le])+x);
		if(ans>=oo)printf("+Inf\n");
		else printf("%lld\n",ans);
	}
	return 0;
}











