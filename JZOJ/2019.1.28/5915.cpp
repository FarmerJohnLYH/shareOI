#include <map>
#include <vector>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=200200,M=500500;
const ll mo=998244353;
ll n,tp;
ll lastans;
ll dep[N],fa[N];
ll rt;
struct node{
	ll l,r,v,hv;
}a[N];
char s[M],st[M];
vector<ll> to[N];
map<char,ll> mp;
void dfs(ll x)
{
	dep[x]=fa[x][dep]+1;
	for(ll p=to[x].size()-1,i=0;i<=p;++i)
	{
		ll tt=to[x][i];
		if(tt!=fa[x])
		{
			tt[fa]=x;
			dfs(tt);
		}
	}
}
ll typ;
ll ha[M];
ll hah(ll l,ll r)
{
	ll rt=0;
	fo(i,l,r)
		rt=(rt*7ll+mp[s[i]])%mo;
	return rt;
}
ll len,m;
ll tw[M];
ll calc(ll x)
{
	ll rt=0;
	m=a[x].r-a[x].l+1;
	fo(i,1,len-m+1)
		if(((ha[i+m-1]-1ll*ha[i-1]*tw[m]%mo)%mo+mo)%mo==a[x].hv)
			++rt;
	return rt;
}
ll solve(ll x,ll y)
{
	ll rt=0;
	while(x!=y)
	{
		if(dep[x]<dep[y])swap(x,y);
		rt+=calc(x)*a[x].v;
		x=fa[x];
	}
	return rt+calc(x);
}
int main()
{
//	freopen("light.in","r",stdin);
//	freopen("light.out","w",stdout);
	freopen("D:/LiuYuanHao/c.in","r",stdin);
	freopen("D:/LiuYuanHao/c.out","w",stdout);
	srand(time(0));rand();rand();
	scanf("%d%d",&n,&typ);rt=1;
	mp['A']=1,mp['C']=2,mp['G']=3,mp['T']=4,mp['U']=5;
	fo(i,1,n)
	{
		a[i].l=a[i-1].r+1;
		scanf("%s",s+a[i].l);
		a[i].r=strlen(s+a[i].l)+a[i].l-1;
		a[i].hv=hah(a[i].l,a[i].r);
	}
	fo(i,1,n)scanf("%d",&a[i].v);
	fo(i,1,n-1)
	{
		ll x,y;	
		scanf("%d%d",&x,&y);
		to[x].push_back(y),to[y].push_back(x);
	} 
	dfs(rt);
	ll _;
	scanf("%d",&_);
	tw[0]=1;fo(i,1,M-100) tw[i]=tw[i-1]*7ll%mo;
	while(_--)
	{
		ll op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		x^=typ*lastans,y^=typ*lastans;
		if(op==1)
		{
			scanf("%s",st+1);len=strlen(st+1);
			ha[0]=0;
			fo(i,1,len) ha[i]=(ha[i-1]*7ll+mp[st[i]])%mo;
			ha[len+1]=0;
			lastans=solve(x,y);
			printf("%d\n",lastans);
		}
		else a[x].v=y;
	}
	return 0;
}








