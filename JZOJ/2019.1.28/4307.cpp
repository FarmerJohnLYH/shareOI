#include <cmath> 
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
const int N = 100100,NUM = 100100,m = 1e5;
int n,k,ans;
int a[N],nr[NUM],g[NUM];
int main()
{
    freopen("drink.in","r",stdin);
    freopen("drink.out","w",stdout);
    //freopen("D:/LiuYuanHao/a.in","r",stdin);
    scanf("%d%d", &n, &k);
    fo(i,1,n) 
    {
        scanf("%d", &a[i]);
        g[i] = max(nr[a[i]],g[i - 1]);
        ans += i - g[i];
        if (a[i] == k) fo(j,k + 1,m) nr[j] = i;
        int q = sqrt(a[i]),p = a[i] - k;
        fo(j,1,q) 
        if ((p % j == 0) && (k < (p/j))) nr[p/j] = i;
    }
    printf("%d", ans);
}





