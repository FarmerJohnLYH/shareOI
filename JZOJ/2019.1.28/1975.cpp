#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
using namespace std;
const int N=1010,mo=10007;
int d[N];
int f[N][N];
int n,m,k,cnt;
int calc(int x){return (1ll*x*(x-1)/2)%mo;}
int read()
{
	int rt=0,n=1;
	char c=getchar();while(!((c>='0'&&c<='9')||c=='-')) c=getchar();
	if(c=='-')n=-1,c=getchar();
	while(c>='0'&&c<='9') rt=rt*10+c-'0',c=getchar();
	return rt*n;
}
ll qsm(ll x,ll y)
{
	ll rt=1;
	x%=mo,y%=(mo-1);
	for (int i=1;i<=y;i<<=1,x=(x*x)%mo)
	if(y&i)rt=(rt*x)%mo;
	return rt;
}
	
int main()
{
	freopen("D:/LiuYuanHao/a1.in","r",stdin);
	n=read(),m=read(),k=read();
	fo(i,1,m) 
	{
		int x=read(),y=read();
		++d[x],++d[y];
	}
	fo(i,1,n)cnt+=(bool)(!(d[i]&1));
	f[0][cnt]=1;
	fo(i,1,k) fo(j,0,n) 
	{
		f[i][j]=(((f[i-1][j]*j)%mo)*(n-j))%mo;
		if(j>=2)  f[i][j]=(f[i][j]+f[i-1][j-2]*calc(n-(j-2)))%mo;
		if(j+2<=n)f[i][j]=(f[i][j]+f[i-1][j+2]*calc(j+2))%mo;
		if(i>=2)  f[i][j]=(0ll+f[i][j]-((((f[i-2][j]*(i-1))%mo)*(calc(n)-(i-2)))%mo))%mo;
		f[i][j]=(f[i][j]%mo+mo)%mo;
	}
	int tmp=1;
	fo(i,1,k)tmp=tmp*i%mo;
	f[k][n]=f[k][n]*qsm(tmp,mo-2)%mo;
	printf("%d\n",f[k][n]);
	return 0;
}
