#include <set>
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
set<int> t;
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
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	// freopen("D:/LiuYuanHao/a.out","w",stdout);
	freopen("miku.in","r",stdin);
	freopen("miku.out","w",stdout);
	n=read(),m=read(),L=read(),R=read();
	fo(i,1,n)
	{
		a[i]=read();
		if(i>1&&a[i-1]>a[i]) t.insert(i);
	}
	fo(i,1,m)
	{
		int le=read(),ri=read();
		int q=*t.lower_bound(le);
		while((t.lower_bound(le)!=t.end())&&q+1<=ri)
		{
			swap(a[q],a[q+1]);
			t.erase(q);
			if(a[q+1]>a[q+2]&&q+2<=n) t.insert(q+1);
			if(a[q-1]>a[q]&&q-1>0) t.insert(q-1);
			q=*t.lower_bound(le);
		}
	}
	fo(i,L,R) 
		write(a[i]),putchar(' ');
	putchar('\n');
	return 0;	
}





