#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll; 
const ll N=1010;
ll f[2][N][N],n,a[N];
#define min(x,y) ((x)<(y)?(x):(y))
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%lld",&n);
	fo(i,1,n) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	fo(i,2,n) a[i]+=a[i-1];
	memset(f,127,sizeof f);
	ll oo=f[0][0][0];
	f[0][1][0]=0;
	ll x=0,y;
	fo(i,0,n-1)
	{
		y=x^1;
		memset(f[y],127,sizeof f[y]);
		fo(j,0,n-i) fo(k,0,n-i-j)
			if(f[x][j][k]!=oo)
			{
				if(j)f[y][j-1][k]=min(f[y][j-1][k],f[x][j][k]);
				f[x][j+k][j]=min(f[x][j+k][j],f[x][j][k]+a[n-i]);
			}
		x=y;
	}
	printf("%lld\n",f[x][0][0]);
}
