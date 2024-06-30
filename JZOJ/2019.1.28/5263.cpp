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
#define fo(i,x,y) for (register int asDfg = (y),i = (x);i <= asDfg;++ i)
#define fd(i,x,y) for (register int asDfg = (y),i = (x);i >= asDfg;-- i)
using namespace std;
typedef double db;
typedef long long ll;
const int N = 110；
int n,T;
int a[N],c[N];
int f[N][N];
int main()
{
    freopen("D:/LiuYuanHao/a.in","r",stdin);
    scanf("%d", &T);
    while (T --)
    {
        memset(f,127,sizeof f);
        scanf("%d", &n);
        fo(i,1,n) scanf("%d", &a[i]),f[i][i][a[i]] = 0,c[i] = (c[i - 1] + a[i]) % 100;
        fo(l,2,n)//区间 size
        {
            fo(i,1,n - l + 1) fo(j,i,i + l - 1)/*分界点*/
            {
                //i~j j+1~i+l
                int x = (c[j] - c[i] + 100) % 100,y = (c[i + l] - c[j] + 100) % 100;
                f[i][i + l] = min(f[i][i + l],x * y + f[i][j] + f[j + 1][i + l]);
            } 
        }
        printf("%d\n", f[1][n]);
    }
}






