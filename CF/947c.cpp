#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm> 
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=300300,L=33,M=N*L;
int n,a[N],p[N],m;
int to[M][2],sz[M],tot;
void insert(int x)
{
	int now=1;
	fd(i,m,0)
	{
		int v=((1<<i)&x)?(1):(0);
		if(to[now][v]==0) to[now][v]=++tot;
		now=to[now][v];
		++sz[now];
	}
}
int find(int x)
{
	int now=1,rt=0;
	fd(i,m,0)
	{
		int v=((1<<i)&x)?(1):(0);
		if(to[now][v]&&sz[to[now][v]]) 
		{
			rt=(rt<<1)+v;
			now=to[now][v];
		}
		else 
		{
			rt=(rt<<1)+(v^1);
			now=to[now][v^1];
		}
		--sz[now];
	}
	return(rt);
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n) 
	{
		scanf("%d",&a[i]);
		fd(l,30,0)
		if(a[i]&(1<<l))
		{
			m=max(m,l);
			break;
		}
	}
	tot=1;
	fo(i,1,n)
	{
		scanf("%d",&p[i]);
		fd(l,30,0)
		if(p[i]&(1<<l))
		{
			m=max(m,l);
			break;
		}
	}
	fo(i,1,n) insert(p[i]);
	fo(i,1,n)
	{
		int q=find(a[i]);
		// del(q);
		printf("%d ",(q^a[i]));
	}
	return 0;
}











