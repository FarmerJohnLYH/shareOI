#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll N=550,M=4040,D=110;
ll w[N],c[N],d[N];
ll n,m;
vector<ll> to[N];
ll dfn[N],vis[N];
ll all,sz[N],rot,cp[N];
void clear()
{
	fo(i,1,n) to[i].clear(),vis[i]=0;
}
void gtsz(ll x,ll f)
{
	sz[x]=1;
	cp[x]=0;
	for(ll p=to[x].size()-1,i=0;i<=p;++i)
	if(to[x][i]!=f)
	{
		ll tt=to[x][i];	
		if(!vis[tt]) 
		{
			gtsz(tt,x);
			sz[x]+=sz[tt];
			cp[x]=max(cp[x],sz[tt]);
		}
	}
	cp[x]=max(cp[x],all-sz[x]);
	if(rot==0||cp[rot]>cp[x]) rot=x;
}
ll cnt,te[N];
void dfs(ll x,ll f)
{
	dfn[x]=++cnt;te[cnt]=x;
	for(ll p=to[x].size()-1,i=0;i<=p;++i)
	if(to[x][i]!=f)
	{
		ll tt=to[x][i];
		if(!vis[tt])
			dfs(tt,x);
	}
}
ll ans;
ll f[N][M],g[M][D],ti[M][D],hd[M],tl[M];
void add(ll &x,ll y)
{
	if(y>x) x=y,ans=max(ans,y);
}
void gtin(ll v,ll tim,ll tp)
{
	if(v<-1000000000)return;
	while(tl[tp]>=hd[tp]&&v>=g[tp][tl[tp]]) --tl[tp];
	g[tp][++tl[tp]]=v,ti[tp][tl[tp]]=tim;
}
void check(ll tp,ll v)
{
	while(tl[tp]>=hd[tp]&&ti[tp][hd[tp]]>v) ++hd[tp];
}
void solve(ll x)
{
	vis[x]=1;
	cnt=0;
	dfs(x,0);
	fo(i,1,cnt) fo(j,0,m) f[i][j]=-oo;
	fo(j,0,d[te[1]])
	{
		ll px=te[1];
		if(m-j*c[px]<0)break; 
		if(j)
			add(f[1][m-j*c[px]],j*w[px]);
	}
	fo(i,1,cnt-1)
	{
		ll px=te[i+1];
		fo(j,0,c[px]) hd[j]=1,tl[j]=0;
		fo(j,0,m)
		if(f[i][j]>=0)
			if(i+sz[te[i]]<=cnt)add(f[i+sz[te[i]]][j],f[i][j]);
		fd(j,m,0)
		{
			ll tp=j%c[px],q=(m-j)/c[px];q*=w[px];
			check(tp,j+d[px]*c[px]);
			ll va=f[i][j];
			if(tl[tp]>=hd[tp]) 
			{
				add(f[i+1][j],g[tp][hd[tp]]+q);
				printf("");
			}
			gtin(va-q,j,tp);
		}
	}
	for(ll p=to[x].size()-1,i=0;i<=p;++i)
	if(!to[x][i][vis])
	{
		rot=0,all=to[x][i][sz];
		gtsz(to[x][i],0);
		solve(rot);
	}
}
int main()
{
//	freopen("shopping.in","r",stdin);
//	freopen("shopping.out","w",stdout);
	freopen("D:/LiuYuanHao/a1.in","r",stdin);
	ll T;scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		ans=0;
		clear();
		fo(i,1,n) scanf("%lld",&w[i]);
		fo(i,1,n) scanf("%lld",&c[i]);
		fo(i,1,n) scanf("%lld",&d[i]);
		fo(i,1,n-1)
		{
			ll x,y;
			scanf("%lld%lld",&x,&y);
			to[x].push_back(y);to[y].push_back(x);
		}
		rot=0,all=n;
		gtsz(1,0);
		solve(rot);
		printf("%lld\n",ans);
	}
	return 0;
}








