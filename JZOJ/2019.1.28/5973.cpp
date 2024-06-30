#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=110,M=1000100;
int a[M],q,typ;
int v[2];
ll n;
ll val(ll x)
{
	if(x<=1e6) return a[x];
	else 
	{
		if(x&1) return(val((x+1)/2ll)*v[(((x+1)/2ll)+1)&1]);
		else return(-val(x/2ll));
	}
}
ll solve(ll n)
{
	if(n==0) return 0; 
	return((n&1)*val(n)+2ll*solve(n/4ll));
}
int main()
{

//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	 freopen("D:/LiuYuanHao/a.ans","w",stdout);
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	v[1]=-1,v[0]=1;a[1]=1;
	fo(i,1,1e6/2) a[2*i]=-a[i],a[i*2-1]=a[i]*v[(i+1)&1];
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%lld",&typ,&n);
		if(typ==1) printf("%lld\n",val(n));		
		else printf("%lld\n",solve(n));
	}
	return 0;
}








