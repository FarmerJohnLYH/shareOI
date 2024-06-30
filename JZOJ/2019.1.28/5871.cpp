#pragma GCC optimize(2) 
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll N=200200;
ll n,m;
ll p[N],c[N];
ll t[N*4],tg[N*4];
void down(ll x)
{ 
	if(tg[x])
	{
		t[x<<1]+=tg[x];t[x<<1|1]+=tg[x];
		tg[x<<1]+=tg[x],tg[x<<1|1]+=tg[x];
		tg[x]=0;
	}
	t[x]=max(t[x<<1|1],t[x<<1]);
}
ll ans,qv;
void add(ll x,ll l,ll r,ll ql)
{
	if(ql<=l)
	{
		t[x]+=qv,tg[x]+=qv;
		return;
	}
	if(l==r)return;
	else down(x);
	ll mid=(l+r)>>1;
	if(mid>=ql)add(x<<1,l,mid,ql);
	add(x<<1|1,mid+1,r,ql);
	t[x]=max(t[x<<1],t[x<<1|1]);
}
ll find(ll x,ll l,ll r,ll p)
{
	if(p==0)return 0;
	if(l==r)return(t[x]);
	else down(x);
	ll mid=(l+r)>>1;
	if(p<=mid) return(find(x<<1,l,mid,p));
	else return(find(x<<1|1,mid+1,r,p));
}
void query(ll x,ll l,ll r,ll ql,ll qr)
{
	if(t[x]<qv||l>ans) return;
	if(l==r) 
	{
		ll p=2*find(1,1,n,l-1);
		if(t[x]==p) 
			ans=min(ans,l);
		qv=t[x];
		return;
	}else  down(x);
	ll mid=(l+r)>>1;
	if(mid>=ql) query(x<<1,l,mid,ql,qr);
	query(x<<1|1,mid+1,r,ql,qr);
}
void build(ll x,ll l,ll r)
{
	if(l==r)
	{
		t[x]=p[l];
		return;
	}
	ll mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	t[x]=max(t[x<<1],t[x<<1|1]);
}
ll va[N];
ll read()
{
    char ch=' ';ll q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;ll n=q*w;return n;
}
ll buf[30],b0;
void write(ll x)
{
	b0=0;
	if(x==0)putchar('0');
	else
	while(x) buf[++b0]=x%10,x/=10;
	fd(i,b0,1) putchar(buf[i]+'0');
}
int main()
{
	 freopen("challenge.in","r",stdin);
	 freopen("challenge.out","w",stdout);
//	 freopen("D:/LiuYuanHao/c1.in","r",stdin);
//	  freopen("D:/LiuYuanHao/c.out","w",stdout);
//	scanf("%lld%lld",&n,&m);
	n=read(),m=read();
	ans=oo;
	fo(i,1,n) 
	{
		p[i]=read();
		va[i]=p[i];
		p[i]+=p[i-1];
		if(ans==oo&&p[i]==p[i-1]*2)
			ans=i;
	}
	build(1,1,n);
	fo(i,1,m)
	{
		ll x,y;
		x=read(),y=read();
		qv=y-va[x];
		va[x]=y;
		add(1,1,n,x);
		if(ans>=x)
		{
			ans=oo;
			qv=2*find(1,1,n,x-1);
			query(1,1,n,x,n);
		}
		if(ans==oo) printf("-1\n");
		else write(ans),putchar('\n');
	}
	return 0;
}











