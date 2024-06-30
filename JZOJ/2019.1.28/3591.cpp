//#pragma GCC optimize(2)
//#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fi first
#define se second
#define fo(i,x,y) for (ll pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (ll pq = (y),i = (x);i >= pq;-- i)
#define oo 100000000
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<ll,ll> PI;
ll lowbit(ll x) {return((x)&(-x));}
ll min(ll x,ll y){return (x>y)?(y):(x);}
ll max(ll x,ll y){return (x>y)?(x):(y);}
const ll N=200200*2;
ll n,q;
struct node{
	ll x,y,op,id,t;
}a[N],b[N],c[N];
ll ans[N];
bool cmp1(node a,node b)
{
	return(a.x<b.x);
}
struct tr{
	ll mn,mx;
}t[N*8];
ll buff[N];
void clear()
{
	fo(i,1,buff[0]) t[buff[i]].mn=1ll*oo*oo,t[buff[i]].mx=-1ll*oo*oo;
	buff[0]=0;
}
void insert(ll x,ll l,ll r,ll qp,ll qv)
{
	buff[++buff[0]]=x;
	if(l==r) t[x].mn=min(t[x].mn,qv),t[x].mx=max(t[x].mx,qv);
	if(l>=r) return;
	ll mid=(l+r)>>1;
	if(qp<=mid) insert(x<<1,l,mid,qp,qv);
	else insert(x<<1|1,mid+1,r,qp,qv);
	t[x].mn=min(t[x<<1].mn,t[x<<1|1].mn);
	t[x].mx=max(t[x<<1].mx,t[x<<1|1].mx);
}
tr query(ll x,ll l,ll r,ll ql,ll qr)
{
	if(l==ql&&r==qr) return(t[x]);
	tr rt={1ll*oo*oo,-1ll*oo*oo},tmp;
	ll mid=(l+r)>>1;
	if(ql<=mid) 
	{
		tmp=query(x*2,l,mid,ql,min(qr,mid));
		if(tmp.mx>rt.mx) rt.mx=tmp.mx;
		if(tmp.mn<rt.mn) rt.mn=tmp.mn;
	}
	if(qr>mid) 
	{
		tmp=query(x*2+1,mid+1,r,max(ql,mid+1),qr);
		if(tmp.mx>rt.mx) rt.mx=tmp.mx;
		if(tmp.mn<rt.mn) rt.mn=tmp.mn;
	}
	return rt;
}
ll bh,ch,bn,cn;
int ppp;
void solve(ll l,ll r)
{
	if(l>=r) return;
	ll mid=(l+r)>>1;
	solve(l,mid);
	solve(mid+1,r);
	bn=0,cn=0;
	fo(i,l,mid)
	if(a[i].op==0)
		b[++bn]=a[i];
	fo(i,mid+1,r)
	if(a[i].op>0)
		c[++cn]=a[i];
	if(bn==0||cn==0) return;
	sort(b+1,b+1+bn,cmp1);
	sort(c+1,c+1+cn,cmp1);
	clear();
	bh=0,ch=0;
	while(ch++<cn)
	{
		while(bh+1<=bn&&b[bh+1].x<=c[ch].x) insert(1,1,q,b[bh+1].t,b[bh+1].x+b[bh+1].y),bh++;
		tr tmp=query(1,1,q,1,c[ch].t);
		if(c[ch].op==2)
			ans[c[ch].id]=max(ans[c[ch].id],-tmp.mn+(c[ch].x+c[ch].y));
		if(c[ch].op==1)
			ans[c[ch].id]=min(ans[c[ch].id],-tmp.mx+(c[ch].x+c[ch].y));
	}
	clear();
	bh=bn+1,ch=cn+1;
	while((--ch)>0)
	{
		while(bh-1>0&&b[bh-1].x>=c[ch].x) insert(1,1,q,b[bh-1].t,b[bh-1].x+b[bh-1].y),bh--;
		tr tmp=query(1,1,q,c[ch].t,q);
		if(c[ch].op==2)ans[c[ch].id]=max(ans[c[ch].id],tmp.mx-(c[ch].x+c[ch].y));
		if(c[ch].op==1)
			ans[c[ch].id]=min(ans[c[ch].id],tmp.mn-(c[ch].x+c[ch].y));
	}
	clear();
	bh=0,ch=0;
	while(ch++<cn)
	{
		while(bh+1<=bn&&b[bh+1].x<=c[ch].x) insert(1,1,q,b[bh+1].t,b[bh+1].x-b[bh+1].y),bh++;
		tr tmp=query(1,1,q,c[ch].t,q);
		if(c[ch].op==2)ans[c[ch].id]=max(ans[c[ch].id],-tmp.mn+(c[ch].x-c[ch].y));
		if(c[ch].op==1)
			ans[c[ch].id]=min(ans[c[ch].id],-tmp.mx+(c[ch].x-c[ch].y));
	}	
	clear();
	bh=bn+1,ch=cn+1;
	while((--ch)>0)
	{
		while(bh-1>0&&b[bh-1].x>=c[ch].x) insert(1,1,q,b[bh-1].t,b[bh-1].x-b[bh-1].y),bh--;
		tr tmp=query(1,1,q,1,c[ch].t);
		if(c[ch].op==2)ans[c[ch].id]=max(ans[c[ch].id],tmp.mx-(c[ch].x-c[ch].y));
		if(c[ch].op==1)
			ans[c[ch].id]=min(ans[c[ch].id],tmp.mn-(c[ch].x-c[ch].y));
	}
}
PI buf[N];
void apt()
{
	fo(i,1,q) buf[i].fi=a[i].y,buf[i].se=i;
	sort(buf+1,buf+1+q);
	fo(i,1,q) a[buf[i].se].t=i;
}
int main()
{
	 freopen("D:/LiuYuanHao/d2.in","r",stdin);
	 freopen("D:/LiuYuanHao/c.out","w",stdout);
	buff[0]=0;
	fo(i,0,8*N-1) t[i].mn=1ll*oo*oo,t[i].mx=-1ll*oo*oo;
	scanf("%lld",&n);
	fo(i,1,n)
	{	
		ll x,y;
		scanf("%lld%lld",&x,&y);
		a[i].x=x,a[i].y=y,a[i].op=0;
		a[i].id=i;
	}
	scanf("%lld",&q);q+=n;
	fo(i,n+1,q) 
	{
		scanf("%lld%lld%lld",&a[i].op,&a[i].x,&a[i].y),a[i].id=i;
			 if(a[i].op==1) ans[i]=1ll*oo*oo;
		else if(a[i].op==2) ans[i]=-1ll*oo*oo;	
	}
	apt();
	solve(1,q);
	fo(i,n+1,q)
	{
		if(a[i].op>0)
			printf("%lld\n",ans[i]);
	}

	return 0;
}









