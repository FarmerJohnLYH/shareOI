#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=2020,mo=1e9+7;
int T,k;
ll n,b[N],c[N][N];
ll ny[N];
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	c[0][0]=c[1][0]=c[1][1]=1;
	ny[1]=1;
	fo(i,2,N-10) ny[i]=((-mo/i)*ny[mo%i]%mo+mo)%mo;
	fo(i,1,N-10) 
	{
		c[i][0]=c[i][i]=1;
		fo(j,1,i-1) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mo;
	}
	b[0]=1;
	fo(i,1,N-10) 
	{
		fo(j,0,i-1)
			b[i]=(b[i]+b[j]*c[i+1][j]%mo)%mo;
		b[i]=((-ny[i+1]*b[i])%mo+mo)%mo;
	}
	b[1]=(mo-b[1])%mo;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%d",&n,&k);
		ll ans=0,nw=n=n%mo;
		fo(i,1,k+1) 
		{
			ans=(ans+c[k+1][k+1-i]*nw%mo*b[k+1-i]%mo)%mo; 
			nw=nw*n%mo;
		}
		ans=ans*ny[k+1]%mo;
		printf("%lld\n",(ans+mo)%mo);	
	}

	return 0;
}








