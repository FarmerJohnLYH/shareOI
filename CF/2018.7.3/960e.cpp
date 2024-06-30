#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x),G=(y);i<=G;++i)
using namespace std;
typedef long long ll;
const ll N=200200*2,mo=1e9+7;
ll n;
ll v[N];
ll f[N][2],g[N][2];
ll ans;
ll fa[N];
vector<ll> son[N];
ll sz[N];
void dfs(ll x)
{
	fo(i,0,son[x].size()-1)
	if(son[x][i]!=fa[x])
	{
		fa[son[x][i]]=x;
		dfs(son[x][i]);
		f[x][0]=(f[x][0]+f[son[x][i]][1])%mo;
		f[x][1]=(f[x][1]+f[son[x][i]][0])%mo;
		sz[x]+=sz[son[x][i]];
	}
	++sz[x],++f[x][0];
}

void dg(ll x)
{
	fo(i,0,son[x].size()-1)
	if(son[x][i]!=fa[x])
	{
		ll tt=son[x][i];
		ans=(0ll+ans+(1ll*((f[x][1]-f[x][0]+f[tt][1]-f[tt][0])*(sz[tt]))%mo*v[tt]))%mo;   
		ans=(0ll+ans+(1ll*((f[tt][1]-f[tt][0])*(sz[1]-sz[tt]))%mo*v[x]))%mo;  
		fo(l,0,1)f[tt][l]=f[x][1^l];
		dg(tt);
	}
}	
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%I64d",&n);
	fo(i,1,n) scanf("%I64d",&v[i]),ans=(ans+v[i]*n)%mo;
	fo(i,1,n-1) 
	{
		ll x,y;
		scanf("%I64d%I64d",&x,&y);
		son[x].push_back(y),son[y].push_back(x);
	}
	dfs(1);
//	fo(i,2,n) g[i][0]=(f[fa[i]][1]-f[i][0]+mo)%mo,g[i][1]=(f[fa[i]][0]-f[i][1]+mo)%mo;
	dg(1);
	printf("%I64d\n",(ans+mo)%mo);
	return 0;
}











