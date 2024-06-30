
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 5;

struct Node {
    int l, r, Num;
} Tr[MAXN * 50];

int tot, Q, N, A, B, P, M, Root;
char S[MAXN], C[10];

int Calc(int i) {
    return (1ll * i * A + B) % N;
}

int Query(int Now, int l, int r, int Side) {
    if (!Now) return 0;
    if (l == r) return Tr[Now].Num;
    int Mid = (l + r) >> 1;
    if (Side <= Mid) return Tr[Now].Num + Query(Tr[Now].l, l, Mid, Side); else
        return Tr[Now].Num + Query(Tr[Now].r, Mid + 1, r, Side);
}

void Modify(int &Now, int l, int r, int lx, int rx, int val) {
    if (rx < l || lx > r) return;
    if (!Now) Now = ++ tot;
    if (l >= lx && r <= rx) {
        Tr[Now].Num += val;
        return;
    }
    int Mid = (l + r) >> 1;
    Modify(Tr[Now].l, l, Mid, lx, rx, val), Modify(Tr[Now].r, Mid + 1, r, lx, rx, val);
}

void Modify(int v, int val) {
    int c = S[v] - '0', l, r;
    if (c == 0) l = 0, r = P - 1; else l = P, r = N - 1;
    l = ((l % N - 1ll * A * v % N) % N + N) % N;
    r = ((r % N - 1ll * A * v % N) % N + N) % N;
    if (l <= r) Modify(Root, 0, N - 1, l, r, val); else
        Modify(Root, 0, N - 1, l, N - 1, val), Modify(Root, 0, N - 1, 0, r, val); 
} 

int main() {
    scanf("%d%d%d%d%d\n", &N, &A, &B, &P, &M);
    scanf("%s", S);
    Root = tot = 1;
    for (int i = 0; i < M; i ++) Modify(i, 1);
    scanf("%d", &Q);
    for (int i = 1; i <= Q; i ++) {
        int v;
        scanf("\n%s%d", C + 1, &v);
        if (C[1] == 'Q') printf("%d\n", M - Query(Root, 0, N - 1, Calc(v))); else {
            Modify(v, -1);
            S[v] = (S[v] == '0') ? '1' : '0';
            Modify(v, 1);
        }
    }
}