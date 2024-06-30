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
const int N = 1001000,Mo = 998244353;
int n,m,p,d;
int A,B,C;
int f[N],rain[N];
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
    freopen("D:/LiuYuanHao/a.in","r",stdin);
    n = read(),m = read(),p = read(),d = read(),A = read(),B = read(),C = read();
    fd(i,1,m) rain[i] = (1ll * rain[i - 1] + (1ll * d * C % Mo) + (1ll * (1 + Mo - d) * B % Mo)) % Mo;
    f[n] = A;
    fd(i,n - 1,0)
        f[i] = (A + (1ll * p * (rain[min(n - i,m)] + f[i + min(n - i,m) + 1]) % Mo) % Mo + (1ll * f[i + 1] % Mo)) % Mo;
    printf("%d", f[0]);
}





