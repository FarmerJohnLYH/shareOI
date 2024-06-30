#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
using namespace std;
const int N=3*200200,mo=998244353,M=4004000;
typedef long long ll;
ll n;
ll p[N],a[N],b[N],k[N];
ll jc[N];
ll qsm(ll x,ll y=mo-2)
{
	ll rt=1;
	while(y)
	{
		if(y&1) rt=rt*x%mo;
		y/=2,x=x*x%mo;
	}
	return rt;
}
int st[N];ll d[N],d0,an[N],a0;
ll A[N],B[N],cs;
ll w[N],wz[N];
ll c[N];
void init(ll cs)
{
	w[0]=1,w[1]=qsm(3,(mo-1)/cs);
	fo(i,2,cs-1) w[i]=w[i-1]*w[1]%mo;
	wz[0]=0;fo(i,1,cs-1) wz[i]=(wz[i>>1]>>1)+(cs>>1)*(i&1);
}
void dft(ll *a,int fg)
{
	fo(i,0,cs-1) c[i]=a[wz[i]];ll tp;
	if(fg==-1) fo(i,1,cs>>1) swap(w[i],w[cs-i]);
	for(ll wv=2,hf=1;wv<=cs;hf=wv,wv<<=1)
	fo(i,0,hf-1) for(int j=i;j+hf<cs;j+=wv) 
		tp=w[cs/wv*i]*c[j+hf]%mo,c[j+hf]=(c[j]-tp+mo)%mo,c[j]=(c[j]+tp)%mo;
	if(fg==-1) 
	{
		fo(i,1,cs>>1) swap(w[i],w[cs-i]);
		ll ny=qsm(cs);
		fo(i,0,cs-1) a[i]=c[i]*ny%mo;
	}else fo(i,0,cs-1) a[i]=c[i];
}
void run(int l1,int r1,int l2,int r2)
{
	ll k=r2-l2+1+r1-l1+1;cs=1;
	while(cs<k) cs<<=1;
	fo(i,l1,r1) A[i-l1]=d[i];fo(i,r1-l1+1,cs-1) A[i]=0;
	fo(i,l2,r2) B[i-l2]=d[i];fo(i,r2-l2+1,cs-1) B[i]=0;
	init(cs);
	dft(A,1),dft(B,1);
	fo(i,0,cs-1) A[i]=A[i]*B[i]%mo;
	dft(A,-1);
	fo(i,l1,r1) d[i]=A[i-l1];
}
ll ca[N];
void ra(int l1,int r1,int l2,int r2)
{
	ll k=r2-l2+1+r1-l1+1;cs=1;
	while(cs<k) cs<<=1;
	fo(i,l1,r1) A[i-l1]=ca[i];fo(i,r1-l1+1,cs-1) A[i]=0;
	fo(i,l2,r2) B[i-l2]=d[i];fo(i,r2-l2+1,cs-1) B[i]=0;
	init(cs);
	dft(A,1),dft(B,1);
	fo(i,0,cs-1) A[i]=A[i]*B[i]%mo;
	dft(A,-1);
	fo(i,l1,l1+cs-1) ca[i]=A[i-l1];
	if(A[r1-l1+1]>0)
		printf("");
}
ll cb[N];
void solve(int l,int r,int q)
{
	if(l==r) 
		return;
	int mid=(l+r)>>1;
	solve(l,mid,q<<1),solve(mid+1,r,q<<1|1);
	run(st[l],st[mid+1]-1,st[mid+1],st[r+1]-1);
	fo(i,st[l],st[mid+1]-1) ca[i]=an[i];
	ra(st[l],st[mid+1]-1,st[mid+1],st[r+1]-1);
	fo(i,st[l],st[l]+cs)
		cb[i]=ca[i];
	fo(i,st[mid+1],st[r+1]-1) ca[i]=an[i];
	ra(st[mid+1],st[r+1]-1,st[l],st[mid+1]-1);
	fo(i,st[l],st[r+1]-1) an[i]=ca[i-]+; 
}
int main()
{
//	freopen("operation.in","r",stdin);
//	freopen("operation.out","w",stdout);
	freopen("D:/LiuYuanHao/a1.in","r",stdin);
	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%lld",&n);
	fo(i,1,n) 
	{
		scanf("%lld%lld%lld",&p[i],&a[i],&b[i]);
		k[i]=((mo-(p[i]*b[i]%mo)+p[i])%mo+b[i])%mo;	
		b[i]=a[i]*p[i]%mo;
		d[st[i]=++d0]=1,d[++d0]=k[i];
		an[st[i]]=b[i];
	}
	st[n+1]=d0+1,st[0]=0;
	solve(1,n,1);
	jc[0]=1;fo(i,1,n) jc[i]=jc[i-1]*i%mo;
	ll ans=0;
	fo(i,0,n-1)
	{
		ans=(ans+an[i+1]*jc[i]%mo*jc[n-i-1]%mo)%mo;
		printf("%lld\n",an[i+1]);
	}
	ans=ans*qsm(jc[n])%mo;
//	printf("%lld\n",ans);
	return 0;
}







