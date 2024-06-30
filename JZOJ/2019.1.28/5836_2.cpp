#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll N=2002000,mo=1e9+7;
ll n,m,k;
ll a[N];
ll q,c[N];
ll ans;
ll t[N*4],las[N],ti[N],lz[N*4];
bool cmp(ll x,ll y)
{
	return(las[x]<las[y]);
}
ll all;
void down(ll x,ll l,ll r)
{
	if(l==r)return;
	ll mid=(l+r)>>1;
	if(l<mid)lz[x<<1]=(lz[x<<1]+lz[x])%mo;
	if(mid+1<r)lz[x<<1|1]=(lz[x<<1|1]+lz[x])%mo;
	t[x<<1|1]=(t[x<<1|1]+(lz[x]*(r-mid)%mo))%mo;
	t[x<<1]=(t[x<<1]+(lz[x]*(mid+1-l)%mo))%mo;
	lz[x]=0;
}
void add(ll x,ll l,ll r,ll ql,ll qr,ll v)
{
	if(lz[x]) down(x,l,r);
	if(ql<=l&&r<=qr)
	{
		if(l<r)lz[x]=v;
		t[x]=(t[x]+v*(r-l+1)%mo)%mo;
		return;
	}
	ll mid=(l+r)>>1;
	if(ql<=mid) add(x<<1,l,mid,ql,qr,v);
	if(qr>mid) add(x<<1|1,mid+1,r,ql,qr,v);
	t[x]=(t[x<<1]+t[x<<1|1])%mo;
}
ll query(ll x,ll l,ll r,ll p)
{
	if(l==r) return(t[x]);
	if(lz[x]) down(x,l,r);
	ll mid=(l+r)>>1;
	if(p<=mid) return(query(x<<1,l,mid,p));
	else return(query(x<<1|1,mid+1,r,p));
}
ll flag;
ll bz[N],nw;
void solve()
{
	bz[1]=1;
	nw=0;
	fo(i,1,all) 
	{
		nw=(nw+bz[i])%mo;
		bz[i+1]=(bz[i+1]+nw)%mo;
		bz[max(las[i],1ll)-1]=(bz[max(las[i],1ll)-1]+mo-nw)%mo;
		if(las[i]==0) ans=(ans+nw)%mo;
	}		
}
ll read()
{
    char ch=' ';ll q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10ll+ch-48;int n=q*w;return n;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
//	freopen("D:/LiuYuanHao/b.in","r",stdin);
	n=read(),m=read(),k=read();
	fo(i,1,n) a[i]=read(),a[i][las]=i;
	fo(i,n+1,n+m) 
	{
		fo(l,1,k)
		if(!las[l]) 
		{
			las[l]=i;
			a[i]=l;
			break;
		}
		if(!a[i]) 
		{
			all=i-1;
			break;
		}
	}
	if(all)
	{
		fo(i,1,k) c[i]=i;
		sort(c+1,c+1+k,cmp);
		fo(i,all+1,n+m)
			a[i]=c[(i-all-1)%k+1];
	}
	memset(las,0,sizeof las);
	all=n+m;
	fo(i,1,all) las[i]=ti[a[i]],ti[a[i]]=i;
	if(m>1e9)
	{
		q=m/k-2;q=all-q*k;
		swap(all,q);
		flag=1;
	}
	solve();
	printf("%lld\n",ans);
	return 0;
}











