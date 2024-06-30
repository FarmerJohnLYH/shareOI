#include <queue>
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
const int N=33;
int n,t;
db p;
int a[N];
int q[N];
int ct;
db f[N][50];
db dfs(int d,int s)
{
	if(f[q[0]][s]) return(f[q[0]][s]);
	if(s>t||d>ct)
		return(d);
	db rt=0;
	if(q[0])
	{
		int tp=q[q[0]--];
		rt+=p*dfs(d+1,s-tp);
		q[++q[0]]=tp;
		fo(i,1,n)
		{
			if(a[i]>q[q[0]]) break;
			q[++q[0]]=a[i];
			rt+=(1-p)*dfs(d+1,s+a[i]);
			--q[0];
		}
		return (f[q[0]][s]=rt); 
	}
	else
	{
		fo(i,1,n)
		{
			q[++q[0]]=a[i];
			rt+=dfs(d+1,a[i]+s)/n;
			--q[0];
		}
		return(f[q[0]][s]=rt);
	}
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	while(scanf("%lf%d%d",&p,&t,&n)!=EOF)
	{
		ct=4040;
		memset(a,0,sizeof a);
		memset(q,0,sizeof q);
		memset(f,0,sizeof f);
		fo(i,1,n)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		printf("%.3lf\n",dfs(0,0));
	}
	return 0;
}









