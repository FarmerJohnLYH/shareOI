#include<cstdio>
#include<ctime>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 1000010, MAXQ = 200010;
const int INF = 1000000000;
int n, Q, type, m, lans;
int last[MAXQ], cnt;
int rt[MAXQ], sum[MAXN<<2];
int ls[MAXN<<2], rs[MAXN<<2];
struct Edge {
	int u, v;
}E[MAXQ];
struct LCT {
	int ch[MAXN<<1][2], fa[MAXN<<1];
	int Min[MAXN<<1], val[MAXN<<1];
	int S[MAXN<<1], top;
	bool rev[MAXN<<1];
	inline void init() {
		for(int i = 0; i <= n; i++) {
			Min[i] = val[i] = INF;
			ch[i][0] = ch[i][1] = fa[i] = 0;
			rev[i] = 0;
		}
	}
	inline bool isroot(int x) {
		return ch[fa[x]][0] != x && ch[fa[x]][1] != x;
	}
	inline void update(int x) {
		int ml = Min[ch[x][0]], mr = Min[ch[x][1]];
		Min[x] = min(val[x], min(ml, mr));
	}
	inline void pushdown(int x) {
		if(rev[x]) {
			rev[x] ^= 1;
			rev[ch[x][0]] ^= 1;
			rev[ch[x][1]] ^= 1;
			swap(ch[x][0], ch[x][1]);
		}
	}
	inline void rotate(int x, int f1) {
		int y = fa[x], z = ch[x][f1^1];
		if(!isroot(y)) ch[fa[y]][ch[fa[y]][1] == y] = x;
		fa[x] = fa[y];
		ch[fa[y] = x][f1^1] = y;
		ch[fa[z] = y][f1] = z;
		update(y);
	}
	inline void Splay(int x) {
		int u = x;
		for(S[top = 1] = u; !isroot(u); u = fa[u]) S[++top] = fa[u];
		while(top) pushdown(S[top--]);
		for(int y=fa[x], z=fa[y]; !isroot(x); z=fa[y=fa[x]]) {
			int f1 = ch[y][1] == x, f2 = ch[z][1] == y;
			if(isroot(y)) rotate(x, f1);
			else if(f1 ^ f2) rotate(x, f1), rotate(x, f2);
			else rotate(y, f2), rotate(x, f1);
		}
		update(x);
	}
	inline void access(int x) {
		for(int t = 0; x ; t = x, x = fa[x])
			Splay(x), ch[x][1] = t, update(x);
	}
	inline void makeroot(int x) {
		access(x), Splay(x), rev[x] ^= 1;
	}
	inline void link(int x, int y) {
		makeroot(x), fa[x] = y;
	}
	inline void cut(int x, int y) {
		makeroot(x), access(y), Splay(y);
		fa[x] = ch[y][0] = 0, update(y);
	}
	inline void Add(int u, int v, int w) {
		ch[w+n][0] = ch[w+n][1] = 0;
		fa[w+n] = 0, val[w+n] = Min[w+n] = w;
		link(u, w+n), link(w+n, v);
	}
	inline int Query(int x, int y) {
		if(x == y) return m;
		makeroot(x), access(y), Splay(y);
		while(ch[y][0]) y = ch[y][0];
		if(y != x) return INF;
		Splay(x);
		return Min[x];
	}
}T;

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch=='-') f=-1;
	for(; isdigit(ch); ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x * f;
}

void Add(int x, int &y, int l, int r, int p) {
	y = ++cnt;
	sum[y] = sum[x]+1;
	if(l == r) return;
	ls[y] = ls[x], rs[y] = rs[x];
	int mid = (l+r)>>1;
	if(p <= mid) Add(ls[x], ls[y], l, mid, p);
	else Add(rs[x], rs[y], mid+1, r, p);
}

int Query(int x, int y, int l, int r, int a, int b) {
	if(l == a && r == b) return sum[y]-sum[x];
	int mid = (l+r)>>1;
	if(b <= mid) return Query(ls[x], ls[y], l, mid, a, b);
	if(a > mid) return Query(rs[x], rs[y], mid+1, r, a, b);
	return Query(ls[x], ls[y], l, mid, a, mid)+
		Query(rs[x], rs[y], mid+1, r, mid+1, b);
}

int main() {

	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);

	int q, i;
	n = read(), Q = read(), type = read();
	T.init();
	for(q = 1; q <= Q; q++) {
		int t = read();
		if(t == 1) {
			int u = read(), v = read();
			if(type) {
				u = (u^lans)%n+1;
				v = (v^lans)%n+1;
			}
			E[++m].u = u, E[m].v = v;
			int res = T.Query(u, v);
			if(res == INF) {
				T.Add(u, v, m);
				Add(rt[m-1], rt[m], 0, Q, 0);
				last[m] = 0;
			}
		
			else {
				if(res != m) 
					T.cut(res+n, E[res].u), T.cut(res+n, E[res].v), T.Add(u, v, m);
				Add(rt[m-1], rt[m], 0, Q, res);
				last[m] = res;
			}
		}
		if(t == 2) {
			int u = E[m].u, v = E[m].v;
			if(u ^ v) T.cut(m+n, u), T.cut(m+n, v);
			if(last[m] && last[m] != m) {
				u = E[last[m]].u, v = E[last[m]].v;
				T.Add(u, v, last[m]);
			}
			m--;
		}
		if(t == 3) {
			int l = read(), r = read();
			if(type) {
				l = (l^lans)%m+1, r = (r^lans)%m+1;
				if(l > r) swap(l, r);
			}
			lans = n-Query(rt[l-1], rt[r], 0, Q, 0, l-1);
			printf("%d\n", lans);
		}
	}
	
	return 0;
}