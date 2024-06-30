#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (ll i=(x);asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<ll,ll> PI;
ll abs(ll x) {return(((x)>=0)?(x):(-(x)));}
ll max(ll x,ll y) {return(((x)>(y))?(x):(y));}
ll min(ll x,ll y) {return(((x)<(y))?(x):(y));}
ll lowbit(ll x) {return((x)&(-x));}
const ll N=50050,dev=1e5;
PI a[N];
struct node{
	ll x,y;//坐标
	ll a,b;//向量
}c[N];
ll n,ans;
void link(ll x,ll y,ll p)
{
	c[p].x=a[x].fi,c[p].y=a[x].se;
	c[p].a=a[y].fi-a[x].fi,c[p].b=a[y].se-a[x].se;
}
ll check(ll now)
{
	
}
int main()
{
	freopen("D:/LiuYuanHao/","r",stdin);
	scanf("%lld",&n);
	fo(i,1,n) 
	{
		scanf("%lld%lld",&a[i].fi,&a[i].se),a[i].fi*=dev,a[i].se*=dev;
		if((i-1)) link(i-1,i,i-1);
	}
	link(n,1,n);
	ll le=0,ri=1e13;//dev*1e7*10
	ll mid=0;
	while(le<=ri)
	{
		mid=(le+ri)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	db buf=(db)ans/((db)dev);
	printf("%.3lf\n",buf);
}











