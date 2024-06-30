#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=1010;
ll n,q,a[N];
ll f[N][N];
int main()
{
	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
//	 freopen("D:/LiuYuanHao/a.in","r",stdin);
//	 freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%lld",&n);fo(i,1,n)scanf("%lld",&a[i]);
	fo(i,1,1000) fo(j,1,n)
	{
		if(i==1)f[i][j]=a[j];
		else if(j==1)f[i][j]=f[i-1][j]+a[j];
		else f[i][j]=min(f[i-1][j-1],f[i-1][j])+a[j];
	}
	scanf("%lld",&q);
	fo(i,1,q)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",f[x][y]);
	}
	return 0;
}











