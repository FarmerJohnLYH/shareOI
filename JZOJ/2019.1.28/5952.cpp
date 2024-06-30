#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
const int N=467895,M=(1<<20)+10;
int n,a[N];
int f[M];
int all;
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
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
void dfs(int cs,int x,int c)
{
	if(cs>19) 
	{
		if(c==0)
			fo(i,0,19) if(!(x&(1<<i))) f[x]=min(f[x],f[x+(1<<i)]);
		return ;	
	}
	dfs(cs+1,x,c);
	if(c>0)dfs(cs+1,x+(1<<cs),c-1);
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	 freopen("ak.in","r",stdin);
	 freopen("ak.out","w",stdout);
	all=(1<<20)-1;
//	scanf("%d",&n);
	n=read();
	memset(f,127,sizeof f);
	fo(i,1,n) 
	{
		a[i]=read()^a[i-1];
//		scanf("%d",&a[i]),a[i]^=a[i-1];
		f[a[i]]=min(f[a[i]],i);
	}
	fd(k,19,0)
		dfs(0,0,k);
	int now;
	fo(i,1,n)
	{
		int ans=0;
		now=0;
		fd(j,19,0) if(!(a[i]&(1<<j)))
		{
			if(f[now^(1<<j)]<=i) now=now^(1<<j),ans+=(1<<(j+1));
		}else ans+=(1<<j);
		write(ans);
	}
	return 0;	
}
