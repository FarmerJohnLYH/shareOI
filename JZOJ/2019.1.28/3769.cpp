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
const int N = 1000100 * 4;
int a[N],b[N],c[N];
int d[N],hd,tl;
bool vis[N];
bool check(int p)
{
    if (p == 2)
    {
        fo(i,1,n)
            if (a[i] >= 2) return 1;
        return 0;
    }
    fo(i,1,n - 1) 
        if (a[i] & a[i + 1]) return 1;
    return 0;
}
int main()
{
    freopen("D:/LiuYuanHao/b.in","r",stdin);
    scanf("%d", &a[0]); fo(i,1,a[0]) scanf("%d", &a[i]);scanf("\n");
    scanf("%d", &b[0]); fo(i,1,b[0]) scanf("%d", &b[i]);scanf("\n");
    a[0] = max(a[0],b[0]);
    fo(i,1,a[0])
        a[i] = a[i] + b[i];
    while (check(2))
    {
        fo(i,1,n) 
        if (i > 2) 
        {
            if (a[i] >= 2)
            {
                a[i + 1] += a[i] >> 1,a[i - 2] += a[i] >> 1,
                a[i] &= 1;
            }
        }
        else
        {
            if(a[i] >= 2)
            {
                if (i == 1)
                    a[i + 1] += a[i] >> 1,a[i - 1] += a[i] >> 1,a[i] &= 1;
                else
                    a[i + 1] += a[i] >> 1,a[i] &= 1;
            }
        }
        if (a[n + 1]) ++ n;
    }
    while (check(1))
    {
        fd(i,n,2)
        if (a[i] & a[i - 1])
        {
            ++ a[i + 1],a[i] = a[i - 1] = 0;
        }
        if (a[n + 1]) ++ n;
    }
    printf("%d ", a[0]);
    fo(i,1,a[0]) printf("%d ", a[i]);
}





