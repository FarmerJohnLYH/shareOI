#include <cmath>
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
ll f[66][10010][2],g[66][10010][2];
ll B,n;
ll A;
ll p;
ll tw[66];
ll mx=0;
ll calc(ll x)
{
	int cl=clock();
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	g[61][0][1]=1;
	fd(i,60,1)
	{
		fo(j,0,A-1)
		{
//			if(j==p)
//				printf("");
			ll tmp=(x&tw[i-1]);
			ll las=(mx-tmp+j)%A;
				   f[i][j][1]+=f[i+1][las][1];//ȡsame
				   g[i][j][1]+=g[i+1][las][1];
			if(tmp)f[i][j][1]+=g[i+1][las][1];
				   f[i][j][0]+=f[i+1][j][0];//ȡ0 
				   g[i][j][0]+=g[i+1][j][0];
			las=(mx+j-tw[i-1])%A;
				   f[i][j][0]+=f[i+1][las][0]+g[i+1][las][0];//ȡ1 
				   g[i][j][0]+=g[i+1][las][0];
			if(tmp)
			{
				f[i][j][0]+=f[i+1][j][1];//ȡ0 
				g[i][j][0]+=g[i+1][j][1];
			}
//			if(j==p)
//				printf("");
		}
		cl=clock()-cl;
		cl=clock();
	}
	ll rt=0;
	rt=f[1][p][1]+f[1][p][0];
	cl=clock()-cl;
	return rt;
}
int main()
{
	freopen("D:/LiuYuanHao/d1.in","r",stdin);
	freopen("D:/LiuYuanHao/d.out","w",stdout);
	int _;
	tw[0]=1;
	fo(i,1,62) tw[i]=tw[i-1]*2;	
	scanf("%lld",&_);
	while(_--)
	{
		scanf("%lld%lld%lld",&A,&B,&n);
		mx=1000000000000000000/A;
		mx*=A;
		while(mx-1000000000000000000<0)
			mx+=A;
		p=B%A;
		printf("%lld\n",calc(B+n*A)-calc(B));
	}
	return 0;
}
