#include <set>
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
const ll N=200200;
ll n,m;
struct node{
	ll x;
};
set<node> s;
ll l[N],r[N];
ll v[N];
bool operator < (node x,node y)
{
	return(v[x.x]>v[y.x]);
}
node p;
void del(ll x)
{
	x[l][r]=x[r],x[r][l]=x[l];
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	ll ans=0;
	scanf("%lld%lld",&n,&m);
	fo(i,1,n) scanf("%lld",&v[i]),l[i]=i-1,r[i]=i+1;
	l[1]=n,r[n]=1;
	0[v]=-oo;
	if(m*2>n) printf("Error!\n");
	else 
	{
		fo(i,1,n) p.x=i,s.insert(p);
		while(m--)
		{
			p.x=0;
			s.insert(p);
			p=*s.begin();s.erase(p);ll mx=p.x;
			p.x=mx[l];s.erase(p);p.x=mx[r];s.erase(p);
			ans+=mx[v];
			mx[v]=mx[l][v]+mx[r][v]-mx[v];
			del(mx[l]),del(mx[r]);
			p.x=mx;s.insert(p);
		}
		printf("%lld\n",ans);		
	}
	return 0;
}











