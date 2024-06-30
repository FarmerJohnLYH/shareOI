#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 666666666666666ll
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
typedef long double db;
const ll N=1010000,M=500500;
const db eps=1e-8;
ll n,m;
struct node{
	db k,b;
	ll l,r;
}a[N];
ll t[M*8];
db get(ll x,ll v)
{
	return((db)(a[x].k*(db)v+a[x].b));
}
void add(ll x,ll l,ll r,ll d)
{
	if(l>r)return;
	ll mid=(l+r)>>1;
	if(a[d].l<=l&&r<=a[d].r)
	{
		if(!t[x]) 
		{
			t[x]=d;
			return;
		}
		db fl=get(d,l),fr=get(d,r),gl=get(t[x],l),gr=get(t[x],r);
		if(fl>=gl&&fr>=gr) 
		{
			t[x]=d;
			return;
		}
		if(fl<=gl&&fr<=gr)return;
		db crs=-(db)(a[t[x]].b-a[d].b)/(db)(a[t[x]].k-a[d].k);
		if(fl+eps<=gl)
		{
			if(mid+1>=crs-eps) add(x<<1,l,mid,t[x]),t[x]=d;
			else add(x<<1|1,mid+1,r,d);
		}
		else
		{
			if(mid+1>=crs-eps) add(x<<1,l,mid,d);
			else add(x<<1|1,mid+1,r,t[x]),t[x]=d;
		}
		return;
	}
	if(a[d].l<=mid) add(x<<1,l,mid,d);
	if(a[d].r>mid) add(x<<1|1,mid+1,r,d);
}
db query(ll x,ll l,ll r,ll p)
{
	if(l==r)
	{
		if(t[x])return(get(t[x],p));	
		else return(0);
	}
	ll mid=(l+r)>>1;db rt=0;
	if(t[x])rt=max(rt,get(t[x],p));
	if(p<=mid) rt=max(rt,query(x<<1,l,mid,p));
	else rt=max(rt,query(x<<1|1,mid+1,r,p));
	return(rt);
}
void nwnd()
{
	ll i=++n;
	db b,k;
	scanf("%Lf%Lf",&b,&k);b-=k;
	a[i].k=k;
	a[i].b=b;
	a[i].l=1,a[i].r=M;
	add(1,1,M,i);
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
//	 freopen("query.in","r",stdin);
//	 freopen("query.out","w",stdout);
	scanf("%lld",&m);
	ll ppp=0;
	while(m--)
	{
		char tp[10];ll x,y,c,d;
		scanf("%s ",&tp);
		if(tp[0]=='Q')
		{
			scanf("%lld",&x);
			db ans=query(1,1,M,x);
//			printf("%Lf\n",ans); 
			printf("%lld\n",(ll)(ans/(db)100));
		}
		else nwnd();
	}
	return 0;
}




