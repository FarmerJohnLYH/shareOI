#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (int pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> PI;
int lowbit(int x) {return((x)&(-x));}
int min(int x,int y){return (x>y)?(y):(x);}
int max(int x,int y){return (x>y)?(x):(y);}
const int N=1010,K=55;
int n,s,k;
int t[N][N]/*点1到点i间 小于 点 j值 数量*/;
int f[N][K];
int tr[N];
PI r[N];
void insert(int x)
{
	while(x<=n)
		++tr[x],x+=lowbit(x);
}
int query(int x)
{
	int rt=0;
	while(x)
	{
		rt+=tr[x];
		x-=lowbit(x);
	}
	return rt;
}
bool cmp(PI a,PI b)
{
	return(a.fi<b.fi||(a.fi==b.fi&&a.se>b.se));
}
int main()
{
	 // freopen("board.in","r",stdin);
	 // freopen("board.out","w",stdout);
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d%d",&n,&s,&k);
	fo(i,1,n)
		scanf("%d",&r[i].fi),r[i].se=i;
	sort(r+1,r+1+n,cmp);
	fo(i,1,s)
	{
		memset(tr,0,sizeof tr);
		int l=1;
		while(r[l].fi<i) ++l;
		fo(j,i,s)
		{
			t[i][j]=t[i][j-1];
			for (;l<=n&&r[l].fi==j;++l)
				t[i][j]+=query(r[l].se-1),insert(r[l].se);
		}
	}
	memset(f,127,sizeof f);
	memset(f[0],0,sizeof f[0]);
	fo(i,1,s)
	{
		fo(j,1,k)
		{
			f[i][j]=f[i][j-1];
			fo(p,1,i)
			{
				f[i][j]=min(f[i][j],f[i-p][j-1]+t[i-p+1][i]);
			}
		}
	}
	printf("%d",f[s][k]);
	return 0;
}









