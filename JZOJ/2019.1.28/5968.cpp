#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=100100,mo=1e9+7;
int a[N];
int n;
ll g[N];
int s[N],s0;
ll ans=1;
ll ny[N],jc[N];
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,30)
	{
		if((1<<i)&y) rt=rt*x%mo;
		x=x*x%mo;
	}
	return rt;
}
ll C(ll m,ll n)
{
	if(m<n)return 0;
	return(jc[m]*ny[n]%mo*ny[m-n]%mo);
}
int main()
{
//	freopen("D:/LiuYuanHao/b.in","r",stdin);
//	freopen("D:/LiuYuanHao/b.ans","w",stdout);
	scanf("%d",&n);
	jc[0]=1;
	fo(i,1,n) g[i]=(g[i-1]+i)%mo,jc[i]=jc[i-1]*i%mo;
	ny[n]=qsm(jc[n],mo-2);
	fd(i,n-1,0) ny[i]=ny[i+1]*(i+1)%mo; 
	fo(i,2,n) g[i]=(g[i-1]*g[i])%mo;
	g[0]=1;
	fd(i,n+1,1) g[i]=g[i-1];
	fo(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	fo(i,1,n) 
	{
		int j=i;
		while(a[i]==a[j+1]&&j+1<=n)
			++j;
		s[++s0]=j-i+1;
		i=j;
	}
	int p=0;g[0]=1;
	ans=g[s[1]];p=s[1];
	fo(i,2,s0)
	{
		ll tmp=1,tp=0;
		
		fo(k,0,s[i]-1)
		{
			tp=(tp+(C(p+k-1,k)*tmp%mo*(s[i]-k)%mo*g[s[i]-k])%mo)%mo;
			tmp=tmp*C(s[i]-k,2)%mo;
		}
		p+=s[i];
		ans=ans*tp%mo;
	}
	printf("%lld\n",ans);
	return 0;
}








