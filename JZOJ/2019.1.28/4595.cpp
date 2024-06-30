#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (register int asDfg = (y),i = (x);i <= asDfg;++ i)
#define fd(i,x,y) for (register int asDfg = (y),i = (x);i >= asDfg;-- i)
using namespace std;
typedef double db;
typedef long long ll;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N = 1010;
int n,m,k,f[N][N][11][2];
char s[N],st[N];
int main() 
{
    // freopen("string.in","r",stdin);
    // freopen("string.out","w",stdout);
    freopen("D:/LiuYuanHao/a.in","r",stdin);
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s\n%s", s + 1, st + 1);
    fo(i,1,n) fo(j,1,m) fo(l,1,k) -
    {
        f[i][j][l][0] = max(f[i - 1][j][l][1],f[i][j - 1][l][1]);
        f[i][j][l][0] = max(f[i][j][l][0],max(f[i - 1][j][l][0],f[i][j - 1][l][0]));
        if (s[i] == st[j])
        {
            f[i][j][l][1] = f[i - 1][j - 1][l - 1][0] + 1;
            if (s[i - 1] == st[j - 1]) f[i][j][l][1] = max(f[i][j][l][1],f[i - 1][j - 1][l][1] + 1);
        }
    }
    printf("%d",max(f[n][m][k][0],f[n][m][k][1]));
}