#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=100100;
int n,k;
int to[N*2],nex[N*2],las[N];
int tot;
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
#define max(x,y) ((x)>(y)?(x):(y))
struct node{
	int v,mx;
	node(int v_=0,int m_=0){v=v_,mx=m_;}
};
node p;
node run(int x,int f,int k)
{
	node rt=node();
	int se=1;
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=f)
	{
		p=run(to[tp],x,k);
		rt.v+=p.v;
		if(se)
		{
			if(rt.mx+p.mx>=k) rt.mx=0,se=0,++rt.v;
			else rt.mx=max(rt.mx,p.mx);	
		}
	}
	rt.mx+=se;
	return rt;
}
int check(int k)
{
	node p=run(1,0,k);
	return p.v;
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
	putchar('\n');
}
int g[N];
int main()
{
	freopen("D:/LiuYuanHao/a1.in","r",stdin);
	freopen("D:/LiuYuanHao/a1.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n-1)
	{
		int x=read(),y=read();
		link(x,y),link(y,x);
	}
	int pe=0;
	write(n); 
	while(pe<n-1)
	{
		int le=pe+2,ri=n-1,rt=pe+1,nw=check(rt);
//		ri=pe+g[pe];
		if(pe>300) 
		while(le<=ri)
		{
			k=(le+ri)>>1;
			if(check(k)!=nw) ri=k-1;
			else rt=k,le=k+1;
		}
		fo(i,pe+1,rt)
			write(nw);
		pe=rt;
	}
	return 0;
}








