#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=5005000,P=500500;
ll n,p;
char st[N];ll t;
ll va,a[N],b[N];
ll a0,len;
ll read()
{
	ll rt=0;
	while(st[t]>='0'&&st[t]<='9'&&t<=len) rt=rt*10+st[t]-'0',++t;
	return rt;
}
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,30)
	{
		if(y&(1<<i)) rt=1ll*rt*x%p;
		x=1ll*x*x%p;
	}
	return rt;
}
ll ny[P],all;
int main()
{
	freopen("expression.in","r",stdin);
	freopen("expression.out","w",stdout);
//	freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%lld%lld",&n,&p);t=1;
	scanf("%s",st+1);len=strlen(st+1);
	fo(i,0,p-1) ny[i]=qsm(i,p-2);
	va=(read()%p+p)%p;
	++t;
	ll val=1,bzp=1;
	while(t<=len)
	{
		val=bzp;
		ll sta=a0+1;
		a[++a0]=1ll*read()*bzp%p;val=1ll*val*a[a0]%p;
		while(t<=len&&st[t]!='+'&&st[t]!='-')
		{
			ll flag=0;
			if(st[t]=='/') flag=1;
			++t;a[++a0]=read();
			if(flag) a[a0]=ny[a[a0]];
			val=val*a[a0]%p;
		}
		if(st[t]=='-') bzp=p-1;else bzp=1;
		all=(all+val)%p;
		fo(p,sta,a0) b[p]=val;++t;
	}
	fo(i,1,a0)
	{
		int gt=((va-(all-b[i])%p)+p)%p;
		if(b[i]*ny[a[i]]%p==0)
		{
			if(gt==0) printf("-1\n");
			else printf("No Solution\n");
			continue;
		} 
		printf("%lld\n",gt*ny[b[i]*ny[a[i]]%p]%p);
	}
	return 0;
}








