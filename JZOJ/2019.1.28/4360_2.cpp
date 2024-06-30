//弃疗
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define anti(x) (x & 1) ? (x + 1) : (x - 1)
#define zero(x) (fabs(x) < eps)
using namespace std;
typedef double db;
typedef long long ll;
const int N = 1e3 + 10, M = 2e4 + 20 + 2 * N;
const db eps = 1e-10, Inf = 1000000000;
db a[N], ans, f[M], b[N];
int w[N], v[N], deg[N], cur[N], que[2][N], p[N];
int to[M], nex[M], g[N], alr[N], flag[N], St[N]; 
int gap[N], d[N];
int n, tot, cnt, s, t;
void add(int u, int v, db Lim)
{
	to[++ tot]=v;
	nex[tot]=g[u];
	g[u]=tot;
	f[tot]=Lim;
	if (tot & 1) add(v, u, 0);
}
void init()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
	{
		int j;
		scanf("%d", &deg[i]);
		j = deg[i];
		memset(alr, 0, sizeof(alr));
		for (int k = 1; k <= deg[i]; ++ k)
		{
			int v;
			scanf("%d", &v);
			if (alr[v]) 
			{ 
				-- j;
				continue;
			}
			alr[v] = 1;
			add(i, v, Inf);
		}
		deg[i] = j;
	}
	for (int i = 1; i <= n; ++ i)
		scanf("%d%d", &v[i], &w[i]);
}
bool Check()
{
	memcpy(cur, deg, sizeof(cur));
	bool re = 0;
	for (int i = 1; i <= n; ++ i) if (!deg[i])
		que[0][++ que[0][0]] = i;
	int q = 0;
	while (que[q][0])
	{
		que[q ^ 1][0] = 0;
		for (int i = 1; i <= que[q][0]; ++ i)
		{
			int u = que[q][i];
			p[u] = 1;
			if (w[u]) re = 1;
			for (int j = g[u]; j; j = nex[j])
			{
				int v = to[j];
				if (p[v]) continue;
				if (!-- cur[v])
					que[q ^ 1][++ que[q ^ 1][0]] = v;
			}
		}
		q ^= 1;
	}
	return re;
}
db dfs(int u, db lim)
{
	if (u == t) 
		return lim;
	db re = 0;
	for (int i = g[u]; i; i = nex[i]) if (f[i] > eps)
	{
		int v = to[i];
		if (d[v] != d[u] - 1) continue;
		db t = dfs(v, min(lim - re, f[i]));
		f[i] -= t, f[anti(i)] += t, re += t;
		if (zero(lim - re)) return re;
	}
	if (!-- gap[d[u]]) d[s] = t;
	gap[++ d[u]] ++;
	return re;
}
bool check(db Lim)
{
	memcpy(g, St, sizeof(g));
	tot = cnt;
	for (int i = 1; i <= tot; i += 2)
	{
		f[i] = Inf;
		f[i + 1] = 0;
	}
	db all = 0;
	for (int i = 1; i <= n; ++ i) if (p[i])
	{
		a[i] = db(v[i]) - w[i] * Lim;
		if (a[i] > -eps)
		{
			all += a[i];
			add(s, i, a[i]);
		}
		else add(i, t, -a[i]);
	}
	memset(d, 0, sizeof(d));
	gap[0] = t;
	while (d[s] < t)
		all -= dfs(s, Inf);
	return all > eps;
}
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	init();
	if (!Check()) 
	{
		puts("CanNotFindTreasure!");
		return 0;
	}
	db l=0,r=Inf;
	memcpy(St,g,sizeof(g));
	cnt=tot;s=n+1,t=n+2;
	while(r-l>eps)
	{
		db mid=(l+r)/2;
		if (check(mid))l=mid;
		else r=mid;
	}
	if(zero(r-Inf))printf("0.0000000");
	else printf("%.10lf", 1 / l);
}
