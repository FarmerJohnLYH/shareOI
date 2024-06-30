#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (ll i=(x);asdfgh=(y);i>=asdfgh;--i)
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
const ll N=220,M=10100;
ll n,m;
struct edge{
	ll x,y,v,t,c;
}e[M*2];
bool cmpt(edge a,edge b){return(a.t<b.t);}
bool cmpc(edge a,edge b){return(a.c<b.c);}
bool cmpv(edge a,edge b){return(a.v<b.v);}
ll f[N];
ll gf(ll x){return(f[x]==x?(x):(f[x]=gf(f[x])));}
PI p[N],ans;
ll b0;
PI buf[N];
PI mst()
{
	PI rt;
	rt.fi=rt.se=0;
	fo(i,0,n) f[i]=i;
	b0=0;
	fo(i,1,m)
	{
		ll fx=gf(e[i].x),fy=gf(e[i].y);
		if(fx!=fy)
		{
			f[fx]=fy;
			rt.fi+=e[i].t,rt.se+=e[i].c;
			buf[++b0].fi=e[i].x,buf[b0].se=e[i].y;
		}
	}
	if(rt.fi*rt.se<ans.fi*ans.se)
	{
		ans=rt;
		fo(i,1,b0) p[i]=buf[i];
	}
	return rt;
}
ll cross(ll ax,ll ay,ll bx,ll by)
{
	return(ax*by-ay*bx);
}
void solve(PI A,PI B)
{
	PI C;
	fo(i,1,m) e[i].v=(A.se-B.se)*e[i].t+e[i].c*(B.fi-A.fi);sort(e+1,e+1+m,cmpv);
	C=mst();
	if(cross(B.fi-A.fi,B.se-A.se,C.fi-A.fi,C.se-A.se/*S三角形*/)>=0) return;
	solve(A,C),solve(C,B);
}
int main()
{
	freopen("timeismoney.in","r",stdin);
	freopen("timeismoney.out","w",stdout);
//	freopen("D:/LiuYuanHao/b1.in","r",stdin);
//	freopen("D:/LiuYuanHao/b.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	fo(i,1,m)
		scanf("%lld%lld%lld%lld",&e[i].x,&e[i].y,&e[i].t,&e[i].c),++e[i].x,++e[i].y;
	ans.fi=oo,ans.se=oo;
	sort(e+1,e+1+m,cmpt);PI A=mst();
	sort(e+1,e+1+m,cmpc);PI B=mst();
	solve(A,B);
	printf("%lld %lld\n",ans.fi,ans.se);
	fo(i,1,n-1) printf("%lld %lld\n",p[i].fi-1,p[i].se-1);
}











