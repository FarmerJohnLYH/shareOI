#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for(ll i=(x);i<=(y);++i)
#define fd(i,x,y) for(ll i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll N=200200*2;
ll n,m,k;
ll t[N*4];
struct node{
	ll p,tp,r;
	node(ll tp_=0,ll p_=0,ll r_=0)
	{
		p=p_,tp=tp_,r=r_;
	}
}a[N*2];ll a0;
ll all,now;
ll ans;
bool cmp(node a,node b)
{
	return(a.p<b.p||(a.p==b.p&&a.tp>b.tp));
}
ll qp,qv;
void add(ll x,ll l,ll r)
{
	if(l==r) 
	{
		t[x]+=qv;
		return;
	}
	ll mid=(l+r)>>1;
	if(qp<=mid) add(x<<1,l,mid);
	else add(x<<1|1,mid+1,r);
	t[x]=t[x<<1]+t[x<<1|1];
}
ll query(ll x,ll l,ll r)
{
	if(l==r) return(l);
	ll mid=(l+r)>>1;
	if(t[x<<1|1]>=qv) return query(x<<1|1,mid+1,r);
	else 
	{
		qv-=t[x<<1|1];
		return query(x<<1,l,mid);
	}
}
ll read()
{
	ll rt=0,fg=1;char ch=getchar();
	while(ch!='-'&&(!(ch>='0'&&ch<='9'))) ch=getchar();
	if(ch=='-') fg=-1,ch=getchar();
	while(ch>='0'&&ch<='9') rt=rt*10+ch-'0',ch=getchar();
	return rt*fg;
}
ll mx,pp;
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("xiaoqiao.in","r",stdin);
	freopen("xiaoqiao.out","w",stdout);
	n=read(),m=read(),k=read();
	all=2*m;
	fo(i,1,n)
	{
		ll v=read(),l=read(),r=read();
		mx=max(mx,v);
		l+=m+1,r+=m+1;
		if(l>r) 
		{
			int l1=l,r1=all+1;
			int l2=1,r2=r;
			a[++a0]=node(1,l1,v);
			if(r1<=all) a[++a0]=node(-1,r1,v);
			a[++a0]=node(1,l2,v);
			if(r2<=all) a[++a0]=node(-1,r2,v);
		}
		else
		{
			a[++a0]=node(1,l,v);
			if(r<=all) a[++a0]=node(-1,r,v);	
		}
	}
	sort(a+1,a+1+a0,cmp);
	ll tl=1;
	fo(i,1,all)
	{
		while(tl<=a0&&a[tl].p==i) 
		{
			qp=a[tl].r,qv=a[tl].tp;
			add(1,1,mx);			
			now+=a[tl].tp;
			++tl;
		}
		if(now>=k) 
		{
			qv=k;
			ll tmp=query(1,1,mx);
			ans=(ans+tmp*tmp);
 		}
	}
	printf("%lld\n",ans);
	return 0;
}








