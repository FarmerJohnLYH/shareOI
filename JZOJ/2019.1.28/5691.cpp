#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
using namespace std;
#define ll long long 
const ll N=300300,mo=998244353;
ll n,m;
ll to[N*2],nex[N*2],las[N];
ll fa[20][N],dep[N];
ll sm[55][N];
ll tot;
void link(ll x,ll y)
{
	to[++tot]=y,tot[nex]=las[x];las[x]=tot;
}
ll read()
{
	ll rt=0,tp=1;
	char ch=getchar();
	while(!((ch>='0'&&ch<='9') || (ch=='-'))) ch=getchar();
	if(ch=='-') tp=-1,ch=getchar();
	while(ch>='0'&&ch<='9') rt=1ll*rt*10+ch-'0',ch=getchar();
	return rt*tp;
}
void dfs(ll x,ll f)
{
	fa[0][x]=f,dep[x]=dep[f]+1;
	for (ll tp=las[x];tp;tp=tp[nex])
	if(tp[to]!=f)
		dfs(tp[to],x);
}/*
ll lca(ll x,ll y)
{
	if(dep[x]<dep[y]) swap(x,y);
	ll p=dep[x]-dep[y];
	fo(i,0,19) if(p&(1<<i)) x=fa[i][x];
	fd(i,19,0) if(fa[i][x]!=fa[i][y])
	{
		x=fa[i][x],y=fa[i][y];
		fd(l,i-1,1) 
		if(fa[i][x]!=fa[i][y]) x=fa[i][x],y=fa[i][y];
		if(fa[0][x]!=fa[0][y]) x=fa[0][x],y=fa[0][y];
		x=fa[0][x],y=fa[0][y];
		return x;
	}
}*/
ll Lca(ll x,ll y)
{    
	if(dep[x]<dep[y])swap(x,y);    
	fo(i,0,19)if((dep[x]-dep[y])&(1<<i))x=fa[i][x];    
	if(x==y)return x;
	fd(i,19,0)if(fa[i][x]!=fa[i][y])x=fa[i][x],y=fa[i][y];
	return fa[0][x];  
}
int main()
{
	 freopen("sum.in","r",stdin);
	 freopen("sum.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.aut","w",stdout);
	n=read();
	fo(i,1,n-1)
	{
		ll x=read(),y=read();
		link(x,y),link(y,x);
	}
	fo(i,1,n) sm[1][i]=(i+sm[1][i-1])%mo;
	fo(l,2,50) fo(i,1,n) 
		sm[l][i]=(1ll*(mo+sm[l-1][i]-sm[l-1][i-1])*i+sm[l][i-1])%mo;
	dep[1]=-1;fa[0][1]=1;
	dfs(1,1);
	fo(l,1,19) fo(i,1,n)
		fa[l][i]=fa[l-1][fa[l-1][i]];
	m=read();
	fo(i,1,m)
	{
		ll x=read(),y=read(),k=read();
		ll q=Lca(x,y);		
		ll ans=(0ll+sm[k][dep[x]]+sm[k][dep[y]]+((mo-sm[k][dep[q]])*2ll)+(0ll+mo+sm[k][dep[q]]-sm[k][dep[q]-1]))%mo;
		printf("%lld\n",ans);
	}
	return 0;
}











