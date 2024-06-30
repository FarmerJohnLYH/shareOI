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
const int N=10001000,V=100000000;
int n;
ll A,B,C;
ll a[N];
void init()
{
	scanf("%d%lld%lld%lld%lld",&n,&A,&B,&C,a+1);
	fo(i,2,n)
	{
		a[i]=1ll*(1ll*a[i-1]*A+1ll*B)%100000001;
	}
	fo(i,1,n) a[i]=a[i]%C+1;
}
int main()
{
//	freopen("D:/LiuYuanHao/d1.in","r",stdin);
//	freopen("a.out","w",stdout);
	init();
	
	a[0]=a[n];
	db ans=0;
	fo(i,1,n)
	{
		ans=(ans+((db)1.0*min(a[i],a[i-1])/((db)1.0*a[i]*a[i-1])));
	}
	printf("%.3lf\n",ans);
	return 0;
}
