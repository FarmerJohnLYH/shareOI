#include <ctime>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),GG=(y);i<=GG;++i)
using namespace std;
typedef double db;
typedef long long ll;
const int N=330;
const db eps=0.0000001;
int n;
db crs(db ax,db ay,db bx,db by){return(ax*by-bx*ay);}
struct node{
	db x,y,r;
}a[N],o;
db dis(node a,node b)
{
	return(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}
struct ve{
	int t,f;
	db ax,ay,bx,by;
}c[N*N],p;int c0;
int f[N][2];
int tch(ve a,ve b)
{
	if(crs(b.ax-a.ax,b.ay-a.ay,a.bx-a.ax,a.by-a.ay)*crs(b.bx-a.ax,b.by-a.ay,a.bx-a.ax,a.by-a.ay)>0) return(0);
	swap(a,b);
	if(crs(b.ax-a.ax,b.ay-a.ay,a.bx-a.ax,a.by-a.ay)*crs(b.bx-a.ax,b.by-a.ay,a.bx-a.ax,a.by-a.ay)>0) return(0);
	return(1);
}
int hd,tl,d[N*10];
vector<int>to[N];
int solve(int st)
{
	int x=st;
	f[x][1]=1;hd=0;d[tl=1]=x;
	while(hd++<tl)
	{
		x=d[hd];
		fo(i,0,to[x].size()-1)
		{
			int tp=to[x][i];
			int a=f[c[tp].t][0],b=f[c[tp].t][1];
			fo(l,0,1)f[c[tp].t][l]|=f[x][l^c[tp].f];
			if(a!=f[c[tp].t][0]||b!=f[c[tp].t][1]) d[++tl]=c[tp].t;	
		}
	}
	return(f[st][0]);
}
int main()
{
	freopen("D:/LiuYuanHao/b3.in","r",stdin);
//	srand(time(0));
	while(scanf("%d",&n)!=EOF)
	{
//		memset(c,0,sizeof c);
		c0=0;memset(f,0,sizeof f);
		fo(i,1,n) to[i].clear();
		fo(i,1,n) scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].r);
		scanf("%lf%lf%lf",&o.x,&o.y,&o.r);
		fo(i,1,n) a[i].r+=o.r;
		fo(i,1,n) fo(j,i+1,n)
		if(dis(a[i],a[j])+eps<=a[i].r+a[j].r)
		{
			c[++c0].ax=a[i].x,c[c0].ay=a[i].y,c[c0].bx=a[j].x,c[c0].by=a[j].y;
			if(a[i].x>a[j].x) swap(c[c0].ax,c[c0].bx),swap(c[c0].ay,c[c0].by);
			c[c0].t=j;to[i].push_back(c0);
			c[c0+1]=c[c0];c[++c0].t=i;
			to[j].push_back(c0);
		}
		ll ra=rand()%100000000;
		p.ax=o.x,p.ay=o.y;p.bx=1e15,p.by=(db)ra*(db)1e15/(db)64726731;
		fo(i,1,c0)
			if(tch(p,c[i]))
				c[i].f=1;
		int flag=0;
		fo(i,1,n)
		if(f[i][1]==f[i][0]&&f[i][0]==0)
		{
			if(solve(i))
			{
				printf("NO\n");
				flag=1;
				break;
			}
		}	
		if(!flag) printf("YES\n");
	}
	return 0;
}











