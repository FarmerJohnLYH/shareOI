#pragma GCC optimize(2)
#include <ctime>
#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll N=300300;
ll n,m;
ll a[N],b[N];ll A[N],B[N];
ll p[N*2],p0;
map<ll,ll> mp;
ll tt[N*2];
struct qry{
	ll t,x,y;
}q[N];
ll ans;
struct node{
	ll c,s;
	node(ll c_=0,ll s_=0)
	{
		c=c_,s=s_;
	}
};
//qrys >=pl
ll t[2][N*4],s[2][N*4];
node qrys(ll k,ll x,ll l,ll r,ll pl)
{
	if(l>=pl)
		return(node(t[k][x],s[k][x]));
	ll mid=(l+r)>>1;
	if(pl>mid) return (qrys(k,x<<1|1,mid+1,r,pl));
	else 
	{
		node va=qrys(k,x<<1|1,mid+1,r,pl),vb=qrys(k,x<<1,l,mid,pl);
		va.s+=vb.s,va.c+=vb.c;
		return va;
	}
}
void cg(ll k,ll x,ll l,ll r,ll pl,ll v)
{
	if(l==r)
	{
		t[k][x]+=v;
		s[k][x]+=v*p[pl];
		return ;
	}
	ll mid=(l+r)>>1;
	if(pl<=mid) cg(k,x<<1,l,mid,pl,v);
	else cg(k,x<<1|1,mid+1,r,pl,v); 
	t[k][x]=t[k][x<<1]+t[k][x<<1|1];
	s[k][x]=s[k][x<<1]+s[k][x<<1|1];
}
void solve(ll t,ll x,ll y)
{
	if(t==0)
	{
		ll le=A[x],ri=mp[y];
		if(le==ri) return;
		cg(0,1,1,p0,le,-1);
		cg(0,1,1,p0,ri,1);
			node va=qrys(1,1,1,p0,le);	
			ans=ans-va.c*a[x]+va.s;
			va=qrys(1,1,1,p0,ri);
			ans=ans+va.c*y-va.s;
		a[x]=y;A[x]=ri;
	}
	else
	{
		ll le=B[x],ri=mp[y];
		if(le==ri) return;
		cg(1,1,1,p0,le,-1);
		cg(1,1,1,p0,ri,1);
			node va=qrys(0,1,1,p0,le);	
			ans=ans-va.c*b[x]+va.s;
			va=qrys(0,1,1,p0,ri);
			ans=ans+va.c*y-va.s;
		b[x]=y;B[x]=ri;
	}
}
ll read()
{
    char ch=' ';ll q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;ll n=q*w;return n;
}
ll buf[40],b0;
void write(ll x)
{
	b0=0;
	if(x==0)putchar('0');
	else
	while(x) buf[++b0]=x%10,x/=10;
	fd(i,b0,1) putchar(buf[i]+'0');
	puts("");
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	n=read();
	fo(i,1,n) a[i]=read(),p[++p0]=a[i];
	fo(i,1,n) b[i]=read(),p[++p0]=b[i];
	m=read();
	fo(i,1,m)
	{
		q[i].t=read(),q[i].x=read(),q[i].y=read();
		p[++p0]=q[i].y;
	}
	sort(p+1,p+1+p0);ll qaq=p0;p0=0;
	p[0]=-1;
	fo(i,1,qaq) 
		if(p[i]!=p[i-1]) p[++p0]=p[i];
	fo(i,1,p0) mp[p[i]]=i;
	fo(i,1,n)
	{
		A[i]=mp[a[i]],B[i]=mp[b[i]];
		cg(0,1,1,p0,A[i],1);
		cg(1,1,1,p0,B[i],1);
	}
	fo(i,1,n) ++tt[B[i]];
	fo(i,1,n) 
	if(tt[A[i]])
		ans-=tt[A[i]]*a[i];
//	printf("");
	fo(i,1,n) 
	{
		node va=qrys(1,1,1,p0,A[i]);
		ans+=va.c*a[i];
		va=qrys(0,1,1,p0,B[i]);
		ans+=va.c*b[i];
	}
	write(ans);
	fo(i,1,m)
	{
		solve(q[i].t,q[i].x,q[i].y);
		write(ans);
	}
	return 0; 
}








