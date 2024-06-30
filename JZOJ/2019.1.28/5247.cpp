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
const int N = 1010;
int n,m;
int x[N],y[N];
int main()
{
    freopen("D:/LiuYuanHao/","r",stdin);
    scanf("%d", &n);
    fo(i,1,n) scanf("%d", &x[i]); sort(x + 1,x + 1 + n);
    fo(i,1,n) scanf("%d", &y[i]); sort(y + 1,y + 1 + n);
    scanf("%d", &m);
    fo(i,1,m)
    {
        int p,q;
        scanf("%d%d", &p, &q);
        int l = 1,r = n,ans = 0;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (x[mid] * y[mid] <= p * y[mid] + q * x[mid]) l = mid + 1,ans = mid;
            else r = mid - 1;
        }
        printf("%d\n", ans);
    }
}






