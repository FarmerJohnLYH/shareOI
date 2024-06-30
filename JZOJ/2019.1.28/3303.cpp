#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=262144+100,mo=1004535809;
int n;
int jc[N],ny[N],w[N],wz[N];
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
int c[N];
struct ffst{
	int a[N],cs;
	void clear()
	{
		fo(i,0,cs-1) a[i]=0;
		cs=0;
	}
	void dft(int flag)
	{
		wz[0]=0;fo(i,1,cs-1)wz[i]=(wz[i>>1]>>1)+((cs>>1)*(i&1)); 
		w[0]=1,w[1]=qsm(3,(mo-1)/cs);
		fo(i,2,cs) w[i]=1ll*w[i-1]*w[1]%mo;int tp;
		if(flag==-1) fo(i,1,cs>>1) swap(w[i],w[cs-i]); 
		fo(i,0,cs-1) c[wz[i]]=a[i];
		for (int wv=2,hf=1;wv<=cs;hf=wv,wv<<=1)
		fo(i,0,hf-1) for(int j=i;j<cs;j+=wv)
		tp=1ll*w[cs/wv*i]*c[j+hf]%mo,c[j+hf]=(c[j]-tp+mo)%mo,c[j]=(c[j]+tp)%mo;
		int nv=qsm(cs,mo-2);
		fo(i,0,cs-1) 
		{
			a[i]=c[i];
			if(flag==-1)a[i]=1ll*a[i]*nv%mo;
		}
	}
}a,b;
int f[N],g[N];
void fft(ffst &a,ffst &b)//a*=b
{
	int ct=max(a.cs,b.cs)*2;
	a.cs=b.cs=ct;
	a.dft(1),b.dft(1);
	fo(i,0,ct-1) a.a[i]=1ll*a.a[i]*b.a[i]%mo; 
	a.dft(-1);
}
void solve(int l,int r)
{
	if(l==r)
	{
		f[l]=(0ll+g[l]+mo-(1ll*jc[l-1]*f[l]%mo))%mo;
		return;
	}
	int mid=(l+r)>>1;
	solve(l,mid);
	a.clear(),b.clear();
	a.cs=(mid-l+1)*2;
	a.a[0]=0;fo(i,l,mid) a.a[i-l+1]=1ll*f[i]*ny[i-1]%mo;
	b.cs=r-l+1;
	b.a[0]=0;fo(i,1,r-l) b.a[i]=1ll*g[i]*ny[i]%mo;
	fft(a,b);
	fo(i,mid+1,r) f[i]=(f[i]+a.a[i-l+1])%mo;
	solve(mid+1,r);
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&n);
	g[0]=1;fo(i,1,N-100) g[i]=qsm(2,(1ll*(i-1)*i/2)%(mo-1));
	jc[0]=1;fo(i,1,N-100) jc[i]=1ll*jc[i-1]*i%mo;
	ny[N-100]=qsm(jc[N-100],mo-2);fd(i,N-100-1,0) ny[i]=1ll*ny[i+1]*(i+1)%mo;
	int css=1;while(css<n)css<<=1;
	solve(1,css);
	printf("%d\n",f[n]);
	return 0;
}











