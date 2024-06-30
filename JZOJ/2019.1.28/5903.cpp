#pragma GCC optimize(2)
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm> 
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=2002000,M=2000000,eps=1e8;
const ll inf=1ll<<60;
int n;
ll dis[N],v[N];
int to[N],nex[N],las[N];
int tot;
ll ans;
void link(int x,int y,int c)
{
	to[++tot]=y,v[tot]=c,nex[tot]=las[x],las[x]=tot;
}
int d[N],vis[N];
int cnt;
int work(int x)
{
	fo(i,1,n) vis[i]=0,dis[i]=inf;
	int rt=x;
	dis[x]=0;
	int hd=0,tl=1;
	d[tl]=x;vis[x]=1;
	cnt+=n;
	while(hd!=tl)
	{
		if(hd>=M)hd-=M;
		hd=hd+1;
		x=d[hd];
		for(int tp=las[x];tp;tp=tp[nex])
		if(tp[to][dis]>dis[x]+tp[v])
		{
			dis[to[tp]]=dis[x]+v[tp];
			if(!to[tp][vis])
			{
				vis[to[tp]]=1;
				if(tl>=M)tl-=M;
				tl=tl+1;
				++cnt;
				d[tl]=to[tp];
			}
		}
		vis[x]=0;
	}
	fo(i,1,n) if(dis[i]>dis[rt]) rt=i;
	return rt;
}
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
int main()
{
	freopen("darksoul.in","r",stdin);
	freopen("darksoul.out","w",stdout);
//	freopen("D:/LiuYuanHao/b.in","r",stdin);
	srand(time(0));rand();rand();
	n=read();
	fo(i,1,n)
	{
		int x,y,c;
		x=read(),y=read(),c=read();
		link(x,y,c),link(y,x,c);
	}
	ans=0;
	int st=1;
		fo(i,1,min(10,n))
		{
			st=i;
				fo(pp,0,1)
				{
					st=work(st);
					ans=max(ans,dis[st]);
				}
		}
	printf("%lld\n",ans+1);
	return 0;
}








