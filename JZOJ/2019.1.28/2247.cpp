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
const ll N=5050,Mo=998244353;
ll a,b,c;
ll yh[N][N],jc[N];
int main()
{
//	freopen("love.in","r",stdin);
//	freopen("love.out","w",stdout);
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%lld%lld%lld",&a,&b,&c);
	yh[1][1]=yh[0][0]=yh[1][0]=yh[2][0]=yh[2][2]=1;
	yh[2][1]=2;
	fo(i,3,N-40) 
	{
		yh[i][0]=yh[i][i]=1;
		fo(j,1,i-1)
			yh[i][j]=(yh[i-1][j]+yh[i-1][j-1])%Mo;
	}
	jc[0]=1;
	fo(i,1,N-40) jc[i]=1ll*jc[i-1]*i%Mo;
	ll ans=1,s1=0,s2=0,s3=0;
	ll tmp=min(a,b);
	fo(i,0,tmp)
		s1=(1ll*s1+1ll*yh[a][i]*yh[b][i]%Mo*jc[i])%Mo;
	tmp=min(b,c);
	fo(i,0,tmp)
		s2=(1ll*s2+1ll*yh[b][i]*yh[c][i]%Mo*jc[i])%Mo;
	tmp=min(a,c);
	fo(i,0,tmp)
		s3=(1ll*s3+1ll*yh[a][i]*yh[c][i]%Mo*jc[i])%Mo;
	ans=(s1*s2%Mo*s3)%Mo;
	printf("%lld\n",ans);
	return 0;
}
