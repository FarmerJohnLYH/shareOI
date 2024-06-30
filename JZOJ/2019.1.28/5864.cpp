#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo (1ll<<60)
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=11,M=1001000;
ll a[N],n;
ll bz[M];
ll hd,tl,d[M],mn[M];
bool vis[M];
priority_queue<ll> qu;
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
//	freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%lld",&n);
	scanf("%lld",&a[1]);
	if(n==2)
	{
		scanf("%lld\n",&a[2]);
		printf("%lld\n",(a[1]-1)*(a[2]-1)-1);
		return 0;
	}
	bz[0]=0;fo(i,1,a[1]-1) bz[i]=oo;
	fo(i,2,n) 
	{
		scanf("%lld",&a[i]);
		bz[a[i]%a[1]]=min(bz[a[i]%a[1]],a[i]);
		qu.push(-a[i]);
	}
	while(!qu.empty())
	{
		ll x=-qu.top();
		qu.pop();
		if(vis[x%a[1]]) continue;
		else vis[x%a[1]]=1;
		fo(i,1,n)
		{
			ll p=x+a[i];
			if(p<bz[p%a[1]]) 
			{
				bz[p%a[1]]=p;
				qu.push(-p);
			}
		}
	}
	ll mx=0;
	fo(i,1,a[1]-1)
		mx=max(mx,bz[i]);
	printf("%lld\n",mx-a[1]);
	return 0;
}











