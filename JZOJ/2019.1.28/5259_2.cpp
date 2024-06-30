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
const int N = 1010,P = 10010;
int n,P;
int f[N][P];
int d[N][2],hd,tl;
int main()
{
    freopen("D:/LiuYuanHao/","r",stdin);
    for (int T = read();T --;)
    {
        n = read(),P = read();
        fo(i,1,n) a[i] = read();
        fo(i,1,n) b[i] = read();
        fo(i,1,n) c[i] = read();
        memset(f,127,sizeof f);
        f[0][0] = 0;
        fo(i,1,n)
        {
            hd = tl = 0;
            fo(j,0,p)
            {
                f[i][j] = min(f[i][j],f[i - 1][j]);
                while (d[hd][0] < x - b[i]) ++ hd;
                while (d[tl][1] >= f[i - 1][j - a[i]] && hd <= tl) -- tl;
                d[++ tl][1] = f[i - 1][j - a[i]];
                d[tl][0] = j - a[i];
                f[i][j] = min(f[i][j],d[hd][1] + c[i]);
            }
        }
    }
}






