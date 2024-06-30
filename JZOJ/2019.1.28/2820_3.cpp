#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const ll mo=998244353,G=3,M0=4e4+10;
typedef long long ll;
ll m,p,A,O,S,U,M;
ll B[M0],h[M0];
ll ksm(ll x,ll y) 
{
	if (y==0) return 1; if (y==1) return x%mo;
	ll t=ksm(x,y>>1);
	return t*t%mo*ksm(x,y&1)%mo;
}
ll wg[M0],wgn[M0];
void dft(ll *A,ll sig) {
	for (ll i=0; i<M; i++) if (h[i]<i) swap(A[i],A[h[i]]);
	for (ll m=2; m<=M; m*=2) 
	{
		ll hf=m/2;
		ll zg=wg[m];
		if (sig==-1) zg=wgn[m];
		for (ll i=0,w=1; i<hf; i++,w=(ll)w*zg%mo) {
			for (ll j=i; j<M; j+=m) {
				ll u=A[j],v=(ll)A[j+hf]*w%mo;
				A[j]=(u+v)%mo,A[j+hf]=(u-v+mo)%mo;
			}
		}
	}
}

struct dxs{
	ll a[M0],cs;
	void add(const dxs &b) {
		cs=max(cs,b.cs);
		for (ll i=0; i<cs; i++) a[i]=(a[i]+b.a[i])%p;
	}
	void fft(const dxs &b) {
		for (M=1; M<cs+b.cs; M*=2);
		for (ll i=1; i<M; i++) h[i]=(h[i>>1]>>1) + (i&1) * (M>>1);
		
		dft(a,1);
		memcpy(B,b.a,M*(sizeof a[0]));
		dft(B,1);
		for (ll i=0; i<M; i++) B[i]=(ll)a[i]*B[i]%mo;
		dft(B,-1);
		ll inv=ksm(M,mo-2);
		memset(a,0,sizeof a);
		cs=min(cs+b.cs-1,m+1);
 		for (ll i=0; i<cs; i++) a[i]=(ll)B[i]*inv%mo,a[i]=(a[i]+mo)%mo%p;
	}
} g,g0,p0,F,tmp,emp;

int main() {
	// freopen("D:/LiuYuanHao/","r",stdin);
	cin>>m>>p>>A>>O>>S>>U;

	ll hz=min(m,A);
	F.cs=m+1;
	for (ll i=1; i<=m; i++) F.a[i]=((ll)O*i*i+S*i+U)%p;
	
	for (int i=1; i<=4e4; i*=2) wg[i]=ksm(G,(mo-1)/i),wgn[i]=ksm(wg[i],mo-2);
	
	g0=p0=emp;
	g0.a[0]=1,g0.cs=1;
	p0.a[0]=0,p0.cs=0;
	ll d=1;
	for (; d<hz; d*=2);
	for (;d;d>>=1) {
		tmp=p0;
		p0.fft(g0);
		p0.add(tmp);

		g=g0;
		g0.fft(g);
		if (hz&d) 
		{
			g0.fft(F);
			p0.add(g0);
		}
	}
	printf("%lld",p0.a[m]%p);
}