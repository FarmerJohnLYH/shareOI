#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (int pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
int lowbit(int x) {return((x)&(-x));}
int min(int x,int y){return (x>y)?(y):(x);}
int max(int x,int y){return (x>y)?(x):(y);}
const int N=44,D=100100,Mo=1e9+7;
int n,d;
int a[N];
int f[N][N][N*N*2][3];
bool cmp(int x,int y)
{
	return(x>y);
}
void add(int &a,ll b)
{
	a=(0ll+a+(b%Mo))%Mo;
}
int jc[D],ny[D];
int C(int x,int y)
{
	return(((1ll*jc[x]*ny[y])%Mo*ny[x-y])%Mo);
}
ll qsm(ll a,ll b)
{
	ll x=1;
	a%=Mo;
	while(b)
	{
		x=((b&1))?((x*(a))%Mo):(x);
		b>>=1,a=(a*a)%Mo;
	}
	return x;
}
int main()
{
	freopen("D:/LiuYuanHao/a2.in","r",stdin);
	jc[0]=1;
	fo(i,1,D-10) jc[i]=(1ll*jc[i-1]*i)%Mo;
	ny[D-10]=qsm(jc[D-10],Mo-2);
	fd(i,D-11,0) ny[i]=(1ll*ny[i+1]*(i+1))%Mo;
	scanf("%d%d",&n,&d);
	fo(i,1,n)
		scanf("%d",&a[i]),--a[i];
	sort(a+1,a+1+n,cmp);
	memset(f,0,sizeof f);
	f[1][0][a[1]][1]=2;
	f[1][0][a[1]*2][0]=1;
	int sm=0;
	fo(i,1,n) sm+=2*a[i];
	fo(i,1,n-1) fo(j,0,n+2) fo(k,0,sm) fo(l,0,2)
	if(f[i][j][k][l])
	{
		add(f[i+1][j+1][k+2*a[i+1]][l],1ll*f[i][j][k][l]*(j+2-l));
		add(f[i+1][j][k+a[i+1]][l],1ll*f[i][j][k][l]*(j*2+2-l));
		if(j)add(f[i+1][j-1][k][l],1ll*f[i][j][k][l]*(j));
		if(l<2)
		{
			add(f[i+1][j+1][k+a[i+1]][l+1],1ll*f[i][j][k][l]*(2-l));
			add(f[i+1][j][k][l+1],1ll*f[i][j][k][l]*(2-l));
		}
	}
	int ans=0;
	fo(i,0,min(d,sm))
		add(ans,(1ll*f[n][0][i][2]*C(d-i,n)));
	printf("%d",ans);
	return 0;
}




