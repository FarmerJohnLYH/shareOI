#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (ll pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (ll pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
ll lowbit(ll x) {return((x)&(-x));}
ll min(ll x,ll y){return (x>y)?(y):(x);}
ll max(ll x,ll y){return (x>y)?(x):(y);}
const ll N=100100;
ll n;
struct node{
	ll x,y;
}a[N],dl,ur;
ll ans;
bool cmpxs(node a,node b)
{
	return(a.x<b.x||(a.x==b.x&&a.y>b.y));
}
bool cmpxb(node a,node b)
{
	return(a.x<b.x||(a.x==b.x&&a.y<b.y));
}
ll sq(ll sx,ll sy,ll lx,ll ly) 
{
	return((lx-sx)*(ly-sy));
}
int main()
{
	freopen("D:/LiuYuanHao/c2.in","r",stdin);
	freopen("D:/LiuYuanHao/c.out","w",stdout);
	scanf("%lld",&n);
	ur.x=ur.y=-oo,dl.x=dl.y=oo;
	fo(i,1,n)
	{
		scanf("%lld%lld",&a[i].x,&a[i].y);
		dl.x=min(a[i].x,dl.x),dl.y=min(a[i].y,dl.y);
		ur.x=max(a[i].x,ur.x),ur.y=max(a[i].y,ur.y);
	}
	printf("%lld\n",((ur.y-dl.y)+(ur.x-dl.x))*2);
	ans=1ll*(ur.x-dl.x)*(ur.y-dl.y);
	sort(a+1,a+1+n,cmpxs);
		ll las=1;	
		ll mxy=a[1].y;
		fo(i,2,n)
		if(a[i].x!=a[las].x)
		{
			ans-=sq(a[las].x,mxy,a[i].x,ur.y);
			mxy=max(mxy,a[i].y);
			las=i;
			if(mxy==ur.y) break;
		}
		las=n;	
		mxy=a[n].y;
		fd(i,n-1,1)
		if(a[i].x!=a[las].x)
		{
			ans-=sq(a[i].x,dl.y,a[las].x,mxy);
			mxy=min(mxy,a[i].y);
			las=i;
			if(mxy==dl.y) break;
		
		}
		
	sort(a+1,a+1+n,cmpxb);
		las=n;	
		mxy=a[n].y;
		fd(i,n-1,1)
		if(a[i].x!=a[las].x)
		{
			ans-=sq(a[i].x,mxy,a[las].x,ur.y);
			mxy=max(mxy,a[i].y);
			las=i;
			if(mxy==ur.y) break;
		}
		
		las=1;
		mxy=a[1].y;
		fo(i,2,n)
		if(a[i].x!=a[las].x)
		{
			ans-=sq(a[las].x,dl.y,a[i].x,mxy);
			mxy=min(mxy,a[i].y);
			las=i;
			if(mxy==dl.y) break;
		}
	printf("%lld\n",ans);
	return 0;
}










