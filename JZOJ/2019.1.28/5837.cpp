#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
namespace io{
	const int N=(1<<21)+1;
	char in[N],out[N],*is=in,*it=in+N-1,*os=out,*ot=out+N-1,o[20],c;
	int j;
	#define gc()(is==it?(it=(is=in)+fread(in,1,N,stdin),(is==it?EOF:*is++)):*is++)
	void flush(){fwrite(out,1,os-out,stdout);os=out;}
	void put(char x){*os++=x;if(os==ot)flush();}
	template<class I>
	void R(I &n){
		for(n=0;(c=gc())>'9'||c<'0';);
		for(;c<='9'&&c>='0';c=gc())n=n*10+(c&15);
	}
	void P(int n){
		if(!n)put('0');
		for(;n;n/=10)o[++j]=n%10+48;
		while(j)put(o[j--]);
	}
}
using io::R;
using io::P;
using io::put;
using namespace std;
typedef long long ll;
const ll N=500500,mo=998244353;
struct node{
	ll fi,se,af,as;
};
ll n,q,T,p[N],A,B,tp;
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,30)
	{
		if((1<<i)&y) rt=1ll*rt*x%mo;
		x=1ll*x*x%mo;
	}
	return rt;
}
ll c[N],tag;
ll cp,ql,qr;
node t[N*4];
node comb(node &a,node &b)//a into b
{
	node c;
	c.fi=(a.fi*b.fi)%mo,c.se=(b.fi*a.se+b.se)%mo;
	c.af=(b.af*a.fi+a.af)%mo,c.as=(b.as+a.se*b.af+a.as)%mo;
//	c.af=(c.af)%mo,c.as=(c.as)%mo;
	return c;
}
void cg(ll x,ll l,ll r)
{
	if(l==r)
	{
		t[x].fi=(mo+(p[l]-p[l]*T+T)%mo)%mo,t[x].se=p[l];
		t[x].af=p[l]*B%mo,t[x].as=((A+B)*p[l])%mo;
		return;
	}
	ll mid=(l+r)>>1;
	if(cp<=mid) cg(x<<1,l,mid);
	else cg(x<<1|1,mid+1,r);
	t[x]=comb(t[x<<1],t[x<<1|1]);
}
node query(ll x,ll l,ll r)
{
	if(ql<=l&&r<=qr) return(t[x]);
	node rt;rt.fi=rt.af=0,rt.se=rt.as=0;
	ll mid=(l+r)>>1;node tp;
	if(ql<=mid) 
	{
		tp=query(x<<1,l,mid);
		rt=tp;
	}
	if(qr>mid)
	{
		tp=query(x<<1|1,mid+1,r);
		if(rt.fi+rt.af+rt.se+rt.as!=0) rt=comb(rt,tp);	
		else rt=tp;
	}
	return rt;
}
ll read()
{
	ll p;
	R(p);
	return p;
    char ch=' ';ll q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10ll+ch-48;ll n=q*w;return n;
}
ll buf[30],b0;
void write(ll x)
{
	b0=0;
	if(x==0)putchar('0');
	else
	while(x) buf[++b0]=x%10,x/=10;
	fd(i,b0,1) putchar(buf[i]+'0');
}
void build(ll x,ll l,ll r)
{
	if(l==r)
	{
		t[x].fi=(mo+(p[l]-p[l]*T+T)%mo)%mo,t[x].se=p[l];
		t[x].af=p[l]*B%mo,t[x].as=((A+B)*p[l])%mo;
		return;
	}
	ll mid=(l+r)>>1;
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	t[x]=comb(t[x<<1],t[x<<1|1]);
}
int main()
{
	 freopen("omeed.in","r",stdin);
	 freopen("omeed.out","w",stdout);
//	freopen("D:/LiuYuanHao/c2.in","r",stdin);
//	freopen("D:/LiuYuanHao/c.out","w",stdout);
	tag=read();
	n=read(),q=read(),T=read(),tp=read(),A=read(),B=read();
	T=T*qsm(tp,mo-2)%mo;
	tp=A*qsm(2,mo-2)%mo*qsm(4,mo-2)%mo*B%mo;
	fo(i,1,n)
	{
		p[i]=read(),tp=read();
		p[i]=p[i]*qsm(tp,mo-2)%mo;
	}
	build(1,1,n);
	while(q--)
	{
		ll x,w,l,r;
		tp=read();
		if(tp)
		{
			l=read(),r=read();
			ql=l,qr=r;
			node rt=query(1,1,n);
			write(rt.as);putchar('\n');
		}
		else
		{
			x=read(),w=read(),tp=read();
			w=w*qsm(tp,mo-2)%mo;
			p[x]=w;cp=x;
			cg(1,1,n);
		}
	}
	return 0;
}











