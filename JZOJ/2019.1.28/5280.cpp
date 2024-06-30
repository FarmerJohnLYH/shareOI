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
const int N = 2000200;
int n,k,f;
int a[N],ans[N],tot,mx,b[N];
bool bz[N];
bool check(int x)
{
    int rt = 0;
    fo(i,1,n)
    {
        if (a[i] % x > k || a[i] < x)
            if ((++ rt) > f) return 0;
    }
    return 1;
}
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;
    int n=q*w;return n;
}
int buf[30];
void write(int x)
{
    if (x<0) putchar('-'),x=-x;
    buf[0]=0;
    while (x) buf[++buf[0]]=x%10,x/=10;
    if (!buf[0]) buf[0]=1,buf[1]=0;
    while (buf[0]) putchar('0'+buf[buf[0]--]);
}
int main()
{
//    freopen("D:/LiuYuanHao/b.in","r",stdin);
//    freopen("D:/LiuYuanHao/b.out","w",stdout);
    int T = read();
    while (T --)
    {
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        n = read(),k = read(),f = read();
        fo(i,1,n)
        {
            int x = read();
            mx = max(mx,x);
            if (x <= 1 + k) ++ a[x]; else ++ b[x - k];
        }
        fo(i,1,mx) a[i] += a[i - 1],b[i] += b[i - 1];
        fo(i,1,k + 1)
            if (a[i - 1] <= f) 
                printf("%d ",i);
        fo(i,k + 2,mx)
        {
            int s = a[mx] - a[i - 1];
            for (int j = i;j <= mx;j += i) s += b[j] - b[max(j - i,j - k - 1)];
            if (n - s <= f) printf("%d ",i);
        }
}



