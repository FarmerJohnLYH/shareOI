/*
#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
const int N=4040,mo=1e9+7;
int n,w,h;
ll a[N],b[N],ans;
int a0,b0;
PI p[N];
map<int,int> ma,mb;
int u[N][N];
PI st[N];int s0;
ll calc(ll m,ll p)
{
	ll n=m-p+1;
	return((n+m)*(m-n+1)/2);
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d%d",&w,&h,&n);
	fo(i,1,n)
		scanf("%d%d",&p[i].fi,&p[i].se);
	sort(p+1,p+1+n);
	int las=0;a[a0=1]=0;
	fo(i,1,n)
	{
		a[++a0]=p[i].fi;
		ma[p[i].fi]=a0;
		if(p[i+1].fi-p[i].fi>1)
		{
			++a0;
			a[++a0]=p[i].fi+1;
		}
	}
	a[a0+1]=w+1;
	fo(i,1,n) swap(p[i].fi,p[i].se);
	sort(p+1,p+1+n);
	las=0;b[0]=-1;
	if(p[1].fi!=0) b[b0=1]=0; 
	fo(i,1,n)
	{
		b[++b0]=p[i].fi;
		mb[p[i].fi]=b0;
		if(p[i+1].fi-p[i].fi>1)
		{
			++b0;
			b[++b0]=p[i].fi+1;
		}
	}
	b[b0+1]=h+1;

	fo(i,1,n) 
	{
		swap(p[i].fi,p[i].se);
		u[ma[p[i].fi]][mb[p[i].se]]=-1;
	}
	fo(i,1,a0) fo(j,1,b0)
	if(u[i][j]!=-1)
		u[i][j]=(u[i][j+1]==-1)?(b[j+1]-b[j]):(u[i][j+1]+(b[j+1]-b[j]));
	fo(j,1,b0)
	{
		ll las=0;s0=0;st[0].fi=-1,st[0].se=w+1;
		fd(i,a0,1)
		{
	 		if(u[i][j]==-1)
			{
				s0=0;
				continue;
			}
			while(s0&&st[s0].fi>=u[i][j]) --s0;
			las=(las+);
			ll S=(b[j+1]-b[j])*(st[s0].se-a[i])%mo;
			ans=(ans+las*S+)%mo;
			las=las+(b[j+1]-b[j])*(st[s0].se-a[i]));
			st[++s0]=make_pair(u[i][j],a[i]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}*/
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<cstring>
using namespace std;

#define FOR(I,A,B) for (int I=int(A);I<int(B);++I)
#define MEM(A,B) memset(A,B,sizeof(A))
#define CPY(A,B) memcpy(A,B,sizeof(B))
#define FIN(A) freopen(A, "r", stdin)
#define FOUT(A) freopen(A, "w", stdout)
#define mp(A, B) make_pair(A, B)
#define x first
#define y second
typedef pair<int, int> Point;
typedef long long LL;

const int N(2010), MOD(1000000007);
struct Node {
    int l, r, h, c;
};
Point p[N];
int he[N], yy[N], sum[N];
map<int, int> num;
int ny, w, h, n;
int mul(LL a, LL b) {
    return a * b % MOD;
}
int add(int a, int b) {
    return (a + b) % MOD;
}
int pow(int a, int b) {
    if (b == 0) return 1;
    int t = pow(a, b / 2);
    t = mul(t, t);
    if (b % 2) t = mul(t, a);
    return t;
}
int calc(LL a0, LL del, LL n) {
    return mul(mul((2 * a0 + (n - 1) * del) % MOD, n), ny);
}
int main() {

    ny = pow(2, MOD - 2);
    cin >> w >> h >> n;
    FOR(i, 0, n) {
        int a, b;
        cin >> a >> b;
        p[i] = mp(a, b);
        num[b] = 0;
    }
    int m = 1;
    yy[0] = -1;
    for (map<int, int> :: iterator it = num.begin(); it != num.end(); ++it) {
        it->second = m;
        yy[m++] = it->first;
    }
    yy[m++] = h + 1;
    sort(p, p + n);
    p[n++] = mp(w + 1, 0);
    int ans = 0, d = (LL)(h + 1) * (h + 2) / 2 % MOD, tot = 0;
    MEM(he, 0);
    for (int i = 0, j = 0; i != n; i = j) {
        int gap = i == 0 ? p[i].x + 1 : p[i].x - p[i - 1].x;
        if (i == 0) ans = add(ans, calc(tot, d, gap));
        else ans = add(ans, calc(tot, d, gap));
        FOR(k, 1, m - 1)
            he[k] += gap;
        tot = add(tot, mul(d, gap));
        for (; j != n && p[j].x == p[i].x; ++j) {
            int x = num[p[j].y], y = w + 1, z;
            for (int k = x; k; --k) {
                y = min(y, he[k]);
                sum[k] = mul(y, yy[k] - yy[k - 1]);
            }
            FOR(k, 1, x + 1)
                sum[k] = add(sum[k], sum[k - 1]);
            int l = x;
            y = he[x];
            z = w + 1;
            FOR(k, x, m - 1) {
                z = min(z, he[k]);
                for (; l && y > z; y = min(y, he[--l]));
                tot = add(tot, -mul(sum[l], yy[k + 1] - yy[k]));
                tot = add(tot, -mul(mul(yy[x] - yy[l], z), yy[k + 1] - yy[k]));
            }
            he[x] = 0;
        }
    }
    if (ans < 0) ans += MOD;
    cout << ans << endl;
    return 0;
}







