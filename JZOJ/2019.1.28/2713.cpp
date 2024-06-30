#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=20;
ll L,R;int p[2][N];int k;
ll f[N][N][N][10][2];//高i位 比x小的数字个数 x出现次数 对x取模 前导0(不顶上界) 
ll ans;
int n[2];ll tw[N];
ll solve(int tp,int m,int c0,int c1,int v,int flag,int zr,int x)
{
	if(c0>=k)return 0;
	if(m==0) return !zr && (v==0) && (c0<k&&c0+c1>=k);
	if(!flag&&f[m][c0][c1][v][zr]>=0) return(f[m][c0][c1][v][zr]);
	ll rt=0;
	fo(i,0,(flag)?p[tp][m]:9)
	{
		rt+=solve(tp,m-1,c0+(i<x&&(!(i==0&&zr))),c1+(i==x),(0ll+v+i*tw[m])%x,flag&&(i==p[tp][m]),zr&&(i==0),x);
	}
	if(!flag) f[m][c0][c1][v][zr]=rt;
	return rt;
}
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	// freopen("a.in","r",stdin);
	// freopen("a.out","w",stdout);
	scanf("%lld%lld%d\n",&L,&R,&k);
	--L;tw[1]=1;
	fo(i,2,18) tw[i]=tw[i-1]*10ll%362880; 
	while(L) p[1][++n[1]]=L%10,L/=10;
	while(R) p[0][++n[0]]=R%10,R/=10;
	fo(x,1,9) 
	{
		memset(f,128,sizeof f);
		ans+=solve(0,n[0],0,0,0,1,1,x);
		memset(f,128,sizeof f);
		ans-=solve(1,n[1],0,0,0,1,1,x);
	}
	printf("%lld\n",ans);
	return 0;
}








