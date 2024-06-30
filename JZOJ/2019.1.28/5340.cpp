#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (register ll i = (x);i <= (y);++ i)
#define fd(i,x,y) for (register ll i = (x);i >= (y);-- i)
using namespace std;
typedef double db;
typedef long long ll;
ll abs(ll x) {return(((x)>=0)?(x):(-(x)));}
ll max(ll x,ll y) {return(((x)>(y))?(x):(y));}
ll min(ll x,ll y) {return(((x)<(y))?(x):(y));}
ll lowbit(ll x) {return((x)&(-x));}
#define Mo 9901
ll a,b;
ll tw[44];
ll pow[44],p[44];
ll qsm(ll t)
{
    ll rt = 0;
    fo(i,0,40) 
    if (t & tw[i])
        rt = (rt * pow[i] + p[i]) % Mo;
    return rt;
}
int main()
{
    freopen("D:/LiuYuanHao/","r",stdin);
    scanf("%lld%lld", &a, &b);
    tw[0] = 1;fo(i,1,40) tw[i] = tw[i - 1] << 1;
    pow[0] = 1,pow[1] = a;
    fo(i,2,40) pow[i] = (pow[i - 1] * pow[i - 1]) % Mo;
    p[0] = 1,p[1] = a + 1;
    fo(i,2,40) p[i] = (p[i - 1] * pow[i - 1] + p[i - 1]) % Mo;
    ll f = qsm(b);
    printf("%lld", f);
}











