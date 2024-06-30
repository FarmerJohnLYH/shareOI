#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define abs(x) (((x)>=0)?(x):(-(x)))
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define fo(i,x,y) for (ll i = (x);i <= (y);++ i)
#define fd(i,x,y) for (ll i = (x);i >= (y);-- i)
using namespace std;
typedef double db;
typedef long long ll;
const ll N = 1000100,Mo = 1000000007;
ll n,m;
ll ans;
ll jc[N],ny[N];
ll c(ll n,ll m)
{
    ll p = (jc[n] * (ny[n - m] * ny[m]) % Mo) % Mo;
}
ll qsm(ll a,ll b)
{
    ll x = 1;
    while (b)
    {
          if (b & 1) x = (x * a) % Mo;
          b >>= 1;
          a = (a * a) % Mo;
    }
    return x;
} 
int main()
{
    freopen("D:/LiuYuanHao/a.in","r",stdin);
    ll tmp = 1;
    fo(i,1,1000010)
    {
        jc[i] = tmp,ny[i] = qsm(tmp,Mo - 2);
        tmp = (tmp * i) % Mo;
    }
    scanf("%lld%lld", &n, &m);
    if (n > m) swap(n,m);
    ans = m % Mo;
    //(m,1)(m+1,2)
    fo(i,2,n)
        ans = (ans + c(m + i,i + 1)) % Mo;
    printf("%lld", ans);
}




#include <cstdio>
#include <algorithm>

typedef long long int64;

const int64 MOD = 1000000007;

int64 n, m, ans;

inline void INC(int64 &a, int64 b) { a = (a + b) % MOD; }
inline void MUL(int64 &a, int64 b) { a = (a * b) % MOD; }

inline int64 pow_m(int64 base, int64 exp) {
  int64 res = 1;
  while (exp) {
    if (exp & 1) MUL(res, base);
    MUL(base, base);
    exp >>= 1;
  }
  return res;
}
inline int64 inv(int64 a) { return pow_m(a, MOD - 2); }
inline void DIV(int64 &a, int64 b) { return MUL(a, inv(b)); }

inline int64 cal(int64 n, int64 m) {
  int64 res = 1;
  for (int64 i = n; i > n - m; --i) MUL(res, i);
  for (int64 i = m; i > 0; --i) DIV(res, i);
  return res;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  scanf("%lld%lld", &n, &m);
  if (m > n) std::swap(n, m);
  printf("%lld\n", (cal(n + m + 1, m) + n) % MOD);
  return 0;
}


