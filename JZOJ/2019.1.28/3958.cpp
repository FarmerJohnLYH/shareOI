#pragma GCC optimize(2) 
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=5050,M=100100*2;
int n,m;
int f[N],bz[N];
ll ans;
int to[M],las[N],nex[M],tot;
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
int d[N*10],hd,tl;
ll cnt[N];
int gf(int x)
{
	return(f[x]==x)?x:(f[x]=gf(f[x]));
}
void cb(int x,int y)
{
	int fx=gf(x),fy=gf(y);
	cnt[fx]+=cnt[fy],cnt[fy]=0;
	f[fy]=fx;
}
void solve(int cl)
{
	fo(i,1,n) f[i]=i,cnt[i]=1;
	hd=0,tl=0;
	memset(bz,255,sizeof bz);
	bz[cl]=cl;
	for(int tp=las[cl];tp;tp=tp[nex])d[++tl]=to[tp],bz[to[tp]]=cl;
	int x;
	while(hd++<tl)
	{
		x=d[hd];
		for(int tp=las[x];tp;tp=tp[nex])
		if(bz[tp[to]]!=cl)
		{
			tp[to][bz]=cl;
			d[++tl]=tp[to];
			cb(x,d[tl]);
		}
		else
		if(tp[to]!=cl&&gf(x)!=gf(tp[to])) cb(x,tp[to]);
	}
	fo(i,1,n)
	if(i!=cl&&cnt[i]>0) ans=ans+(1ll*cnt[i]*(n-cnt[i]-1));
	ans=ans/2;
}
int main()
{
	freopen("D:/LiuYuanHao/c.in","r",stdin);
	freopen("D:/LiuYuanHao/c.ans","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y),link(y,x);
	}
	fo(i,1,n)
	{
		ans=0;
		solve(i);
		printf("%lld\n",ans+n-1);
	}
	return 0;
}











