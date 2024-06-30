#pragma GCC optimize(2) 
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
const int N=400400,M=200200*6;
int n,m,q;
int to[M],nex[M],las[N],tot;
int f[N];
int read()
{
	int rt=0,fg=1;char ch=getchar();
	while(ch!='-'&&(!(ch>='0'&&ch<='9'))) ch=getchar();
	if(ch=='-') fg=-1,ch=getchar();
	while(ch>='0'&&ch<='9') rt=rt*10+ch-'0',ch=getchar();
	return rt*fg;
}
inline void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
int w[N],r[N],ans[N],ri[N];
int lg[N];
int d[N],dis[N];
int bz[N],de[M],fn;
int check(int e)
{
	fo(i,1,n) f[i]=oo;
	fo(i,1,e) 
	{
		int p=r[i][w];
		de[p]=de[p^1]=1;	
		bz[i+n]=1;
	}
	f[1]=0;d[1]=1;
	int hd=0,tl=1;
	while(hd++<tl)
	{
		int x=d[hd];
		for(int tp=las[x];tp;tp=tp[nex])
		if(f[x]+1<f[to[tp]] && (!de[tp]) && (!bz[to[tp]]))
		{
			f[to[tp]]=f[x]+1;
			d[++tl]=to[tp];
		}
	}
	fo(i,1,e) 
	{
		int p=r[i][w];
		de[p]=de[p^1]=0;	
		bz[i+n]=0;
	}
	int rt=0;
	fo(i,1,fn) if(f[i]!=dis[i])
		++rt;
	return rt;
}
int buf[30],b0;
void write(int x)
{
	b0=0;
	if(x==0)putchar('0');
	else
	while(x) buf[++b0]=x%10,x/=10;
	fd(i,b0,1) putchar(buf[i]+'0');
	putchar('\n');
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("train.in","r",stdin);
//	freopen("train.out","w",stdout);
	n=read(),m=read(),q=read();fn=n;
	tot=1;
	fo(i,2,q) lg[i]=lg[i>>1]+1;
	fo(i,1,m)
	{
		int x,y;
		x=read(),y=read();
		link(x,y),link(y,x);
		w[i]=tot;
	}
	check(0);
	fo(i,1,n) dis[i]=f[i];
	fo(i,1,q)
	{
		r[i]=read();
		int x=w[r[i]][to],y=to[1^w[r[i]]],z=++n;
		link(x,z),link(z,x);
		link(y,z),link(z,y);
	}
	fo(i,1,q)
	{
		ri[i]=i;
		ans[i]=check(i);int w=i;
		for(int p=(1<<lg[q-i]);p;p>>=1)
		if(check(w+p)==ans[i]) ri[i]=w+p,w+=p;
		fo(k,i+1,ri[i]) ans[k]=ans[i];
		i=ri[i];
	}
	fo(i,1,q) 
		write(ans[i]);
	return 0;
}
