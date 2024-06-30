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
int n,w[N][4],f[N][5],ans;
//1 比前者矮的(1) 2 比前者高的(2) 3 比前者矮的(2) 4 比前者高的(3) 
int h(int x)
{
    if (x >= 3) return x - 1;
    else return x;
}
int main()
{
    freopen("D:/LiuYuanHao/g.in","r",stdin);
    scanf("%d", &n);
    fo(i,1,n) scanf("%d%d%d", &w[i][1], &w[i][2], &w[i][3]);
    fo(fd,1,4)
    {
        memset(f[1],128,sizeof f[1]);
        f[1][fd] = w[1][h(fd)];
        fo(i,2,n + 1)
        {
            f[i][1] = max(f[i - 1][4],f[i - 1][2]) + w[i][1];
            f[i][2] = f[i - 1][1] + w[i][2],f[i][3] = f[i - 1][4] + w[i][2];
            f[i][4] = max(f[i - 1][1],f[i - 1][3]) + w[i][3];
        }
        ans = max(ans,f[n + 1][fd]);
    }
    printf("%d", ans);
}





