#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int M=20200,N=5000500;
typedef long long ll;
int n,m,sta[N],sta0;
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
int rot;
struct node{
	int tr,tf,v,sz;
	ll s;
}t[N];int sn[N][2],fa[N];
void down(int x)
{
	if(t[x].tr)
	{
		fo(l,0,1) if(sn[x][l]) sn[x][l][t].tr^=1;
		t[x].tr=0;
		swap(sn[x][0],sn[x][1]);
	}
	if(t[x].tf!=oo)
	{
		fo(l,0,1) if(sn[x][l]) 
		{
			sn[x][l][t].tf=t[x].tf;
			sn[x][l][t].s=1ll*sn[x][l][t].sz*t[x].tf;	
			sn[x][l][t].v=t[x].tf;  
		}
		t[x].tf=0;
	}
}
void update(int x)
{
	t[x].sz=1;
	fo(l,0,1) if(sn[x][l]) t[x].sz+=sn[x][l][t].sz;
	if(t[x].tr||t[x].tf!=oo)
		down(x);
	t[x].s=t[x].v;
	fo(l,0,1) if(sn[x][l]) t[x].s+=t[sn[x][l]].s;
}
void init(int x)
{
	t[x].s=t[x].v=0,t[x].tr=0,t[x].tf=oo;
	t[x].sz=1;
	update(x);
}
void splay(int x,int upr)
{
	while(fa[x]!=upr)
	{
		if(fa[fa[x]]!=upr)
		{
			if(gl(x)==gl(fa[x])) rotate(fa[x]);
			else rotate(x);
		}
		rotate(x);
	}
	update(x);
	if(upr==0) rot=x;
	else update(upr);
}
int main()
{
	freopen("D:/LiuYuanHao/","r",stdin);
	n=read(),m=read();
	fo(i,1,n)
	{
		init(i);
		int v=read();
		t[x].s=t[x].v=v;
		fa[sn[i-1][1]=i]=i-1;
		splay(v,0);
	}
	fo(i,1,m)
	{

	}
	return 0;
}











