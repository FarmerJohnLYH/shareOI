#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=100100;
ll s[N];
ll n,d,b;
bool check(ll m){
	if(m==(n+1)/2) return 1;
	fo(i,m+1,n/2)
	{
		ll all=(i-m)*b,j=n-i+1,l1=max(1ll,i-i*d),r1=min(n,i+i*d),l2=max(1ll,j-i*d),r2=min(n,j+i*d);
		if(r1<l2)
		{
			if(s[r1]-s[l1-1]<all)return 0;
			if(s[r2]-s[l2-1]<all)return 0;
		}
		else
		if(l1<l2&&l2<=r1&&r1<r2)
		{
			if(s[r1]-s[l2-1]<max(all-(s[l2-1]-s[l1-1]),0ll)+max(all-(s[r2]-s[r1]),0ll)) return 0;
		}
		else 
			if(s[r2]-s[l1-1]<2*all) return 0;
	}
	return 1;
}
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%I64d%I64d%I64d",&n,&d,&b);
	fo(i,1,n)
	{
		ll x;
		scanf("%I64d",&x);
		s[i]=s[i-1]+x;
	}
	ll l=0,r=(n+1)/2,ans=r+1;
	while (l<=r)
	{
		ll mid=(l+r)/2;
		if (check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%I64d\n",ans);
}