#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=4004000,eps=1e8;
const ll inf=1ll<<60;
int n;
ll v[N],dis[N];
int to[N],nex[N],las[N];
int tot;
void link(int x,int y,int c)
{
	to[++tot]=y,v[tot]=c,nex[tot]=las[x],las[x]=tot;
}
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
int fa[N],vis[N],c[N],c0;
ll vl[N];
ll mx[N],all,ans;
int ccc;
void dfs(int x,int pv)
{
	for(int tp=las[x];tp;tp=tp[nex])
	if(tp!=(pv^1))
	{
		if(to[tp][fa])
		{
			if(c0) continue;
			++ccc;
			int y=x;
			while(y!=to[tp])
			{
				vl[++c0]=(dis[y]-dis[fa[y]]);
				c[c0]=y;
				y=fa[y];
			}
			c[++c0]=y,vl[c0]=v[tp];
			fo(i,1,c0) all+=vl[i],vis[c[i]]=1;
			continue;
		}
		fa[to[tp]]=x;
		to[tp][dis]=dis[x]+v[tp];
		dfs(to[tp],tp);
	}
}
int fr;
void run(int x)
{
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=fa[x]&&!to[tp][vis])
	{
		to[tp][fa]=x;
		to[tp][dis]=dis[x]+v[tp];
		run(to[tp]);
	}
	if(dis[x]>dis[fr]) fr=x;
}
int hd,tl;
ll b[N][2],pre[N];
void solve()
{
	if(c0==1)return;
	fo(i,1,c0) vl[i+c0]=vl[i],mx[i+c0]=mx[i];
	c0*=2;	
	hd=1,tl=0;
	fo(i,1,c0)
		pre[i+1]=pre[i]+vl[i];
	fo(i,1,c0)
	{
		while((pre[i]-b[hd][1])*2>all&&hd<=tl)++hd;
		if(hd<=tl)
			ans=max(ans,pre[i]+mx[i]+b[hd][0]);
		while(mx[i]-pre[i]>=b[tl][0]&&hd<=tl) --tl;
		b[++tl][0]=mx[i]-pre[i],b[tl][1]=pre[i];
	}
}
int main()
{
	freopen("darksoul.in","r",stdin);
	freopen("darksoul.out","w",stdout);
//	freopen("D:/LiuYuanHao/b.in","r",stdin);
	n=read();tot=1;
	fo(i,1,n)
	{
		int x,y,c;
		x=read(),y=read(),c=read();
		if(x!=y) link(x,y,c),link(y,x,c);
	}
	ans=0;
	dfs(1,0);
	if(!c0) c[c0=1]=1;
	fo(i,1,c0)
	{
		int x=c[i];
		fa[x]=0;
		vis[x]=dis[x]=0;
		fr=x;
		run(x);
		mx[i]=dis[fr];
		fa[fr]=0;
		dis[fr]=0;
		run(fr);
		ans=max(ans,dis[fr]);
		vis[x]=1;
	}
	solve();
	printf("%lld\n",ans+1);
	return 0;
}




