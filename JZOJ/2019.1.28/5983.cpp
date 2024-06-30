#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=1001000,mo=1000109107;
ll T,n,m,k;
ll ans;
int a[N];
int v(int x,int y)
{
	return(((n-x-y)*2ll)<n);
}
int check()
{
	int c0=0;
	fo(i,1,m-1)
		if(v(a[i],a[i+1])) ++c0;
	if(v(a[m],a[1])) ++c0; 
	if(c0==k) return((a[1]));
	else return 0;
}
void dfs(int x,int y)
{
	if(y==m)
	{
		if(x==0)return;
		a[y]=x;
		ans+=check();
		return ;
	}
	fo(i,1,x)
		a[y]=i,dfs(x-i,y+1);
}
ll pa[N];
int main()
{
	 freopen("polygon.in","r",stdin);
	 freopen("polygon.out","w",stdout);
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%lld",&T);
	pa[3]=1;
	fo(i,2,1e6/2) pa[2*i+1]=(pa[2*i-1]+1ll*i*i%mo)%mo;
	while(T--)
	{
		scanf("%lld%lld%lld",&n,&m,&k
		ans=0;
		if((k<=2) || n<=10)
			dfs(n,1);
		else
		if(k==3 && m==3)
		{
			ans=pa[n];
		}
		printf("%lld\n",ans%mo);
	}
	return 0;
}








