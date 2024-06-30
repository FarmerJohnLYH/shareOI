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
const int N = 200200;
int n,m;
struct node{
	int id;
	ll x,y;
}a[N],b[N],c[N];
ll ans,q[N];
bool cmp(node x,node y)
{
	return x.x < y.y;
}
bool pmc(node x,node y)
{
	return x.x > y.y;
}
db cal(node x,node y)
{
	return ((db)(x.y - y.y) / (db)(x.x - y.x));
}
ll find(node o) //二分查找队列
{
	int l = 2,r = q[0],rt = 1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (cal(a[q[mid]],a[q[mid - 1]]) <= (db)o.y) ans = mid,l = mid + 1;
		else r = mid - 1;
	}
	int tmp = a[q[ans]].id;
	return c[tmp].y - abs(o.x - c[tmp].x) * o.y;
} 
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n, &m);
	fo(i,1,n)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].id = i;
		c[i] = a[i];
		a[i].x = -a[i].x;
	}
	fo(i,1,m)
	{
		scanf("%d%d", &b[i].x, &b[i].y);
		b[i].id = i;
	}
	sort(a + 1,a + 1 + n,pmc);
	sort(b + 1,b + 1 + m,cmp);
	int hd = 0;
	fo(i,1,m)
	{
		while (hd < 0 && b[i].x + a[hd + 1].x >= 0)
		{
			++ hd;
			while (q[0] > 1 && cal(a[q[q[0]]],a[q[q[0] - 1]]) >= cal(a[hd],a[q[q[0] - 1]])) -- q[0];
			q[++ q[0]] = hd;
		}
		ans[b[i].id] = max(ans[b[i].id],find(b[i]));
	}

	q[0] = 0;
	fo(i,1,n) a[i] = c[i];
	sort(a + 1,a + 1 + n,pmc);
	hd = 0;
	fo(i,1,m)
	{
		while (hd < 0 && a[hd + 1].x - b[i].x >= 0)
		{
			++ hd;
			while (q[0] > 1 && cal(a[q[q[0]]],a[q[q[0] - 1]]) >= cal(a[hd],a[q[q[0] - 1]])) -- q[0];
			q[++ q[0]] = hd;
		}
		ans[b[i].id] = max(ans[b[i].id],find(b[i]));
	}
	fo(i,1,m) printf("%lld\n", ans[i]);
	return 0;
}
