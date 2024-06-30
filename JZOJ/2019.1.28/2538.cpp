#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define oo 2139062143
using namespace std;
const int NUM=2000020000,SQT=50500;
int T,a0,a1,b0,b1;
int pri[SQT],bz[SQT];
void gtpri()
{
	bz[1]=1;
	fo(i,2,50000)
	{
		if(!bz[i]) pri[++pri[0]]=i;
		fo(j,1,pri[0])
		{
			if(i*pri[j]>=50000)break;
			bz[i*pri[j]]=1;
			if(!(i%pri[j]))break;
		}
	}
}
int calc(int x,int y)
{
	int rt=0;
	while(!(y%x)) y/=x,++rt;
	return (rt);
}
int work(int P)
{
	int c0=calc(P,a0),c1=calc(P,a1),d0=calc(P,b0),d1=calc(P,b1);
	int tl=0,tr=oo;
	if(c0<c1||d0>d1) return 0;
	if(c0==c1) tl=c1;
	if(d0==d1) tr=d1;
	if(c0>c1)
	{
		if(!(c1>=tl&&c1<=tr)) return 0;
		else tl=tr=c1;
	}
	if(d0<d1)
	{
		if(!(d1>=tl&&d1<=tr)) return 0;
		else tl=tr=d1; 
	}
	return(tr-tl+1);
}
int main()
{
	freopen("D:/LiuYuanHao/son.in","r",stdin);
	freopen("D:/LiuYuanHao/a.out","w",stdout);

	gtpri();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&a0,&a1,&b0,&b1);	
		// int mn=min(a0,min(a1,min(b0,b1)));
		long long ans=1;
		//21222 2 999993719 1999987438
		fo(i,1,pri[0])
		if(b1%pri[i]==0)
		{
			ans*=work(pri[i]);
			while(b1%pri[i]==0) b1/=pri[i];
			if(!ans||(pri[i]*pri[i]>=b1))break;
		}
		if(b1!=1)ans*=work(b1);
		printf("%lld\n",ans);
	}	
	return 0;
}
