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
const int N = 3030,Mo = 1e9 + 7;
int f[N][N];
int n,k;
int main()
{
    freopen("D:/LiuYuanHao/b.in","r",stdin);
    int T;
    scanf("%d", &T);
    f[1][1] = 1,f[2][1] = 2,f[3][1] = 4,f[3][2] = 2;
        fo(i,4,3000)
        {
            fo(j,0,3000)
            {
                f[i][j] = (f[i][j] + f[i - 1][j] * 2 * j) % Mo;
                if (i - 2 * j + 2 > 0 && j - 1 >= 0) f[i][j] = (f[i][j] + (f[i - 1][j - 1] * (i - 2 * (j - 1)) % Mo)) % Mo;
            }
        }
        fo(i,1,3000) fo(j,0,2999)
            f[i][j] = (f[i][j] + f[i][j - 1]) % Mo; 
    while (T --)
    {
        scanf("%d%d", &n, &k);
        printf("%d", f[n][n - k]);
    }
}





