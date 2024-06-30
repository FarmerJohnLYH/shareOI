#pragma GCC optimize(2)
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef pair<int,int> PI;
#define fi first
#define se second
const int N=11,M=N*N;
int n;
int f[M],tw[M];
int a[4][4],p0;
vector<PI> p[M];int v[M],sz[M],bp[M];
int e[N][N],an[N][N],r[N][N],cnt;
int gf(int x)
{
	return(f[x]==x)?(x):(f[x]=gf(f[x]));
}
PI fj(int x)
{
	PI c;
	c.fi=(x-1)/n+1;
	c.se=(x-1)%n+1;
	return(c);
}
int h(int x,int y)
{
	return((x-1)*n+y);
}
void comb(int x,int y)
{
	int fx=gf(x),fy=gf(y);
	f[fx]=fy;
}
int all,jiu[M];
int bzh[N],bzl[N];
int tim;
int pl[M];
void dfs(int xx,int y)
{
	int x=pl[xx];
	if(x>p0)
	{
		int flag=0;
		++cnt;if(an[1][1]==0)flag=1;
		fo(i,1,n) fo(j,1,n)
		{
			if(flag)break;
			if(e[i][j]<an[i][j]) 
			{
				flag=1;
				break;
			}
			if(e[i][j]>an[i][j]) 
			{
				flag=2;
				break;
			}
		}
		if(flag==1) fo(i,1,n) fo(j,1,n) an[i][j]=e[i][j];
		return;
	}
	if(y>sz[x]) 
	{
		if(v[x]==1)
			dfs(xx+1,1);
		return;
	}
	if(jiu[sz[x]-y+1]<v[x]) 
		return;
	PI c=p[x][y-1];
	fo(i,1,3) if(bp[x]&(1<<i))
	{
		fd(j,3,1)
		{
			if(v[x]%a[i][j]==0)
			{
				if(!(bzh[c.fi]&(1<<a[i][j])))
				if(!(bzl[c.se]&(1<<a[i][j])))
				{
					e[c.fi][c.se]=a[i][j];
					v[x]/=a[i][j];
					(bzh[c.fi]|=(1<<a[i][j]));
					(bzl[c.se]|=(1<<a[i][j]));
					dfs(xx,y+1);
					v[x]*=a[i][j];
					(bzh[c.fi]-=(1<<a[i][j]));
					(bzl[c.se]-=(1<<a[i][j]));
					e[c.fi][c.se]=0;
				}
			}
		}
	}
}
bool cmp(int x,int y)
{
	return(v[x]<v[y]);
}
int main()
{
	freopen("kenken.in","r",stdin);
	freopen("kenken.out","w",stdout);
//	freopen("D:/LiuYuanHao/c1.in","r",stdin);
	a[1][1]=9,a[1][2]=6,a[1][3]=3;
	a[2][1]=8,a[2][2]=4,a[2][3]=2;
	a[3][1]=7,a[3][2]=5,a[3][3]=1;
	scanf("%d",&n);all=h(n,n);
	fo(i,1,all) f[i]=i,pl[i]=i;
	jiu[0]=1;
	fo(i,1,all) jiu[i]=min(100001,jiu[i-1]*9);
	fo(i,1,n) fo(j,1,n)
	{
		scanf("%d",&r[i][j]);
		if(i-1)if(r[i][j]==r[i-1][j]) comb(h(i,j),h(i-1,j));
		if(j-1)if(r[i][j]==r[i][j-1]) comb(h(i,j),h(i,j-1));
	}
	fo(i,1,all) if(gf(i)==i)
	{
		tw[i]=++p0,v[p0]=r[(i-1)/n+1][(i-1)%n+1];
		bp[p0]=(1<<3);
		fo(l,1,2) if(v[p0]%a[l][3]==0)bp[p0]|=(1<<l);  
	}
	fo(i,1,all) p[tw[gf(i)]].push_back(fj(i)),++sz[tw[gf(i)]];
	sort(pl+1,pl+1+p0,cmp);
	dfs(1,1);
	printf("%d\n",cnt);
	fo(i,1,n)
	{
		fo(j,1,n)
			printf("%d ",an[i][j]);
		printf("\n");
	}
	return 0;
}











