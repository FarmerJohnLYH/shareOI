#pragma GCC optimize(2) 
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 1000000000
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
const int N=1515,M=50050;
int a[N],n,m,L,R;
int t[N];
int read()
{
	int rt=0,fg=1;char ch=getchar();
	while(!(ch=='-'||(ch>='0'&&ch<='9'))) ch=getchar();
	if(ch=='-') fg=-1,ch=getchar();
	while(ch>='0'&&ch<='9') rt=rt*10+ch-'0',ch=getchar();
	return rt*fg;
}
int buf[30],b0;
void write(int n)
{
	if(n==0)
	{
		putchar('0');
		return;
	}b0=0;
	while(n) buf[++b0]=n%10,n/=10;
	fd(i,b0,1) putchar(buf[i]+'0');
}
int tt,eps=2e8;

int main()
{
	// freopen("miku.in","r",stdin);
	// freopen("miku.out","w",stdout);
	n=read(),m=read(),L=read(),R=read();
	fo(i,1,n)a[i]=read();
	fo(i,1,m)
	{
		int le=read(),ri=read(),mn=oo,mx=-oo,tt=le;
		fo(j,le,ri) t[a[j]]=i,mn=min(mn,a[j]),mx=max(mx,a[j]);
		fo(j,mn,mx) if(t[j]==i) a[tt++]=j;
		tt+=mx-mn+ri-le;
		if(tt>eps)
			break;
	}
	fo(i,L,R) 
		write(a[i]),putchar(' ');
	putchar('\n');
	return 0;	
}



