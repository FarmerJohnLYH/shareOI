#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=55,M=440,mo=1e9+7;
int n,m;
ll f[M][M][N];
int a[2][M];
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,30)
	{
		if((1<<i)&y) rt=rt*x%mo;
		x=x*x%mo;
	}
	return rt;
}
ll jc[M],ny[M];
ll P(ll x,ll y)
{
	if(x<y)return 0;
	return(jc[x]*ny[x-y]%mo);
}
int d[M];
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,n)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		++a[0][x],++a[1][m-y+1];
		++d[x+1],--d[m-y+1];
	}
	fo(i,1,m) d[i]+=d[i-1];
	jc[0]=1;fo(i,1,400) jc[i]=jc[i-1]*i%mo;
	ny[400]=qsm(jc[400],mo-2);fd(i,399,0)ny[i]=ny[i+1]*(i+1)%mo; 
	f[0][0][0]=1;
	fo(i,1,m)
	{
		int lw=a[0][i],rw=a[1][i];
		fo(j,0,m) fo(k,0,n)
		{
			if(k-rw>=0&&j+lw-1>=0)f[i][j][k]=(f[i][j][k]+f[i-1][j+lw-1][k-rw]*P(j+lw,lw))%mo;
			if(k-rw+1>=0)f[i][j][k]=(f[i][j][k]+f[i-1][j+lw][k-rw+1]*(k+1)%mo*P(j+lw,lw)%mo)%mo;
			if(d[i]&&k-rw>=0) f[i][j][k]=(f[i][j][k]+f[i-1][j+lw][k-rw]*d[i]%mo*P(j+lw,lw)%mo)%mo;
		}
	}
	ll ans=0;
	fo(i,0,m) ans=(ans+f[m][i][0])%mo;
	printf("%lld\n",ans);
	return 0;
}








