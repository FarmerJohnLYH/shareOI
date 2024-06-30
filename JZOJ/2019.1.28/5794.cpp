//#pragma GCC optimize(2) 
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define fi first
#define se second
using namespace std;
typedef pair<int,int> PI;
const int N=10100,M=1001000;
int n,m,le,ri;
struct edge{
	int x,y,l,r;
}e[N*3];
int p[M],b[M];
int bz[M];
int f[N],nex[M];
int gf(int x)
{
	return(f[x]==x)?(x):(f[x]=gf(f[x]));
}
PI check(int len)
{
	for(int i=nex[le];i<=ri&&i>0;i=nex[i+1])
//	if(b[i]>b[i+1])
	{
		for(int j=1;j<=n+4;j+=4)
		{
			f[j]=j;
			f[j+1]=j+1;
			f[j+2]=j+2;
			f[j+3]=j+3;
		}
		fo(j,1,m) 
		if(e[j].l<=i&&i+len-1<=e[j].r) 
		{
			int fx=gf(e[j].x),fy=gf(e[j].y);
			f[fx]=fy;
			if(gf(1)==gf(n))return make_pair(i,i+len-1);
		}
	}
	return make_pair(0,0);
}
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
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.ans","w",stdout);
	le=1e6,ri=0;
	n=read(),m=read();
	fo(i,1,m)
	{
//		scanf("%d%d%d%d",&e[i].x,&e[i].y,&e[i].l,&e[i].r);
		e[i].x=read(),e[i].y=read(),e[i].l=read(),e[i].r=read();
		e[i].l=max(e[i].l,1);
		ri=max(ri,e[i].r),le=min(le,e[i].l);
		++p[e[i].l],--p[e[i].r+1];
		bz[e[i].l]=1;
	}
	int l=1,r=0,cnt=0;
	fo(i,le,ri+1)
	{
		p[i]+=p[i-1];
		if(p[i]<1)
		{
			fo(k,0,cnt-1)b[i-cnt+k]=cnt-k;
			cnt=0;
		}
		else ++cnt;
		r=max(r,cnt);
	}
	while(p[le]<1&&le<=ri)++le;
	while(p[ri]<1&&le<=ri)--ri;
	fd(i,ri,le) 
	{
		if(bz[i]) 
		{
			nex[i]=i;
		}else nex[i]=nex[i+1];
	}
	PI ans=make_pair(0,0);
	while(l<=r)
	{
		int len=(l+r)>>1;PI d=check(len);
		if(d.fi>0) ans=d,l=len+1;
		else r=len-1;
	}
	if(ans.fi==0)
	{
		printf("0\n");
		return 0;
	}
	write(ans.se-ans.fi+1);putchar('\n');
	fo(i,ans.fi,ans.se) write(i),putchar(' ');
	return 0;
}











