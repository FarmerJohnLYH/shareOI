#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (int i=(x),asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> PI;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N=16;
int n,m;
int a[N],b[N],c[N],d[N],e[N];
int ans;
int f[N];
bool check()
{
	fo(i,2,m)
	if(e[i]<e[i-1]) return 0;
	memset(f,0,sizeof f);
	fo(i,1,n)
	{
		f[i]=1;
		fo(j,1,i-1)
		if(c[j]<c[i])
			f[i]=max(f[i],f[j]+1);
		if(f[i]>m)return 0;
	}
	fo(i,1,m)
	if(f[e[i]]!=i) return 0;
	return 1;
}
void dfs(int x,int y)
{
	if(x>n)
	{
		if(check())
			++ans;
		return;
	}
	fo(i,1,n)
	if(!d[i])
	if(i>=a[y+1]||i<=a[y])
	{
		c[x]=i,d[i]=1;
		if(b[i])
		{
			e[b[i]]=x;
			dfs(x+1,y+1);
		}
		else
			dfs(x+1,y);
		d[i]=0;
	}
}
int main()
{
//	freopen("D:/LiuYuanHao/b.in","r",stdin);
	freopen("arg.in","r",stdin);
	freopen("arg.out","w",stdout);
	scanf("%d%d",&n,&m);
	ans=-1;
	fo(i,1,m) 
	{
		scanf("%d",&a[i]);b[a[i]]=i;
		if(a[i]<a[i-1]) ans=0;
	}
	if(ans==0)
	{
		printf("0\n");
		return 0;
	}
	dfs(1,0);
	printf("%d\n",ans+1);
	return 0;
}











