#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (ll i=(x),asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<ll,ll> PI;
ll abs(ll x) {return(((x)>=0)?(x):(-(x)));}
ll max(ll x,ll y) {return(((x)>(y))?(x):(y));}
ll min(ll x,ll y) {return(((x)<(y))?(x):(y));}
ll lowbit(ll x) {return((x)&(-x));}
const ll N=100100,M=26;
ll n,m;
ll f[2][4];//[i][i-1] [i][i] [i][i+1] 
ll g[N][8],st[N];
ll mi(ll o)
{
	ll rt=0;
	fo(i,1,3) 
	{
		if(f[o][i]) rt|=(1<<(i-1))*f[o][i];
	}
	return rt;
}
void je(ll o,ll cd)
{
	ll rt=cd;
	fo(i,1,3) f[o][i]=(bool)(rt&(1<<(i-1)));
}
bool check(ll o)
{
	fo(i,1,3) 
		if(f[o][i]<0) return (0);
	return 1;
}
int main()
{
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);
	//freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%lld%lld\n",&n,&m);
	fo(i,1,n) 
	{
		char ch=getchar();while(!(ch>='a'&&ch<='z')) ch=getchar();
		st[i]=ch-'a'+1;
	}
	//1 1/0 1/0
	f[0][1]=1;
	fo(ch,1,m)
	{
			 if(ch==st[1]) f[0][2]=1,f[0][3]=1;
		else if(ch==st[2]) f[0][2]=0,f[0][3]=1;
		else f[0][2]=f[0][3]=0;
		g[1][mi(0)]++;
	}
	fo(i,1,n-1)
	{
		fo(ch,1,m)/*T[1]*/
		fo(s,0,7)/*i*/
		if(g[i][s])
		{
			memset(f[1],255,sizeof f[1]);
			je(0,s);
			if(ch==st[i])f[1][1]=f[0][1]/*+1*/;
			f[1][1]=max(f[1][1],f[0][2]);
			if(ch==st[i+1])f[1][2]=f[0][2];
			f[1][2]=max(f[1][2],max(f[1][1]-1,f[0][3]-1));
			if(ch==st[i+2]) f[1][3]=f[0][3];
			f[1][3]=max(f[1][3],f[1][2]);
			ll tmp=0;
			if(check(1))
				g[i+1][tmp=mi(1)]+=g[i][s];
		}
	}
	ll ans=0;
	fo(s,0,7)
	{
		je(0,s);
		if(f[0][2]!=0) continue;
		ans+=g[n][s]; 
	}
	printf("%lld",ans);
	return 0;
}











