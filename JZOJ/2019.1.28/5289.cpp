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
const int N = 300300;
int n,m;
int a[N];
bool check(int x)
{
    while (x % 10 == 2 || x % 10 == 3) x /= 10;
    return x;
}
int main()
{
    freopen("D:/LiuYuanHao/b.in","r",stdin);
    n = read(),m = read();
    fo(i,1,n) a[i] = read();
    fo(i,1,m)
    {
        char typ = getchar();
        int l = read(),r = read();
        int cnt = 0;
        if (typ == 'c')
        {
            fo(j,l,r)
                if (check(a[j])) ++ cnt;
            printf("%d\n", cnt);
        }
        else
        {
            int x = read();
            fo(j,l,r) a[j] += x;    
        }
        getchar();
    }
}











