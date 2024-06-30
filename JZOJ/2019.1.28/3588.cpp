#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (ll pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (ll pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
ll lowbit(ll x) {return((x)&(-x));}
ll min(ll x,ll y){return (x>y)?(y):(x);}
ll max(ll x,ll y){return (x>y)?(x):(y);}
const ll N=100100,mo=1e9;
ll n;
struct node{
	ll a[13];
	char op;
	void clear()
	{
		op=0;
		memset(a,0,sizeof a);
	}
}s[N];
ll sn;
char st[N];
ll sum[13];
void init()
{
	fo(i,1,n)
	{
		ll t,p=1;
		scanf("%lld",&t);
		p=1;
		fo(j,0,10)
		{
			sum[j]=(sum[j]+p)%mo;
			p=(p*t)%mo;
		}

	}
}
node mul(node a,node b)
{
	node rt;
	rt.clear();
	fo(i,0,10) fo(j,0,10)
	{
		rt.a[i+j]=(rt.a[i+j]+(1ll*a.a[i]*b.a[j]%mo))%mo;
	}
	return rt;

}
void solve()
{
	while(sn>1&&s[sn-1].op!='('&&s[sn-1].op!=0)
	{
		if(s[sn-1].op=='+')
		{
			fo(i,0,10) s[sn-1].a[i]=(s[sn-1].a[i]+s[sn].a[i])%mo;
		}
		else
		if(s[sn-1].op=='-')
		{
			fo(i,0,10) s[sn-1].a[i]=(s[sn-1].a[i]-s[sn].a[i]+mo)%mo;
		}
		else
		if(s[sn-1].op=='*')
		{
			s[sn-1]=mul(s[sn-1],s[sn]);
		}
		else
		if(s[sn-1].op=='h')
		{
			ll rt=0;
		fo(i,0,10)
			{
				rt=(rt+(1ll*sum[i]*s[sn].a[i])%mo)%mo;
			}
			s[sn-1].clear();
			s[sn-1].a[0]=rt;
		}
		else
		if(s[sn-1].op=='f')
		{
			s[sn-1]=mul(s[sn],s[sn]);
		}
		s[sn--].clear();
		s[sn].op=0; 
	}
}
int main()
{
	freopen("D:/LiuYuanHao/b3.in","r",stdin);
	scanf("%lld",&n);
	init();
	scanf("%s",st+1);
	sn=0;
	fo(i,1,strlen(st+1))
	{
		if((st[i]=='+'||st[i]=='*')&&(st[i+1]!='/'&&st[i+1]!=':')) s[sn].op=st[i];
		else 
		if(st[i]=='-') 
		{
			if(!sn||s[sn].op!=0) ++sn;
			s[sn].op='-';
		}
		else if(st[i]=='+'&&st[i+1]=='/') s[++sn].op='h',++i;
		else if(st[i]=='*'&&st[i+1]==':') s[++sn].op='f',++i;
		else if(st[i]=='(') s[++sn].op='(';
		else 
		if(st[i]==')')
		{
			solve();	
			--sn;
			s[sn]=s[sn+1];
			s[sn+1].clear();
		}	
		else
		{
				 if(st[i]=='N') s[++sn].a[0]=n;
			else if(st[i]=='X') s[++sn].a[1]=1;
			else 
			{
				ll v=st[i++]-'0';
				for (ll len=strlen(st+1);i<=len&&(st[i]>='0'&&st[i]<='9');++i)
					v=(v*10+st[i]-'0')%mo;
				--i;
				s[++sn].a[0]=v;
			}
		}
	}
	solve();
	printf("%lld\n",s[1].a[0]);
	return 0;
}









