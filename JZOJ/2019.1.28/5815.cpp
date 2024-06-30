#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll N=800800*2;
const ll p1=29,p2=998244353;//19260817;
ll n,m,Q;
char s[N],t[N];
char st[N];
ll tr[N],f[N];
ll p[N],all;
ll lowbit(ll x){return(x&(-x));}
void add(ll x,ll v)
{
	++x;
	if(x<=0)return;
	for(;x<=all;x+=lowbit(x)) tr[x]+=v;
}
ll query(ll x)
{
	++x;
	ll rt=0;
	for(;x;x-=lowbit(x)) rt+=tr[x];
	return(rt);
}
ll h[2][N],ct[2][N];
ll find(ll wz,ll l,ll r)
{
	ll rt=(h[wz][r]+p2-(1ll*h[wz][l-1]*p[r-l+1]%p2))%p2;
	return rt;
}
void hsh(char *s,ll wz)
{
	n=strlen(s+1);
	fo(i,1,n) h[wz][i]=((h[wz][i-1]*p1)+s[i]-'a'+1)%p2;
}
void mc(char *s,ll wz)
{
	n=strlen(s+1);
	fd(i,n,1) st[2*i]=s[i],st[2*i+1]='#';
	st[1]='#';
	n=n*2+1; 
	ll p=0;
	memset(f,0,sizeof f);
	memset(tr,0,sizeof tr);
	fo(i,1,n)
	{
		if(p+f[p]>i) f[i]=min(p+f[p]-i,f[p-(i-p)]);
		while(st[i-f[i]-1]==st[i+f[i]+1]&&i-f[i]-1>0&&i+f[i]+1<=n)
			++f[i];
		if(f[i]+i>=p+f[p]) p=i;
	}
	all=n;
	fo(i,3,n) 
	if(f[i]>1)
	{
		if(i-f[i]-1<=0)add(0,1);else add(i-f[i]-1,1);
		if(i-2>=0) add(i-2,-1);
	}
	ct[wz][0]=query(0)+1;
	fo(i,1,n/2-1) 
		ct[wz][i]=query(2*i)+ct[wz][i-1]+1;
	ct[wz][(n-1)/2]=query(n-1)+ct[wz][(n-1)/2-1];
}
int main()
{
//	freopen("D:/LiuYuanHao/a2.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	 freopen("palindrome.in","r",stdin);
	 freopen("palindrome.out","w",stdout);
	p[0]=1,p[1]=p1;fo(i,1,N/2) p[i]=(1ll*p[i-1]*p1)%p2;
	scanf("%s\n",s);memset(s,0,sizeof s);
	scanf("%s\n%s\n",s+1,t+1);
	m=strlen(t+1);
	fo(i,1,m>>1) swap(t[i],t[m-i+1]);
	mc(s,0),mc(t,1);
	hsh(s,0),hsh(t,1);
	scanf("%lld",&Q);
	n=strlen(s+1),m=strlen(t+1);
	while(Q--)
	{
		ll x,y;scanf("%lld%lld",&x,&y);
		ll le=1,ri=max(n-x,m-y)+1,rt=0;
		while(le<=ri)
		{
			ll mid=(le+ri)>>1;
			if(find(0,x,x+mid-1)==find(1,y,y+mid-1))
				le=mid+1,rt=mid;
			else ri=mid-1;
		}
		ll ans=ct[0][(x+rt-1)]-ct[0][x-1]+ct[1][y+rt-1]-ct[1][y-1]+rt;
		printf("%lld\n",ans);
	}
	return 0;
}











