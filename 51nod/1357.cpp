#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll N=1000100;
ll n,m;
ll a[N],ans;
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	// freopen("lock.in","r",stdin);
	// freopen("lock.out","w",stdout);
	scanf("%lld%lld",&n,&m);++n;
	fo(i,2,n) scanf("%lld",&a[i]);
	a[1]=0;
	fo(i,1,n) a[i]=(m+a[i+1]-a[i])%m;
	sort(a+1,a+1+n);
	ll fl=1,fr=n;
	while(fl<fr)
	{
		ll p=a[fl];
		a[fl]-=(m-a[fr]);
		if(a[fl]<0)a[fr]=m+a[fl],a[fl]=0; else a[fr]=m;
		ans+=p-a[fl];
		if(a[fl]==0) ++fl;if(a[fr]==m) --fr; 
	}
	ans+=min(a[fl],m-a[fl]);
	printf("%lld\n",ans);
	return 0;
}











