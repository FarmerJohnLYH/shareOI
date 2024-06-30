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
#define fm(i,x) for (int i = las[x];i;i = e[i].nex)
using namespace std;
typedef double db;
typedef long long ll;
const int N = 100100;
char st[21][N],sta[N],stb[N];
int len[21],p[N];
int n,m;
int main()
{
    freopen("house.in","r",stdin);
    freopen("house.out","w",stdout);
    scanf("%d%d\n", &n, &m);
    fo(i,1,n)
        scanf("%s\n", st[i] + 1),len[i] = strlen(st[i]+1);
    while (m --)
    {
        scanf("%s%s\n", sta + 1, stb + 1);
        int lena = strlen(sta + 1),lenb = strlen(stb + 1);
        fo(i,2,lena)
        {
            while (sta[i] != sta[j + 1] && j) j = p[j];
            p[i] = (sta[i]==sta[j + 1]) ?(++j):j;
        }
        fo(k,1,n)
        {
            j = 0;
            fo(i,1,len[k])
            {
                if (st[k][i] == '$') continue;
                while (sta[j + 1] != st[k][i] && j) j = p[j];
                if (sta[j + 1] == st[k][i])
                {
                    if ((++ j) !=lena) continue;
                    v = i,l = lenb;
                    while (l)
                    {
                        if (st[k][v]!='$') st[k][v] = stb[l],-- l;
                        -- v;
                    }
                    l += lena - lenb;
                    while (l)
                    {
                        if (st[k][v] != '$') st[k][v] = '$',-- l;
                        -- v;
                    }
                    j = 0;
                }
            }
        }
    }
    fo(i,1,n)
    {
        fo(j,1,len[i])
            if (st[i][j] != '$') putchar(st[i][j]);
        putchar("\n");
    }
}