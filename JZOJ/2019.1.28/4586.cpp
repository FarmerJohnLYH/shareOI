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
const int N=50050,Mo=1000000009;
int n,a[N];
int b[N],l[N],ans=1;
int gcd(int x,int y)
{
	return(x==0)?(y):(gcd(y%x,x));
}
int qsm(int x,int y)
{
	int rt=1,now=x;
	y%=Mo;
	fo(i,0,31)
	{
		if(y&(1<<i)) rt=(1ll*rt*now)%Mo;
		now=(1ll*now*now)%Mo;
	}
	return rt;
}
int main()
{
	freopen("ned.in","r",stdin);
	freopen("ned.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n)
	{
		scanf("%d",&a[i]);
		l[i]=i,ans=(1ll*ans*a[i])%Mo;
	}
	fo(i,2,n)
	{
		for (int j=i-1,las=i;j;las=j,j=l[j]-1)
		{
			a[j]=gcd(a[j],a[las]);
			if(a[j]==a[las]) l[las]=l[j];
			ans=(1ll*ans*qsm(a[j],j-l[j]+1)%Mo);
		}
	}	
	printf("%d\n",ans);
	return 0;
}
