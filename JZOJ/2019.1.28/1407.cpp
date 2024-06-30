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
const int N = 100100,M = 50500;
int f[N],a[N];  
int n,m;
int main()  
{
    freopen("D:/LiuYuanHao/f.in","r",stdin);  
    scanf("%d%d", &n, &m);  
    fo(i,1,n)
        scanf("%d", a[i]);  
    int e = n + 1;  
    f[e] = 0;  
    while (e > 1)  
    {
        int o = 0;
        fo(i,1,e - 1)
            if (a[i] + i >= e) 
            {
                o = i;
                break;
            }
        f[o] = f[e] + 1;  
        fo(j,o + 1,e - 1)
        {  
            if (a[j] + j >= e) f[j] = f[e] + 1;  
            else f[j] = f[o] + 1;  
        }
        e = o;  
    }  
    fo(i,1,m)
    {
        int tmp;
        scanf("%d", &tmp);
        printf("%d ", f[tmp]);
    }
}   