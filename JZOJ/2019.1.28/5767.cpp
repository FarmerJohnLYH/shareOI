#pragma GCC optimize(2) 
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define add(x,y) (x+=(y))%=mo
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=110,mo=998244353;
int bz[N*2][N*2];
int n,w[6];
ll all;
ll a[N*2];
int f[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int t,int x,int y,int ct,ll v)
{
	if(t>n) 
	{
		a[ct]=(a[ct]+v)%mo;
		return;
	}
	fo(i,0,3) 
	{
		int xx=x+f[i][0],yy=y+f[i][1];
		++bz[xx+N][yy+N];
		if(bz[xx+N][yy+N]==1) dfs(t+1,xx,yy,ct+1,v*w[i]%mo);
		else dfs(t+1,xx,yy,ct,v*w[i]%mo);
		--bz[xx+N][yy+N];
	}
}
ll qsm(ll x,int y)
{
	ll rt=1;
	fo(i,0,30)
	{
		if(y&(1ll<<i)) rt=rt*x%mo; 
		x=x*x%mo;
	} 
	return rt;
} 
ll v1,v2,v0,v3;
ll g[2][N*2/*en*/][N/*len*/][N*2/*ending*/];
void solve()
{
	int o=0;
	g[o][N+0][1][N+0]=1;
	int le=0,ml=1;
	fo(i,1,n) 
	{
		o=1^o;
		memset(g[o],0,sizeof g[o]);
		fo(j,le,le+ml-1) fo(l,1,ml) fo(e,j,j+l-1)
		{
			fo(fx,0,1)
			{
				int p=e+f[fx][0],jn=j,ln=l;
				if(p<jn)ln=jn-p+ln,jn=p;if(p>jn+ln-1)ln=p-jn+1;
				if(g[o^1][N+j][l][N+e])
					add(g[o][N+jn][ln][N+p],g[o^1][N+j][l][N+e]*w[fx]%mo);
				if(g[o][N+jn][ln][N+p])le=min(le,p),ml=max(ml,ln);
			}
		}
	}
	fo(i,-n,n) fo(j,1,n+1) fo(e,i,i+j-1) 
		add(a[j],g[o][i+N][j][e+N]);
	fo(i,1,n+1) v1=(v1+a[i]*i)%mo,v2=(v2+a[i]*i*i)%mo;
	v3=((v2*all-v1*v1)%mo+mo)%mo;
	printf("%lld\n",v3);
}
int main()
{
	 freopen("altair.in","r",stdin);
	 freopen("altair.out","w",stdout);
//	freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d",&n);
	all=0;
	fo(i,0,3) scanf("%d",&w[i]),all+=w[i];
	all=qsm(all,n);
	if(w[2]+w[3]==0)
	{
		solve();
		return 0;
	}
	bz[N+0][N+0]=1;
	dfs(1,0,0,1,1);
	fo(i,1,n+1) v1=(v1+a[i]*i)%mo,v2=(v2+a[i]*i*i)%mo;
	v3=((v2*all-v1*v1)%mo+mo)%mo;
	printf("%lld\n",v3);
	return 0;
}











