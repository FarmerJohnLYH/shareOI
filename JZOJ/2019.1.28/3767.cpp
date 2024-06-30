#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define stor(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define abs(x) (((x)>=0)?(x):(-(x)))
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define fo(i,x,y) for (int i = (x);i <= (y);++ i)
#define fd(i,x,y) for (int i = (x);i >= (y);-- i)
using namespace std;
typedef double db;
typedef long long ll;
const int N = 33, Mo = 1e9 + 7;
int n,m,num,tot,nm[N];
char st[N];
map<char, int> mp;
//0 num || 1 +-*/ || 2 ( || 3 ) || 4 0 
bool bz[5][5] = {
    {1,1,0,1,1},
    {1,0,1,0,1},
    {1,0,1,0,1},
    {0,1,0,1,0},
    {1,1,0,1,1}};
struct node{
    int to,nex;
}e[N * N];
int las[N];
ll f[N][N][N][2];
void link(int x,int y)
{
    e[++ tot].to = y,e[tot].nex = las[x];
    las[x] = tot;
}
int main()
{
    freopen("D:/LiuYuanHao/a.in","r",stdin);
    scanf("%d%d%d\n", &n, &m, &num);
    fo(i,1,9) mp[(char)i + '0'] = 0;
    mp['+'] = mp['-'] = mp['*'] = mp['/'] = 1;
    mp['('] = 2,mp[')'] = 3,mp['0'] = 4;
    scanf("%s", st + 1);
    fo(i,1,n) 
    {
        nm[i] = mp[st[i]];
        if (nm[i] == 0 || st[i] == '-') f[1][i][0][0] = 1;
        if (nm[i] == 2) f[1][i][1][0] = 1;
        if (nm[i] == 4) f[1][i][0][1] = 1;
    }
    fo(i,1,m)
    {
        int x,y;
        scanf("%d%d", &x, &y);
        link(x,y),link(y,x);
    }
    fo(i,2,num) fo(j,1,n) fo(k,0,i)
        if (!(nm[j] == 2 && k == 0))
        for (int tmp = las[j];tmp;tmp = e[tmp].nex)
        {
            int to = e[tmp].to;
            if (bz[nm[to]][nm[j]] || (st[to] == '(' && st[j] == '-'))
            {
                int k1 = k;
                if (nm[j] == 2) -- k1; else if (nm[j] == 3) ++ k1;
                ll v = f[i - 1][to][k1][0];
                if (nm[j] != 4 && nm[j] != 0) v = (v + f[i - 1][to][k1][1]) % Mo; 
                if (! (nm[j] == 4 && nm[to] != 0 && nm[to] != 4) ) f[i][j][k][0] = (f[i][j][k][0] + v) % Mo;
                else f[i][j][k][1] = (f[i][j][k][1] + v) % Mo;
            }
        }
    ll ans = 0;
    fo(i,1,n)
        if (nm[i] != 1) 
            ans = (ans + f[num][i][0][0] + f[num][i][0][1]) % Mo;
    printf("%lld",ans);
}