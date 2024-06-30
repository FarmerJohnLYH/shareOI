#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=6060,S=110,mo=1e4+7;
int h,w,s;
int C[N][N];
int f[N][S],g[N][S];
int ans;
int dd(int x,int y) 
{
	return C[x+y-1][y-1];
}
int qsm(int a,int b)
{
	int x=1;
	a%=mo,b%=(mo-1);
	while(b)
	{
		x=((b&1))?((1ll*x*(a))%mo):(x);
		b>>=1,a=(1ll*a*a)%mo;
	}
	return x;
}
int main() 
{
	 freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("greedhead.in","r",stdin);
//	freopen("greedhead.out","w",stdout);
	scanf("%d%d%d",&h,&w,&s);
	C[0][0]=1;
	fo(i,1,h+w+s) 
	{
		C[i][i]=C[i][0]=1;
		fo(j,1,i-1) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
	}
	int mx=max(h,w);
	g[0][0]=f[0][0]=1;
	fo(i,1,mx) fo(j,0,s) fo(l,0,s-j)
	f[i][j+l]=(f[i][j+l]+(1ll*f[i-1][j]*l%mo))%mo,g[i][j+l]=(g[i][j+l]+(1ll*g[i-1][j]*(l+1)%mo))%mo;
	fo(d,1,min(h-1,s+4))
	{
		int wc=max(1,C[w-1+d-2][w-2]),dn=w-1,rn=d-1;
		int rm=(h-1)*(w-1)-dn-rn;
		rm=qsm(1+s,rm);
		fo(zg,0,s) 
		{
			int sum=0;
			fo(gg,0,zg) 
				sum=(sum+g[dn][gg]*f[rn][zg-gg]%mo)%mo;
			ans=(ans+rm*wc%mo*sum%mo*dd(s-zg,h-d)%mo)%mo;
		}
	}
	swap(h,w);swap(f,g);
	fo(d,1,min(h-1,s+4))
	{
		int wc=max(1,C[w-1+d-2][w-2]),dn=w-1,rn=d-1;
		int rm=(h-1)*(w-1)-dn-rn;
		rm=qsm(1+s,rm);
		fo(zg,0,s) 
		{
			int sum=0;
			fo(gg,0,zg) 
				sum=(sum+g[dn][gg]*f[rn][zg-gg]%mo)%mo;
			ans=(ans+rm*wc%mo*sum%mo*dd(s-zg,h-d)%mo)%mo;
		}
	}
	printf("%d\n",ans);
}
