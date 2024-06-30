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
const int N=1010;
int n;
struct node{
	int a,d,c;
}a[N];
bool cmpc(node x,node y)
{
	return(x.c>y.c);
}
int f[N][N];
int main()
{
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	freopen("D:/LiuYuanHao/b.out","w",stdout);
	for(;scanf("%d",&n)!=EOF;)
	{
		fo(i,1,n) 
		{
			scanf("%d%d",&a[i].d,&a[i].a);
			a[i].c=a[i].a+a[i].d;
		}
		sort(a+1,a+1+n,cmpc);
		int att;
		scanf("%d",&att);
		memset(f,127,sizeof f);
		f[n+1][0]=0;
		fd(i,n+1,2) fo(j,0,n-i+1)
		if(f[i][j]<oo)
		{
			f[i-1][j]=min(f[i][j],f[i-1][j]);
			if(a[i-1].a>=f[i][j]) f[i-1][j+1]=min(f[i-1][j+1],f[i][j]+a[i-1].d);
		}
		fd(i,n,0) 
		if(f[1][i]<oo&&f[1][i]<=att) 
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
