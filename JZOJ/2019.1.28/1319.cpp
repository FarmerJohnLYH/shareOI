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
const int N = 220,M = 11 * N;
int n,m,w;
int e[N][M];
bool bz[M];
int ans[M];
void euler(int x, int las)
{   
    fo(i,1,e[x][0]) 
    {
        if (e[x][i] == -1) continue;
        e[x][i] = -1;
        euler(e[x][i],x)
    }
    ans[++ tot] = las;
}  
int main()
{
    freopen("D:/LiuYuanHao/c.in","r",stdin);
    scanf("%d%d", &n, &m);
    fo(i,1,n)
    {
        int x;
        scanf("%d", &x);
        w += x;
    }
    ans[ans[0] = 1] = 1;
    fo(i,1,m)
    {
        int x,y;
        scanf("%d%d", &x, &y);
        e[x][++ e[x][0]] = y,e[y][++ e[y][0]] = x;
    }
    fo(i,1,n) sort(e[i] + 1,e[i] + 1 + e[i][0])
    euler(1,-1);
    fo(i,1,tot) printf("%d ", ans[i]);

}





