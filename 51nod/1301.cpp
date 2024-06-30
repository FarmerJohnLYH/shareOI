#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=2222,mo=1e9+7,all=2047;
typedef long long ll;
int n,m;
int f[N][N][2],tw[20];
ll ans;
int se(int y,int x)
{
	return((x&tw[y])?1:0);
}
ll solve(int x)
{
	ll rt=0;
	memset(f,0,sizeof f);
	f[0][0][0]=1;//BµÄµÚxÎ»
	fo(i,1,max(n,m))
	{
		fo(s,0,all) fo(k,0,1)
		{
			f[i][s][k]=f[i-1][s][k];
			if(i<=n) f[i][s][k]=(f[i][s][k]+f[i-1][s^i][k])%mo;
			if(i<=m) f[i][s][k]=(f[i][s][k]+f[i-1][s^i][k^se(x,i)])%mo;
		}
	}
	fo(s,tw[x],tw[x+1]-1)
		rt=(rt+f[max(n,m)][s][1])%mo;
	return rt;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	tw[0]=1;fo(i,1,15) tw[i]=tw[i-1]*2;
	fo(i,0,10)
		ans=(ans+solve(i))%mo;
	printf("%lld\n",ans);
	return 0;
}








