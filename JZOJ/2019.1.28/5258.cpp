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
const int N = 100100,NM = 2048;
int n,m;
int a[N][4],b[N][4];
int p[N][3],q[NM];
int o[4],ans;
int get(int x,int y)
{
    int dif = 0,sm = 0;
    fo(i,1,3) 
    {
        sm += !(a[x][i] ^ a[y][i]);
        int u = a[x][i] ^ a[y][i];
        while (u) u -= lowbit(u),++ dif;
    }
    if (dif == 2) return (sm == 1)?2:1;
    else return 0;
}
int main()
{
    freopen("D:/LiuYuanHao/b.in","r",stdin);
    o[1] = 1023,o[2] = 1047552,o[3] = 1072693248;
    scanf("%d%d", &n, &m);
    fo(i,1,n)
    {
        scanf("%d", &a[i][0]);
        fo(j,1,3) 
        {
            a[i][j] = a[i][0] & o[j];
            p[i][j] = q[a[i][j]];
            q[a[i][j]] = i;
        }
    }
    //ans默认*2
    fd(i,n,1)
    {
        fo(j,1,3)
        {
            for(int tmp = p[i][j];tmp;tmp = p[tmp][j])
                ans += get(i,tmp);
        }
    }
    printf("%d", ans);
}






