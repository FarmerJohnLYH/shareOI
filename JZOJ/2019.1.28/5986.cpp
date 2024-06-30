#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=10010;
ll n,m;
ll v[N][N],a[N],b[N];
ll solve()
{	
	ll sum=0;
	fo(i,1,n)fo(j,1,n) v[i][j]=min(a[i],b[j]),sum+=v[i][j];
	return sum;
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("D:/LiuYuanHao/a.ansa","w",stdout);
	// freopen("a.in","r",stdin);
	// freopen("a.ans","w",stdout);
	scanf("%lld",&n);
	fo(i,1,n) scanf("%lld",&a[i]);
	fo(i,1,n) scanf("%lld",&b[i]);
	printf("%lld\n",solve());
	scanf("%lld",&m);
	fo(i,1,m)
	{
		ll tp,x,y;
		scanf("%lld%lld%lld",&tp,&x,&y);
		if(tp==0) a[x]=y;
		else b[x]=y;
		printf("%lld\n",solve());
	}
	return 0; 
}








