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
const int N = 5050,NUM = 2002000;
int d[NUM * 2]/*默认 数字都+2002000*/
int n,D,a[N]; 
struct node{
    int le,ri;
    int sm;
}e[N * N],er[N * N];
bool cmp(node a,node b)
{
    return (a.le < b.le ||((a.le == b.le) && (a.ri < b.ri)));
}
bool cmpr(node a,node b)
{
    return (a.ri < b.ri ||((a.ri == b.ri) && (a.le < b.le)));
}
int main()
{
    freopen("D:/LiuYuanHao/c.in","r",stdin);
    scanf("%d%d", &n， &D);
    fo(i,1,n)
    {
        scanf("%d", &a[i]);
        a[i] += NUM;
        fo(j,i - D + 1,i) 
        {
            int l = i + 1,r = j + D - 1;
            if (l > r) continue;
            e[++ tot].le = l,e[tot].ri = r,
            e[tot].sm = a[i] + a[j];
            er[tot] = e[tot];
        }
    }
    sort(e + 1,e + 1 + tot,cmp);
    sort(er + 1,er + 1 + tot,cmpr);
    int ze = 1,zer = 1; 
    fo(i,1,n)
    {
        //i-1 进队  i-d出队
        while (e[ze].le >= i - 1)
        {
            ++ ze;
            ++ d[e[ze].sm];
        }
        while (er[zer].ri <= i - d)
        {
            ++ zer;
            -- d[er[zer].sm];
        }
        int ans = 0;
        fo(j,i - D + 1,i - 1)
            ans += d[a[i] - a[j] + NUM + NUM];
        printf("%d\n", ans);
    }
}












