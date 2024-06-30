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
const int N = 330;
int n;
struct node{
	int x,y;
	int v;
}a[N * N];
int d[N];
int v[N][N];
bool bz[N];
int ans = oo;
int l[N],r[N],tot;
void dfs(int fl,int le,int ri)
{
	if (le + ri >= ans) return;
	if (fl > d[0])
	{
		ans = le + ri;
		return;		
	}
	int tmp = 0;
	fo(i,1,l[0])
		tmp = max(tmp,v[d[fl]][l[i]]);
	l[++ l[0]] = d[fl];
	dfs(fl + 1,max(tmp,le),ri);
	-- l[0];

	tmp = 0;
	fo(i,1,r[0])
		tmp = max(tmp,v[d[fl]][r[i]]);
	r[++ r[0]] = d[fl];
	dfs(fl + 1,le,max(tmp,ri));
	-- r[0];
}
bool cmp(node x,node y)
{
	return x.v > y.v;
}
int main()
{
	freopen("broken.in","r",stdin);
	freopen("broken.out","w",stdout);
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d", &n);
	fo(i,1,n - 1) fo(j,i + 1,n)
	{
		scanf("%d", &v[i][j]);v[j][i] = v[i][j];
		a[++ tot].x = i,a[tot].y = j,a[tot].v = v[i][j];
	}
	sort(a+1,a+1+tot,cmp);
	fo(i,1,tot)
	{
		if (!bz[a[i].x]) d[++ d[0]] = a[i].x,bz[a[i].x] = 1;
		if (!bz[a[i].y]) d[++ d[0]] = a[i].y,bz[a[i].y] = 1;
	}
	dfs(1,0,0);
	printf("%d\n", ans);
	return 0;
}
