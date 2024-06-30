#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define i0 i + i
#define i1 i + i + 1
using namespace std;

const int N = 1e6 + 5;

int n, A, B, C, ty, x, y, m;

struct node {
	int x, y, z;
} c[N];

ll ans;

void gg(int x, int y, int z) { c[++ m].x = x; c[m].y = y; c[m].z = z;}

int cmp(node a, node b) {
	return a.z > b.z;
}

struct tree {
	ll s; int bz, mi;	
} t[N * 4];

int px, py, pl, pr;

void down(int i, int x, int y) {
	if(t[i].bz) {
		int m = x + y >> 1;
		
		t[i0].bz = max(t[i0].bz, t[i].bz);
		t[i0].s = (ll) t[i0].bz * (m - x + 1);
		
		t[i1].bz = max(t[i1].bz, t[i].bz);
		t[i1].s = (ll) t[i1].bz * (y - m);
		
		t[i0].mi = t[i0].bz;
		t[i1].mi = t[i1].bz;
		
		t[i].bz = 0;
	}
}

void fi(int i, int x, int y) {
	if(x == y) {
		if(t[i].bz <= py) px = x;
		return;
	}
	int m = x + y >> 1; down(i, x, y);
	if(t[i0].mi <= py) fi(i0, x, m); else fi(i1, m + 1, y);
}

void add(int i, int x, int y) {
	if(y < pl || x > pr) return;
	if(x >= pl && y <= pr) {
		t[i].bz = t[i].mi = px;
		t[i].s = (ll) t[i].bz * (y - x + 1);
		return;
	}
	int m = x + y >> 1; down(i, x, y);
	add(i0, x, m); add(i1, m + 1, y);
	t[i].mi = min(t[i0].mi, t[i1].mi);
	t[i].s = t[i0].s + t[i1].s;
}

void ins(int x, int y) {
	py = y; px = A + 1;
	fi(1, 1, A);
	if(px <= x) {
		pl = px; pr = x; px = y;
		add(1, 1, A);
	}
}

void read(int &x) {
	char c = ' ';
	for(; c < '0' || c > '9'; c = getchar());
	x = 0; for(; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - 48;
}

int main() {
	freopen("i.in", "r", stdin);
	freopen("i.out", "w", stdout);
	scanf("%d %d %d %d", &n, &A, &B, &C);
	fo(i, 1, n) {
		read(ty); read(x); read(y);
		if(ty == 1) gg(x, y, C);
		if(ty == 2) gg(A, x, y);
		if(ty == 3) gg(y, B, x);
	}
	sort(c + 1, c + n + 1, cmp);
	fo(i, 1, n) {
		ans += t[1].s * (c[i - 1].z - c[i].z);
		ins(c[i].x, c[i].y);
	}
	ans += t[1].s * c[n].z;
	printf("%lld\n", ans);
}