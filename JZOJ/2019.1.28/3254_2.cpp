//心累+Good game
#include<cstdio>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

const int inf = 1 << 30;

int n, a[10], mi, mx, b[10][10], tb, du[10], d[10], dis[10];

const int M = 1000;

int final[M], next[M], to[M], r[M], tot = 1, S, T, co[M], dt[M], cur[M];
void cl() {
    fo(i, 1, T) final[i] = dt[i] = co[i] = cur[i] = 0;
    fo(i, 2, tot) next[i] = 0;
    tot = 1;
}
void link(int x, int y, int z) {
    next[++ tot] = final[x], to[tot] = y, r[tot] = z, final[x] = tot;
    next[++ tot] = final[y], to[tot] = x, r[tot] = 0, final[y] = tot;
}
int dfs(int x, int flow) {
    if(x == T) return flow;
    int use = 0;
    for(int i = cur[x]; i; i = next[i], cur[x] = i) {
        int y = to[i];
        if(r[i] && dt[y] + 1 == dt[x]) {
            int tmp = dfs(y, min(flow - use, r[i]));
            r[i] -= tmp, r[i ^ 1] += tmp, use += tmp;
            if(use == flow) return use;
        }
    }
    cur[x] = final[x];
    if(!(-- co[dt[x]])) dt[S] = T;
    ++ co[++ dt[x]];
    return use;
}

int p[10][10], q[10];
int bz[10], ans, sum;

void dd(int x) {
    if(x > n) {
        sum ++; return;
    }
    fo(i, 1, n) if(!bz[i]) {
        int ky = 1;
        fo(j, 1, b[i][0]) if(bz[b[i][j]])  {
            ky = 0; break;
        }
        if(ky) bz[i] = 1, dd(x + 1), bz[i] = 0;
    }
}

void dg(int x, int y) {
    if(tb > 9) return;
    if(x > n) {
        d[0] = 0; fo(i, 1, n) du[i] = 0;
        fo(i, 1, n) fo(j, 1, b[i][0]) du[b[i][j]] ++;
        fo(i, 1, n) if(!du[i]) d[++ d[0]] = i;
        fo(i, 1, d[0]) fo(j, 1, b[d[i]][0]) if(!(-- du[b[d[i]][j]])) d[++ d[0]] = b[d[i]][j];
        if(d[0] != n) return;
        int dep = 0;
        fd(i, d[0], 1) {
            if(!b[d[i]][0]) {dis[d[i]] = 1; continue;}
            int y = dis[b[d[i]][1]];
            fo(j, 2, b[d[i]][0]) if(y != dis[b[d[i]][j]]) return;
            dis[d[i]] = y + 1;
        }
        fo(i, 1, n) p[i][0] = q[i] = 0;
        fo(i, 1, n) p[dis[i]][++ p[dis[i]][0]] = i, dep = max(dep, dis[i]);

        fo(i, 2, dep) {
            cl();
            int tmp = 0;
            fo(j, 1, p[i][0]) {
                int x = p[i][j];
                tmp += a[x] - b[x][0];
                if(a[x] < b[x][0]) return;
                link(S, x, a[x] - b[x][0]);
                fo(k, 1, b[x][0]) link(x, b[x][k], inf), q[b[x][k]] ++;
            }
            fo(j, 1, p[i - 1][0]) {
                int x = p[i - 1][j];
                if(a[x] < q[x]) return;
                if(a[x] > q[x]) link(x, T, a[x] - q[x]);
            }

            co[0] = T; int fw = 0;
            for(; dt[S] < T;) fw += dfs(S, inf);
            if(fw < tmp) return;
        }
        sum = 0; dd(1);
        if(sum >= mi && sum <= mx) ans ++;
        return;
    }
    if(y > n) {
        dg(x + 1, x + 2);
        return;
    }
    tb ++;
    b[x][++ b[x][0]] = y;
    dg(x, y + 1); b[x][0] --;
    b[y][++ b[y][0]] = x;
    dg(x, y + 1); b[y][0] --;
    tb --;
    dg(x, y + 1);
}

int main() {
    // freopen("D:/LiuYuanHao/a.in","r",stdin);
    scanf("%d", &n);
    fo(i, 1, n) scanf("%d", &a[i]);
    scanf("%d %d", &mi, &mx);
    S = n + 1; T = n + 2;
    dg(1, 2);
    printf("%d\n", ans);
}