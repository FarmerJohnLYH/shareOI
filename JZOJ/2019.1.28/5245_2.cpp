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
const int N = 500500;
int n,m,T;
ll ans,a[N],b[N];
ll read()
{
    char ch=' ';ll q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;
    ll n=q*w;return n;
}
ll work(int p)
{
    ll tmp = 1ll * p * (p - 1) / 2 * n;
    b[n] = min(a[n],1ll * m * p - tmp);
    fd(i,n - 1,1) b[i] = min(a[i],b[i + 1] - p);
    if (b[1] - p < tmp) return 0;
    ll sum = b[1],s = max(0,b[1] - 1ll * (m + 1) * (p - 1) + tmp - 1),now = b[1];
    ll space = m - n * p - s + 1;
    fo(i,2,n)
    {
        now += p;
        int mov = min(b[i] - now,space);
        space -= mov,now += mov,sum += now;
    }
    return sum;
}
int main()
{
    freopen("compete.in","r",stdin); 
    freopen("compete.out","w",stdout);
    freopen("D:/LiuYuanHao/b.in","r",stdin);
    for (T = read();T --;)
    {
        n = read(),m = read();
        fo(i,1,n) a[i] = read();
        ll ans = 0;
        fo(i,1,m/n) 
            ans = max(ans,work(i));
        printf("%lld\n", ans);
    }
    fclose(stdin); fclose(stdout);
    return 0;
}