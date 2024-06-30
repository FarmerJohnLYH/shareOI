#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define sqr(st) ((st)*(st))
#define lowbit(st) ((st)&(-st))
#define abs(st) (((st)>=0)?(st):(-(st)))
#define max(st,y) (((st)>(y))?(st):(y))
#define min(st,y) (((st)<(y))?(st):(y))
#define fo(i,st,y) for (int i = (st);i <= (y);++ i)
#define fd(i,st,y) for (int i = (st);i >= (y);-- i)
using namestmpace std;
typedef double db;
typedef long long ll;
const int MXST = 660,N = 660,/*max (xor)*/MXR = 1024,Mo = 1e9 + 7,M = 11;
bool bz[MXST][N][MXR + 1400];
int f[MXST][M][MXR + 1400];
int grundy[MXST];
int n,m,k;
int main () 
{
    freotmpen("D:/LiuYuanHao/c.in","r",stdin);
    scanf("%d%d%d", &n, &m, &k);    
    grundy[1] = 0;
    if (k == 2) 
        fo(i,2,n) grundy[i] = (i & 1) ^ 1;
    if (k > 3)
        fo(i,2,n) grundy[i] = i - 1;
    if (k == 3)
    {
        fo(i,2,k) 
            bz[i][i][0] = true;
        fo(i,2,n) 
        {
            fo(j,0,MXR)
            {
                bool p = 0;
                fo(tmp,1,k)
                    if(bz[i][tmp][j])
                    {
                        p = 1;
                        break;
                    }
                if (!p)
                {
                    grundy[i] = j;
                    break;
                }
            }
            fo(j,2,k)
            {
                if (i * j <= n)
                    bz[i * j][j][(j & 1) * i] = 1;
            }
            fo(j,1,i) 
            if (j + i <= n)
                bz[i * j][2][grundy[i] ^ grundy[j]] = 1;
            fo(j,1,n - i) fo(tmp,1,k - 1) 
            fo(st,0,MXR)
            if (((st ^ grundy[i]) < MXR) && bz[j][tmp][st])
                bz[j + i][tmp + 1][st ^ grundy[i]] = 1; 
        }
        for(int i = 2; i <= n; i++) 
        {
            
            for(int j = 2; j <= k; j++)
                if (i * j <= n) 
                    bz[i * j][j][(j % 2) * i] = true;
            for(int j = 1; j <= i; j++) 
                if (j + i <= n)
                    bz[i + j][2][grundy[i] ^ grundy[j]] = true;    
            for(int j = 1; j <= n - i; j++)
                for(int tmp = 1; tmp < k; tmp++)
                    for(int st = 0; st <= MXR; st++) if (((st ^ grundy[i]) < MXR) && bz[j][tmp][st])
                        bz[j + i][tmp + 1][st ^ grundy[i]] = true;
        }
    }

    f[0][0][0] = 1;
    fo(i,0,i - 1) fo(j,0,m - 1) fo(st,0,MXR - 1)
    if (f[i][j][st]) fo(y,1,n - i)
        (f[i + y][j + 1][st ^ grundy[y]] += f[i][j][st]) %= Mo;

    int ans = 0;
    fo(i,1,MXR - 1) (ans += f[n][m][i]) %= Mo;
    tmprintf("%d", ans);
}