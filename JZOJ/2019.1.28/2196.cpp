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
const int N=110,Mo=2007;
int n,T;
int qsm(int a,int b)
{
	int x=1;
	a%=Mo,b%=(Mo-1);
	while(b)
	{
		x=((b&1))?((1ll*x*(a))%Mo):(x);
		b>>=1,a=(1ll*a*a)%Mo;
	}
	return x;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int ans=(4ll*n*qsm(5,n-1))%Mo;
		printf("%d\n",ans);
	}
	return 0;
}
