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
const int N = 100100;
int n,l,r;
int h[N];
int sq[N],s[N];
double query(int l,int r)
{
    return (double)((sq[r] - sq[i - 1]) / (j - i + 1) - sqr((s[j] - s[i - 1]) / (j - i + 1)));
}
int main()
{
    freopen("D:/LiuYuanHao/a.in","r",stdin);
    scanf("%d%d%d", &n, &l, &r);
    sq[0] = s[0] = 0;
    fo(i,1,n) scanf("%d", &h[i]),sq[i] = sq[i - 1] + sqr(h[i]),s[i] = s[i - 1] + h[i];
    double ans = oo;    
    fo(i,1,n - l + 1)
        ans = min(ans,query(i,i + l - 1))
    printf("%.3lf", ans);
}





