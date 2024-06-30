#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (int pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
int lowbit(int x) {return((x)&(-x));}
int min(int x,int y){return (x>y)?(y):(x);}
int max(int x,int y){return (x>y)?(x):(y);}
const int N=100100,M=10100;
int n,m,h[N],x[M],s[M];
int to[N][2];
struct node{
	int id,v;
	int nex,las;
}a[N];
int p[N];
int next[N][18],v[2][N][18];
bool cmp(node a,node b)
{
	return(a.v<b.v);
}
int dis(int x,int y)
{
	return(abs(a[x].v-a[y].v));
}
int ana,anb;
void solve(int x,int y)
{
	
}
int main()
{
	freopen("D:/LiuYuanHao/","r",stdin);
	scanf("%d",&n);
	fo(i,1,n)
	{
		scanf("%d",&h[i]);
		a[i].id=i,a[i].v=h[i];
	}
	sort(a+1,a+1+n,cmp);
	fo(i,1,n)
	{
		p[a[i].id]=i;
		a[i].las=i-1;
		a[i].nex=i+1;
	}
	a[n].nex=1,a[1].las=n;
	fo(i,1,n-1)
	{
		int now=p[i],mx=a[now].nex,se=0;
		if(dis(a[now].las,now)<dis(mx,now))
		{
			se=mx,mx=a[now].las;
		}
		else se=a[now].las;
		if(dis(a[a[now].las].las,now)<dis(mx,now))
		{
			se=mx,mx=a[a[now].las].las;
		}
		else se=a[a[now].las].las;
		if(dis(a[a[now].nex].nex,now)<dis(mx,now))
		{
			se=mx,mx=a[a[now].nex].nex;
		}
		else se=a[a[now].nex].nex;
		if(mx==se) se=0;
		to[i][0]=mx,to[i][1]=se;
		a[a[now].las].nex=a[now].nex,a[a[now].nex].las=a[now].las;
	}
	fo(i,1,n)
	{
		next[i][0]=to[to[i][1]][0];
		v[1][i][0]=dis(i,to[i][1]);
		v[0][i][0]=dis(to[i][1],to[to[i][1]][0]);
	}
	fo(l,1,17)
	{
		fo(i,1,n)
		{
			next[i][l]=next[next[i][l-1]][l-1];
			v[1][i][l]=v[1][i][l-1]+v[1][next[i][l-1]][l-1];
			v[0][i][l]=v[0][i][l-1]+v[0][next[i][l-1]][l-1];
		}
	}
	int x0;
	scanf("%d",&x0);
	fo(st,1,n)
	{
		solve(st,x0);
	}

	return 0;
}
