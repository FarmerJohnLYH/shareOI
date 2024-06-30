//GG again
#include <cstdio>
#include <cstring>
#include <iostream>
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int mo=998244353,N=32768+100;
int m,p,n,O,S,U;
int sz;
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
struct nt{
	int a[N],cs;
	int c[N],wz[N],W[N];
	void init()
	{
		int rt=1;
		while(rt<cs)rt<<=1;
		cs=rt;
		wz[0]=0;fo(i,1,cs-1) wz[i]=(wz[i>>1]>>1)+((i&1)*(cs>>1)); 
	}
	void dft(int sig)
	{
		fo(i,0,cs-1) c[wz[i]]=a[i];
		W[0]=1,W[1]=qsm(3,(mo-1)/cs);int u=0;
		fo(i,2,cs-1) W[i]=W[i-1]*W[1]%mo;
		for (int wv=2,hf=1;wv<=cs;hf=wv,wv<<=1)
		fo(i,0,hf-1) for(int l=i;l<cs;l+=hf) 
		u=1ll*W[(sig==1)?(cs/wv*i):(cs-cs/wv*i)]*c[l+hf]%mo,c[l+hf]=(c[l]-u+mo)%mo,c[l]=(c[l]+u)%mo;
		int inv=qsm(cs,mo-2);
		fo(i,0,cs-1)
		{
			a[i]=c[i];	
			if(sig==-1)a[i]=1ll*a[i]*inv%mo;
		}
	}
}a,f,g,e;
void solve(int n)
{
	if(n==0) 
	{
		g.a[0]=1;
		g.cs=1;
		g.init();
		return;
	}
	if(n&1)
	{
		solve(n-1);
		g.cs=g.cs+e.cs;
		g.init();
		g.dft(1);
		fo(i,0,g.cs-1) g.a[i]=(1ll*g.a[i]*e.a[i])%mo;
		if(g.cs>f.cs)f.cs=g.cs,f.init();
		g.dft(-1);
		fo(i,0,f.cs-1) f.a[i]=(f.a[i]+g.a[i])%mo%p;
		return;
	}
	solve(n/2);
	memcpy(&a,&f,sizeof f);
	a.cs=g.cs=a.cs+g.cs;
	a.init(),g.init();
	g.dft(1),a.dft(1);
	fo(i,0,max(a.cs,g.cs))a.a[i]=(1ll*a.a[i]*g.a[i])%mo;
	a.dft(-1);
	f.cs=a.cs;
	f.init();
	fo(i,0,f.cs) f.a[i]=(f.a[i]+a.a[i])%mo%p;
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d%d%d%d%d",&m,&p,&n,&O,&S,&U);
	fo(i,1,m) e.a[i]=(i*i*O+S*i+U)%mo;
	e.cs=m+1;
	e.init();
	e.dft(1);
	solve(n);
	printf("%d\n",f.a[n]);
}

