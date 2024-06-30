#pragma GCC optimize(2) 
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define fi first
#define se second 
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PI;
const int N=2020;
const ll A=1e14,eps=100;
ll n,m;
int q;
PI a[N];
int f[N];
ll le,ri,mid;
ll sqr(ll x)
{
	return(x*x);
}
//1 <0,? 2 >x,? 3 ?,<0 4 ?,>y 
int gf(int x)
{
	return (f[x]==x)?x:(f[x]=gf(f[x]));
}
void comb(int x,int y)
{
	x=gf(x),y=gf(y);
	if(x!=y) f[x]=y;
}
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
int check(ll p)
{
	ll val=ceil(pow(p,0.5));
	fo(i,1,q+4) f[i]=i;
	fo(i,1,q) 
	{
		if(a[i].fi-val<0) comb(i,q+1);
		if(a[i].se-val<0) comb(i,q+3);
		if(a[i].fi+val>n) comb(i,q+2);
		if(a[i].se+val>m) comb(i,q+4);
		fo(j,i+1,q)
			if(sqr(a[i].fi-a[j].fi)+sqr(a[i].se-a[j].se)<=4*p) comb(i,j);
	}
	int p1=gf(q+1),p2=gf(q+2),p3=gf(q+3),p4=gf(q+4);
	return(!(p1==p2||p1==p3||p3==p4||p4==p2));
}
int main()
{
	 freopen("AC.in","r",stdin);
	 freopen("AC.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%lld%lld%d",&n,&m,&q);
	fo(i,1,q)
	{
		a[i].fi=read(),a[i].se=read();
		a[i].fi*=eps,a[i].se*=eps;
	}
	n*=eps,m*=eps;
	le=0,ri=A*eps*eps;
	double ans=0;
	while(le<=ri)
	{
		mid=(le+ri)>>1;
		if(check(mid)) le=mid+1,ans=mid;
		else ri=mid-1;
	}
	ans=pow(ans,(double)0.5)/(double)eps;
	printf("%.2lf\n",ans);
	return 0;
}




