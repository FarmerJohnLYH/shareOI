#include <cstdio>
#include <cstring>
#include <iostream>
#define oo ((ll)1e15)
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll N=330;
ll n;
ll f[N][N*N],p[N][N*N];
ll k,x;
void dp()
{
	f[0][0]=1;p[0][0]=1;
	fo(i,1,n)
	{
		fo(j,0,min(1ll*i*(i-1)/2,x))
		{
			if(j-(i-1)-1<0) f[i][j]=p[i-1][j];
			else f[i][j]=p[i-1][j]-p[i-1][j-(i-1ll)-1ll];
			if(f[i][j]>1e15) f[i][j]=oo;
		}
		p[i][0]=f[i][0];
		fo(j,1,x)p[i][j]=p[i][j-1]+f[i][j];
	}
}
ll vis[N],a[N];
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%lld%lld%lld",&n,&k,&x);
	dp();
	fo(i,1,n)
	{
		ll cnt=0;
		fo(j,1,n)
		if(!vis[j])
		{
			int c=j-1;
			fo(l,1,j-1) c-=vis[l];
			if(f[n-i][x-c]+cnt>=k)
			{
				a[i]=j;vis[j]=1; 
				x-=c;k-=cnt;
				break;
			}
			cnt+=f[n-i][x-c];
		}
	}
	fo(i,1,n) printf("%lld ",a[i]);
	printf("\n");
	return 0;
}











