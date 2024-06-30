#pragma GCC optimize (2)
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fi first
#define se second 
#define fo(i,x,y) for (int i=(x),GG=(y);i<=GG;++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PI;
const int N=262144*2+1000,Th=4,mo=998244353;
int n,m;
int A[N],B[N];
int e[N];
int w[N],rsz,wz[N];
struct ffst{
	int cs,a[N];
	void clear()
	{
		fo(i,0,cs-1) a[i]=0;
		cs=0;
	}
	void dft(int flag)
	{
		fo(i,0,cs-1) e[wz[i]]=a[i];int tp;
		if(flag==-1) fo(i,1,cs>>1) swap(w[i],w[cs-i]);
		for(int wv=2,hf=1;wv<=cs;hf=wv,wv<<=1)
		fo(i,0,hf-1) for(int j=i;j<cs;j+=wv)
		tp=1ll*w[cs/wv*i]*e[j+hf]%mo,e[j+hf]=(e[j]-tp+mo)%mo,e[j]=(e[j]+tp)%mo;
		if(flag==-1) fo(i,1,cs>>1) swap(w[i],w[cs-i]);
		fo(i,0,cs-1)
		{
			a[i]=e[i];
			if(flag==-1)a[i]=1ll*a[i]*rsz%mo;
		}
	}
}a,b;
PI c[N],d[N];
ll ans[N];
int max(int x,int y){return(x>y)?(x):(y);}
int gt(int x)
{
	int w=1;
	for(;w<x;w*=2);
	return w;
}
int qsm(int x,int y)
{
	int rt=1;
	fo(i,0,30)
	{
		if(y&(1<<i)) rt=1ll*rt*x%mo;
		x=1ll*x*x%mo;
	}
	return rt;
}
void fnit(int cs)
{
	w[0]=1,w[1]=qsm(3,(mo-1)/cs);
	fo(i,2,cs) w[i]=1ll*w[i-1]*w[1]%mo;
	wz[0]=0;fo(i,1,cs-1) wz[i]=(wz[i>>1]>>1)+((i&1)*(cs>>1)); 
	rsz=qsm(cs,mo-2);
}
void fft(ffst &a,ffst &b)
{
	int cs=gt(a.cs+b.cs);
	a.cs=b.cs=cs;
	fnit(cs);
	a.dft(1),b.dft(1);
	fo(i,0,cs-1) a.a[i]=(1ll*a.a[i]*b.a[i])%mo;
	a.dft(-1);
}
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
void init()
{
	int a0,a1,a2,a3,a4,a5;
	int b0,b1,b2,b3,b4,b5;
	memset(A,0,sizeof A);
	memset(B,0,sizeof B);
	memset(ans,0,sizeof ans);
	a0=read(),a1=read(),a2=read(),a3=read(),a4=read(),a5=read();
	b0=read(),b1=read(),b2=read(),b3=read(),b4=read(),b5=read();
	m=max(a5,b5)+1;
	++A[a0],++A[a1];
	fo(i,2,n-1)
	{
		int tp=(1ll*a2*a1%a5+1ll*a3*a0%a5+a4)%a5;
		a0=a1,a1=tp;
		++A[tp];
		m=max(m,tp);
	}
	++B[b0],++B[b1];
	fo(i,2,n-1)
	{
		int tp=(1ll*b2*b1%b5+1ll*b3*b0%b5+b4)%b5;
		b0=b1,b1=tp;
		++B[tp];
		m=max(m,tp);
	}
}
PI ot;
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		init();
		fo(k,1,Th)
		{
			a.clear(),b.clear();
			a.cs=gt(m);fo(i,0,m) a.a[i]=(A[i]>=k)?1:0; 
			b.cs=gt(m);fo(i,0,m) b.a[i]=(B[i]>=k)?1:0; 
			fft(a,b);		
			fo(i,0,2*m) 
			if(a.a[i]) ans[i]+=a.a[i];
		}
		int c0=0,d0=0;
		fo(i,0,m) if(A[i]>Th) c[++c0].fi=i,c[c0].se=A[i]-Th;
		fo(i,0,m) if(B[i]>Th) d[++d0].fi=i,d[d0].se=B[i]-Th;
		fo(i,1,c0) fo(j,1,d0) ans[c[i].fi+d[j].fi]+=(ll)min(c[i].se,d[j].se);
		ot.fi=-1,ot.se=0;
		fo(i,0,2*m) if(ans[i]>ot.fi||(ans[i]==ot.fi&&i>ot.se)) ot.fi=ans[i],ot.se=i;
		printf("%lld %lld\n",ot.fi,ot.se);
	}
	return 0;
}











