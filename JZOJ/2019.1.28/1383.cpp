#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=16;
ll f[N][N*9][2],g[N][N*9][2];
int n,s;
ll a[N],b[N],tn[N];
ll solve(ll *a)
{
	n=a[0];
	if(s==0)return 1;
	if(!a[0]) return(0);
	memset(f,0,sizeof f);
	int mx=a[n];
	fo(i,0,a[n]-1)f[n][i][0]=1;
	f[n][a[n]][1]=1;
	fd(i,n,2)
	{
		int tmp=mx;
		fo(j,0,mx)
		{
			fo(l,0,9)
			{
				if(f[i][j][0])
				{
					f[i-1][j+l][0]+=f[i][j][0];
					g[i-1][j+l][0]=min(g[i-1][j+l][0],g[i][j][0]+tn[i-2]*l);
					tmp=max(j+l,tmp);
				}
				if(f[i][j][1])
				{
					if(l<a[i-1]) f[i-1][j+l][0]+=f[i][j][1],g[i-1][j+l][0]=min(g[i][j][1]+tn[i-2]*l,g[i-1][j+l][0]);
					if(l==a[i-1]) f[i-1][j+l][1]+=f[i][j][1],g[i-1][j+l][1]=min(g[i][j][1]+tn[i-2]*l,g[i-1][j+l][1]);
					tmp=max(j+l,tmp);
				}
			}
		}
		mx=min(tmp,s);
	}
	return(f[1][s][1]+f[1][s][0]);
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	ll x,y;tn[0]=1;fo(i,1,N-1) tn[i]=tn[i-1]*10;
	scanf("%lld%lld%d",&x,&y,&s);--x;
	while(x) a[++a[0]]=x%10,x/=10;
	while(y) b[++b[0]]=y%10,y/=10;
	printf("%lld\n",solve(b)-solve(a));
	return 0;
}











