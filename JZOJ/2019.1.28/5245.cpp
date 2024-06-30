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
#define fo(i,x,y) for (ll i = (x);i <= (y);++ i)
#define fd(i,x,y) for (ll i = (x);i >= (y);-- i)
using namespace std;
typedef double db;
typedef long long ll;
const ll N = 500500,M = 5005000;
ll n,m;
ll a[N];
ll read()
{
    char ch=' ';ll q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;
    ll n=q*w;return n;
}

ll buf[30];
void write(ll x)
{
    if (x<0) putchar('-'),x=-x;
    buf[0]=0;
    while (x) buf[++buf[0]]=x%10,x/=10;
    if (!buf[0]) buf[0]=1,buf[1]=0;
    while (buf[0]) putchar('0'+buf[buf[0]--]);
}
int main()
{
    freopen("D:/LiuYuanHao/b.in","r",stdin);
    for (ll T = read();-- T;)
    {
        n = read(),m = read();
        fo(i,1,n) a[i] = read();
        fd(i,n - 1,1) 
        {
            a[i] = min(a[i],a[i + 1] - 1);
            p[i] = a[i];
        }
        if (a[1] <= 0)
        {
            printf("0\n");
            continue;
        }
        ll now = min(a[n],m);
        bool flag = 1;
        while (now > 0)
        {
            fd(i,n,1) 
            {
                a[i] -= now;
                now = min(now - 1,a[i - 1]);
            }
            fo(i,1,n)
                if (a[i] <= 0) break;
        }
        ll ans = 0;
        fo(i,1,n) ans += p[i] - a[i];
        write(ans)
    }
}





