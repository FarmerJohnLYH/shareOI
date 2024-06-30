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
#define fo(i,x,y) for (int i = (x);i <= (y);++ i)
#define fd(i,x,y) for (int i = (x);i >= (y);-- i)
using namespace std;
typedef double db;
typedef long long ll;
const int N = 2020;
int n;
int c[N],s[N];
int f[N][N];
int S(int l,int r)
{
    return (s[r] - s[l - 1]);
}
int main()
{
    freopen("D:/LiuYuanHao/a.in","r",stdin);
    memset(f,128,sizeof f);
    scanf("%d", &n);
    fo(i,1,n) scanf("%d", &c[i]),s[i] = c[i] + s[i - 1];
    fo(i,1,n) fo(j,n - i,n) f[i][j] = S(i,n);
    fd(i,n-1,1) fo(j,1,n) fo(k,1,j)
        f[i][j] = max(f[i][j],S(i,i + k - 1) - f[i + k][k * 2])
    printf("%d", f[1][1]);
}





