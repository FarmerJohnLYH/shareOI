#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=50500*3,mo=4000037,M=mo+100;
ll n,m,bz;
struct node{
	ll x,y,i;
}a[M];
ll hx[M],hy[M],v[M],d[M];
ll ha(ll px,ll py)
{
	ll x=px%mo,y=py%mo;
	ll po=(x*311ll%mo+y*1107ll%mo+19260817ll)%mo;
	while((hx[po]!=px||hy[po]!=py)&&hx[po]!=0) po=(po+1)%mo;
	if(!hx[po])hx[po]=px,hy[po]=py,bz=1,d[po]=px+py;
	return(po);
}
vector<ll> s[M][2];
ll fa[M];
void add(ll x,ll y)
{
	bz=0;
	ll nw=ha(x,y),pre,fg;
	if(!bz) return;
	while(x!=y)
	{
 		pre=ha(x,y);
		if(x>y) x%=y,fg=0;
		else y%=x,fg=1;
		if(x*y==0) x=y=1;
		bz=0;nw=ha(x,y);
		s[nw][fg].push_back(pre);
		fa[pre]=nw;
		if(!bz) return;
	}
}
ll all,ans;
ll gcd(ll x,ll y)
{
	return(y==0)?x:(gcd(y,x%y));
}
bool cmp(ll x,ll y){return(d[x]>d[y]);}
#define abs(x) ((x)>0?(x):(-(x)))
void run(ll x)
{
	ll cnt=0;
	fo(l,0,1)
	{
		if(s[x][l].empty()) continue;
		for(ll p=s[x][l].size()-1,i=0;i<=p;++i)
			run(s[x][l][i]);
		sort(s[x][l].begin(),s[x][l].end(),cmp);	
		ll pre=s[x][l][0],va=pre[v],pd=(l==0)?hy[x]:hx[x];
		for(ll p=s[x][l].size()-1,i=1;i<=p;++i)
			ans+=abs(va)*((d[pre]-s[x][l][i][d])/pd),va+=s[x][l][i][v],pre=s[x][l][i];
		cnt+=va;
		ans+=abs(va)*((d[pre]-d[x])/pd);
	}
	v[x]+=cnt;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
freopen("a.in","r",stdin);
freopen("a.out","w",stdout);
	scanf("%lld",&n);
	all=0;
	fo(i,1,n) 
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		all=gcd(all,gcd(x,y));
		a[i].x=x,a[i].y=y;
	}
	fo(i,1,n) 
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		all=gcd(all,gcd(x,y));
		a[i+n].x=x,a[i+n].y=y;
	}
	fo(i,1,n*2)
	{
		ll t;
		a[i].x/=all,a[i].y/=all;	
		if(i<=n) t=1;
		else t=-1;
		add(a[i].x,a[i].y);
		v[a[i].i=ha(a[i].x,a[i].y)]+=t;
	}
	run(ha(1,1));
	printf("%lld\n",ans);
	return 0;
}








