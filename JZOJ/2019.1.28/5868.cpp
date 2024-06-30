#pragma GCC optimize(2) 
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define fi first
#define se second
#define mep make_pair
#define oo (1ll<<62)
#define ull __int128
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=1000010000,K=40004000,MX=3333333;
ll p[MX],T,n,k;
ll p0;
vector<ll> pi[55];ll cpi;
map<ll,ll> mp; 
void apart(ll x,ll y)
{
	fo(i,1,p0)
	{
		if(p[i]*p[i]>x)break; 
		if(x%p[i]==0)
		{
			while(x%p[i]==0) x/=p[i];
			pi[y].push_back(p[i]);
		}
	}
	if(x>1) pi[y].push_back(x);
}
bool bp[K];
void init()
{
	bp[0]=bp[1]=1;
	fo(i,2,K)
	{
		if(!bp[i]) p[++p0]=i;
		fo(j,1,p0)
		{
			if(p[j]*i>K) break;	
			bp[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
}
ull exgcd(ull a,ull b,ull &x,ull &y)
{
	if(b==0)
	{
		x=1,y=0;
		return(a);
	}
	ull rt=exgcd(b,a%b,x,y);
	ull t=x;x=y,y=t-(a/b)*y;
	return (rt);
}
ll wz,NUM;
ll f[MX];
priority_queue< pair<ll,ll> > qu;
void Dij()
{
	while(!qu.empty())qu.pop();
	qu.push(mep(-0,0));
	ll m=pi[wz].size()-1;
	while(!qu.empty())
	{
		ll x=qu.top().se,y=-qu.top().fi;
		qu.pop();
		if(f[x]<y) continue;
		fo(i,1,m)
		{
			ll tp=y+pi[wz][i];
			if(tp>n) break; 
			if(tp<f[tp%pi[wz][0]])
			{
				f[tp%pi[wz][0]]=tp;
				qu.push(mep(-tp,tp%pi[wz][0]));
			}
		}
	}
}
void work(ll A,ll B)
{
	ull x=0,y=0,a=A,b=B;
	ull gd=exgcd(pi[wz][0],pi[wz][1],x,y);
	a/=gd,b/=gd,x=x*n,y=y*n;
	if(n%gd!=0)
	{
		printf("NO\n");
		return;
	}
	ull qaq=x/b;
	if(x<0&&x%b!=0) --qaq;
	x=x-(qaq)*b,y=y+qaq*a;	
	if(y>=0) printf("YES\n");
	else printf("NO\n");
}
int main()
{
//	freopen("fantasy.in","r",stdin);
//	freopen("fantasy.out","w",stdout);
	freopen("D:/LiuYuanHao/a1.in","r",stdin);
	freopen("D:/LiuYuanHao/c.out","w",stdout);
	init();
	scanf("%lld",&NUM);scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&k);
		if(k==1) 
		{
			printf("NO\n");
			continue;
		}
		wz=mp[k];
		if(pi[wz].size()==0)
		{
			wz=mp[k]=++cpi;
			apart(k,wz);
		}
		if(n%pi[wz][0]==0)
		{
			printf("YES\n");
			continue;
		}
		if(NUM==7||NUM==8||pi[wz].size()==1)
		{
			if(n%pi[wz][0]==0) printf("YES\n");
			else printf("NO\n");
			continue;
		}/*
		if(NUM==9||pi[wz].size()==2)
		{
			work(pi[wz][0],pi[wz][1]);
			continue;
		}*/
		f[0]=0;
		fo(i,1,pi[wz][0]-1) f[i]=oo;
		Dij();
		if(f[n%pi[wz][0]]<=n) 
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}











